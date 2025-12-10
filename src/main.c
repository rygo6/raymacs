#define CONCAT(a, b) a  ##  b #a

static int Test(int input) {
	int output = input;
	// comment
	const char* str = "Hello\'\n";
	char tick = '"';
	int vala = 10 + 2;
	int valb = 10 / 2;
	return output;
}

#define HELLO { \
	int i = 0; /* Test */ \
	int o = 1; \
}

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
| Ctrl+Alt+J/L              | Word jump                                      |
| Ctrl+Up/Down              | Block jump                                     |
| Ctrl+Alt+I/K              | Block jump                                     |
| Up/Down/Left/Right        | Move                                           |
| Alt+I/J/K/L               | Move Alt                                       |
| Ctrl+G                    | Go to line number                              |
| Ctrl+M                    | Go to matching bracket                         |
| Alt Toggle                | Command Mode                                   |
+---------------------------+------------------------------------------------+
| SELECTION                                                                  |
+---------------------------+------------------------------------------------+
| Shift+Left/Right          | Select character                               |
| Shift+Up/Down             | Select line up/down                            |
| Shift+Home                | Select to beginning of line                    |
| Shift+End                 | Select to end of line                          |
| Ctrl+Shift+Left/Right     | Select word jump                               |
| Ctrl+Shift+Alt+J/L        | Select word jump                               |
| Ctrl+Shift+Up/Down        | Block select / Multi-cursor                    |
| Ctrl+Shift+Alt+I/K        | Block select / Multi-cursor                    |
| Ctrl+Shift+Mouse Drag     | Block select                                   |
| Mouse Double Click        | Select word                                    |
| Mouse Triple Click        | Select line                                    |
+---------------------------+------------------------------------------------+
| MULTI-CURSOR & FIND/REPLACE                                                |
+---------------------------+------------------------------------------------+
| Ctrl+Shift+N              | Select next occurrence (multi-cursor)          |
| Ctrl+Shift+B              | Select previous occurrence                     |
// I think this should be command?
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
| Ctrl+Shift+{ }            | Wrap with braces                               |
| Ctrl+[ ]                  | Wrap with brackets                             |
| Ctrl+Shift+( )            | Wrap with parentheses                          |
| Ctrl+'                    | Wrap with single quotes                        |
| Ctrl+Shift+"              | Wrap with double quotes                        |
| Ctrl+`                    | Wrap with backticks                            |
+---------------------------+------------------------------------------------+
| WORD OPERATIONS                                                            |
+---------------------------+------------------------------------------------+
| Ctrl+Backspace            | Delete word backwards                          |
| Ctrl+Delete               | Delete word forwards                           |
+---------------------------+------------------------------------------------+

GOOD IDEA 
Alt + { - Jump to Nearest, then next
Alt + } - ...
Alt + [ - ...
Alt + ] - ...
Alt + " - ...

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "raylib.h"
#include "raymath.h"

/*
 * Logging
 */
#define ANSI_RESET   "\033[0m"
#define ANSI_BLACK   "\033[30m"
#define ANSI_RED     "\033[31m"
#define ANSI_GREEN   "\033[32m"
#define ANSI_YELLOW  "\033[33m"
#define ANSI_BLUE    "\033[34m"
#define ANSI_MAGENTA "\033[35m"
#define ANSI_CYAN    "\033[36m"
#define ANSI_WHITE   "\033[37m"

#define ANSI_BRIGHT_BLACK   "\033[90m" 
#define ANSI_BRIGHT_RED     "\033[91m"
#define ANSI_BRIGHT_GREEN   "\033[92m"
#define ANSI_BRIGHT_YELLOW  "\033[93m"
#define ANSI_BRIGHT_BLUE    "\033[94m"
#define ANSI_BRIGHT_MAGENTA "\033[95m"
#define ANSI_BRIGHT_CYAN    "\033[96m"
#define ANSI_BRIGHT_WHITE   "\033[97m"

#define ANSI_BG_BLACK   "\033[40m"
#define ANSI_BG_RED     "\033[41m"
#define ANSI_BG_GREEN   "\033[42m"
#define ANSI_BG_YELLOW  "\033[43m"
#define ANSI_BG_BLUE    "\033[44m"
#define ANSI_BG_MAGENTA "\033[45m"
#define ANSI_BG_CYAN    "\033[46m"
#define ANSI_BG_WHITE   "\033[47m"

#define ANSI_BG_BRIGHT_BLACK   "\033[100m"
#define ANSI_BG_BRIGHT_RED     "\033[101m"
#define ANSI_BG_BRIGHT_GREEN   "\033[102m"
#define ANSI_BG_BRIGHT_YELLOW  "\033[103m"
#define ANSI_BG_BRIGHT_BLUE    "\033[104m"
#define ANSI_BG_BRIGHT_MAGENTA "\033[105m"
#define ANSI_BG_BRIGHT_CYAN    "\033[106m"
#define ANSI_BG_BRIGHT_WHITE   "\033[107m"

#define ANSI_BOLD      "\033[1m"
#define ANSI_DIM       "\033[2m"
#define ANSI_ITALIC    "\033[3m"
#define ANSI_UNDERLINE "\033[4m"
#define ANSI_REVERSE   "\033[7m"
#define ANSI_HIDDEN    "\033[8m"
#define ANSI_STRIKE    "\033[9m"

#define LOG(_format, ...)      fprintf(stderr, ANSI_DIM ANSI_CYAN __FILE__ ANSI_WHITE ":" ANSI_GREEN "%-5d" ANSI_WHITE  "INFO: " ANSI_RESET _format, __LINE__, ##__VA_ARGS__)
#define LOG_WARN(_format, ...) fprintf(stderr, ANSI_DIM ANSI_BLUE __FILE__ ANSI_WHITE ":" ANSI_GREEN "%-5d" ANSI_YELLOW "WARN: " ANSI_RESET _format, __LINE__, ##__VA_ARGS__)
#define LOG_ERR(_format, ...)  fprintf(stderr, ANSI_DIM ANSI_BLUE __FILE__ ANSI_WHITE ":" ANSI_GREEN "%-5d" ANSI_RED    "ERR:  " ANSI_RESET _format, __LINE__, ##__VA_ARGS__)

/* Log One-Time. Only use in debug it is heavy. */
static char _logOnceBuffer[128];
static char _logOnceNewBuffer[128];
#define DEBUG_LOG_ONCE(_format, ...) ({ \
	sprintf(_logOnceNewBuffer, _format, ##__VA_ARGS__); \
	if (strcmp(_logOnceBuffer, _logOnceNewBuffer) != 0) { \
		strcpy(_logOnceBuffer, _logOnceNewBuffer); \
		LOG(_format, __VA_ARGS__); \
	} \
})

/*
 * Utility
 */
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
typedef unsigned char utf8;

#define CACHE_LINE 64

#define COUNT(_array) (sizeof(_array) / sizeof(_array[0]))

#define MIN(_a, _b) \
({ \
	__auto_type _valA = (_a); \
	__auto_type _valB = (_b); \
	_valA < _valB ? _valA : _valB; \
})

#define MAX(_a, _b) \
({ \
	__auto_type _valA = (_a); \
	__auto_type _valB = (_b); \
	_valA > _valB ? _valA : _valB; \
})

#define UNUSED            __attribute__((unused))
#define FALLTHROUGH       __attribute__((fallthrough))
#define CACHE_ALIGN       __attribute__((aligned(CACHE_LINE)))
#define FORCE_INLINE      __attribute__((always_inline)) static inline
#define PACKED            __attribute__((packed))
#define ALIGN(_size)      __attribute__((aligned(_size)))
#define NO_RETURN         __attribute__((noreturn))

#define LIKELY(x)         __builtin_expect(!!(x), 1)
#define UNLIKELY(x)       __builtin_expect(!!(x), 0)

#define XMALLOC_ALIGNED(_align, _size) \
({ \
	void* p = _aligned_malloc(_size, _align); \
	if (p == NULL) PANIC("XMALLOC_ALIGNED FAIL!"); \
	p; \
})

#define ZERO_P(_p) memset((void*)(_p), 0, sizeof(*_p))

/*
 * Validation
 */
#define STATIC_ASSERT(...) _Static_assert(__VA_ARGS__)
#define ASSERT(_condition, ...) assert((_condition) && #_condition " " __VA_ARGS__)

#define PANIC(_format, ...) \
({ \
	fprintf(stderr, ANSI_RED __FILE__ ":%d PANIC! " _format ANSI_RESET, __LINE__, ##__VA_ARGS__); \
	__builtin_trap(); \
})

// TODO
#define CHECK(_command)
#define TRY(_command)

#define REQUIRE(_command) \
({ \
	RESULT _r = _command; \
	if (UNLIKELY(_r != RESULT_SUCCESS)) PANIC(#_command " == %s\n", string_RESULT(_r)); \
})

/*
 * Global Enum
 */
#define DEF_ARRAY_ITEM(_item, ...)  _item,
#define DEF_ENUM_ITEM(_item, ...)   _item __VA_OPT__(=) __VA_ARGS__,
#define DEF_STRING_ITEM(_item, ...) case _item: return #_item;
#define DEF_ENUM(_enum) \
	typedef enum PACKED _enum { \
		DEF_##_enum(DEF_ENUM_ITEM) \
	} _enum; \
	static const char* string_##_enum(_enum _item) { \
		switch(_item) { \
			DEF_##_enum(DEF_STRING_ITEM) \
			default: return #_enum " N/A"; \
		} \
	}

#define DEF_RESULT(DEF) \
	DEF(RESULT_ERROR,      -1) \
	DEF(RESULT_SUCCESS,     0) \
	DEF(RESULT_COLLISION,   1) \
	DEF(RESULT_PARSE_ERROR, 2)
DEF_ENUM(RESULT);

#define DEF_DIRECTION(DEF) \
	DEF(DIRECTION_NONE) \
	DEF(DIRECTION_FORWARD) \
	DEF(DIRECTION_BACKWARD) \
	DEF(DIRECTION_COUNT)
DEF_ENUM(DIRECTION);

#define DEF_SCOPE(DEF) \
	DEF(SCOPE_TAB) \
	DEF(SCOPE_DEFINE) \
	DEF(SCOPE_CURLY) \
	DEF(SCOPE_PAREN) \
	DEF(SCOPE_BRACKET) \
	DEF(SCOPE_QUOTE) \
	DEF(SCOPE_BLOCK_COMMENT) \
	DEF(SCOPE_LINE_COMMENT) \
	DEF(SCOPE_COUNT)
DEF_ENUM(SCOPE);

#define DEF_TOKEN(DEF) \
	DEF(TOKEN_NONE) \
	DEF(TOKEN_TYPE) \
	DEF(TOKEN_KEYWORD) \
	DEF(TOKEN_WHITESPACE) \
	DEF(TOKEN_OPERATOR) \
	DEF(TOKEN_PREPROCESS) \
	DEF(TOKEN_CONTINUE) \
	DEF(TOKEN_SCOPE) \
	DEF(TOKEN_QUOTE) \
	DEF(TOKEN_TEXT) \
	DEF(TOKEN_ESCAPE) \
	DEF(TOKEN_COMMENT) \
	DEF(TOKEN_COUNT)
DEF_ENUM(TOKEN);

#define FIND_CARET_COLOR     (Color){   0, 255,   0, 255 }
#define FIND_HIGHLIGHT_COLOR (Color){   0, 255,   0, 64  }
#define COLOR_COMMAND_BOX    (Color){  20,  20,   2, 200 }
#define COLOR_TEXT_BOX       (Color){  37,  37,  38, 255 }
#define COLOR_CARET       ORANGE
#define COLOR_HOVER       (Color){   0, 255,   0, 64  }
#define COLOR_CODE        (Color){ 216, 222, 233, 255 }
#define COLOR_PREPROCESS  (Color){ 198, 149, 198, 255 }
#define COLOR_CONTINUE    (Color){ 148,  99, 148, 255 }
#define COLOR_NUMBER      (Color){ 249, 174,  87, 255 }
#define COLOR_STRING      (Color){ 153, 199, 148, 255 } 
#define COLOR_COMMENT     (Color){ 166, 172, 185, 255 }  
#define COLOR_MACRO_NAME  (Color){ 249, 174,  87, 255 }
#define COLOR_OPERATOR    (Color){ 249, 123,  87, 255 }
#define COLOR_BACKGROUND  (Color){  48,  56,  65, 255 } 
#define COLOR_WHITESPACE  (Color){  68,  76,  85, 255 } 
#define COLOR_ESCAPE      (Color){ 198, 149, 198, 255 } 
#define COLOR_TEXT        (Color){ 127, 199, 148, 255 } 
#define COLOR_QUOTE       (Color){  96, 180, 180, 255 } 
#define COLOR_SCOPE       (Color){ 255, 255, 255, 255 } 
#define COLOR_KEYWORD     (Color){ 236,  96, 102, 255 }
#define COLOR_TYPE        (Color){ 198, 149, 198, 255 }

static Color TOKEN_COLOR[] = {
	[TOKEN_NONE]       = COLOR_CODE,
	[TOKEN_TYPE]       = COLOR_TYPE,
	[TOKEN_KEYWORD]    = COLOR_KEYWORD,
	[TOKEN_WHITESPACE] = COLOR_WHITESPACE,
	[TOKEN_OPERATOR]   = COLOR_OPERATOR,
	[TOKEN_PREPROCESS] = COLOR_PREPROCESS,
	[TOKEN_CONTINUE]   = COLOR_CONTINUE,
	[TOKEN_SCOPE]      = COLOR_SCOPE,
	[TOKEN_QUOTE]      = COLOR_QUOTE,
	[TOKEN_TEXT]       = COLOR_TEXT,
	[TOKEN_ESCAPE]     = COLOR_ESCAPE,
	[TOKEN_COMMENT]    = COLOR_COMMENT,
};
STATIC_ASSERT(COUNT(TOKEN_COLOR) == TOKEN_COUNT);

#define DEF_PREPROCESS_TOKENS(DEF) \
	DEF("#define") \
	DEF("#include")

#define DEF_KEYWORD_TOKENS(DEF) \
	DEF("_Static_assert") \
	DEF("_Noreturn") \
	DEF("_Generic") \
	DEF("continue") \
	DEF("volatile") \
	DEF("register") \
	DEF("restrict") \
	DEF("_Alignof") \
	DEF("_Alignas") \
	DEF("typedef") \
	DEF("default") \
	DEF("_Atomic") \
	DEF("typeof") \
	DEF("switch") \
	DEF("static") \
	DEF("sizeof") \
	DEF("return") \
	DEF("inline") \
	DEF("extern") \
	DEF("while") \
	DEF("const") \
	DEF("break") \
	DEF("goto") \
	DEF("else") \
	DEF("case") \
	DEF("auto") \
	DEF("for") \
	DEF("if") \
	DEF("do")

#define DEF_TYPE_TOKENS(DEF) \
	DEF("unsigned") \
	DEF("uint64_t") \
	DEF("ptrdiff_t") \
	DEF("uint32_t") \
	DEF("uint16_t") \
	DEF("wchar_t") \
	DEF("struct") \
	DEF("signed") \
	DEF("size_t") \
	DEF("int64_t") \
	DEF("int32_t") \
	DEF("int16_t") \
	DEF("double") \
	DEF("uint8_t") \
	DEF("float") \
	DEF("short") \
	DEF("int8_t") \
	DEF("_Bool") \
	DEF("union") \
	DEF("void") \
	DEF("long") \
	DEF("char") \
	DEF("enum") \
	DEF("int")

static const char* PREPROCESS_TOKENS[] = {
	DEF_PREPROCESS_TOKENS(DEF_ARRAY_ITEM)
};

static const char* KEYWORD_TOKENS[] = {
	DEF_KEYWORD_TOKENS(DEF_ARRAY_ITEM)
};

static const char* TYPE_TOKENS[] = {
	DEF_TYPE_TOKENS(DEF_ARRAY_ITEM)
};

typedef u16 tok_k;
#define MAP_CAPACITY 4096
#define TOKEN_MASK 0x0FFF // 12 bit mask

static TOKEN TOKEN_MAP[MAP_CAPACITY];

#define TOKEN_HASH_SEED 11
#define TOKEN_HASH(_h, _c) (_h + (_h << 5) + (_c))  

static tok_k TokenKeyRange(const char *str, int iStart, int iEnd)
{
	tok_k hash = TOKEN_HASH_SEED;
	for (int i = iStart; i <= iEnd; ++i) 
		hash = TOKEN_HASH(hash, str[i]);
	return hash & TOKEN_MASK;
}

static tok_k TokenKey(const char *str)
{
	tok_k hash = TOKEN_HASH_SEED; utf8 c;
	while ((c = *str++))
		hash = TOKEN_HASH(hash, c);
	return hash & TOKEN_MASK;
}

static RESULT ContructTokenMap(TOKEN category, int tokenCount, const char** tokens)
{
	for (int iTkn = 0; iTkn < tokenCount; iTkn++) {
		tok_k k = TokenKey(tokens[iTkn]);
		if (TOKEN_MAP[k] != TOKEN_NONE) {
			LOG_ERR("Type Hash Collision! %s %d %s\n", tokens[iTkn], k, string_TOKEN(category));
			return RESULT_COLLISION;
		}
		TOKEN_MAP[k] = category;
		LOG("%s %d %s\n", tokens[iTkn], k, string_TOKEN(category));
	}
	return RESULT_SUCCESS;
}


static inline Vector2 GetWorldToBoxLocal(Vector2 point, Rectangle rect)
{
    return (Vector2){ point.x - rect.x, point.y - rect.y };
}

static inline Vector2 GetBoxLocalToWorld(Vector2 point, Rectangle rect)
{
    return (Vector2){ point.x + rect.x, point.y + rect.y };
}

/*
 * CodeBox
 */
#define MAX_INPUT_CHARS      2048
#define TEXT_BUFFER_CAPACITY 64000

#define CASE_EITHER(_key, _a, _b) case _key | _a | _b: case _key | _a: case _key | _b
#define TO_LOWER_C(_c) 'a' + (_c - 'A')

const int endCharLength = 1;
const int tabWidth = 4;
const int fontXSpacing = 10;
const int fontYSpacing = 20;
const int fontSize = 24;
const char availableChars[] = "·¬ abcdefghijklmnopqrstuvwxyzABDCEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+[];',./{}:\"<>?|`~\n\t\\";

