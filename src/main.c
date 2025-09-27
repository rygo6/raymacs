#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "raylib.h"
#include "raymath.h"

//      0  1    2
// 369  
// bcioolharnline
// 012345678901234

#define FIND_CARET_COLOR     (Color){   0, 255,   0, 255 }
#define FIND_HIGHLIGHT_COLOR (Color){   0, 255,   0, 64  }
#define COLOR_COMMAND_BOX    (Color){  20,  20,   2, 200 }
#define COLOR_TEXT_BOX       (Color){ 230, 230, 230, 255 }

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

#define MAX_INPUT_CHARS      2048
#define TEXT_BUFFER_CAPACITY 32000

#define LOG(...) printf(__VA_ARGS__);
#define CASE_EITHER(_key, _a, _b) case _key | _a | _b: case _key | _a: case _key | _b
#define TO_LOWER_C(_c) 'a' + (_c - 'A')

float xCharCapacity = 128;
float yCharCapacity = 128;

const int endCharLength = 1;
const int tabWidth = 4;
const float fontXSpacing = 10;
const float fontYSpacing = 20;
const float fontSize = 24;
const char availableChars[] = "·¬ abcdefghijklmnopqrstuvwxyzABDCEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+[];',./{}:\"<>?|`~\n\t\\";

typedef enum Direction : u8 {
	DIRECTION_NONE,
	DIRECTION_FORWARD,
	DIRECTION_BACKWARD,
	DIRECTION_COUNT,
} Direction;
static const char* string_Direction[] = {
	[DIRECTION_NONE]     = "DIRECTION_NONE",
	[DIRECTION_FORWARD]  = "DIRECTION_FORWARD",
	[DIRECTION_BACKWARD] = "DIRECTION_BACKWARD",
};

#define CARET_COUNT 128
#define CARET_INVALID INT_MIN

typedef struct Caret {
	int index;
	int collumn;
	int line;
} Caret;

typedef struct Highlight {
	int startIndex;
	int endIndex;
} Highlight;

typedef struct CodeBox {
	int focusStartLineIndex;
	int focusStartLine;

	bool  caretEnabled[CARET_COUNT];
	Caret caret[CARET_COUNT];

	int caretIndex;
	int caretLine;
	int caretLineIndex;

	int newLineCount;
	int bufferCount;

	char* buffer;
	char* path;
	bool dirty;
} CodeBox;

typedef struct Command {
	bool enabled;
	bool toggled;
	bool skipCount;
	bool firstKeyPressed;

	Direction scanDirection;
	int       scanFoundIndex;

	int  bufferCount;
	char buffer[32];
} Command;

// Find specified char. 
static int TextFindCharBackward(const char* text, int index, char c) {
	while (index >= 0 && text[index] != c) index--;    
	return index;
}

// Find specified char. 
static int TextFindCharForward(const char* pBuffer, int index, char c) {
	while (pBuffer[index] != c && pBuffer[index] != '\0') index++;    
	return index;
}

// Find specified substring. 
static int TextFindTextBackward(const char* text, int index, const char* find) {
	while (index >= 0) {
		int i = 0;
		while (text[index + i] == find[i]) 
			if (find[++i] == '\0') return index;
		index--;
	}
	return index;
}

// Find specified substring. 
static int TextFindTextForward(const char* text, int index, const char* find) {
	while (text[index] != '\0') {
		int i = 0; while (text[index + i] == find[i]) 
			if (find[++i] == '\0') return index;
		index++;
	}
	return index;
}

// Find first char which is not the specified char.
static int TextNegateFindCharBackward(const char* text, int index, char find) {
	while (index >= 0 && text[index] == find) index--;    
	return index;
}

// Find first char which is not the specified char.
static int TextNegateFindCharForward(const char* text, int index, char find) {
	while (text[index] == find && text[index] != '\0') index++;    
	return index;
}

static int TextFindCharsForward(const char* text, int index, const char* find) {
	while (text[index] != '\0') {
		int i = 0; while (find[i] != '\0') 
			if (text[index] == find[i++]) return index;
		index++;
	}
	return index;
}

static int TextFindCharsBackward(const char* text, int index, const char* find) {
	while (index >= 0) {
		int i = 0; while (find[i] != '\0') 
			if (text[index] == find[i++]) return index;
		index--;
	}
	return index;
}

