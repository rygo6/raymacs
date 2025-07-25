#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "raylib.h"
#include "raymath.h"

//      0  1    2
// 369  
// bcioolharnline
// 012345678901234

#define FIND_CARET_COLOR     (Color){ 0, 255, 0, 255 }
#define FIND_HIGHLIGHT_COLOR (Color){ 0, 255, 0, 64 }

typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;
typedef int8_t      i8;
typedef int16_t     i16;
typedef int32_t     i32;
typedef int64_t     i64;
typedef float       f32;
typedef double      f64;
typedef const char* str;

#define MAX_INPUT_CHARS 2048
#define TEXT_BUFFER_CAPACITY 32000

#define LOG(...) printf(__VA_ARGS__);
#define CASE_EITHER(_key, _a, _b) case _key | _a | _b: case _key | _a: case _key | _b
#define TO_LOWER_C(_c) 'a' + (_c - KEY_A)

const int endCharLength = 1;
float maxCharWidth = 128;
float maxCharHeight = 128;
const float fontXSpacing = 10;
const float fontYSpacing = 20;
const float fontSize = 24;
const char availableChars[] = "·¬ abcdefghijklmnopqrstuvwxyzABDCEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+[];',./{}:\"<>?|`~\n\t\\";

typedef struct TextBuffer {
	int startLineIndex;
	int startLine;
	int caretBufferIndex;
	int caretRow;
	int caretCollumn;
	int newLineCount;
	int bufferCount;
	char* buffer;
	char* path;
	bool dirty;
} TextBuffer;

typedef enum Direction {
	DIRECTION_NONE,
	DIRECTION_FORWARD,
	DIRECTION_BACKWARD,
	DIRECTION_COUNT,
} Direction;
const char* string_Direction[] = {
	[DIRECTION_NONE]     = "DIRECTION_NONE",
	[DIRECTION_FORWARD]  = "DIRECTION_FORWARD",
	[DIRECTION_BACKWARD] = "DIRECTION_BACKWARD",
};

#define COMMAND_BUFFER_CAPACITY 32
typedef struct CommandBuffer {
	bool enabled;
	bool repeat;

	int  bufferCount;
	char buffer[COMMAND_BUFFER_CAPACITY];

	Direction scanDirection; 
	int       scanFoundIndex;

} CommandBuffer;

static int buffScanCharLeft(const char* pBuffer, int index, char c) {
	while (pBuffer[index] != c && index >= 0) index--;    
	return index;
}

static int buffScanCharRight(const char* pBuffer, int index, char c) {
	while (pBuffer[index] != c && pBuffer[index] != '\0') index++;    
	return index;
}

// static int textLineStart(const char* pText) {
// 	return buffScanCharLeft(pText->buffer, pText->caretBufferIndex, '\n') + 1;
// }

static inline int textCollumnIndex(const TextBuffer* pText) {
	return pText->caretBufferIndex - (buffScanCharLeft(pText->buffer, pText->caretBufferIndex, '\n') + endCharLength);  
}

static bool buffSearchCountCharLeft(const char* pBuffer, char searchChar, char countChar, int* pFoundIndex, int *pCount) {
	int index = *pFoundIndex;
	while (pBuffer[index] != searchChar) {
		if (pBuffer[index] == countChar) *pCount = *pCount + 1;
		if (index <= 0) return false;
		index--; 
	}
	*pFoundIndex = index;
	return true;
}

static bool buffSearchCountCharRight(const char* pBuffer, char searchChar, char countChar, int* pFoundIndex, int *pCount) {
	int index = *pFoundIndex;
	while (pBuffer[index] != searchChar) {
		if (pBuffer[index] == countChar) *pCount = *pCount + 1;
		if (pBuffer[index] == '\0') return false;
		index++;    
	}
	*pFoundIndex = index;
	return true;
}

static void textUpdateStartLineIndex(TextBuffer* pText) {
	int index = 0;
	int startLine = pText->startLine;
	int startLineCount = 0;
	while (startLineCount < startLine) {
		if (pText->buffer[index] == '\n' || pText->buffer[index] == '\0')
			startLineCount++;
		index++;
	}
	pText->startLineIndex = index;
}

static void textUpdateStartLineLeft(TextBuffer* pText) {
	if (pText->caretRow < 0) {
		pText->startLine += pText->caretRow;
		pText->caretRow = 0;

		if (pText->startLine < 0)
			pText->startLine = 0;

		textUpdateStartLineIndex(pText);
	}
}

