static int Test(int input) {
	int output = input;
	// comment
	const char* str = "Hello\n";
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
| Alt+Left/Right            | Word jump                                      |
| Ctrl+Up/Down              | Block jump                                     |
| Alt+Up/Down               | Block jump                                     |
| Up Down Left Right        | Move                                           |
| Ctrl+I J K L              | Move Alt                                       |
| Ctrl+G                    | Go to line number                              |
| Ctrl+M                    | Go to matching bracket                         |
| Alt+Alphanumeric Char     | Jump To Char. Jump To Next Ocurrance.          |
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

#define COUNT(_array)     (sizeof(_array) / sizeof(_array[0]))

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

#define HIDDEN_ADD 30

#define COLOR_CODE        (Color){ 216, 222, 233, 255 }
#define COLOR_PREPROCESS  (Color){ 198, 149, 198, 255 }
#define COLOR_CONTINUE    (Color){ 148,  99, 148, 255 }
#define COLOR_NUMBER      (Color){ 249, 174,  87, 255 }
#define COLOR_STRING      (Color){ 153, 199, 148, 255 } 
#define COLOR_COMMENT     (Color){ 166, 172, 185, 255 }  
#define COLOR_MACRO_NAME  (Color){ 249, 174,  87, 255 }
#define COLOR_OPERATOR    (Color){ 249, 123,  87, 255 }
#define COLOR_BACKGROUND  (Color){  48,  56,  65, 255 } 
#define COLOR_WHITESPACE  (Color){  38,  46,  55, 255 } 
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
	DEF("define") \
	DEF("include")

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

#define TOKEN_HASH(_h, _c) (_h + (_h << 5) + (_c))  

static tok_k TokenKeyRange(const char *str, int iStart, int iEnd)
{
	tok_k hash = 0;
	for (int i = iStart; i <= iEnd; ++i) hash = TOKEN_HASH(hash, str[i]);
	return hash & TOKEN_MASK;
}

static tok_k TokenKey(const char *str)
{
	tok_k hash = 0; utf8 c;
	while ((c = *str++)) hash = TOKEN_HASH(hash, c);
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

/*
 * CodeBox
 */
#define MAX_INPUT_CHARS      2048
#define TEXT_BUFFER_CAPACITY 64000

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

#define CARET_COUNT 128
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

	char*           pText;
	TOKEN* pToken;
	TextMeta*       pTextMeta;

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

		case '#': case ',':	case '.': case ';':	case '@': case '\\':
			return true;

		default:
			return false;
	}
}