// Find char skipping a specified number of matches. 
static int TextFindCharSkipForward(const char* pBuffer, char find, int skipCount) {
	int index = 0;
	while (pBuffer[index] != '\0' && skipCount > 0) {
		if (pBuffer[index] == find) skipCount--;   
		index++;
	}
	return index;
}

// Count occurances of char.
static int TextCountCharForward(const char* text, int index, int range, char find) {
	int count = 0;
	for (int i = 0; i < range; ++i) {
		if (text[i] == find) count++;
		if (text[i] == '\0') break;
	}
	return count;
}

// Find char index and also count occurense of another char during scan.
static bool TextFindCountCharForward(const char* pBuffer, char searchChar, char countChar, int* pFoundIndex, int *pCount) {
	int index = *pFoundIndex;
	while (pBuffer[index] != searchChar) {
		if (pBuffer[index] == countChar) *pCount = *pCount + 1;
		if (pBuffer[index] == '\0') return false;
		index++;    
	}
	*pFoundIndex = index;
	return true;
}

// Find char index and also count occurense of another char during scan.
static bool TextFindCountCharBackward(const char* pBuffer, char searchChar, char countChar, int* pFoundIndex, int *pCount) {
	int index = *pFoundIndex;
	while (pBuffer[index] != searchChar) {
		if (pBuffer[index] == countChar) *pCount = *pCount + 1;
		if (index <= 0) return false;
		index--;
	}
	*pFoundIndex = index;
	return true;
}

// The index of the first character which the caret is currently on.
static inline int CodeBoxCaretLineIndex(const CodeBox* pCode) {
	int lineStartIndex = TextFindCharBackward(pCode->buffer, pCode->caretIndex, '\n') + endCharLength;
	return pCode->caretIndex - lineStartIndex;
}

static inline int CodeBoxCaretLine(const CodeBox* pCode) {
	return TextCountCharForward(pCode->buffer, 0, pCode->caretIndex, '\n');
}

// Focus on a given line.
static void CodeBoxFocusLine(CodeBox* pCode, int toLine) {
	int charCapacity = yCharCapacity;

	int yMin = pCode->focusStartLine;
	if (toLine < yMin) {
		pCode->focusStartLine = toLine;
		pCode->focusStartLineIndex = TextFindCharSkipForward(pCode->buffer, '\n', pCode->focusStartLine);
	}

	int yMax = yMin + charCapacity;
	if (toLine > yMax) {
		pCode->focusStartLine = toLine - charCapacity;
		pCode->focusStartLineIndex = TextFindCharSkipForward(pCode->buffer, '\n', pCode->focusStartLine);
	}

	TraceLog(LOG_INFO, "%d  %d  %d  \n", toLine, pCode->focusStartLine, pCode->focusStartLineIndex);
	// LOG("%d  %d  \n", pCode->focusStartLine, pCode->focusStartLineIndex);
} 

// Focus on a given character index.
static inline void CodeBoxFocusIndex(CodeBox* pCode, int toIndex) {
	int toLine = CodeBoxCaretLine(pCode);
	CodeBoxFocusLine(pCode, toLine);
}

static inline void CodeBoxFocusCaret(CodeBox* pCode) {
	CodeBoxFocusLine(pCode, pCode->caretLine);
}