#define CARET_MAX_CAPACITY 8
#define CARET_INVALID INT_MIN

#define TOKEN_MAX_INCREMENT 15
typedef struct PACKED TextMeta {
	TOKEN token : 6;

	u8 BLOCK_COMMENT : 1;
	u8 LINE_COMMENT  : 1;
	u8 PREPROCESS    : 1;
	u8 QUOTE         : 1;

	u8 SCOPE_TAB     : 4;
	u8 SCOPE_CURLY   : 4;
	u8 SCOPE_PAREN   : 4;
	u8 SCOPE_BRACKET : 4;

	u8 iTokenStartOffset : 4;
	u8 iTokenEndOffset   : 4;

	u16 iScopeStartOffset : 16; // Could someone really have a scope bigger than 65k?
	u16 iScopeEndOffset   : 16;

} TextMeta;

typedef struct Highlight {
	int startIndex;
	int endIndex;
} Highlight;

typedef struct CodeRow {
	int startIndex;
	int endIndex;
} CodeRow;

typedef struct CodePos {
	int index;
	int row;
	int col;
} CodePos;

typedef struct CodeBox {
	int focusStartRowIndex;
	int focusStartRow;

	int 	 caretCount;
	CodePos* pCarets;

	CodePos mark;

	int boxRowCount;
	int boxColCount;
	CodeRow* pBoxRows;

	int textRowCount;
	int textCount;
	char*     pText;
	CodeRow*  pTextRows;
	TOKEN*    pTextToken;
	TextMeta* pTextMeta;

	char* path;
	bool dirty;
} CodeBox;