static RESULT ProcessMeta(CodeBox* pCode) {
	const int   count = pCode->bufferCount;
	const char* pBuf  = pCode->pText; 
	TextMeta*   pMeta = pCode->pTextMeta;

	int iC    = 0;
	int iStrt = 0;

	// Prev Char, Current Char, Next Char
	char pc = '\0';
	char c  = '\0';
	char nc = pBuf[0];

	// Prev Delim, Current Delim, Next Delim
	bool pd = true;
	bool d  = true;
	bool nd = Delimiter(nc);

	TextMeta meta; ZERO_P(&meta);

processChar:
	pc = c;	c  = nc; nc = pBuf[iC + 1];
	pd = d;	d  = nd; nd = Delimiter(nc);

	if (UNLIKELY(c == '\0')) goto error;

	bool comment    = meta.BLOCK_COMMENT || meta.LINE_COMMENT;
	bool quote      = meta.QUOTE;
	bool preprocess = meta.PREPROCESS;
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
					goto setMetaNext;

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
					goto setMetaNext;
			}
		}

		/* Parse Quote */
		case (true << 1): {
			switch (c) 
			{
				case '\\':
					meta.token = TOKEN_ESCAPE;
					pMeta[iC]      = meta;
					pMeta[iC + 1]  = meta;
					meta.token = TOKEN_TEXT;
					goto nextNext;

				case '"':
					meta.token = TOKEN_QUOTE;
					pMeta[iC]  = meta;
					meta.token = TOKEN_NONE;
					meta.QUOTE = 0;
					goto next;

				default:
					goto setMetaNext;
			}
		}

		/* Parse Text */
		default: {
			// TODO can this be melded into the switch below?
			u8 delimitTransition = pd | d << 1 | nd << 2;
			switch (delimitTransition) 
			{
				case true  | false << 1 | false << 2:
					iStrt = iC;
					break;

				case true  | false << 1 | true  << 2:
					iStrt = iC;
					FALLTHROUGH;

				case false | false << 1 | true  << 2:
					int iEnd = iC;
					int len  = iEnd + 1 - iStrt;
					tok_k t  = TokenKeyRange(pBuf, iStrt, iEnd);
					meta.token = TOKEN_MAP[t];
					bool isPreprocess = (meta.token == TOKEN_PREPROCESS);
					meta.PREPROCESS = isPreprocess | meta.PREPROCESS;
					for (int i = iStrt - isPreprocess; i < iEnd; ++i) {
						pMeta[i].token      = meta.token;
						pMeta[i].PREPROCESS = meta.PREPROCESS;
						pMeta[i].iTokenStartOffset = i - iStrt;
						pMeta[i].iTokenEndOffset   = iEnd - i;
					}
					break;
			}

			switch (c) 
			{
			#define INCREMENT_CASE(_add, _sub, _scope, _token) \
				case _add: \
					meta._scope += (meta._scope < TOKEN_MAX_INCREMENT); \
					meta.token = _token; \
					goto setMetaNext; \
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

				case '_':
				case 'a'...'z':
				case 'A'...'Z':
				case '0'...'9':
					goto setMetaNext;

				/* Whitespace */
				case '\n':
					if (meta.PREPROCESS && pc != '\\') {
						meta.token = TOKEN_WHITESPACE;
						pMeta[iC]  = meta;
						meta.PREPROCESS = 0;
						goto next;
					}
					meta.token = TOKEN_WHITESPACE;
					goto setMetaNext;

				case ' ' :
				case '\0':
				case '\t':
				case '\r': // Carriage return
				case '\v': // Vertical tab
				case '\f': // Form feed
					meta.token = TOKEN_WHITESPACE;
					goto setMetaNext;

				/* Comment or Operator */
				case '/':
					switch (nc) 
					{
						case '/':
							meta = (TextMeta){.token = TOKEN_COMMENT, .LINE_COMMENT = 1, .BLOCK_COMMENT = meta.BLOCK_COMMENT};
							goto setMetaNext;
						case '*':
							meta.token = TOKEN_COMMENT;
							meta.BLOCK_COMMENT = 1;
							goto setMetaNext;
						default:
							meta.token = TOKEN_OPERATOR;
							goto setMetaNext;
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
					goto setMetaNext;

				/* Quotes */
				case '"':
					meta.token = TOKEN_QUOTE;
					meta.QUOTE = 1; 
					pMeta[iC] = meta; 
					meta.token = TOKEN_TEXT;
					goto next;

				case '\'':
				case '`':
					meta.token = TOKEN_QUOTE;
					goto setMetaNext;

				/* Preprocess */
				case '#':
					meta.token = TOKEN_PREPROCESS;
					goto setMetaNext;

				case '\\':
					if (meta.PREPROCESS && nc == '\n') {
						meta.token = TOKEN_CONTINUE;
						pMeta[iC]  = meta;
						meta.token = TOKEN_WHITESPACE;
						pMeta[iC + 1]  = meta;
						meta.token = TOKEN_PREPROCESS;
						goto nextNext;
					}
					goto setMetaNext;

				case ',':
				case '.':
				case ';':
				case '@':
					meta.token = TOKEN_NONE;
					goto setMetaNext;
			}
		}
	} // switch (parseComment | parseQuote << 1) 

nextNext:
	++iC;
	pc = c;	c  = nc; nc = pBuf[iC + 1];
	pd = d;	d  = nd; nd = Delimiter(nc);
	goto next;

setMetaNext:
	pMeta[iC] = meta;
	goto next;

next:
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
static int TextFindCharBackward(const char* text, int index, char c) {
	while (index >= 0 && text[index] != c) index--;    
	return index;
}