static void textUpdateStartLineRight(TextBuffer* pText) {
	int iMaxCharHeight = maxCharHeight - 1;

	if (pText->caretRow > iMaxCharHeight) {
		pText->startLine += pText->caretRow - iMaxCharHeight;
		pText->caretRow = iMaxCharHeight;

		textUpdateStartLineIndex(pText);
	}
} 

typedef enum TextScanMatch{
	TEXT_SCAN_MATCH_IMMEDIATE,
	TEXT_SCAN_MATCH_SKIP_IMMEDIATE,
	TEXT_SCAN_COUNT,
} TextScanMatch;

typedef enum TextCaret {
	TEXT_CARET_LEFT,
	TEXT_CARET_RIGHT,
	TEXT_CARET_COUNT,
} TextCaret;

static void textScanCharLeft(TextBuffer* pText, char scanChar, TextCaret caretJustify, TextScanMatch scanMatch) {
	int newLineCount = 0;
	int newIndex = pText->caretBufferIndex;
	if (scanMatch == TEXT_SCAN_MATCH_SKIP_IMMEDIATE) {
		if (caretJustify == TEXT_CARET_RIGHT && newIndex >= 0) {
			if      (pText->buffer[newIndex - 1] == '\n') { newIndex--; newLineCount++; }
			else if (pText->buffer[newIndex - 1] == scanChar)      newIndex--;
		}
		if      (pText->buffer[newIndex] == '\n') { newIndex--; newLineCount++; }
		else if (pText->buffer[newIndex] == scanChar)      newIndex--;
	}
	if (!buffSearchCountCharLeft(pText->buffer, scanChar, '\n', &newIndex, &newLineCount)) return;
	if (caretJustify == TEXT_CARET_RIGHT) newIndex++;
	if (newIndex <= 0) return;

	pText->caretBufferIndex = newIndex;
	pText->caretRow -= newLineCount;
	pText->caretCollumn = textCollumnIndex(pText);
	textUpdateStartLineLeft(pText);
}

static void textScanCharRight(TextBuffer* pText, char scanChar, TextCaret caretJustify, TextScanMatch scanMatch) {
	int newLineCount = 0;
	int newIndex = pText->caretBufferIndex;
	if (scanMatch == TEXT_SCAN_MATCH_SKIP_IMMEDIATE){
		if      (pText->buffer[newIndex] == '\n') { newIndex++; newLineCount++; }
		else if (pText->buffer[newIndex] == scanChar) newIndex++;
	}
	if (!buffSearchCountCharRight(pText->buffer, scanChar, '\n', &newIndex, &newLineCount))	return;
	if (caretJustify == TEXT_CARET_RIGHT) newIndex++;
	if (newIndex >= pText->bufferCount - endCharLength)	return;

	pText->caretBufferIndex = newIndex;
	pText->caretRow += newLineCount;
	pText->caretCollumn = textCollumnIndex(pText);
	textUpdateStartLineRight(pText);
} 

// static void textScanBuffRight(TextBuffer* pText, char* pScanBuff) {
// 	int newLineCount = 0;
// 	int newIndex = TextFindIndex(pText->buffer + pText->caretBufferIndex, pScanBuff);
// 	if (newIndex == 0) return;
// 	if (newIndex >= pText->bufferCount - endCharLength)	return;

// 	pText->caretBufferIndex = newIndex;
// 	pText->caretRow += newLineCount;
// 	pText->caretCollumn = textCollumnIndex(pText);
// 	textUpdateStartLineRight(pText);
// } 

static void textInsertChar(TextBuffer* pText, char c) {
	memmove(pText->buffer + pText->caretBufferIndex + 1, pText->buffer + pText->caretBufferIndex, pText->bufferCount - pText->caretBufferIndex - 1);
	pText->buffer[pText->caretBufferIndex] = c;
	pText->bufferCount++;
	pText->caretBufferIndex++;
	pText->caretCollumn++;
	pText->dirty = true;
}

static TextBuffer text;

#define MASK_ASCII        0b00000000000000000000000111111111 
#define KEY_LSHIFT_MOD 0b10000000000000000000000000000000
#define KEY_RSHIFT_MOD 0b01000000000000000000000000000000
#define KEY_LALT_MOD   0b00100000000000000000000000000000
#define KEY_RALT_MOD   0b00010000000000000000000000000000
#define KEY_LCTRL_MOD  0b00001000000000000000000000000000
#define KEY_RCTRL_MOD  0b00000100000000000000000000000000