typedef struct Command {
	bool enabled;
	bool toggled;
	bool skipCount;
	bool firstKeyPressed;

	int  scanFoundIndex;

	int  bufferCount;
	char buffer[32];
} Command;

/*
 * CodeBox Parse
 */
static inline bool Delimiter(char c) 
{
	switch (c) 
	{
		case '\0':

		/* Whitespace */
		case ' ': case '\t': case '\n':
		case '\r': // Carriage return
		case '\v': // Vertical tab
		case '\f': // Form feed

		/* Operators */
		case '!': case '%': case '&': case '*': case '+': case '-': case '/': case ':': case '<': case '=': case '>': case '?': case '^': case '|': case '~': 	

		/* Quotes */
		case '"': case '\'': case '`':

		/* Scopes */
		case '(': case ')': case '{': case '}':	case '[': case ']':

		case ',': case '.': case ';':	case '@': case '\\':
			return true;

		default:
			return false;
	}
}

static RESULT ProcessMeta(CodeBox* pCode) 
{
	const int   count = pCode->textCount;
	const char* pText = pCode->pText; 
	TextMeta*   pMeta = pCode->pTextMeta;

	int iC    = 0;
	int iStrt = 0;

	// Prev Char, Current Char, Next Char
	char pc = '\0';
	char c  = '\0';
	char nc = pText[0];

	// Prev Delim, Current Delim, Next Delim
	bool pd = true;
	bool d  = true;
	bool nd = Delimiter(nc);

	TextMeta meta; ZERO_P(&meta);

processChar:
	bool comment    = meta.BLOCK_COMMENT || meta.LINE_COMMENT;
	bool quote      = meta.QUOTE;
	bool preprocess = meta.PREPROCESS;

	pc = c;	c  = nc; nc = pText[iC + 1];
	pd = d;	d  = nd; nd = Delimiter(nc);

	switch (comment | quote << 1) 
	{
		/* Parse Comment */
		case (true): {
			switch (c) 
			{
				case '/':
					if (pc == '*') {
						pMeta[iC] = meta;
						meta.token = TOKEN_NONE;
						meta.BLOCK_COMMENT = 0; 
						goto next;
					}	
					goto metaAndNext;

				case '\n': 
					meta.token = TOKEN_WHITESPACE;
					pMeta[iC] = meta;
					meta.token = TOKEN_COMMENT;
					meta.LINE_COMMENT = 0;
					goto next;

				case ' ': 
				case '\t': 
					meta.token = TOKEN_WHITESPACE;
					pMeta[iC] = meta;
					meta.token = TOKEN_COMMENT;
					goto next;

				default:
					goto metaAndNext;
			}
		}

		/* Parse Quote */
		case (true << 1): {
			switch (c) 
			{
				case '\\':
					meta.token     = TOKEN_ESCAPE;
					pMeta[iC]      = meta;
					pMeta[iC + 1]  = meta;
					meta.token     = TOKEN_TEXT;
					goto skipAndNext;

				case '\'':
				case '"':
					switch (pc) 
					{
					case '\'':
						goto metaAndNext;

					default:
						meta.token = TOKEN_QUOTE;
						pMeta[iC]  = meta;
						meta.token = TOKEN_NONE;
						meta.QUOTE = 0;
						goto next;
					}

				default:
					goto metaAndNext;
			}
		}

		/* Parse Text */
		default:
			
			/* Test Delimit and Token Lookup*/
			u8 delimitTransition = pd | d << 1 | nd << 2;
			switch (delimitTransition) 
			{
				/* Start Token */
				case true  | false << 1 | false << 2:
					iStrt = iC;
					break;

				/* Start Single Char Token */
				case true  | false << 1 | true  << 2:
					iStrt = iC;
					FALLTHROUGH;

				/* End Token */
				case false | false << 1 | true  << 2:
					int iEnd = iC;
					tok_k kTok = TokenKeyRange(pText, iStrt, iEnd);
					TOKEN tok = TOKEN_MAP[kTok];
					if (tok == TOKEN_NONE) 
						goto next;

					bool isPreprocess = (meta.token == TOKEN_PREPROCESS);
					meta.token = tok;
					meta.PREPROCESS = isPreprocess | meta.PREPROCESS;
					for (int i = iStrt; i <= iEnd; ++i) {
						pMeta[i].token      = meta.token;
						pMeta[i].PREPROCESS = meta.PREPROCESS;
						pMeta[i].iTokenStartOffset = i - iStrt;
						pMeta[i].iTokenEndOffset   = iEnd - i;
					}
					goto next;
			}

			/* Test Char */
			switch (c) 
			{
				/* Token Chars */
				// case '_':
				// case '`':
				// case 'a'...'z':
				// case 'A'...'Z':
				// case '0'...'9':
				// 	goto next;
				default: goto next;

				/* Increment */
			#define INCREMENT_CASE(_add, _sub, _scope, _token) \
				case _add: \
					meta._scope += (meta._scope < TOKEN_MAX_INCREMENT); \
					meta.token = _token; \
					goto metaAndNext; \
				case _sub: \
					meta.token = _token; \
					pMeta[iC]  = meta; \
					meta._scope -= (meta._scope > 0);  \
					goto next;

				/* Scopes */
				INCREMENT_CASE('[', ']', SCOPE_BRACKET, TOKEN_SCOPE)
				INCREMENT_CASE('{', '}', SCOPE_CURLY,   TOKEN_SCOPE)
				INCREMENT_CASE('(', ')', SCOPE_PAREN,   TOKEN_SCOPE)

			#undef INCREMENT_CASE

				/* Whitespace */
				case '\n':
					if (meta.PREPROCESS && pc != '\\') {
						meta.token = TOKEN_WHITESPACE;
						pMeta[iC]  = meta;
						meta.PREPROCESS = 0;
						goto next;
					}
					meta.token = TOKEN_WHITESPACE;
					goto metaAndNext;

				case ' ' :
				case '\0':
				case '\t':
				case '\r': // Carriage return
				case '\v': // Vertical tab
				case '\f': // Form feed
					meta.token = TOKEN_WHITESPACE;
					goto metaAndNext;

				/* Comment or Operator */
				case '/':
					switch (nc) 
					{
						case '/':
							meta = (TextMeta){.token = TOKEN_COMMENT, .LINE_COMMENT = 1, .BLOCK_COMMENT = meta.BLOCK_COMMENT};
							goto metaAndNext;
						case '*':
							meta.token = TOKEN_COMMENT;
							meta.BLOCK_COMMENT = 1;
							goto metaAndNext;
						default:
							meta.token = TOKEN_OPERATOR;
							goto metaAndNext;
					}
	 
				/* Operators */
				case '!':
				case '%':
				case '&':
				case '+':
				case '-':
				case '*':
				case ':':
				case '<':
				case '=':
				case '>':
				case '?':
				case '^':
				case '|':
				case '~':
					meta.token = TOKEN_OPERATOR;
					goto metaAndNext;

				/* Quotes */
				case '"':
				case '\'':
					meta.token = TOKEN_QUOTE;
					meta.QUOTE = true; 
					pMeta[iC]  = meta; 
					meta.token = TOKEN_TEXT;
					goto next;

				/* Preprocess */
				case '#':
					switch (nc) 
					{
						case '#':
							meta.token = TOKEN_PREPROCESS; 
							pMeta[iC]   = meta; 
							pMeta[iC+1] = meta;						
							goto skipAndNext;

						default:
							meta.token = TOKEN_PREPROCESS;
							goto metaAndNext;
					}

				case '\\':
					if (meta.PREPROCESS && nc == '\n') {
						meta.token = TOKEN_CONTINUE;   
						pMeta[iC] = meta;
						meta.token = TOKEN_WHITESPACE; 
						pMeta[iC+1] = meta;
						meta.token = TOKEN_PREPROCESS;
						goto skipAndNext;
					}
					goto metaAndNext;

				case ',':
				case '.':
				case ';':
				case '@':
					meta.token = TOKEN_NONE;
					goto metaAndNext;
			}
	} // switch (parseComment | parseQuote << 1) 

skipAndNext: // Skip char and go to next
	++iC;
	pc = c;	c  = nc; nc = pText[iC + 1];
	pd = d;	d  = nd; nd = Delimiter(nc);
	goto next;

metaAndNext: // Set meta and go to next
	pMeta[iC] = meta;

next: // Go to next char
	if (UNLIKELY(++iC == count)) return RESULT_SUCCESS; 
	goto processChar;

error:
	LOG_ERR("Unexpected Parse Char! %c%c%c\n", pc, c, nc);
	return RESULT_PARSE_ERROR;
}