// Update all caret state for index.
static void CodeBoxUpdateCaret(CodeBox* pCode, int newCaretIndex) {
	pCode->caretIndex     = newCaretIndex;
	pCode->caretLine      = CodeBoxCaretLine(pCode);
	pCode->caretLineIndex = CodeBoxCaretLineIndex(pCode);
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

// these I think can be simplified
static void textScanCharLeft(CodeBox* pCode, char scanChar, TextCaret caretJustify, TextScanMatch scanMatch) {
	int newLineCount = 0;
	int newIndex = pCode->caretIndex;
	if (scanMatch == TEXT_SCAN_MATCH_SKIP_IMMEDIATE) {
		if (caretJustify == TEXT_CARET_RIGHT && newIndex >= 0) {
			if      (pCode->buffer[newIndex - 1] == '\n') { newIndex--; newLineCount++; }
			else if (pCode->buffer[newIndex - 1] == scanChar)      newIndex--;
		}
		if      (pCode->buffer[newIndex] == '\n') { newIndex--; newLineCount++; }
		else if (pCode->buffer[newIndex] == scanChar)      newIndex--;
	}
	if (!TextFindCountCharBackward(pCode->buffer, scanChar, '\n', &newIndex, &newLineCount)) return;
	if (caretJustify == TEXT_CARET_RIGHT) newIndex++;
	if (newIndex <= 0) return;

	pCode->caretIndex = newIndex;
	pCode->caretLine -= newLineCount;
	pCode->caretLineIndex = CodeBoxCaretLineIndex(pCode);
	CodeBoxFocusLine(pCode, pCode->caretLine);
}

static void textScanCharRight(CodeBox* pCode, char scanChar, TextCaret caretJustify, TextScanMatch scanMatch) {
	int newLineCount = 0;
	int newIndex = pCode->caretIndex;
	if (scanMatch == TEXT_SCAN_MATCH_SKIP_IMMEDIATE){
		if      (pCode->buffer[newIndex] == '\n') { newIndex++; newLineCount++; }
		else if (pCode->buffer[newIndex] == scanChar) newIndex++;
	}
	if (!TextFindCountCharForward(pCode->buffer, scanChar, '\n', &newIndex, &newLineCount))	return;
	if (caretJustify == TEXT_CARET_RIGHT) newIndex++;
	if (newIndex >= pCode->bufferCount - endCharLength)	return;

	pCode->caretIndex = newIndex;
	pCode->caretLineIndex = CodeBoxCaretLineIndex(pCode);
	pCode->caretLine += newLineCount;
	CodeBoxFocusLine(pCode, pCode->caretLine);
} 

static void textInsertChar(CodeBox* pCode, char c) {
	memmove(pCode->buffer + pCode->caretIndex + 1, pCode->buffer + pCode->caretIndex, pCode->bufferCount - pCode->caretIndex - 1);
	pCode->buffer[pCode->caretIndex] = c;
	pCode->bufferCount++;
	pCode->caretIndex++;
	pCode->caretLineIndex++;
	pCode->dirty = true;
}

static void CommandScanFinish(CodeBox* pCode, Command* pCommand) {
	CodeBoxUpdateCaret(pCode, pCode->caretIndex + pCommand->scanFoundIndex);
	CodeBoxFocusLine(pCode, pCode->caretLine);

	pCommand->scanFoundIndex  = 0;
	pCommand->enabled         = false;
	pCommand->firstKeyPressed = false;
	pCommand->bufferCount     = 0;
	pCommand->toggled         = false;
}

static CodeBox text;

#define MASK_ASCII    0b00000000000000000000000111111111 
#define KEY_SHIFT_MOD 0b10000000000000000000000000000000
#define KEY_ALT_MOD   0b01000000000000000000000000000000
#define KEY_CTRL_MOD  0b00100000000000000000000000000000

int main(void)
{
	/* Config */
	SetTraceLogLevel(LOG_ALL);
	SetConfigFlags(FLAG_VSYNC_HINT);
	EnableEventWaiting();

	const int screenWidth = 1600;
	const int screenHeight = 1200;

	InitWindow(screenWidth, screenHeight, "rayDE");
	   
	/* Font */
	int codepointCount = 0;
	int *codepoints = LoadCodepoints(availableChars, &codepointCount);
	Font font = LoadFontEx("resources/JetBrainsMono-Regular.ttf", fontSize, codepoints, codepointCount);
	SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);
	SetTextLineSpacing(0); 

	/* File */
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

	/* State */
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
	} input = {};

	Command command = {};

	bool mouseOnText = false;
	int framesCounter = 0;
	int currentKey = 0;
	int priorKey = 0;

	Rectangle textBox = { 5, 20, screenWidth - 10, screenHeight - 25 };
	CodeBox* pCode = &text;

	/*
	 * Main Loop
	 */
	LoopBegin:

	framesCounter++;

	xCharCapacity = (textBox.width / fontXSpacing) - 1;
	yCharCapacity = (textBox.height / fontYSpacing) - 1;
	
	/* Input Read */
	{
		SetMouseCursor(mouseOnText ? MOUSE_CURSOR_IBEAM : MOUSE_CURSOR_DEFAULT);

		input.scrollMouse = GetMouseWheelMove();

		input.lMouse = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

		input.lShift = IsKeyDown(KEY_LEFT_SHIFT);
		input.lAlt   = IsKeyDown(KEY_LEFT_ALT);
		input.lCtrl  = IsKeyDown(KEY_LEFT_CONTROL) | IsKeyDown(KEY_LEFT_SUPER);

		input.rShift = IsKeyDown(KEY_RIGHT_SHIFT);
		input.rAlt   = IsKeyDown(KEY_RIGHT_ALT);
		input.rCtrl  = IsKeyDown(KEY_RIGHT_CONTROL) | IsKeyDown(KEY_RIGHT_SUPER);

		input.modifierCombination = 
			(input.lShift ? KEY_SHIFT_MOD : 0) |
			(input.lAlt   ? KEY_ALT_MOD   : 0) |
			(input.lCtrl  ? KEY_CTRL_MOD  : 0) |

			(input.rShift ? KEY_SHIFT_MOD : 0) |
			(input.rAlt   ? KEY_ALT_MOD   : 0) |
			(input.rCtrl  ? KEY_CTRL_MOD  : 0);
					
		currentKey = GetKeyPressed();
		if (currentKey == 0 && IsKeyPressedRepeat(priorKey))
			currentKey = priorKey;
	}

	/* Command Finish */
	if (command.enabled) {

		// Released!
		if (currentKey == 0 && input.modifierCombination == 0) {

			// Toggle Command On!
			if (!command.toggled && !command.firstKeyPressed) {
				LOG("Command Toggle On\n");
				command.toggled = true;
			}

			// Scanned? Jump to immediately.
			if (command.scanFoundIndex > 0 && !command.toggled) {
				CommandScanFinish(pCode, &command);
				LOG("Command Quick Scan Finish\n");
			} 

		} 

	}

	if (command.toggled) {

		// LOG("Command Toggled\n");
		input.lAlt = true;
		input.modifierCombination = 
			(input.lShift ? KEY_SHIFT_MOD : 0) |
			(input.lAlt   ? KEY_ALT_MOD   : 0) |
			(input.lCtrl  ? KEY_CTRL_MOD  : 0) |

			(input.rShift ? KEY_SHIFT_MOD : 0) |
			(input.rAlt   ? KEY_ALT_MOD   : 0) |
			(input.rCtrl  ? KEY_CTRL_MOD  : 0);

	}

	/*
	 * Input Process
	 */

	// TODO pull this into struct function to be used solely for text input
	const char* pBuf = pCode->buffer;
	const int iCrt   = pCode->caretIndex;
	while (currentKey > 0)
	{
		int modifiedKey = currentKey;
		switch (currentKey | input.modifierCombination) {

			/* Move Left Keys */
			case KEY_LEFT: 
			case KEY_J | KEY_CTRL_MOD:
				if (pCode->caretIndex <= 0) break;

				pCode->caretIndex--;
				pCode->caretLineIndex = CodeBoxCaretLineIndex(pCode);
				if (pCode->buffer[pCode->caretIndex] == '\n') {
					pCode->caretLine--;
					CodeBoxFocusLine(pCode, pCode->caretLine);
				}

				break;

			case KEY_LEFT | KEY_SHIFT_MOD:
			case KEY_J    | KEY_CTRL_MOD | KEY_SHIFT_MOD: {
				if (iCrt <= 0) break;

				int newIndex = CARET_INVALID;
				switch(pBuf[iCrt - 1]){
					case ' ':  newIndex = TextNegateFindCharBackward(pBuf, iCrt - 1, ' ');  break;
					case '\n': newIndex = TextNegateFindCharBackward(pBuf, iCrt - 1, '\n'); break;
					default:   newIndex = TextFindCharsBackward(pBuf, iCrt - 1, " \n");     break;
				}

				if (newIndex != CARET_INVALID) {
					CodeBoxUpdateCaret(pCode, newIndex + 1);
					CodeBoxFocusCaret(pCode);
				}

				break;
			}

			/* Move Right Keys */
			case KEY_RIGHT: 
			case KEY_L | KEY_CTRL_MOD:
				if (pCode->caretIndex >= pCode->bufferCount - endCharLength) 
					break;

				pCode->caretIndex++;		
				pCode->caretLineIndex = CodeBoxCaretLineIndex(pCode);
				if (pCode->buffer[pCode->caretIndex] == '\n') {
					pCode->caretLine++;
					CodeBoxFocusLine(pCode, pCode->caretLine);
				}

				break;

			case KEY_RIGHT | KEY_SHIFT_MOD:
			case KEY_L     | KEY_CTRL_MOD | KEY_SHIFT_MOD: {
				if (pBuf[iCrt] == '\0') break;

				int newIndex = CARET_INVALID;
				switch(pBuf[iCrt]){
					case ' ':  newIndex = TextNegateFindCharForward(pBuf, iCrt, ' ');  break;
					case '\n': newIndex = TextNegateFindCharForward(pBuf, iCrt, '\n'); break;
					default:   newIndex = TextFindCharsForward(pBuf, iCrt, " \n");     break;
				}

				if (newIndex != CARET_INVALID) {
					CodeBoxUpdateCaret(pCode, newIndex);
					CodeBoxFocusCaret(pCode);
				}

				break;
			}

			/* Move Up Keys */
			case KEY_UP: 
			case KEY_I | KEY_CTRL_MOD:{
				int upLineEnd     = TextFindCharBackward(pCode->buffer, pCode->caretIndex - endCharLength, '\n');     	   
				int upLineStart   = TextFindCharBackward(pCode->buffer, upLineEnd - endCharLength, '\n') + endCharLength;
				int upLineLength  = upLineEnd - upLineStart;
				if (upLineStart < 0) break;
				pCode->caretIndex = upLineStart + (pCode->caretLineIndex < upLineLength ? text.caretLineIndex : upLineLength);
				pCode->caretLine--;
				CodeBoxFocusLine(pCode, pCode->caretLine);
				break;
			}

			case KEY_UP | KEY_SHIFT_MOD:
			case KEY_I  | KEY_CTRL_MOD | KEY_SHIFT_MOD: {
				int startIndex      = pCode->buffer[pCode->caretIndex] == '\n' ? pCode->caretIndex - endCharLength : pCode->caretIndex;
				int blockStartIndex = TextFindTextBackward(pCode->buffer, startIndex, "\n\n");
				int blockEndIndex   = TextNegateFindCharBackward(pCode->buffer, blockStartIndex, '\n');  
				pCode->caretIndex   = blockEndIndex + 1;
				CodeBoxFocusIndex(pCode, pCode->caretIndex);
				break;
			}

			/* Move Down Keys */
			case KEY_DOWN: 
			case KEY_K | KEY_CTRL_MOD: {
				int currentLineEnd = TextFindCharForward(pCode->buffer, pCode->caretIndex, '\n');
				int downLineStart  = currentLineEnd + endCharLength;
				int downLineEnd    = TextFindCharForward(pCode->buffer, downLineStart, '\n');
				if (downLineStart >= pCode->bufferCount - endCharLength) break;
				int downLineDiff  = downLineEnd - downLineStart;
				pCode->caretIndex = downLineStart + (pCode->caretLineIndex < downLineDiff ? pCode->caretLineIndex : downLineDiff);
				pCode->caretLine++;
				CodeBoxFocusLine(pCode, pCode->caretLine);
				break;
			}

			case KEY_DOWN | KEY_SHIFT_MOD:
			case KEY_K    | KEY_CTRL_MOD | KEY_SHIFT_MOD: {
				int blockEndIndex   = TextFindTextForward(pCode->buffer, pCode->caretIndex, "\n\n");
				int blockStartIndex = TextNegateFindCharForward(pCode->buffer, blockEndIndex, '\n');
				pCode->caretIndex   = blockStartIndex;
				CodeBoxFocusIndex(pCode, pCode->caretIndex);
				break;
			}

			/* Command Keys */
			case KEY_ALT_MOD | KEY_RIGHT_ALT: 
			case KEY_ALT_MOD | KEY_LEFT_ALT: 
				if (!command.enabled) {
					LOG("Command Begin\n");
					command.enabled = true;

					if (command.bufferCount > 0) 
						command.scanFoundIndex = TextFindIndex(pCode->buffer + pCode->caretIndex + 1, command.buffer) + 1;

					break;
				} 

				if (command.enabled && command.toggled ) {
					LOG("Command Toggle Off\n");
					command.enabled = false;
					command.toggled = false;
					break;
				}

				break;

			case KEY_ALT_MOD | KEY_CTRL_MOD | KEY_LEFT_CONTROL: 
				break;

			case KEY_ALT_MOD | KEY_ENTER: 
				if (!command.enabled)
					break;

				LOG("Command Finish\n");

				if (command.scanFoundIndex > 0) {
					CommandScanFinish(pCode, &command);
					LOG("Command Scan Finish\n");
				}


				break;

			case KEY_ALT_MOD | KEY_TAB: 
				if (!command.enabled)
					break;

				LOG("%d %d\n", pCode->caretIndex, command.scanFoundIndex);

				if (command.bufferCount > 0) {
					command.scanFoundIndex = TextFindIndex(pCode->buffer + pCode->caretIndex + command.scanFoundIndex + 1, command.buffer) + command.scanFoundIndex + 1;
				}

				if (command.scanFoundIndex > 0) {
					int scanFoundLine = TextCountCharForward(pCode->buffer, pCode->caretIndex, command.scanFoundIndex, '\n') + pCode->caretLine;
					CodeBoxFocusLine(pCode, scanFoundLine);
					LOG("%d \n", scanFoundLine);
				}

				break;

			case '`'  | KEY_ALT_MOD: 
			case '-'  | KEY_ALT_MOD: 
			case '='  | KEY_ALT_MOD: 
			case '['  | KEY_ALT_MOD: 
			case ']'  | KEY_ALT_MOD: 
			case '\\' | KEY_ALT_MOD:
			case ';'  | KEY_ALT_MOD: 
			case '\'' | KEY_ALT_MOD:
			case ','  | KEY_ALT_MOD: 
			case '.'  | KEY_ALT_MOD: 
			case '/'  | KEY_ALT_MOD: 

			case (KEY_ALT_MOD | '0') ... (KEY_ALT_MOD | '9'): 
				textScanCharRight(pCode, currentKey, TEXT_CARET_LEFT, TEXT_SCAN_MATCH_SKIP_IMMEDIATE);
				break;

			case '1'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '!'; goto UpdateCommandKey;
			case '2'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '@'; goto UpdateCommandKey;
			case '3'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '#'; goto UpdateCommandKey;
			case '4'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '$'; goto UpdateCommandKey;
			case '5'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '%'; goto UpdateCommandKey;
			case '6'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '^'; goto UpdateCommandKey;
			case '7'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '&'; goto UpdateCommandKey;
			case '8'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '*'; goto UpdateCommandKey;
			case '9'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '('; goto UpdateCommandKey;
			case '0'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = ')'; goto UpdateCommandKey;
			case '`'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '~'; goto UpdateCommandKey;
			case '-'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '_'; goto UpdateCommandKey;
			case '='  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '+'; goto UpdateCommandKey;
			case '['  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '{'; goto UpdateCommandKey;
			case ']'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '}'; goto UpdateCommandKey;
			case '\\' | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '|'; goto UpdateCommandKey;
			case ';'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = ':'; goto UpdateCommandKey;
			case '\'' | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '"'; goto UpdateCommandKey;
			case ','  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '<'; goto UpdateCommandKey;
			case '.'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '>'; goto UpdateCommandKey;
			case '/'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '?'; goto UpdateCommandKey;

			case (KEY_ALT_MOD | 'A') ... (KEY_ALT_MOD | 'Z'): 
				modifiedKey = TO_LOWER_C(currentKey);
				goto UpdateCommandKey;

			case (KEY_ALT_MOD | KEY_SHIFT_MOD | 'A') ... (KEY_ALT_MOD | KEY_SHIFT_MOD | 'Z'): 
				goto UpdateCommandKey;

			case KEY_ALT_MOD | KEY_BACKSPACE:
			case KEY_ALT_MOD | KEY_SHIFT_MOD | KEY_BACKSPACE:
				command.firstKeyPressed = true; 
				if (command.bufferCount > 0) command.bufferCount--;
				goto UpdateCommandScan;

			case KEY_ALT_MOD | KEY_CTRL_MOD | KEY_BACKSPACE:
			case KEY_ALT_MOD | KEY_CTRL_MOD | KEY_SHIFT_MOD | KEY_BACKSPACE:
			case KEY_ALT_MOD | KEY_DELETE:
				command.firstKeyPressed = true;
				command.bufferCount = 0;
				command.scanFoundIndex = 0;
				command.buffer[command.bufferCount] = '\0';
				break;

			UpdateCommandKey:
				if (!command.firstKeyPressed) {     
					command.firstKeyPressed = true; 
					command.bufferCount = 0;        
					command.scanFoundIndex = 0;     
				} 
				command.buffer[command.bufferCount++] = modifiedKey;

			UpdateCommandScan:
				command.buffer[command.bufferCount] = '\0';
				command.scanFoundIndex = TextFindIndex(pCode->buffer + pCode->caretIndex + 1, command.buffer) + 1;
				break;

			/* Utility Keys */
			case KEY_CTRL_MOD | KEY_S:
				LOG("Saving: %s", text.path);
				SaveFileText(text.path, text.buffer);
				break;

			/* Character Delete Keys */
			case KEY_BACKSPACE: if (text.bufferCount > 0) {
					if (text.buffer[text.caretIndex - 1] == '\n') 
						text.newLineCount--;
					
					memmove(text.buffer + text.caretIndex - 1, text.buffer + text.caretIndex, text.bufferCount - text.caretIndex);
					text.bufferCount--;
					text.caretIndex--;
				}
				break;

			case KEY_DELETE: if (text.bufferCount > 0 && text.caretIndex < text.bufferCount - 1) {
					if (text.buffer[text.caretIndex] == '\n') 
						text.newLineCount--;
					
					text.bufferCount--;
					memmove(text.buffer + text.caretIndex, text.buffer + text.caretIndex + 1, text.bufferCount - text.caretIndex - 1);
				}
				break;

			/* Character Insert Keys */
			case KEY_ENTER: 
				textInsertChar(pCode, '\n'); 
				text.newLineCount++; 
				break;

			case KEY_SPACE:
				textInsertChar(pCode, ' '); 
				break;

			case KEY_TAB: 
				textInsertChar(pCode, '\t'); 
				break;

			case (KEY_SHIFT_MOD | 'A') ... (KEY_SHIFT_MOD | 'Z'): 
				textInsertChar(pCode, currentKey); 
				break;

			case 'A' ... 'Z': 
				textInsertChar(pCode, 'a' + (currentKey- KEY_A)); 
				break;

			case KEY_KP_0 ... KEY_KP_9: 
				textInsertChar(pCode, '0' + (currentKey- KEY_KP_0)); 
				break;

			case '0' ... '9': 
				textInsertChar(pCode, currentKey); 
				break;

			case '`':  textInsertChar(pCode, currentKey); break;
			case '-':  textInsertChar(pCode, currentKey); break;
			case '=':  textInsertChar(pCode, currentKey); break;
			case '[':  textInsertChar(pCode, currentKey); break;
			case ']':  textInsertChar(pCode, currentKey); break;
			case '\\': textInsertChar(pCode, currentKey); break;
			case ';':  textInsertChar(pCode, currentKey); break;
			case '\'': textInsertChar(pCode, currentKey); break;
			case ',':  textInsertChar(pCode, currentKey); break;
			case '.':  textInsertChar(pCode, currentKey); break;
			case '/':  textInsertChar(pCode, currentKey); break;

			case KEY_SHIFT_MOD | '1':  textInsertChar(pCode, '!'); break;
			case KEY_SHIFT_MOD | '2':  textInsertChar(pCode, '@'); break;
			case KEY_SHIFT_MOD | '3':  textInsertChar(pCode, '#'); break;
			case KEY_SHIFT_MOD | '4':  textInsertChar(pCode, '$'); break;
			case KEY_SHIFT_MOD | '5':  textInsertChar(pCode, '%'); break;
			case KEY_SHIFT_MOD | '6':  textInsertChar(pCode, '^'); break;
			case KEY_SHIFT_MOD | '7':  textInsertChar(pCode, '&'); break;
			case KEY_SHIFT_MOD | '8':  textInsertChar(pCode, '*'); break;
			case KEY_SHIFT_MOD | '9':  textInsertChar(pCode, '('); break;
			case KEY_SHIFT_MOD | '0':  textInsertChar(pCode, ')'); break;
			case KEY_SHIFT_MOD | '`':  textInsertChar(pCode, '~'); break;
			case KEY_SHIFT_MOD | '-':  textInsertChar(pCode, '_'); break;
			case KEY_SHIFT_MOD | '=':  textInsertChar(pCode, '+'); break;
			case KEY_SHIFT_MOD | '[':  textInsertChar(pCode, '{'); break;
			case KEY_SHIFT_MOD | ']':  textInsertChar(pCode, '}'); break;
			case KEY_SHIFT_MOD | '\\': textInsertChar(pCode, '|'); break;
			case KEY_SHIFT_MOD | ';':  textInsertChar(pCode, ':'); break;
			case KEY_SHIFT_MOD | '\'': textInsertChar(pCode, '"'); break;
			case KEY_SHIFT_MOD | ',':  textInsertChar(pCode, '<'); break;
			case KEY_SHIFT_MOD | '.':  textInsertChar(pCode, '>'); break;
			case KEY_SHIFT_MOD | '/':  textInsertChar(pCode, '?'); break;

			default: break;
		}
		
		priorKey = currentKey;
		currentKey = GetKeyPressed();
	}

	/*
	 * Render
	 */
	BeginDrawing();
	{
		float frameTime = GetFrameTime();
		Vector2 mousePosition = GetMousePosition();
		Vector2 caretPosition;
		Vector2 scanFoundPosition;
		int index = pCode->focusStartLineIndex;

		ClearBackground(RAYWHITE);

		DrawText(TextFormat("frameTime: %f/", frameTime), 512, 0, 20, GRAY);
		DrawText(TextFormat("INPUT CHARS: %i %i", text.bufferCount, text.caretIndex), 0, 0, 20, DARKGRAY);

		/* 
		 * Text Panel
		 */
		DrawRectangleRec(textBox, COLOR_TEXT_BOX);
		DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

		for (int y = 0; y < yCharCapacity; ++y) {
			int tabCount = 0;
			for (int x = 0; x < xCharCapacity - (tabCount * tabWidth); ++x) {
				Vector2 position = {
					textBox.x + (fontXSpacing * x) + (tabCount * fontXSpacing * 4), 
					textBox.y + (fontYSpacing * y)
				};										
				Rectangle rect = {position.x, position.y, fontXSpacing, fontYSpacing};

				if (index == text.caretIndex)
					caretPosition = position;

				if (index == text.caretIndex + command.scanFoundIndex)
					scanFoundPosition = position;
				
				if (input.lMouse && CheckCollisionPointRec(mousePosition, rect)) {
					float xDiff = mousePosition.x - (rect.x + (rect.width / 2));
					text.caretIndex = xDiff > 0 ? index + 1 : index;
					text.caretLineIndex = CodeBoxCaretLineIndex(&text);
				}

				char c = text.buffer[index];
				Color color = DARKGRAY;
				switch (text.buffer[index]) {
					case '\0':
						goto FinishDrawingText;

					case '\n':
						// Check click on entire line
						rect.width = textBox.width - rect.width;
						if (input.lMouse && CheckCollisionPointRec(mousePosition, rect)){
							text.caretIndex = index;
							text.caretLineIndex = CodeBoxCaretLineIndex(&text);
						}

						x = xCharCapacity;
						c =  '|';
						color = LIGHTGRAY;
						goto DrawChar;

					case '\t':
						// Step more spaces for tab width
						rect.width += (tabCount * fontXSpacing * tabWidth);
						tabCount++;
						c = '-';
						color = LIGHTGRAY;
						goto DrawChar;

					case ' ':
						c =  '_';
						color = LIGHTGRAY;
						goto DrawChar;

					default:
					DrawChar: {
						int codePointSize;
						int codePoint = GetCodepoint(&c, &codePointSize);
						DrawTextCodepoint(font, codePoint, position, fontSize, color);
						index++;
						break;
					}
				}								
			}
		}      
		FinishDrawingText:

		/*
		 * Command Caret
		 */
		DrawLineEx(
			(Vector2){caretPosition.x, caretPosition.y}, 
			(Vector2){caretPosition.x, caretPosition.y + fontYSpacing}, 
			4, ORANGE);

		/* Scan Highlight */
		if (command.enabled && command.scanFoundIndex > 0) {
			DrawRectangleRec((Rectangle){
					.x = scanFoundPosition.x, 
					.y = scanFoundPosition.y, 
					.width = fontXSpacing * command.bufferCount, 
					.height = fontYSpacing}, 
				FIND_HIGHLIGHT_COLOR);
			DrawLineEx(
				(Vector2){scanFoundPosition.x, scanFoundPosition.y}, 
				(Vector2){scanFoundPosition.x, scanFoundPosition.y + fontYSpacing}, 
				4, FIND_CARET_COLOR);
		}

		/* Command Box */
		if (command.enabled) {
			const int commandBoxExpand = 4;
			Rectangle commandBoxRect = {
				.x = caretPosition.x - commandBoxExpand,
				.y = caretPosition.y - commandBoxExpand,
				.width = fontXSpacing * command.bufferCount + commandBoxExpand * 2, 
				.height = fontYSpacing + commandBoxExpand * 2,
			};

			DrawRectangleRec(commandBoxRect, COLOR_COMMAND_BOX);
			DrawRectangleLinesEx(commandBoxRect, 2, WHITE);

			for (int index = 0; index < command.bufferCount; ++index) {
				char c = command.buffer[index];
				int codePointSize;
				int codePoint = GetCodepoint(&c, &codePointSize);
				Vector2 position = { caretPosition.x + (fontXSpacing * index), caretPosition.y };								
				DrawTextCodepoint(font, codePoint, position, fontSize, WHITE);
			}
		}
	}
	EndDrawing();

	if(!WindowShouldClose()) 
		goto LoopBegin;

	/*
	 * Clearnup
	 */
	CloseWindow();

	return 0;
}