#define KEY_RCTRL_A KEY_A | KEY_RCTRL_MOD
#define KEY_RCTRL_D KEY_D | KEY_RCTRL_MOD
#define KEY_RCTRL_W KEY_W | KEY_RCTRL_MOD
#define KEY_RCTRL_S KEY_S | KEY_RCTRL_MOD

#define KEY_LCTRL_J KEY_J | KEY_LCTRL_MOD
#define KEY_LCTRL_L KEY_L | KEY_LCTRL_MOD
#define KEY_LCTRL_I KEY_I | KEY_LCTRL_MOD
#define KEY_LCTRL_K KEY_K | KEY_LCTRL_MOD

int main(void)
{
	/// Initialization
	SetConfigFlags(FLAG_VSYNC_HINT);
	EnableEventWaiting();

	const int screenWidth = 1600;
	const int screenHeight = 1200;

	InitWindow(screenWidth, screenHeight, "rayDE");
	   
	/// Font
	int codepointCount = 0;
	int *codepoints = LoadCodepoints(availableChars, &codepointCount);
	Font font = LoadFontEx("resources/JetBrainsMono-Regular.ttf", fontSize, codepoints, codepointCount);
	SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);
	SetTextLineSpacing(0); 

	/// Editor State
	Rectangle textBox = { 5, 20, screenWidth - 10, screenHeight - 25 };
	bool mouseOnText = false;
	int framesCounter = 0;

	struct {
		float scrollMouse;
		bool  lMouse;
		bool  lShift;
		bool  lCtrl;
		bool  lAlt;
		bool  rShift;
		bool  rCtrl;
		bool  rAlt;
		u32   modifierCombination;
	} input;

	/// File
	{
		text.path = "./src/main.c";
		char* loadedFile = LoadFileText(text.path);
		while (loadedFile[text.bufferCount] != '\0') {
			if (loadedFile[text.bufferCount] == '\n') text.newLineCount++;
			text.bufferCount++;
		}
		LOG("Loaded Buffer Size %d\n", text.bufferCount);
		assert(text.bufferCount < TEXT_BUFFER_CAPACITY && "Loaded buffer size too big!");

		text.buffer = calloc(TEXT_BUFFER_CAPACITY, sizeof(char));
		memcpy(text.buffer, loadedFile, text.bufferCount + 1);
		free(loadedFile);
	}

	/// Text State
	CommandBuffer command = {
		.enabled = false,
		.repeat  = false,

		.bufferCount = 0,
		.buffer      = {},

		.scanDirection = DIRECTION_FORWARD,
		.scanFoundIndex = -1,
	};

	int priorKey = 0;

	TextBuffer* pText = &text;
	
	/// Loop
	while (!WindowShouldClose())   
	{
		framesCounter++;

		maxCharWidth = (textBox.width / fontXSpacing) - 1;
		maxCharHeight = (textBox.height / fontYSpacing) - 1;
		
		/// Input 
		{
			SetMouseCursor(mouseOnText ? MOUSE_CURSOR_IBEAM : MOUSE_CURSOR_DEFAULT);
	
			//// Refresh Input
			input.scrollMouse = GetMouseWheelMove();

			input.lMouse = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

			input.lShift = IsKeyDown(KEY_LEFT_SHIFT);
			input.lAlt   = IsKeyDown(KEY_LEFT_ALT);
			input.lCtrl  = IsKeyDown(KEY_LEFT_CONTROL) | IsKeyDown(KEY_LEFT_SUPER);

			input.rShift = IsKeyDown(KEY_RIGHT_SHIFT);
			input.rAlt   = IsKeyDown(KEY_RIGHT_ALT);
			input.rCtrl  = IsKeyDown(KEY_RIGHT_CONTROL) | IsKeyDown(KEY_RIGHT_SUPER);

			input.modifierCombination = 
				(input.lShift ? KEY_LSHIFT_MOD : 0) |
				(input.lAlt   ? KEY_LALT_MOD   : 0) |
				(input.lCtrl  ? KEY_LCTRL_MOD  : 0) |

				(input.rShift ? KEY_RSHIFT_MOD : 0) |
				(input.rAlt   ? KEY_RALT_MOD   : 0) |
				(input.rCtrl  ? KEY_RCTRL_MOD  : 0) ;
						
			int currentKey = GetKeyPressed();
			if (currentKey == 0 && IsKeyPressedRepeat(priorKey))
				currentKey = priorKey;

			/// Finish Input Actions Release
			if (currentKey == 0 && input.modifierCombination == 0) {

				if (command.enabled){
					LOG("Command Finish\n");
					command.enabled = false;

					if (command.scanFoundIndex > 0) {
						pText->caretBufferIndex += command.scanFoundIndex;
						command.scanFoundIndex = -1;
					}
				}

			}

			/// Input Switch
			while (currentKey > 0)
			{
				int modifiedKey = currentKey;
				switch (currentKey | input.modifierCombination) {

					/// Move Left
					case KEY_LEFT: 
					case KEY_RCTRL_A:
					case KEY_LCTRL_J:
						if (pText->caretBufferIndex <= 0) break;

						pText->caretBufferIndex--;

						if (pText->buffer[pText->caretBufferIndex] == '\n')
							pText->caretRow--;

						pText->caretCollumn = textCollumnIndex(pText);

						textUpdateStartLineLeft(pText);
						break;

					CASE_EITHER(KEY_LEFT,    KEY_LSHIFT_MOD, KEY_RSHIFT_MOD):
					CASE_EITHER(KEY_RCTRL_A, KEY_LSHIFT_MOD, KEY_RSHIFT_MOD):
					CASE_EITHER(KEY_LCTRL_J, KEY_LSHIFT_MOD, KEY_RSHIFT_MOD):
						textScanCharLeft(pText, ' ', TEXT_CARET_RIGHT, TEXT_SCAN_MATCH_SKIP_IMMEDIATE);
						break;

					/// Move Right
					case KEY_RIGHT: 
					case KEY_RCTRL_D:
					case KEY_LCTRL_L:
						if (pText->caretBufferIndex >= pText->bufferCount - endCharLength) break;

						if (pText->buffer[pText->caretBufferIndex] == '\n')
							pText->caretRow++;
						
						pText->caretBufferIndex++;		
						pText->caretCollumn = textCollumnIndex(pText);

						textUpdateStartLineRight(pText);
						break;

					CASE_EITHER(KEY_RIGHT,   KEY_LSHIFT_MOD, KEY_RSHIFT_MOD):
					CASE_EITHER(KEY_RCTRL_D, KEY_LSHIFT_MOD, KEY_RSHIFT_MOD):
					CASE_EITHER(KEY_LCTRL_L, KEY_LSHIFT_MOD, KEY_RSHIFT_MOD):
						textScanCharRight(pText, ' ', TEXT_CARET_RIGHT, TEXT_SCAN_MATCH_SKIP_IMMEDIATE);
						break;

					case KEY_LALT_MOD | KEY_LEFT_ALT: 
						if (!command.enabled) {
							LOG("Command Enabled\n");
							command.enabled = true;
						}
						break;

					case KEY_LALT_MOD | KEY_LCTRL_MOD | KEY_LEFT_CONTROL: 
						if (command.enabled) {
							command.scanDirection = command.scanDirection == DIRECTION_FORWARD ? DIRECTION_BACKWARD : DIRECTION_FORWARD;
							LOG("Command Scan %s\n", string_Direction[command.scanDirection]);
						}
						break;

					case KEY_LALT_MOD | '`' : 
					case KEY_LALT_MOD | '-' : 
					case KEY_LALT_MOD | '=' : 
					case KEY_LALT_MOD | '[' : 
					case KEY_LALT_MOD | ']' : 
					case KEY_LALT_MOD | '\\':
					case KEY_LALT_MOD | ';' : 
					case KEY_LALT_MOD | '\'':
					case KEY_LALT_MOD | ',' : 
					case KEY_LALT_MOD | '.' : 
					case KEY_LALT_MOD | '/' : 

					case (KEY_LALT_MOD | '0') ... (KEY_LALT_MOD | '9'): 
						textScanCharRight(pText, currentKey, TEXT_CARET_LEFT, TEXT_SCAN_MATCH_SKIP_IMMEDIATE);
						break;

					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '1':  modifiedKey = '!'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '2':  modifiedKey = '@'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '3':  modifiedKey = '#'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '4':  modifiedKey = '$'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '5':  modifiedKey = '%'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '6':  modifiedKey = '^'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '7':  modifiedKey = '&'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '8':  modifiedKey = '*'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '9':  modifiedKey = '('; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '0':  modifiedKey = ')'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '`':  modifiedKey = '~'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '-':  modifiedKey = '_'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '=':  modifiedKey = '+'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '[':  modifiedKey = '{'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | ']':  modifiedKey = '}'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '\\': modifiedKey = '|'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | ';':  modifiedKey = ':'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '\'': modifiedKey = '"'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | ',':  modifiedKey = '<'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '.':  modifiedKey = '>'; goto UpdateCommandBuffer;
					case KEY_LALT_MOD | KEY_LSHIFT_MOD | '/':  modifiedKey = '?'; goto UpdateCommandBuffer;

					case (KEY_LALT_MOD | 'A') ... (KEY_LALT_MOD | 'Z'): 
						modifiedKey = TO_LOWER_C(currentKey);
						goto UpdateCommandBuffer;

					case (KEY_LALT_MOD | KEY_LSHIFT_MOD | 'A') ... (KEY_LALT_MOD | KEY_LSHIFT_MOD | 'Z'): 
						goto UpdateCommandBuffer;



					/// Move Up
					case KEY_UP: 
					case KEY_RCTRL_W:
					case KEY_LCTRL_I:
					{
						int upLineEnd   = buffScanCharLeft(pText->buffer, pText->caretBufferIndex - 1, '\n');        
						int upLineStart = buffScanCharLeft(pText->buffer, upLineEnd - endCharLength, '\n') + endCharLength;
						int upLineDiff  = upLineEnd - upLineStart;
						if (upLineStart < 0)
							break;

						text.caretBufferIndex = upLineStart + (text.caretCollumn < upLineDiff ? text.caretCollumn : upLineDiff);
						text.caretRow--;
					
						textUpdateStartLineLeft(pText);
						break;
					}

					CASE_EITHER(KEY_UP,      KEY_LSHIFT_MOD, KEY_RSHIFT_MOD):
					CASE_EITHER(KEY_RCTRL_W, KEY_LSHIFT_MOD, KEY_RSHIFT_MOD):
					CASE_EITHER(KEY_LCTRL_I, KEY_LSHIFT_MOD, KEY_RSHIFT_MOD):
						textScanCharLeft(pText, '{', TEXT_CARET_LEFT, TEXT_SCAN_MATCH_SKIP_IMMEDIATE);
						break;

					/// Move Down
					case KEY_DOWN: 
					case KEY_RCTRL_S:
					case KEY_LCTRL_K:
					{
						int currentLineEnd = buffScanCharRight(pText->buffer, pText->caretBufferIndex, '\n');
						int downLineStart = currentLineEnd + endCharLength;
						int downLineEnd = buffScanCharRight(pText->buffer, downLineStart, '\n');
						if (downLineStart >= text.bufferCount - endCharLength)
							break;

						int downLineDiff = downLineEnd - downLineStart;

						text.caretBufferIndex = downLineStart + (text.caretCollumn < downLineDiff ? text.caretCollumn : downLineDiff);
						text.caretRow++;        

						textUpdateStartLineRight(pText);
						break;
					}

					CASE_EITHER(KEY_DOWN,    KEY_LSHIFT_MOD, KEY_RSHIFT_MOD):
					CASE_EITHER(KEY_RCTRL_S, KEY_LSHIFT_MOD, KEY_RSHIFT_MOD):
					CASE_EITHER(KEY_LCTRL_K, KEY_LSHIFT_MOD, KEY_RSHIFT_MOD):
						textScanCharRight(pText, '{', TEXT_CARET_LEFT, TEXT_SCAN_MATCH_SKIP_IMMEDIATE);
						break;

					/// Utility Keys
					case KEY_LCTRL_MOD | KEY_S:
						LOG("Saving: %s", text.path);
						SaveFileText(text.path, text.buffer);
						break;

					/// Character Delete Keys
					case KEY_BACKSPACE: if (text.bufferCount > 0) {
							if (text.buffer[text.caretBufferIndex - 1] == '\n') 
								text.newLineCount--;
							
							memmove(text.buffer + text.caretBufferIndex - 1, text.buffer + text.caretBufferIndex, text.bufferCount - text.caretBufferIndex);
							text.bufferCount--;
							text.caretBufferIndex--;
						}
						break;

					case KEY_DELETE: if (text.bufferCount > 0 && text.caretBufferIndex < text.bufferCount - 1) {
							if (text.buffer[text.caretBufferIndex] == '\n') 
								text.newLineCount--;
							
							text.bufferCount--;
							memmove(text.buffer + text.caretBufferIndex, text.buffer + text.caretBufferIndex + 1, text.bufferCount - text.caretBufferIndex - 1);
						}
						break;

					/// Character Insert Keys
					case KEY_ENTER: 
						textInsertChar(pText, '\n'); 
						text.newLineCount++; 
						break;

					case KEY_SPACE:
						textInsertChar(pText, ' '); 
						break;

					case KEY_TAB: 
						textInsertChar(pText, '\t'); 
						break;

					case (KEY_LSHIFT_MOD | 'A') ... (KEY_LSHIFT_MOD | 'Z'): 
						textInsertChar(pText, currentKey); 
						break;

					case 'A' ... 'Z': 
						textInsertChar(pText, 'a' + (currentKey- KEY_A)); 
						break;

					case KEY_KP_0 ... KEY_KP_9: 
						textInsertChar(pText, '0' + (currentKey- KEY_KP_0)); 
						break;

					case '0' ... '9': 
						textInsertChar(pText, currentKey); 
						break;

					case '`':  textInsertChar(pText, currentKey); break;
					case '-':  textInsertChar(pText, currentKey); break;
					case '=':  textInsertChar(pText, currentKey); break;
					case '[':  textInsertChar(pText, currentKey); break;
					case ']':  textInsertChar(pText, currentKey); break;
					case '\\': textInsertChar(pText, currentKey); break;
					case ';':  textInsertChar(pText, currentKey); break;
					case '\'': textInsertChar(pText, currentKey); break;
					case ',':  textInsertChar(pText, currentKey); break;
					case '.':  textInsertChar(pText, currentKey); break;
					case '/':  textInsertChar(pText, currentKey); break;

					case KEY_LSHIFT_MOD | '1':  textInsertChar(pText, '!'); break;
					case KEY_LSHIFT_MOD | '2':  textInsertChar(pText, '@'); break;
					case KEY_LSHIFT_MOD | '3':  textInsertChar(pText, '#'); break;
					case KEY_LSHIFT_MOD | '4':  textInsertChar(pText, '$'); break;
					case KEY_LSHIFT_MOD | '5':  textInsertChar(pText, '%'); break;
					case KEY_LSHIFT_MOD | '6':  textInsertChar(pText, '^'); break;
					case KEY_LSHIFT_MOD | '7':  textInsertChar(pText, '&'); break;
					case KEY_LSHIFT_MOD | '8':  textInsertChar(pText, '*'); break;
					case KEY_LSHIFT_MOD | '9':  textInsertChar(pText, '('); break;
					case KEY_LSHIFT_MOD | '0':  textInsertChar(pText, ')'); break;
					case KEY_LSHIFT_MOD | '`':  textInsertChar(pText, '~'); break;
					case KEY_LSHIFT_MOD | '-':  textInsertChar(pText, '_'); break;
					case KEY_LSHIFT_MOD | '=':  textInsertChar(pText, '+'); break;
					case KEY_LSHIFT_MOD | '[':  textInsertChar(pText, '{'); break;
					case KEY_LSHIFT_MOD | ']':  textInsertChar(pText, '}'); break;
					case KEY_LSHIFT_MOD | '\\': textInsertChar(pText, '|'); break;
					case KEY_LSHIFT_MOD | ';':  textInsertChar(pText, ':'); break;
					case KEY_LSHIFT_MOD | '\'': textInsertChar(pText, '"'); break;
					case KEY_LSHIFT_MOD | ',':  textInsertChar(pText, '<'); break;
					case KEY_LSHIFT_MOD | '.':  textInsertChar(pText, '>'); break;
					case KEY_LSHIFT_MOD | '/':  textInsertChar(pText, '?'); break;

					UpdateCommandBuffer:
						command.buffer[command.bufferCount++] = modifiedKey;
						command.buffer[command.bufferCount] = '\0';
						command.scanFoundIndex = TextFindIndex(pText->buffer + pText->caretBufferIndex, command.buffer);
						break;

					default: break;

				} //switch (currentKey| input.modifierCombination) 
				
				priorKey = currentKey;
				currentKey = GetKeyPressed();

			} // while (currentKey > 0)
		}


		/// Draw
		BeginDrawing();
		{
			ClearBackground(RAYWHITE);
			
			float frameTime = GetFrameTime();

			DrawText(TextFormat("frameTime: %f/", frameTime), 512, 0, 20, GRAY);
			DrawText(TextFormat("INPUT CHARS: %i %i", text.bufferCount, text.caretBufferIndex), 0, 0, 20, DARKGRAY);

			DrawRectangleRec(textBox, RAYWHITE);
			DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);
			
			// bool blink = ((framesCounter/20) % 2) == 0;
			
			Vector2 mousePosition = GetMousePosition();

			int index = pText->startLineIndex;
			// int startLineCount = 0;
			// while (startLineCount < text.startLine) {
			// 	if (text.buffer[index] == '\n' || text.buffer[index] == '\0')
			// 		startLineCount++;
			// 	index++;
			// }

			const int tabWidth = 4;

			for (int y = 0; y < maxCharHeight; ++y) {
				int tabCount = 0;
				for (int x = 0; x < maxCharWidth - (tabCount * tabWidth); ++x) {

					Vector2 position = {
						textBox.x + (fontXSpacing * x) + (tabCount * fontXSpacing * 4), 
						textBox.y + (fontYSpacing * y)
					};										

					if (index == text.caretBufferIndex)
						DrawLineEx(
							(Vector2){position.x, position.y}, 
							(Vector2){position.x, position.y + fontYSpacing}, 
							4, ORANGE);

					if (command.bufferCount != 0 && command.scanFoundIndex != -1 && index == text.caretBufferIndex + command.scanFoundIndex) {
						DrawRectangleRec(
							(Rectangle) {
								.x = position.x, .y = position.y, 
								.width = fontXSpacing * command.bufferCount, 
								.height = fontYSpacing}, 
							FIND_HIGHLIGHT_COLOR);
						DrawLineEx(
							(Vector2){position.x, position.y}, 
							(Vector2){position.x, position.y + fontYSpacing}, 
							4, FIND_CARET_COLOR);
					}

					Rectangle rect = {position.x, position.y, fontXSpacing, fontYSpacing};

					char c = text.buffer[index];
					Color color = DARKGRAY;
					switch (text.buffer[index]) {
						case '\0':
							goto FinishDrawingText;

						case '\n':

							c =  '|';
							color = LIGHTGRAY;
							int codePointSize;
							int codePoint = GetCodepoint(&c, &codePointSize);
							DrawTextCodepoint(font, codePoint, position, fontSize, color);

							index++;

							// Check click on entire line
							rect.width = textBox.width - rect.width;
							if (input.lMouse && CheckCollisionPointRec(mousePosition, rect)){
								text.caretBufferIndex = index - 1;
								text.caretCollumn = textCollumnIndex(&text);
							}
							goto NextLine;

						case '\t':
							c = '-';
							color = LIGHTGRAY;
							tabCount++;
							// Step more spaces for tab width
							rect.width += (tabCount * fontXSpacing * tabWidth);
							break;

						case ' ':
							c =  '_';
							color = LIGHTGRAY;
							break;

						default: break;
					}
				
					if (input.lMouse && CheckCollisionPointRec(mousePosition, rect)){
						float xDiff = mousePosition.x - (rect.x + (rect.width / 2));
						text.caretBufferIndex = xDiff > 0 ? index + 1 : index;
						text.caretCollumn = textCollumnIndex(&text);
					}
										
					int codePointSize;
					int codePoint = GetCodepoint(&c, &codePointSize);
					DrawTextCodepoint(font, codePoint, position, fontSize, color);
										
					index++;
				}


				NextLine:;
			}       



			// if (command.enabled != 0 && command.scanFoundIndex != -1 && index == text.caretBufferIndex + command.scanFoundIndex) {
			// 	DrawRectangleRec(
			// 		(Rectangle) {
			// 			.x = position.x, .y = position.y, 
			// 			.width = fontXSpacing * command.bufferCount, 
			// 			.height = fontYSpacing}, 
			// 		FIND_HIGHLIGHT_COLOR);
			// 	DrawLineEx(
			// 		(Vector2){position.x, position.y}, 
			// 		(Vector2){position.x, position.y + fontYSpacing}, 
			// 		4, FIND_CARET_COLOR);
			// }
		}

		FinishDrawingText:
		EndDrawing();
		
	}

	/// Cleanup
	CloseWindow();

	return 0;
}