/*
 * Codebox Text Search
 */

// Find specified char. 
static int TextFindCharBackward(const char* text, int index, char c)
{
	while (index >= 0 && text[index] != c) index--;    
	return index;
}

// Find specified char. 
static int TextFindCharForward(const char* pText, int index, char c)
{
	while (pText[index] != c && pText[index] != '\0') index++;    
	return index;
}

// Find specified substring. 
static int TextFindTextBackward(const char* text, int index, const char* find)
{
	while (index >= 0) {
		int i = 0; while (text[index + i] == find[i]) 
			if (find[++i] == '\0') return index;
		index--;
	}
	return index;
}

// Find specified substring. Will return end null terminator index if it doesn't find.
static int TextFindTextForward(const char* text, int index, const char* find)
{
	const char* s = text;
	int foundIndex = index;
	while (s[foundIndex] != '\0') {
		int i = 0; while (s[foundIndex + i] == find[i]) 
			if (find[++i] == '\0') return foundIndex;
		foundIndex++;
	}
	return index;
}

static int TextFindTextsForward(const char* text, int index, const char** finds)
{
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
static int TextEqualsText(const char* text, const char* equals)
{
	assert(equals[0] != '\0');
	int index = 0;
	while (text[index] == equals[index] && text[index] != '\0')
		if (equals[++index] == '\0') return index;
	return 0;
}

// Find first char which is not the specified char.
static int TextNegateFindCharBackward(const char* text, int index, char find)
{
	while (index >= 0 && text[index] == find) index--;    
	return index;
}

// Find first char which is not the specified char.
static int TextNegateFindCharForward(const char* text, int index, char find)
{
	while (text[index] == find && text[index] != '\0') index++;    
	return index;
}

static int TextFindCharsForward(const char* text, int index, const char* find)
{
	while (text[index] != '\0') {
		int i = 0; while (find[i] != '\0') 
			if (text[index] == find[i++]) return index;
		index++;
	}
	return index;
}

static int TextFindCharsBackward(const char* text, int index, const char* find)
{
	while (index >= 0) {
		int i = 0; while (find[i] != '\0') 
			if (text[index] == find[i++]) return index;
		index--;
	}
	return index;
}

// Find char skipping a specified number of matches. 
static int TextFindCharSkipForward(const char* pText, char find, int skipCount)
{
	int index = 0;
	while (pText[index] != '\0' && skipCount > 0) {
		if (pText[index] == find) skipCount--;   
		index++;
	}
	return index;
}

// Count occurances of char.
static int TextCountCharForward(const char* text, int index, int range, char find)
{
	int count = 0;
	for (; index < range; ++index) {
		if (text[index] == find) count++;
		if (text[index] == '\0') break;
	}
	return count;
}

// Find char index and also count occurense of another char during scan.
static bool TextFindCountCharForward(const char* pText, char searchChar, char countChar, int* pFoundIndex, int *pCount)
{
	int index = *pFoundIndex, count = *pCount; 
	char c;	do {
		c = pText[index++];
		count += c == countChar;
	} while (c && c != searchChar);
	*pFoundIndex = index - 1; *pCount = count;
	return c == searchChar;
}

// Find char index and also count occurense of another char during scan.
static bool TextFindCountCharBackward(const char* pText, char searchChar, char countChar, int* pFoundIndex, int *pCount)
{
	int index = *pFoundIndex;
	while (pText[index] != searchChar) {
		if (pText[index] == countChar) *pCount = *pCount + 1;
		if (index <= 0) return false;
		index--;
	}
	*pFoundIndex = index;
	return true;
}

// The index of char on current line
static inline int CodeBoxIndexCol(const CodeBox* pCode, int index)
{
	int lineStartIndex = TextFindCharBackward(pCode->pText, index - 1, '\n') + endCharLength;
	return index - lineStartIndex;
}

// Line given index is on
static inline int CodeBoxIndexRow(const CodeBox* pCode, int index)
{
	return TextCountCharForward(pCode->pText, 0, index, '\n');
}

// Focus on a given row.
static void CodeBoxFocusRow(CodeBox* pCode, int toRow)
{
	int boxRowCount = (int)pCode->boxRowCount;

	int yMin = pCode->focusStartRow;
	if (toRow < yMin) {
		pCode->focusStartRow = toRow;
		pCode->focusStartRowIndex = TextFindCharSkipForward(pCode->pText, '\n', pCode->focusStartRow);
	}

	int yMax = yMin + boxRowCount;
	if (toRow > yMax) {
		pCode->focusStartRow = toRow - boxRowCount;
		pCode->focusStartRowIndex = TextFindCharSkipForward(pCode->pText, '\n', pCode->focusStartRow);
	}
} 

static void CodeBoxIncrementFocusRow(CodeBox* pCode, int increment)
{
	pCode->focusStartRow -= increment;
	pCode->focusStartRow = MAX(pCode->focusStartRow, 0);
	pCode->focusStartRow = MIN(pCode->focusStartRow, pCode->textRowCount);
	pCode->focusStartRowIndex = TextFindCharSkipForward(pCode->pText, '\n', pCode->focusStartRow);
	// LOG("focusStartRow: %d\n", pCode->focusStartRow);
}

// Focus on a given character index.
static inline void CodeBoxFocusIndex(CodeBox* pCode, int toIndex)
{
	int toRow = CodeBoxIndexRow(pCode, toIndex);
	CodeBoxFocusRow(pCode, toRow);
}

/* Focus on Mark */
static inline void CodeBoxFocusMark(CodeBox* pCode)
{
	CodeBoxFocusRow(pCode, pCode->mark.row);
}

/* Update Mark Index */
static void CodeSetMarkIndex(CodeBox* pCode, int newMarkIndex)
{
	pCode->mark.index   = newMarkIndex;
	pCode->mark.row     = CodeBoxIndexRow(pCode, newMarkIndex);
	pCode->mark.col     = CodeBoxIndexCol(pCode, newMarkIndex);
	assert(pCode->mark.index >= 0);
	assert(pCode->mark.index <= pCode->textCount);
	assert(pCode->mark.row   >= 0);
	assert(pCode->mark.row   <= pCode->textRowCount);
	assert(pCode->mark.col   >= 0);
}

/* Sync Current Mark To Specified Caret  */
static void CodeSyncMarkToCaret(CodeBox* pCode, u8 iCaret)
{
	memcpy(pCode->pCarets + iCaret, &pCode->mark, sizeof(CodePos));
}

/* Sync Current Mark Row To Specified Caret */
static void CodeSyncMarkRowToCaret(CodeBox* pCode, u8 iCaret)
{
	CodePos mark = pCode->mark;
	CodeRow row  = pCode->pTextRows[mark.row];
	int newCol = MIN(row.endIndex - row.startIndex, mark.col);
	int newIndex = row.startIndex + newCol;
	CodePos* pCaret = pCode->pCarets + iCaret;
	pCaret->index = newIndex;
	pCaret->col   = newCol;
	pCaret->row   = mark.row;
	pCode->mark.index = newIndex;
}

static void CodeBoxInsertCharAtIndex(CodeBox* pCode, int index, char c)
{
	memmove(pCode->pText + index + 1, pCode->pText + index, pCode->textCount - index - 1);
	pCode->dirty = true;
	pCode->pText[index] = c;
	pCode->textCount++;
	pCode->pCarets[0].index++;
	pCode->pCarets[0].col++;
	pCode->textRowCount += c == '\n';
}

static inline void CodeBoxInsertChar(CodeBox* pCode, char c)
{
	CodeBoxInsertCharAtIndex(pCode, pCode->pCarets[0].index, c);
}

static void CodeBoxDeleteCharAtIndex(CodeBox* pCode, int index)
{
	if (pCode->textCount == 0) return;
	memmove(pCode->pText + index - 1, pCode->pText + index, pCode->textCount - index);
	pCode->textRowCount -= pCode->pText[index - 1] == '\n';
	pCode->textCount--;
}

static inline void CodeBoxDeleteChar(CodeBox* pCode) 
{
	CodeBoxDeleteCharAtIndex(pCode, pCode->pCarets[0].index);
}

static void CommandFinish(CodeBox* pCode, Command* pCommand)
{
	CodeSetMarkIndex(pCode, pCommand->scanFoundIndex);
	CodeBoxFocusRow(pCode, pCode->pCarets[0].row);
	pCommand->scanFoundIndex  = 0;
	pCommand->bufferCount     = 0;
	pCommand->enabled         = false;
	pCommand->toggled         = false;
	pCommand->firstKeyPressed = false;
}


void PrintU16Binary(u16 value) {
	for (int i = 15; i >= 0; i--) {
		putchar((value & (1 << i)) ? '1' : '0');
		if (i % 4 == 0) putchar(' ');
	}
	putchar('\n');
}

static CodeBox text;

#define MASK_ASCII    0b00000000000000000000000011111111 
#define KEY_SHIFT_MOD 0b10000000000000000000000000000000
#define KEY_ALT_MOD   0b01000000000000000000000000000000
#define KEY_CTRL_MOD  0b00100000000000000000000000000000

int main(void)
{
	REQUIRE(ContructTokenMap(TOKEN_PREPROCESS, COUNT(PREPROCESS_TOKENS), PREPROCESS_TOKENS));
	REQUIRE(ContructTokenMap(TOKEN_TYPE,       COUNT(TYPE_TOKENS),       TYPE_TOKENS));
	REQUIRE(ContructTokenMap(TOKEN_KEYWORD,    COUNT(KEYWORD_TOKENS),    KEYWORD_TOKENS));

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

	/* State */
	CodeBox* pCode = &text;

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
	// TODO dynamically update
	pCode->boxColCount = (int)(textBox.width  / fontXSpacing);
	pCode->boxRowCount = (int)(textBox.height / fontYSpacing);
	pCode->pBoxRows    = XMALLOC_ALIGNED(CACHE_LINE, text.boxRowCount * sizeof(CodeRow));
	memset(pCode->pBoxRows, 0, text.boxRowCount * sizeof(CodeRow));

	pCode->pCarets = XMALLOC_ALIGNED(CACHE_LINE, CARET_MAX_CAPACITY * sizeof(CodePos));
	memset(pCode->pBoxRows, 0, CARET_MAX_CAPACITY * sizeof(CodePos));
	pCode->caretCount = 1;

	/* File Load */
	{
		pCode->pText      = XMALLOC_ALIGNED(CACHE_LINE, TEXT_BUFFER_CAPACITY * sizeof(char));
		pCode->pTextRows  = XMALLOC_ALIGNED(CACHE_LINE, TEXT_BUFFER_CAPACITY * sizeof(CodeRow));
		pCode->pTextToken = XMALLOC_ALIGNED(CACHE_LINE, TEXT_BUFFER_CAPACITY * sizeof(TOKEN));
		pCode->pTextMeta  = XMALLOC_ALIGNED(CACHE_LINE, TEXT_BUFFER_CAPACITY * sizeof(TextMeta));

		memset(pCode->pText,      0, TEXT_BUFFER_CAPACITY * sizeof(char));
		memset(pCode->pTextRows,  0, TEXT_BUFFER_CAPACITY * sizeof(CodeRow));
		memset(pCode->pTextToken, 0, TEXT_BUFFER_CAPACITY * sizeof(TOKEN));
		memset(pCode->pTextMeta,  0, TEXT_BUFFER_CAPACITY * sizeof(TextMeta));

		pCode->path = "./src/main.c";
		char* loadedFile = LoadFileText(pCode->path);
		int index = 0;
		int rowIndex = 0;
		int startIndex = 0;
		CodeRow* pTextRows = pCode->pTextRows;
		while (loadedFile[index] != '\0') {
			if (loadedFile[index] == '\n') {
				pTextRows[rowIndex].startIndex = startIndex;
				pTextRows[rowIndex].endIndex = index;
				startIndex = index + 1;
				rowIndex++;
			}
			index++;
		}
		pCode->textRowCount = rowIndex;
		pCode->textCount = index;
		LOG("Loaded Buffer Size %d\n", text.textCount);
		ASSERT(text.textCount < TEXT_BUFFER_CAPACITY, "Loaded buffer size too big!");

		memcpy(pCode->pText, loadedFile, pCode->textCount + 1);
		free(loadedFile);

		ProcessMeta(&text);
	}

/*
 * Main Loop
 */
LoopBegin:

	framesCounter++;

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
	const int iCaret = 0;
	const CodePos mark = pCode->mark;
	CodePos* pMark = &pCode->mark;
	CodePos caret = pCode->pCarets[0];
	CodePos* pCaret = &pCode->pCarets[0];
	char* pText = pCode->pText;
	while (currentKey > 0)
	{
		int modifiedKey = currentKey;
		switch (currentKey | input.modifierCombination) {

			/* Move Left Keys */
			case KEY_LEFT: 
			case KEY_A | KEY_ALT_MOD:
				if (caret.index <= 0) break;
				CodeSetMarkIndex(pCode, mark.index - 1);
				CodeSyncMarkToCaret(pCode, 0);
				break;

			case KEY_LEFT | KEY_CTRL_MOD:
			case KEY_A    | KEY_CTRL_MOD | KEY_ALT_MOD: {
				if (caret.index <= 0) break;

				int newIndex = CARET_INVALID;
				switch(pText[mark.index - 1]){
					case ' ':  newIndex = TextNegateFindCharBackward(pText, mark.index - 1, ' ');  break;
					case '\n': newIndex = TextNegateFindCharBackward(pText, mark.index - 1, '\n'); break;
					default:   newIndex = TextFindCharsBackward(pText, mark.index - 1, " \n");     break;
				}

				if (newIndex != CARET_INVALID) {
					CodeSetMarkIndex(pCode, newIndex + 1);
					CodeSyncMarkRowToCaret(pCode, 0);
					CodeBoxFocusMark(pCode);
				}

				break;
			}

			/* Move Right Keys */
			case KEY_RIGHT: 
			case KEY_D | KEY_ALT_MOD:
				if (caret.index >= pCode->textCount) break;
				CodeSetMarkIndex(pCode, mark.index + 1);
				CodeSyncMarkToCaret(pCode, 0);
				break;

			case KEY_RIGHT | KEY_CTRL_MOD:
			case KEY_D     | KEY_CTRL_MOD | KEY_ALT_MOD: {
				if (caret.index >= pCode->textCount) break;

				int newIndex = CARET_INVALID;
				switch(pText[mark.index]){
					case ' ':  newIndex = TextNegateFindCharForward(pText, mark.index, ' ');  break;
					case '\n': newIndex = TextNegateFindCharForward(pText, mark.index, '\n'); break;
					default:   newIndex = TextFindCharsForward(pText, mark.index, " \n");     break;
				}

				if (newIndex != CARET_INVALID) {
					CodeSetMarkIndex(pCode, newIndex);
					CodeSyncMarkRowToCaret(pCode, 0);
					CodeBoxFocusMark(pCode);
				}

				break;
			}

			/* Move Up Keys */
			case KEY_UP: 
			case KEY_W | KEY_ALT_MOD:{
				pMark->row--;
				CodeSyncMarkRowToCaret(pCode, 0);
				CodeBoxFocusMark(pCode);
				break;
			}

			case KEY_UP | KEY_CTRL_MOD:
			case KEY_W  | KEY_CTRL_MOD | KEY_ALT_MOD: {
				int startIndex      = pText[mark.index] == '\n' ? mark.index - endCharLength : mark.index;
				int blockStartIndex = TextFindTextBackward(pText, startIndex, "\n\n");
				int blockEndIndex   = TextNegateFindCharBackward(pText, blockStartIndex, '\n');  
				int newCaretIndex   = blockEndIndex + 1;
				CodeSetMarkIndex(pCode, newCaretIndex);
				CodeSyncMarkRowToCaret(pCode, 0);
				CodeBoxFocusMark(pCode);
				break;
			}

			/* Move Down Keys */
			case KEY_DOWN: 
			case KEY_S | KEY_ALT_MOD: {
				pMark->row++;
				CodeSyncMarkRowToCaret(pCode, 0);
				CodeBoxFocusMark(pCode);
				break;
			}

			case KEY_DOWN | KEY_CTRL_MOD:
			case KEY_S    | KEY_CTRL_MOD | KEY_ALT_MOD: {
				// Search"\n\n" to find where there is a new line gap
				int blockEndIndex   = TextFindTextForward(pText, mark.index, "\n\n");
				int blockStartIndex = TextNegateFindCharForward(pText, blockEndIndex, '\n');
				blockStartIndex = TextNegateFindCharForward(pText, blockStartIndex, ' ');
				blockStartIndex = TextNegateFindCharForward(pText, blockStartIndex, '\t');
				int newCaretIndex   = blockStartIndex;
				CodeSetMarkIndex(pCode, newCaretIndex);
				CodeSyncMarkRowToCaret(pCode, 0);
				CodeBoxFocusMark(pCode);
				break;
			}

			/* Command Keys */
			// case KEY_ALT_MOD | KEY_RIGHT_ALT: 
			// case KEY_ALT_MOD | KEY_LEFT_ALT: 
			// 	if (!command.enabled) {
			// 		LOG("Command Begin\n");
			// 		command.enabled = true;
			// 		command.scanFoundIndex = pCode->pActiveCaret->index;
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

			// 	LOG("%d %d\n", pCode->pActiveCaret->index, command.scanFoundIndex);

			// 	command.scanFoundIndex = TextFindTextForward(pCode->pText, command.scanFoundIndex + 1, command.pText);
			// 	if (command.scanFoundIndex > 0) {
			// 		int scanFoundLine = TextCountCharForward(pCode->pText, pCode->pActiveCaret->index, command.scanFoundIndex, '\n') + pCode->pActiveCaret->row;
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
				command.scanFoundIndex = TextFindTextForward(pText, mark.index, command.buffer);
				break;

			/* Utility Keys */
			case KEY_CTRL_MOD | KEY_S:
				LOG("Saving: %s", text.path);
				SaveFileText(text.path, text.pText);
				break;

			/* Character Delete Keys */
			case KEY_BACKSPACE: CodeBoxDeleteChar(pCode); pCode->mark.index--; break;
			case KEY_DELETE:    CodeBoxDeleteChar(pCode); break;

			/* Character Insert Keys */
			case KEY_ENTER: CodeBoxInsertChar(pCode, '\n'); break;
			case KEY_SPACE: CodeBoxInsertChar(pCode, ' '); break;
			case KEY_TAB:   CodeBoxInsertChar(pCode, '\t'); break;

			case 'A' ... 'Z': CodeBoxInsertChar(pCode, 'a' + (currentKey - KEY_A)); break;
			case '0' ... '9': CodeBoxInsertChar(pCode, currentKey); break;

			case (KEY_SHIFT_MOD | 'A') ... (KEY_SHIFT_MOD | 'Z'): CodeBoxInsertChar(pCode, currentKey); break;
			case KEY_KP_0 ... KEY_KP_9: CodeBoxInsertChar(pCode, '0' + (currentKey - KEY_KP_0)); break;

			case '`':  CodeBoxInsertChar(pCode, currentKey); break;
			case '-':  CodeBoxInsertChar(pCode, currentKey); break;
			case '=':  CodeBoxInsertChar(pCode, currentKey); break;
			case '[':  CodeBoxInsertChar(pCode, currentKey); break;
			case ']':  CodeBoxInsertChar(pCode, currentKey); break;
			case '\\': CodeBoxInsertChar(pCode, currentKey); break;
			case ';':  CodeBoxInsertChar(pCode, currentKey); break;
			case '\'': CodeBoxInsertChar(pCode, currentKey); break;
			case ',':  CodeBoxInsertChar(pCode, currentKey); break;
			case '.':  CodeBoxInsertChar(pCode, currentKey); break;
			case '/':  CodeBoxInsertChar(pCode, currentKey); break;

			case KEY_SHIFT_MOD | '1':  CodeBoxInsertChar(pCode, '!'); break;
			case KEY_SHIFT_MOD | '2':  CodeBoxInsertChar(pCode, '@'); break;
			case KEY_SHIFT_MOD | '3':  CodeBoxInsertChar(pCode, '#'); break;
			case KEY_SHIFT_MOD | '4':  CodeBoxInsertChar(pCode, '$'); break;
			case KEY_SHIFT_MOD | '5':  CodeBoxInsertChar(pCode, '%'); break;
			case KEY_SHIFT_MOD | '6':  CodeBoxInsertChar(pCode, '^'); break;
			case KEY_SHIFT_MOD | '7':  CodeBoxInsertChar(pCode, '&'); break;
			case KEY_SHIFT_MOD | '8':  CodeBoxInsertChar(pCode, '*'); break;
			case KEY_SHIFT_MOD | '9':  CodeBoxInsertChar(pCode, '('); break;
			case KEY_SHIFT_MOD | '0':  CodeBoxInsertChar(pCode, ')'); break;
			case KEY_SHIFT_MOD | '`':  CodeBoxInsertChar(pCode, '~'); break;
			case KEY_SHIFT_MOD | '-':  CodeBoxInsertChar(pCode, '_'); break;
			case KEY_SHIFT_MOD | '=':  CodeBoxInsertChar(pCode, '+'); break;
			case KEY_SHIFT_MOD | '[':  CodeBoxInsertChar(pCode, '{'); break;
			case KEY_SHIFT_MOD | ']':  CodeBoxInsertChar(pCode, '}'); break;
			case KEY_SHIFT_MOD | '\\': CodeBoxInsertChar(pCode, '|'); break;
			case KEY_SHIFT_MOD | ';':  CodeBoxInsertChar(pCode, ':'); break;
			case KEY_SHIFT_MOD | '\'': CodeBoxInsertChar(pCode, '"'); break;
			case KEY_SHIFT_MOD | ',':  CodeBoxInsertChar(pCode, '<'); break;
			case KEY_SHIFT_MOD | '.':  CodeBoxInsertChar(pCode, '>'); break;
			case KEY_SHIFT_MOD | '/':  CodeBoxInsertChar(pCode, '?'); break;

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
		/* 
		 * Window
		 */
		ClearBackground(RAYWHITE);
		const Vector2 hoverPos = GetMousePosition();

		/* 
		 * Code Box
		 */
		bool boxHover = CheckCollisionPointRec(hoverPos, textBox);
		Vector2 hoverBoxPos = GetWorldToBoxLocal(hoverPos, textBox);

		int hoverCol = hoverBoxPos.x / fontXSpacing;
		int hoverRow = hoverBoxPos.y / fontYSpacing;

		// DrawText(TextFormat("frameTime: %f/", GetFrameTime()), 512, 0, 20, GRAY);
		DrawText(TextFormat("col: %i >row: %i pCaret[0].index: %i hoverPos: x%.1f y%.1f c%i r%i", 
			pCode->mark.col, pCode->mark.row, pCode->pCarets[0].index, hoverBoxPos.x, hoverBoxPos.y, hoverCol, hoverRow), 0, 0, 20, DARKGRAY);

		DrawRectangleRec(textBox, COLOR_BACKGROUND);
		DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, boxHover ? COLOR_CARET : DARKGRAY);

		Color textColor = COLOR_TEXT;
		Color caretColor = BLANK;
		Vector2 scanFoundPosition = { -1, -1};
		CodeRow* pBoxRows = pCode->pBoxRows;
		int boxRowCount = pCode->boxRowCount;
		int boxColCount = pCode->boxColCount;
		int iChar = pCode->focusStartRowIndex;

		for (int iRow = 0; iRow < boxRowCount; ++iRow) {
			pBoxRows[iRow].startIndex = iChar;
			// int tabCount = 0;
			// for (int iCol = 0; iCol < boxColCount - (tabCount * tabWidth); ++iCol) {
			for (int iCol = 0; iCol < boxColCount; ++iCol) {
				
				Vector2 position = {
					// textBox.x + (fontXSpacing * iCol) + (tabCount * fontXSpacing * 4), 
					textBox.x + (fontXSpacing * iCol), 
					textBox.y + (fontYSpacing * iRow)
				};										
				Rectangle rect = {position.x, position.y, fontXSpacing, fontYSpacing};

				char c = text.pText[iChar];
				TextMeta m = text.pTextMeta[iChar];

				// if (iChar == text.pActiveCaret->index) {
				// 	caretColor = COLOR_CARET;
				// 	caretPosition = position;
				// 	DEBUG_LOG_ONCE("%s %d %d\n", string_TOKEN(m.token), m.QUOTE, Delimiter(c));
				// }

				if (iChar == command.scanFoundIndex) 
					scanFoundPosition = position;

				// #define GENERATE_BITMASK(_type) ((m._type > 0) << TEXT_META_TYPE_##_type ) | 
				// u16 mask = (u16)META_TYPES(GENERATE_BITMASK) 0;
				// #undef GENERATE_BITMASK

				#define COLOR_A(_color, _a) (Color){_color.r, _color.g, _color.b, _a}

				if (m.SCOPE_PAREN > 0) {
					DrawRectangleRec(rect, COLOR_A(WHITE, m.SCOPE_PAREN * 10));
				}

				// if (m.BLOCK_COMMENT) {
				// 	DrawRectangleRec(rect, COLOR_A(BLUE, 10));
				// }

				if (m.PREPROCESS) {
					DrawRectangleRec(rect, COLOR_A(COLOR_PREPROCESS, 20));
				}

				if (m.QUOTE) {
					DrawRectangleRec(rect, COLOR_A(COLOR_QUOTE, 50));
				}

				switch (c) 
				{
					case '\0':
						pBoxRows[iRow].endIndex = iChar;
						goto FinishDrawingText;

					/* Whitespace */
					case ' ':
						c =  '_';
						goto DrawChar;

					case '\t':
						// // Step more spaces for tab width
						// rect.width += (tabCount * fontXSpacing * tabWidth);
						// tabCount++;
						c = '-';
						goto DrawChar;

					case '\r':
					case '\v':
					case '\f':
					case '\n':
						pBoxRows[iRow].endIndex = iChar;
						iCol = boxColCount;
						c =  '\\';
						goto DrawChar;

				DrawChar:
					default:
						int codePointSize;
						int codePoint = GetCodepoint(&c, &codePointSize);
						Color color = TOKEN_COLOR[m.token];
						DrawTextCodepoint(font, codePoint, position, fontSize, color);
						iChar++;
						break;
				}									
			}
		}      
		FinishDrawingText:

		/*
		 * Hover
		 */
		Vector2 hoverSnapBoxPos = (Vector2){ (hoverCol * fontXSpacing), (hoverRow * fontYSpacing) };
		Vector2 hoverSnapPos    = GetBoxLocalToWorld(hoverSnapBoxPos, textBox);
		DrawRectangleRec((Rectangle){hoverSnapPos.x, hoverSnapPos.y, fontXSpacing, fontYSpacing}, COLOR_HOVER);

		if (input.lMouse) {
			pCode->mark.col = hoverCol;
			pCode->mark.row = hoverRow;
			CodeSyncMarkRowToCaret(pCode, 0);

			TextMeta m = pCode->pTextMeta[pCode->pCarets[0].index];
			char c = pCode->pText[pCode->pCarets[0].index];
			DEBUG_LOG_ONCE("%s %d %d\n", string_TOKEN(m.token), m.QUOTE, Delimiter(c));
		}

		/*
		 * Mark
		 */
		Vector2 markBoxPos = (Vector2){ (pCode->mark.col * fontXSpacing), ((pCode->mark.row - pCode->focusStartRow) * fontYSpacing) };
		Vector2 markPos    = GetBoxLocalToWorld(markBoxPos, textBox);
		DrawLineEx(
			(Vector2){markPos.x, markPos.y}, 
			(Vector2){markPos.x, markPos.y + fontYSpacing}, 
			2, GREEN);

		/*
		 * Caret
		 */
		Vector2 caretBoxPos = (Vector2){ (pCode->pCarets[0].col * fontXSpacing), ((pCode->pCarets[0].row - pCode->focusStartRow) * fontYSpacing) };
		Vector2 caretPos    = GetBoxLocalToWorld(caretBoxPos, textBox);
		DrawLineEx(
			(Vector2){caretPos.x, caretPos.y}, 
			(Vector2){caretPos.x, caretPos.y + fontYSpacing}, 
			4, COLOR_CARET);

		/*
		 * Command
		 */
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
				.x = caretPos.x - commandBoxExpand,
				.y = caretPos.y - commandBoxExpand,
				.width = fontXSpacing * command.bufferCount + commandBoxExpand * 2, 
				.height = fontYSpacing + commandBoxExpand * 2,
			};

			DrawRectangleRec(commandBoxRect, COLOR_COMMAND_BOX);
			DrawRectangleLinesEx(commandBoxRect, 2, WHITE);

			for (int iCommand = 0; iCommand < command.bufferCount; ++iCommand) {
				char c = command.buffer[iCommand];
				int codePointSize;
				int codePoint = GetCodepoint(&c, &codePointSize);
				Vector2 position = { caretPos.x + (fontXSpacing * iCommand), caretPos.y };								
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



