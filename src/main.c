/*
	rayDE - Raylib Development Enviornment

+---------------------------+------------------------------------------------+
| Shortcut                  | Action                                         |
+---------------------------+------------------------------------------------+
| FILE OPERATIONS                                                            |
+---------------------------+------------------------------------------------+
| Ctrl+N                    | New file                                       |
| Ctrl+O                    | Open file                                      |
| Ctrl+S                    | Save                                           |
| Ctrl+Shift+S              | Save As                                        |
| Ctrl+W                    | Close current tab/file                         |
+---------------------------+------------------------------------------------+
| BASIC EDITING                                                              |
+---------------------------+------------------------------------------------+
| Ctrl+Z                    | Undo                                           |
| Ctrl+Y (or Ctrl+Shift+Z)  | Redo                                           |
| Ctrl+A                    | Select all                                     |
| Ctrl+L                    | Select entire current line                     |
| Ctrl+Shift+K              | Delete entire line                             |
| Ctrl+R                    | Delete character                               |
| Ctrl+Shift+R              | Delete line                                    |
| Ctrl+D                    | Duplicate line below                           |
| Ctrl+Shift+D              | Duplicate line above                           |
| Ctrl+Enter                | Insert line below without moving cursor        |
| Ctrl+Shift+Enter          | Insert line above                              |
| Tab                       | Indent                                         |
| Shift+Tab                 | Unindent                                       |
| Ctrl+/                    | Toggle line comment                            |
+---------------------------+------------------------------------------------+
| NAVIGATION                                                                 |
+---------------------------+------------------------------------------------+
| Home                      | Go to beginning of line                        |
| End                       | Go to end of line                              |
| Ctrl+Home                 | Go to beginning of document                    |
| Ctrl+End                  | Go to end of document                          |
| Ctrl+Left/Right           | Word jump                                      |
| Ctrl+Up/Down              | Block jump                                     |
| Ctrl+G                    | Go to line number                              |
| Ctrl+M                    | Go to matching bracket                         |
| Alt+I/J/K/L               | Arrow alternatives (Up/Left/Down/Right)        |
+---------------------------+------------------------------------------------+
| SELECTION                                                                  |
+---------------------------+------------------------------------------------+
| Shift+Left/Right          | Select character                               |
| Shift+Up/Down             | Select line up/down                            |
| Shift+Home                | Select to beginning of line                    |
| Shift+End                 | Select to end of line                          |
| Ctrl+Shift+Left/Right     | Select word jump                               |
| Ctrl+Shift+Up/Down        | Block select / Multi-cursor                    |
| Ctrl+Shift+Mouse Drag     | Block select                                   |
| Mouse Double Click        | Select word                                    |
| Mouse Triple Click        | Select line                                    |
+---------------------------+------------------------------------------------+
| MULTI-CURSOR & FIND/REPLACE                                                |
+---------------------------+------------------------------------------------+
| Ctrl+Shift+N              | Select next occurrence (multi-cursor)          |
| Ctrl+Shift+B              | Select previous occurrence                     |
// I thik this should be command?
// I need command drawer you can click on
| Ctrl+F                    | Find                                           |
| Ctrl+H                    | Find and replace                               |
| F3                        | Find next                                      |
| Shift+F3                  | Find previous                                  |
+---------------------------+------------------------------------------------+
| MOVEMENT                                                                   |
+---------------------------+------------------------------------------------+
| Ctrl+E                    | Expand selection (to word, to scope)           |
| Ctrl+Shift+E              | Shrink selection                               |
| Alt+Shift+Up/Down         | Move line up/down                              |
| Alt+Shift+Left/Right      | Move selection left/right                      |
+---------------------------+------------------------------------------------+
| CODE ASSISTANCE                                                            |
+---------------------------+------------------------------------------------+
| Ctrl+Space                | Autocomplete menu                              |
| Ctrl+Shift+Space          | Parameter info                                 |
+---------------------------+------------------------------------------------+
| TEXT WRAPPING                                                              |
+---------------------------+------------------------------------------------+
| Ctrl+Shift+{              | Wrap with braces                               |
| Ctrl+[                    | Wrap with brackets                             |
| Ctrl+Shift+(              | Wrap with parentheses                          |
| Ctrl+'                    | Wrap with single quotes                        |
| Ctrl+Shift+"              | Wrap with double quotes                        |
| Ctrl+`                    | Wrap with backticks                            |
+---------------------------+------------------------------------------------+
| WORD OPERATIONS                                                            |
+---------------------------+------------------------------------------------+
| Ctrl+Backspace            | Delete word backwards                          |
| Ctrl+Delete               | Delete word forwards                           |
+---------------------------+------------------------------------------------+

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "raylib.h"
#include "raymath.h"

#define PANIC(_message) assert(false && _message);

#define STATIC_ASSERT(...) _Static_assert(__VA_ARGS__)
#define XMALLOC_ALIGNED(_align, _size) ({ \
	void* p = _aligned_malloc(_size, _align); \
	if (p == NULL) PANIC("XMALLOC_ALIGNED Failed!"); \
	p; \
})


#define FIND_CARET_COLOR     (Color){   0, 255,   0, 255 }
#define FIND_HIGHLIGHT_COLOR (Color){   0, 255,   0, 64  }
#define COLOR_COMMAND_BOX    (Color){  20,  20,   2, 200 }
#define COLOR_TEXT_BOX       (Color){  37,  37,  38, 255 }

#define COLOR_PREPROCESSOR (Color){ 198, 149, 198, 255 }
#define COLOR_NUMBER       (Color){ 249, 174,  87, 255 }
#define COLOR_STRING       (Color){ 153, 199, 148, 255 } 
#define COLOR_COMMENT      (Color){ 166, 172, 185, 255 }  
#define COLOR_MACRO_NAME   (Color){ 249, 174,  87, 255 }
#define COLOR_BACKGROUND   (Color){  48,  56,  65, 255 } 
#define COLOR_OPERATOR     (Color){ 249, 123,  87, 255 }
#define COLOR_TEXT         (Color){ 216, 222, 233, 255 }
#define COLOR_TEXT_HIDDEN  (Color){  53,  61,  70, 255 } 
#define COLOR_QUOTE        (Color){  96, 180, 180, 255 } 
#define COLOR_SCOPE        (Color){ 255, 255, 255, 255 } 
#define COLOR_KEYWORD      (Color){ 236,  96, 102, 255 }
#define COLOR_TYPE         (Color){ 198, 149, 198, 255 }

static const char* TOKEN_DELIMITERS = " \t\n\r\v\f!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~";
static const char* TOKEN_OPERATORS = "!%&*+-/:<=>?^|~";
static const char* TOKEN_QUOTES = "\"'`";
static const char* TOKEN_SCOPES = "(){}[]";

#define TOKEN_TYPES_COLOR (Color){ 156, 220, 254, 255 }
static const char* TOKEN_TYPES[] = {
    "unsigned",  
    "uint64_t",  
    "ptrdiff_t", 
    "uint32_t",  
    "uint16_t",  
    "wchar_t",   
    "struct",    
    "signed",    
    "size_t",    
    "int64_t",   
    "int32_t",   
    "int16_t",   
    "double",    
    "uint8_t",   
    "float",     
    "short",     
    "int8_t",    
    "_Bool",     
    "union",     
    "void",      
    "long",      
    "char",      
    "enum",      
    "int",       
    NULL  
};

static const char* TOKEN_KEYWORDS[] = {
    "_Static_assert",
    "_Noreturn",
    "_Generic",
    "continue",
    "volatile",
    "register",
    "restrict",
    "_Alignof",
    "_Alignas",
    "typedef",
    "default",
    "_Atomic",
    "typeof",
    "switch",
    "static",
    "sizeof",
    "return",
    "inline",
    "extern",
    "while",
    "const",
    "break",
    "goto",
    "else",
    "case",
    "auto",
    "for",
    "if",
    "do",
    NULL
};

#if defined(__AVX512F__)
    #define VECTOR_SIZE 64
#elif defined(__AVX2__) || defined(__AVX__)
    #define VECTOR_SIZE 32  
#elif defined(__SSE2__) || defined(__ARM_NEON)
    #define VECTOR_SIZE 16
#else
    #define VECTOR_SIZE 8
#endif

typedef char vstr __attribute__ ((vector_size (VECTOR_SIZE)));
STATIC_ASSERT(VECTOR_SIZE == 32);
STATIC_ASSERT(sizeof(vstr) == 32);

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

#define ASSERT(_condition, ...) assert((_condition) && __VA_ARGS__)
#define COUNT(_array) (sizeof(_array) / sizeof(_array[0]))
#define MAX_INPUT_CHARS      2048
#define TEXT_BUFFER_CAPACITY 64000

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
	int focusStartRowIndex;
	int focusStartRow;

	bool  caretEnabled[CARET_COUNT];
	Caret caret[CARET_COUNT];

	// Index in entire buffer.
	int caretIndex;
	// Index of line. CaretRow?
	int caretRow;
	// Index of caret on current line. CaretCollumn?
	int caretCollumn;

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
		int i = 0; while (text[index + i] == find[i]) 
			if (find[++i] == '\0') return index;
		index--;
	}
	return index;
}

// Find specified substring. Will return end null terminator index if it doesn't find.
static int TextFindTextForward(const char* text, int index, const char* find) {
	const char* s = text;
	int foundIndex = index;
	while (s[foundIndex] != '\0') {
		int i = 0; while (s[foundIndex + i] == find[i]) 
			if (find[++i] == '\0') return foundIndex;
		foundIndex++;
	}
	return index;
}

static int TextFindTextsForward(const char* text, int index, const char** finds) {
	while (text[index] != '\0') {
		int f = 0; while (finds[f] != NULL) {
			const char* find = finds[f++];
			int i = 0; while (text[index + i] == find[i])
				if (find[++i] == '\0') return index;
		}
		index++;
	}
	return -1;
}

// Test if Text exactly equals given text. 0 if false. strlen of equals if true.
static int TextEqualsText(const char* text, const char* equals) {
	assert(equals[0] != '\0');
	int index = 0;
	while (text[index] == equals[index] && text[index] != '\0')
		if (equals[++index] == '\0') return index;
	return 0;
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
	for (; index < range; ++index) {
		if (text[index] == find) count++;
		if (text[index] == '\0') break;
	}
	return count;
}

// Find char index and also count occurense of another char during scan.
static bool TextFindCountCharForward(const char* pBuffer, char searchChar, char countChar, int* pFoundIndex, int *pCount) {
	int index = *pFoundIndex, count = *pCount; 
	char c;	do {
		c = pBuffer[index++];
		count += c == countChar;
	} while (c && c != searchChar);
	*pFoundIndex = index - 1; *pCount = count;
	return c == searchChar;
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

// The index of char on current line
static inline int CodeBoxIndexCollumn(const CodeBox* pCode, int index) {
	int lineStartIndex = TextFindCharBackward(pCode->buffer, index - 1, '\n') + endCharLength;
	LOG("%d %d\n", lineStartIndex, index);
	return index - lineStartIndex;
}

// The index of caret on current line.
static inline int CodeBoxCaretCollumn(const CodeBox* pCode) {
	return CodeBoxIndexCollumn(pCode, pCode->caretIndex);
}

// Line given index is on
static inline int CodeBoxIndexRow(const CodeBox* pCode, int index) {
	return TextCountCharForward(pCode->buffer, 0, index, '\n');
}

// Line the caret is on.
static inline int CodeBoxCaretRow(const CodeBox* pCode) {
	return CodeBoxIndexRow(pCode, pCode->caretIndex);
}

// Focus on a given row.
static void CodeBoxFocusRow(CodeBox* pCode, int toRow) {
	int charCapacity = (int)yCharCapacity;

	int yMin = pCode->focusStartRow;
	if (toRow < yMin) {
		pCode->focusStartRow = toRow;
		pCode->focusStartRowIndex = TextFindCharSkipForward(pCode->buffer, '\n', pCode->focusStartRow);
	}

	int yMax = yMin + charCapacity;
	if (toRow > yMax) {
		pCode->focusStartRow = toRow - charCapacity;
		pCode->focusStartRowIndex = TextFindCharSkipForward(pCode->buffer, '\n', pCode->focusStartRow);
	}
} 

static void CodeBoxIncrementFocusRow(CodeBox* pCode, int increment) {
	pCode->focusStartRow -= increment;
	pCode->focusStartRowIndex = TextFindCharSkipForward(pCode->buffer, '\n', pCode->focusStartRow);
}

// Focus on a given character index.
static inline void CodeBoxFocusIndex(CodeBox* pCode, int toIndex) {
	int toRow = CodeBoxIndexRow(pCode, toIndex);
	CodeBoxFocusRow(pCode, toRow);
}

static inline void CodeBoxFocusCaret(CodeBox* pCode) {
	CodeBoxFocusRow(pCode, pCode->caretRow);
}

// Update all caret state for index.
static void CodeBoxUpdateCaretIndex(CodeBox* pCode, int newCaretIndex) {
	pCode->caretIndex   = newCaretIndex;
	pCode->caretRow     = CodeBoxCaretRow(pCode);
	pCode->caretCollumn = CodeBoxCaretCollumn(pCode);
	assert(pCode->caretIndex >= 0);
	assert(pCode->caretIndex <= pCode->bufferCount);
	assert(pCode->caretRow   >= 0);
	assert(pCode->caretRow   <= pCode->newLineCount);
	assert(pCode->caretCollumn >= 0);
}

static void CodeBoxUpdateCaretIndexLine(CodeBox* pCode, int newCaretIndex, int newCaretLine) {
	pCode->caretIndex   = newCaretIndex;
	pCode->caretRow     = newCaretLine;
	pCode->caretCollumn = CodeBoxCaretCollumn(pCode);
	assert(newCaretLine == CodeBoxCaretRow(pCode));
	assert(pCode->caretIndex >= 0);
	assert(pCode->caretIndex <= pCode->bufferCount);
	assert(pCode->caretRow   >= 0);
	assert(pCode->caretRow   <= pCode->newLineCount);
	assert(pCode->caretCollumn >= 0);
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

static void textInsertChar(CodeBox* pCode, char c) {
	memmove(pCode->buffer + pCode->caretIndex + 1, pCode->buffer + pCode->caretIndex, pCode->bufferCount - pCode->caretIndex - 1);
	pCode->buffer[pCode->caretIndex] = c;
	pCode->bufferCount++;
	pCode->caretIndex++;
	pCode->caretCollumn++;
	pCode->dirty = true;
}

static void CommandFinish(CodeBox* pCode, Command* pCommand) {
	CodeBoxUpdateCaretIndex(pCode, pCommand->scanFoundIndex);
	CodeBoxFocusRow(pCode, pCode->caretRow);

	pCommand->scanFoundIndex  = 0;
	pCommand->bufferCount     = 0;
	pCommand->enabled         = false;
	pCommand->toggled         = false;
	pCommand->firstKeyPressed = false;
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

		text.buffer = XMALLOC_ALIGNED(VECTOR_SIZE, TEXT_BUFFER_CAPACITY * sizeof(char));
		memset(text.buffer, 0, TEXT_BUFFER_CAPACITY * sizeof(char));
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
	CodeBox*  pCode   = &text;

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

		CodeBoxIncrementFocusRow(pCode, input.scrollMouse);
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
				CommandFinish(pCode, &command);
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
			case KEY_A | KEY_ALT_MOD:
				if (pCode->caretIndex <= 0) break;

				pCode->caretIndex--;
				pCode->caretCollumn = CodeBoxCaretCollumn(pCode);
				if (pCode->buffer[pCode->caretIndex] == '\n') {
					pCode->caretRow--;
					CodeBoxFocusCaret(pCode);
				}

				break;

			case KEY_LEFT | KEY_CTRL_MOD:
			case KEY_A    | KEY_CTRL_MOD | KEY_ALT_MOD: {
				if (iCrt <= 0) break;

				int newIndex = CARET_INVALID;
				switch(pBuf[iCrt - 1]){
					case ' ':  newIndex = TextNegateFindCharBackward(pBuf, iCrt - 1, ' ');  break;
					case '\n': newIndex = TextNegateFindCharBackward(pBuf, iCrt - 1, '\n'); break;
					default:   newIndex = TextFindCharsBackward(pBuf, iCrt - 1, " \n");     break;
				}

				if (newIndex != CARET_INVALID) {
					CodeBoxUpdateCaretIndex(pCode, newIndex + 1);
					CodeBoxFocusCaret(pCode);
				}

				break;
			}

			/* Move Right Keys */
			case KEY_RIGHT: 
			case KEY_D | KEY_ALT_MOD:
				if (pCode->caretIndex >= pCode->bufferCount - endCharLength) 
					break;

				pCode->caretIndex++;		
				pCode->caretCollumn = CodeBoxCaretCollumn(pCode);
				if (pCode->buffer[pCode->caretIndex] == '\n') {
					pCode->caretRow++;
					CodeBoxFocusCaret(pCode);
				}

				break;

			case KEY_RIGHT | KEY_CTRL_MOD:
			case KEY_D     | KEY_CTRL_MOD | KEY_ALT_MOD: {
				if (pBuf[iCrt] == '\0') break;

				int newIndex = CARET_INVALID;
				switch(pBuf[iCrt]){
					case ' ':  newIndex = TextNegateFindCharForward(pBuf, iCrt, ' ');  break;
					case '\n': newIndex = TextNegateFindCharForward(pBuf, iCrt, '\n'); break;
					default:   newIndex = TextFindCharsForward(pBuf, iCrt, " \n");     break;
				}

				if (newIndex != CARET_INVALID) {
					CodeBoxUpdateCaretIndex(pCode, newIndex);
					CodeBoxFocusCaret(pCode);
				}

				break;
			}

			/* Move Up Keys */
			case KEY_UP: 
			case KEY_W | KEY_ALT_MOD:{
				int upLineEnd     = TextFindCharBackward(pCode->buffer, pCode->caretIndex - 1, '\n');     	   
				int upLineStart   = TextFindCharBackward(pCode->buffer, upLineEnd - 1, '\n') + endCharLength;
				int upLineLength  = upLineEnd - upLineStart;
				LOG("%d %d\n", upLineEnd, upLineStart);
				if (upLineStart < 0) break;
				pCode->caretIndex = upLineStart + (pCode->caretCollumn < upLineLength ? text.caretCollumn : upLineLength);
				pCode->caretRow--;
				CodeBoxFocusRow(pCode, pCode->caretRow);
				break;
			}

			case KEY_UP | KEY_CTRL_MOD:
			case KEY_W  | KEY_CTRL_MOD | KEY_ALT_MOD: {
				int startIndex      = pCode->buffer[pCode->caretIndex] == '\n' ? pCode->caretIndex - endCharLength : pCode->caretIndex;
				int blockStartIndex = TextFindTextBackward(pCode->buffer, startIndex, "\n\n");
				int blockEndIndex   = TextNegateFindCharBackward(pCode->buffer, blockStartIndex, '\n');  
				int newCaretIndex   = blockEndIndex + 1;
				CodeBoxUpdateCaretIndex(pCode, newCaretIndex);
				CodeBoxFocusCaret(pCode);
				break;
			}

			/* Move Down Keys */
			case KEY_DOWN: 
			case KEY_S | KEY_ALT_MOD: {
				int currentLineEnd = TextFindCharForward(pCode->buffer, pCode->caretIndex, '\n');
				int downLineStart  = currentLineEnd + endCharLength;
				int downLineEnd    = TextFindCharForward(pCode->buffer, downLineStart, '\n');
				if (downLineStart >= pCode->bufferCount - endCharLength) break;
				int downLineDiff  = downLineEnd - downLineStart;
				pCode->caretIndex = downLineStart + (pCode->caretCollumn < downLineDiff ? pCode->caretCollumn : downLineDiff);
				pCode->caretRow++;
				CodeBoxFocusCaret(pCode);
				break;
			}

			case KEY_DOWN | KEY_CTRL_MOD:
			case KEY_S    | KEY_CTRL_MOD | KEY_ALT_MOD: {
				// Search"\n\n" to find where there is a new line gap
				int blockEndIndex   = TextFindTextForward(pCode->buffer, pCode->caretIndex, "\n\n");
				int blockStartIndex = TextNegateFindCharForward(pCode->buffer, blockEndIndex, '\n');
				blockStartIndex = TextNegateFindCharForward(pCode->buffer, blockStartIndex, ' ');
				blockStartIndex = TextNegateFindCharForward(pCode->buffer, blockStartIndex, '\t');
				int newCaretIndex   = blockStartIndex;
				CodeBoxUpdateCaretIndex(pCode, newCaretIndex);
				CodeBoxFocusCaret(pCode);
				break;
			}

			/* Command Keys */
			// case KEY_ALT_MOD | KEY_RIGHT_ALT: 
			// case KEY_ALT_MOD | KEY_LEFT_ALT: 
			// 	if (!command.enabled) {
			// 		LOG("Command Begin\n");
			// 		command.enabled = true;
			// 		command.scanFoundIndex = pCode->caretIndex;
			// 		LOG("%d\n", command.scanFoundIndex);
			// 		break;
			// 	} 

			// 	if (command.enabled && command.toggled ) {
			// 		LOG("Command Toggle Off\n");
			// 		command.enabled = false;
			// 		command.toggled = false;
			// 		break;
			// 	}

			// 	break;

			// case KEY_ALT_MOD | KEY_CTRL_MOD | KEY_LEFT_CONTROL: 
			// 	break;

			// case KEY_ALT_MOD | KEY_ENTER: 
			// 	if (!command.enabled)
			// 		break;

			// 	LOG("Command Finish\n");
			// 	CommandFinish(pCode, &command);

			// 	break;

			// case KEY_ALT_MOD | KEY_SHIFT_MOD | KEY_TAB: 

			// 	break;

			// case KEY_ALT_MOD | KEY_TAB: 
			// 	if (!command.enabled)
			// 		break;

			// 	LOG("%d %d\n", pCode->caretIndex, command.scanFoundIndex);

			// 	command.scanFoundIndex = TextFindTextForward(pCode->buffer, command.scanFoundIndex + 1, command.buffer);
			// 	if (command.scanFoundIndex > 0) {
			// 		int scanFoundLine = TextCountCharForward(pCode->buffer, pCode->caretIndex, command.scanFoundIndex, '\n') + pCode->caretRow;
			// 		CodeBoxFocusRow(pCode, scanFoundLine);
			// 		LOG("%d \n", scanFoundLine);
			// 	}

			// 	break;

			// case '`'  | KEY_ALT_MOD: 
			// case '-'  | KEY_ALT_MOD: 
			// case '='  | KEY_ALT_MOD: 
			// case '['  | KEY_ALT_MOD: 
			// case ']'  | KEY_ALT_MOD: 
			// case '\\' | KEY_ALT_MOD:
			// case ';'  | KEY_ALT_MOD: 
			// case '\'' | KEY_ALT_MOD:
			// case ','  | KEY_ALT_MOD: 
			// case '.'  | KEY_ALT_MOD: 
			// case '/'  | KEY_ALT_MOD: 

			// case (KEY_ALT_MOD | '0') ... (KEY_ALT_MOD | '9'): 
			// 	goto UpdateCommandKey;

			// case '1'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '!'; goto UpdateCommandKey;
			// case '2'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '@'; goto UpdateCommandKey;
			// case '3'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '#'; goto UpdateCommandKey;
			// case '4'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '$'; goto UpdateCommandKey;
			// case '5'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '%'; goto UpdateCommandKey;
			// case '6'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '^'; goto UpdateCommandKey;
			// case '7'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '&'; goto UpdateCommandKey;
			// case '8'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '*'; goto UpdateCommandKey;
			// case '9'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '('; goto UpdateCommandKey;
			// case '0'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = ')'; goto UpdateCommandKey;
			// case '`'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '~'; goto UpdateCommandKey;
			// case '-'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '_'; goto UpdateCommandKey;
			// case '='  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '+'; goto UpdateCommandKey;
			// case '['  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '{'; goto UpdateCommandKey;
			// case ']'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '}'; goto UpdateCommandKey;
			// case '\\' | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '|'; goto UpdateCommandKey;
			// case ';'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = ':'; goto UpdateCommandKey;
			// case '\'' | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '"'; goto UpdateCommandKey;
			// case ','  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '<'; goto UpdateCommandKey;
			// case '.'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '>'; goto UpdateCommandKey;
			// case '/'  | KEY_ALT_MOD | KEY_SHIFT_MOD: modifiedKey = '?'; goto UpdateCommandKey;

			// case (KEY_ALT_MOD | 'A') ... (KEY_ALT_MOD | 'Z'): 
			// 	modifiedKey = TO_LOWER_C(currentKey);
			// 	goto UpdateCommandKey;

			// case (KEY_ALT_MOD | KEY_SHIFT_MOD | 'A') ... (KEY_ALT_MOD | KEY_SHIFT_MOD | 'Z'): 
			// 	goto UpdateCommandKey;

			// case KEY_ALT_MOD | KEY_BACKSPACE:
			// case KEY_ALT_MOD | KEY_SHIFT_MOD | KEY_BACKSPACE:
			// 	command.firstKeyPressed = true; 
			// 	if (command.bufferCount > 0) command.bufferCount--;
			// 	goto UpdateCommandScan;

			// case KEY_ALT_MOD | KEY_CTRL_MOD | KEY_BACKSPACE:
			// case KEY_ALT_MOD | KEY_CTRL_MOD | KEY_SHIFT_MOD | KEY_BACKSPACE:
			// case KEY_ALT_MOD | KEY_DELETE:
			// 	command.firstKeyPressed = true;
			// 	command.bufferCount = 0;
			// 	command.scanFoundIndex = 0;
			// 	command.buffer[command.bufferCount] = '\0';
			// 	break;

			UpdateCommandKey:
				if (!command.firstKeyPressed) command.firstKeyPressed = true;   
				command.buffer[command.bufferCount++] = modifiedKey;
				command.buffer[command.bufferCount] = '\0';

			UpdateCommandScan:
				LOG("%d\n", command.scanFoundIndex);
				command.scanFoundIndex = TextFindTextForward(pCode->buffer, pCode->caretIndex, command.buffer);
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
		Color textColor = COLOR_TEXT;
		Color caretColor = BLANK;
		Vector2 mousePosition = GetMousePosition();
		Vector2 caretPosition = { -1, -1};
		Vector2 scanFoundPosition = { -1, -1};;
		float frameTime = GetFrameTime();
		int iChar = pCode->focusStartRowIndex;
		int scanAheadCount = 0;
		bool delimiter = false;

		ClearBackground(RAYWHITE);

		DrawText(TextFormat("frameTime: %f/", frameTime), 512, 0, 20, GRAY);
		DrawText(TextFormat("caretCollumn: %i caretRow: %i caretIndex: %i", pCode->caretCollumn, pCode->caretRow, pCode->caretIndex, pCode->focusStartRow), 0, 0, 20, DARKGRAY);

		/* 
		 * Text Panel
		 */
		DrawRectangleRec(textBox, COLOR_BACKGROUND);
		DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

		for (int y = 0; y < yCharCapacity; ++y) {
			int tabCount = 0;
			for (int x = 0; x < xCharCapacity - (tabCount * tabWidth); ++x) {
				
				Vector2 position = {
					textBox.x + (fontXSpacing * x) + (tabCount * fontXSpacing * 4), 
					textBox.y + (fontYSpacing * y)
				};										
				Rectangle rect = {position.x, position.y, fontXSpacing, fontYSpacing};

				if (iChar == text.caretIndex) {
					caretColor = ORANGE;
					caretPosition = position;
				}

				if (iChar == command.scanFoundIndex) 
					scanFoundPosition = position;
				
				if (input.lMouse && CheckCollisionPointRec(mousePosition, rect)) {
					float xDiff = mousePosition.x - (rect.x + (rect.width / 2));
					text.caretIndex = xDiff > 0 ? iChar + 1 : iChar;
					text.caretCollumn = CodeBoxCaretCollumn(&text);
				}

				char c = text.buffer[iChar];
				switch (text.buffer[iChar]) {

					case '\0':
						delimiter = true;
						goto FinishDrawingText;

					/* Whitespace */
					case ' ':
						c =  '_';
						textColor = COLOR_TEXT_HIDDEN;
				    	delimiter = true;
						goto DrawChar;

					case '\t':
						// Step more spaces for tab width
						rect.width += (tabCount * fontXSpacing * tabWidth);
						tabCount++;
						c = '-';
						textColor = COLOR_TEXT_HIDDEN;
				    	delimiter = true;
						goto DrawChar;

					case '\n':
						// Check click on entire line
						rect.width = textBox.width - rect.width;
						if (input.lMouse && CheckCollisionPointRec(mousePosition, rect)){
							text.caretIndex = iChar;
							text.caretCollumn = CodeBoxCaretCollumn(&text);
						}

						x = xCharCapacity;
						c =  '|';
						textColor = COLOR_TEXT_HIDDEN;
				    	delimiter = true;
						goto DrawChar;

					// Need to deal with these?
				    case '\r':
				    case '\v':
				    case '\f':
						c =  '?';
						textColor = COLOR_TEXT_HIDDEN;
				    	delimiter = true;
						goto DrawChar;

					/* Operators */
					case '!':
					case '%':
					case '&':
					case '*':
					case '+':
					case '-':
					case '/':
					case ':':
					case '<':
					case '=':
					case '>':
					case '?':
					case '^':
					case '|':
					case '~':
						textColor = COLOR_OPERATOR;
				    	delimiter = true;
						goto DrawChar;

					/* Quotes */
					case '"':
					case '\'':
					case '`':
						textColor = COLOR_QUOTE;
						delimiter = true;
						goto DrawChar;

					/* Scopes */
					case '(':
					case ')':
					case '{':
					case '}':
					case '[':
					case ']':
						textColor = COLOR_SCOPE;
						delimiter = true;
						goto DrawChar;

					case '#':
					case ',':
					case '.':
					case ';':
					case '@':
					case '\\':
						textColor = COLOR_COMMENT;
						delimiter = true;
						goto DrawChar;

					default:
						if (scanAheadCount > 0) goto DrawChar;

						textColor = COLOR_TEXT;

						if (delimiter == false) goto DrawChar;
						delimiter = false;

						// Check Keyword Tokens
						for (int t = 0; TOKEN_KEYWORDS[t] != NULL; ++t) {
							scanAheadCount = TextEqualsText(text.buffer + iChar, TOKEN_KEYWORDS[t]);
							if (scanAheadCount > 0) {
								textColor = COLOR_KEYWORD;
								goto DrawChar;
							}
						}

						// Check Type Tokens
						for (int t = 0; TOKEN_TYPES[t] != NULL; ++t) {
							scanAheadCount = TextEqualsText(text.buffer + iChar, TOKEN_TYPES[t]);
							if (scanAheadCount > 0) {
								textColor = COLOR_TYPE;
								goto DrawChar;
							}
						}

					DrawChar: {
						int codePointSize;
						int codePoint = GetCodepoint(&c, &codePointSize);
						DrawTextCodepoint(font, codePoint, position, fontSize, textColor);
						iChar++;
						scanAheadCount--;
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
			4, caretColor);

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

			for (int iCommand = 0; iCommand < command.bufferCount; ++iCommand) {
				char c = command.buffer[iCommand];
				int codePointSize;
				int codePoint = GetCodepoint(&c, &codePointSize);
				Vector2 position = { caretPosition.x + (fontXSpacing * iCommand), caretPosition.y };								
				DrawTextCodepoint(font, codePoint, position, fontSize, WHITE);
			}
		}
	}
	EndDrawing();

	if(!WindowShouldClose()) 
		goto LoopBegin;

	/*
	 * Cleanup
	 */
	CloseWindow();

	return 0;
}