// Find specified char. 
static int TextFindCharForward(const char* pText, int index, char c) {
	while (pText[index] != c && pText[index] != '\0') index++;    
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
static int TextFindCharSkipForward(const char* pText, char find, int skipCount) {
	int index = 0;
	while (pText[index] != '\0' && skipCount > 0) {
		if (pText[index] == find) skipCount--;   
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
static bool TextFindCountCharForward(const char* pText, char searchChar, char countChar, int* pFoundIndex, int *pCount) {
	int index = *pFoundIndex, count = *pCount; 
	char c;	do {
		c = pText[index++];
		count += c == countChar;
	} while (c && c != searchChar);
	*pFoundIndex = index - 1; *pCount = count;
	return c == searchChar;
}

// Find char index and also count occurense of another char during scan.
static bool TextFindCountCharBackward(const char* pText, char searchChar, char countChar, int* pFoundIndex, int *pCount) {
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
static inline int CodeBoxIndexCollumn(const CodeBox* pCode, int index) {
	int lineStartIndex = TextFindCharBackward(pCode->pText, index - 1, '\n') + endCharLength;
	return index - lineStartIndex;
}

// The index of caret on current line.
static inline int CodeBoxCaretCollumn(const CodeBox* pCode) {
	return CodeBoxIndexCollumn(pCode, pCode->caretIndex);
}

// Line given index is on
static inline int CodeBoxIndexRow(const CodeBox* pCode, int index) {
	return TextCountCharForward(pCode->pText, 0, index, '\n');
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
		pCode->focusStartRowIndex = TextFindCharSkipForward(pCode->pText, '\n', pCode->focusStartRow);
	}

	int yMax = yMin + charCapacity;
	if (toRow > yMax) {
		pCode->focusStartRow = toRow - charCapacity;
		pCode->focusStartRowIndex = TextFindCharSkipForward(pCode->pText, '\n', pCode->focusStartRow);
	}
} 

static void CodeBoxIncrementFocusRow(CodeBox* pCode, int increment) {
	pCode->focusStartRow -= increment;
	pCode->focusStartRowIndex = TextFindCharSkipForward(pCode->pText, '\n', pCode->focusStartRow);
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

static void CodeBoxInsertCharAtIndex(CodeBox* pCode, int index, char c) {
	memmove(pCode->pText + index + 1, pCode->pText + index, pCode->bufferCount - index - 1);
	pCode->dirty = true;
	pCode->pText[index] = c;
	pCode->bufferCount++;
	pCode->caretIndex++;
	pCode->caretCollumn++;
	pCode->newLineCount += c == '\n';
}

static inline void CodeBoxInsertChar(CodeBox* pCode, char c) {
	CodeBoxInsertCharAtIndex(pCode, pCode->caretIndex, c);
}

static void CodeBoxDeleteCharAtIndex(CodeBox* pCode, int index) {
	if (pCode->bufferCount == 0) return;
	memmove(pCode->pText + index - 1, pCode->pText + index, pCode->bufferCount - index);
	pCode->newLineCount -= pCode->pText[index - 1] == '\n';
	pCode->bufferCount--;
}

static inline void CodeBoxDeleteChar(CodeBox* pCode) {
	CodeBoxDeleteCharAtIndex(pCode, pCode->caretIndex);
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

		text.pText   = XMALLOC_ALIGNED(CACHE_LINE, TEXT_BUFFER_CAPACITY * sizeof(char));
		text.pToken    = XMALLOC_ALIGNED(CACHE_LINE, TEXT_BUFFER_CAPACITY * sizeof(TOKEN));
		text.pTextMeta = XMALLOC_ALIGNED(CACHE_LINE, TEXT_BUFFER_CAPACITY * sizeof(TextMeta));

		memset(text.pText,   0, TEXT_BUFFER_CAPACITY * sizeof(char));
		memset(text.pToken,    0, TEXT_BUFFER_CAPACITY * sizeof(TOKEN));
		memset(text.pTextMeta, 0, TEXT_BUFFER_CAPACITY * sizeof(TextMeta));

		memcpy(text.pText, loadedFile, text.bufferCount + 1);
		free(loadedFile);

		ProcessMeta(&text);
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
	const char* pBuf = pCode->pText;
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
				if (pCode->pText[pCode->caretIndex] == '\n') {
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
				if (pCode->pText[pCode->caretIndex] == '\n') {
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
				int upLineEnd     = TextFindCharBackward(pCode->pText, pCode->caretIndex - 1, '\n');     	   
				int upLineStart   = TextFindCharBackward(pCode->pText, upLineEnd - 1, '\n') + endCharLength;
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
				int startIndex      = pCode->pText[pCode->caretIndex] == '\n' ? pCode->caretIndex - endCharLength : pCode->caretIndex;
				int blockStartIndex = TextFindTextBackward(pCode->pText, startIndex, "\n\n");
				int blockEndIndex   = TextNegateFindCharBackward(pCode->pText, blockStartIndex, '\n');  
				int newCaretIndex   = blockEndIndex + 1;
				CodeBoxUpdateCaretIndex(pCode, newCaretIndex);
				CodeBoxFocusCaret(pCode);
				break;
			}

			/* Move Down Keys */
			case KEY_DOWN: 
			case KEY_S | KEY_ALT_MOD: {
				int currentLineEnd = TextFindCharForward(pCode->pText, pCode->caretIndex, '\n');
				int downLineStart  = currentLineEnd + endCharLength;
				int downLineEnd    = TextFindCharForward(pCode->pText, downLineStart, '\n');
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
				int blockEndIndex   = TextFindTextForward(pCode->pText, pCode->caretIndex, "\n\n");
				int blockStartIndex = TextNegateFindCharForward(pCode->pText, blockEndIndex, '\n');
				blockStartIndex = TextNegateFindCharForward(pCode->pText, blockStartIndex, ' ');
				blockStartIndex = TextNegateFindCharForward(pCode->pText, blockStartIndex, '\t');
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

			// 	command.scanFoundIndex = TextFindTextForward(pCode->pText, command.scanFoundIndex + 1, command.pText);
			// 	if (command.scanFoundIndex > 0) {
			// 		int scanFoundLine = TextCountCharForward(pCode->pText, pCode->caretIndex, command.scanFoundIndex, '\n') + pCode->caretRow;
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
				command.scanFoundIndex = TextFindTextForward(pCode->pText, pCode->caretIndex, command.buffer);
				break;

			/* Utility Keys */
			case KEY_CTRL_MOD | KEY_S:
				LOG("Saving: %s", text.path);
				SaveFileText(text.path, text.pText);
				break;

			/* Character Delete Keys */
			case KEY_BACKSPACE: CodeBoxDeleteChar(pCode); pCode->caretIndex--; break;
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

		float frameTime = GetFrameTime();
		DrawText(TextFormat("frameTime: %f/", frameTime), 512, 0, 20, GRAY);
		DrawText(TextFormat("caretCollumn: %i caretRow: %i caretIndex: %i", pCode->caretCollumn, pCode->caretRow, pCode->caretIndex, pCode->focusStartRow), 0, 0, 20, DARKGRAY);

		/* 
		 * Code Box
		 */
		DrawRectangleRec(textBox, COLOR_BACKGROUND);
		DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

		Color textColor = COLOR_TEXT;
		Color caretColor = BLANK;
		Vector2 mousePosition = GetMousePosition();
		Vector2 caretPosition = { -1, -1};
		Vector2 scanFoundPosition = { -1, -1};;
		int iChar = pCode->focusStartRowIndex;

		for (int y = 0; y < yCharCapacity; ++y) {
			int tabCount = 0;
			for (int x = 0; x < xCharCapacity - (tabCount * tabWidth); ++x) {
				
				Vector2 position = {
					textBox.x + (fontXSpacing * x) + (tabCount * fontXSpacing * 4), 
					textBox.y + (fontYSpacing * y)
				};										
				Rectangle rect = {position.x, position.y, fontXSpacing, fontYSpacing};

				char c = text.pText[iChar];
				TextMeta m = text.pTextMeta[iChar];

				if (iChar == text.caretIndex) {
					caretColor = ORANGE;
					caretPosition = position;
					DEBUG_LOG_ONCE("%s %d %d\n", string_TOKEN(m.token), m.QUOTE, Delimiter(c));
				}

				if (iChar == command.scanFoundIndex) 
					scanFoundPosition = position;
				
				if (input.lMouse && CheckCollisionPointRec(mousePosition, rect)) {
					float xDiff = mousePosition.x - (rect.x + (rect.width / 2));
					text.caretIndex = xDiff > 0 ? iChar + 1 : iChar;
					text.caretCollumn = CodeBoxCaretCollumn(&text);
				}

				// #define GENERATE_BITMASK(_type) ((m._type > 0) << TEXT_META_TYPE_##_type ) | 
				// u16 mask = (u16)META_TYPES(GENERATE_BITMASK) 0;
				// #undef GENERATE_BITMASK

				#define COLOR_A(_color, _a) (Color){_color.r, _color.g, _color.b, _a}

				// if (m.SCOPE_PAREN > 0) {
				// 	DrawRectangleRec(rect, COLOR_A(WHITE, m.SCOPE_PAREN * 10));
				// }

				// if (m.BLOCK_COMMENT) {
				// 	DrawRectangleRec(rect, COLOR_A(BLUE, 10));
				// }

				if (m.PREPROCESS) {
					DrawRectangleRec(rect, COLOR_A(COLOR_PREPROCESS, 50));
				}

				if (m.QUOTE) {
					DrawRectangleRec(rect, COLOR_A(COLOR_QUOTE, 50));
				}

				switch (c) 
				{
					case '\0':
						goto FinishDrawingText;

					/* Whitespace */
					case ' ':
						c =  '_';
						goto DrawChar;

					case '\t':
						// Step more spaces for tab width
						rect.width += (tabCount * fontXSpacing * tabWidth);
						tabCount++;
						c = '-';
						goto DrawChar;

					case '\r':
					case '\v':
					case '\f':
					case '\n':
						// Check click on entire line
						rect.width = textBox.width - rect.width;
						if (input.lMouse && CheckCollisionPointRec(mousePosition, rect)){
							text.caretIndex = iChar;
							text.caretCollumn = CodeBoxCaretCollumn(&text);
						}

						x = xCharCapacity;
						c =  '\\';
						goto DrawChar;

					default:
					DrawChar: {
						int codePointSize;
						int codePoint = GetCodepoint(&c, &codePointSize);
						Color color = TOKEN_COLOR[m.token];
						DrawTextCodepoint(font, codePoint, position, fontSize, color);
						iChar++;
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



