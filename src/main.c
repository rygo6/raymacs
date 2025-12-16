void T() {
	int a =!1;
	int b = 1||0;
	a--;
}

static double Test(int input) {
	const char* str = "Hello\'\n";
	int output = input;
	/* comment */
	char tick = '"';
	int vala = 10 + 2;
	int valb = 10 / 2;
	if (vala-->= 0) 
		vala >>= 2;
	return output;
}

#define CONCAT(a, b) a  ##  b #a

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
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "raylib.h"
#include "raymath.h"

// #undef true
// #undef false

// #define true  (-1)
// #define false (0)

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

#define typeof __typeof__

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

#define FILL(_arr, _value, _count) \
	for (typeof(_count) i = 0; i < (_count); ++i) { (_arr)[i] = (_value); }

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

#define XCALLOC(_count, _type) \
({ \
	void* p = calloc(_count, sizeof(_type)); \
	if (p == NULL) PANIC("XCALLOC FAIL!"); \
	p; \
})

#define ZERO_P(_p) memset((void*)(_p), 0, sizeof(*_p))

/*
 * Validation
 */
#define STATIC_ASSERT(...) _Static_assert(__VA_ARGS__)

#ifdef NDEBUG
	#define ASSERT(_condition, _format, ...)
#else
	#define ASSERT(_condition, _format, ...) ({ \
		if (UNLIKELY(!(_condition))) \
			fprintf(stderr, "\n" ANSI_RED __FILE__ ":%d ASSERT! " #_condition " " _format "\n" ANSI_RESET, __LINE__, ##__VA_ARGS__); \
		assert((_condition) && #_condition); \
	})
#endif

#define PANIC(_format, ...) \
({ \
	fprintf(stderr, "\n" ANSI_RED __FILE__ ":%d PANIC! " _format "\n" ANSI_RESET, __LINE__, ##__VA_ARGS__); \
	__builtin_trap(); \
})

// TODO
#define CHECK(_command)
#define TRY(_command)

#define REQUIRE(_command) \
({ \
	RESULT _result = _command; \
	if (UNLIKELY(_result != RESULT_SUCCESS)) PANIC(#_command " == %s\n", string_RESULT(_result)); \
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

#define DEF_TOK_CATEGORY(DEF) \
	DEF(TOK_CATEGORY_NONE) \
	DEF(TOK_CATEGORY_TYPE) \
	DEF(TOK_CATEGORY_KEYWORD) \
	DEF(TOK_CATEGORY_WHITESPACE) \
	DEF(TOK_CATEGORY_OPERATOR) \
	DEF(TOK_CATEGORY_PREPROCESS) \
	DEF(TOK_CATEGORY_CONTINUE) \
	DEF(TOK_CATEGORY_SCOPE) \
	DEF(TOK_CATEGORY_QUOTE) \
	DEF(TOK_CATEGORY_TEXT) \
	DEF(TOK_CATEGORY_ESCAPE) \
	DEF(TOK_CATEGORY_COMMENT) \
	DEF(TOK_CATEGORY_COUNT)
DEF_ENUM(TOK_CATEGORY);

#define FIND_CARET_COLOR     (Color){   0, 255,   0, 255 }
#define FIND_HIGHLIGHT_COLOR (Color){   0, 255,   0, 64  }
#define COLOR_COMMAND_BOX    (Color){  20,  20,   2, 200 }
#define COLOR_TEXT_BOX       (Color){  37,  37,  38, 255 }
#define COLOR_CARET       ORANGE
#define COLOR_HOVER       (Color){   0, 255,   0, 64  }
#define COLOR_CODE        (Color){ 216, 222, 233, 255 }
#define COLOR_PREPROCESS  (Color){ 182, 160, 191, 255 }
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
#define COLOR_SCOPE       (Color){ 255, 196, 202, 255 } 
#define COLOR_KEYWORD     (Color){ 236,  96, 102, 255 }
#define COLOR_TYPE        (Color){ 198, 149, 198, 255 }

/*
 * C11 Lexer
 */
static Color TOK_CATEGORY_COLOR[] = {
	[TOK_CATEGORY_NONE]       = COLOR_CODE,
	[TOK_CATEGORY_TYPE]       = COLOR_TYPE,
	[TOK_CATEGORY_KEYWORD]    = COLOR_KEYWORD,
	[TOK_CATEGORY_WHITESPACE] = COLOR_WHITESPACE,
	[TOK_CATEGORY_OPERATOR]   = COLOR_OPERATOR,
	[TOK_CATEGORY_PREPROCESS] = COLOR_PREPROCESS,
	[TOK_CATEGORY_CONTINUE]   = COLOR_CONTINUE,
	[TOK_CATEGORY_SCOPE]      = COLOR_SCOPE,
	[TOK_CATEGORY_QUOTE]      = COLOR_QUOTE,
	[TOK_CATEGORY_TEXT]       = COLOR_TEXT,
	[TOK_CATEGORY_ESCAPE]     = COLOR_ESCAPE,
	[TOK_CATEGORY_COMMENT]    = COLOR_COMMENT,
};
STATIC_ASSERT(COUNT(TOK_CATEGORY_COLOR) == TOK_CATEGORY_COUNT);

#define DEF_PREPROCESS_TOKS(DEF) \
	DEF("#include", TOK_PP_INCLUDE) \
	DEF("#define",  TOK_PP_DEFINE) \
	DEF("#ifndef",  TOK_PP_IFNDEF) \
	DEF("#ifdef",   TOK_PP_IFDEF) \
	DEF("#endif",   TOK_PP_ENDIF) \
	DEF("#undef",   TOK_PP_UNDEF) \
	DEF("#elif",    TOK_PP_ELIF) \
	DEF("#else",    TOK_PP_ELSE) \
	DEF("#error",   TOK_PP_ERROR) \
	DEF("#pragma",  TOK_PP_PRAGMA) \
	DEF("#line",    TOK_PP_LINE) \
	DEF("#if",      TOK_PP_IF) \
	DEF("##",       TOK_PP_HASH_HASH) \
	DEF("#",        TOK_PP_HASH)

#define DEF_KEYWORD_TOKS(DEF) \
	DEF("_Static_assert", TOK_STATIC_ASSERT) \
	DEF("_Thread_local",  TOK_THREAD_LOCAL) \
	DEF("_Imaginary",     TOK_IMAGINARY) \
	DEF("_Noreturn",      TOK_NORETURN) \
	DEF("_Complex",       TOK_COMPLEX) \
	DEF("_Generic",       TOK_GENERIC) \
	DEF("_Alignof",       TOK_ALIGNOF) \
	DEF("_Alignas",       TOK_ALIGNAS) \
	DEF("_Atomic",        TOK_ATOMIC) \
	DEF("continue",       TOK_CONTINUE) \
	DEF("volatile",       TOK_VOLATILE) \
	DEF("register",       TOK_REGISTER) \
	DEF("restrict",       TOK_RESTRICT) \
	DEF("typedef",        TOK_TYPEDEF) \
	DEF("default",        TOK_DEFAULT) \
	DEF("typeof",         TOK_TYPEOF) \
	DEF("switch",         TOK_SWITCH) \
	DEF("static",         TOK_STATIC) \
	DEF("sizeof",         TOK_SIZEOF) \
	DEF("return",         TOK_RETURN) \
	DEF("inline",         TOK_INLINE) \
	DEF("extern",         TOK_EXTERN) \
	DEF("while",          TOK_WHILE) \
	DEF("const",          TOK_CONST) \
	DEF("break",          TOK_BREAK) \
	DEF("goto",           TOK_GOTO) \
	DEF("else",           TOK_ELSE) \
	DEF("case",           TOK_CASE) \
	DEF("auto",           TOK_AUTO) \
	DEF("for",            TOK_FOR) \
	DEF("if",             TOK_IF) \
	DEF("do",             TOK_DO)

#define DEF_TYPE_TOKS(DEF) \
	DEF("unsigned", TOK_UNSIGNED) \
	DEF("struct",   TOK_STRUCT) \
	DEF("signed",   TOK_SIGNED) \
	DEF("double",   TOK_DOUBLE) \
	DEF("float",    TOK_FLOAT) \
	DEF("short",    TOK_SHORT) \
	DEF("_Bool",    TOK_BOOL) \
	DEF("union",    TOK_UNION) \
	DEF("void",     TOK_VOID) \
	DEF("long",     TOK_LONG) \
	DEF("char",     TOK_CHAR) \
	DEF("enum",     TOK_ENUM) \
	DEF("int",      TOK_INT)

#define DEF_STDTYPE_TOKS(DEF) \
	DEF("ptrdiff_t", TOK_PTRDIFF_T) \
	DEF("uint64_t",  TOK_UINT64_T) \
	DEF("uint32_t",  TOK_UINT32_T) \
	DEF("uint16_t",  TOK_UINT16_T) \
	DEF("int64_t",   TOK_INT64_T) \
	DEF("int32_t",   TOK_INT32_T) \
	DEF("int16_t",   TOK_INT16_T) \
	DEF("wchar_t",   TOK_WCHAR_T) \
	DEF("uint8_t",   TOK_UINT8_T) \
	DEF("size_t",    TOK_SIZE_T) \
	DEF("int8_t",    TOK_INT8_T)

#define DEF_WHITESPACE_TOKS(DEF) \
	DEF(" ",  TOK_SPACE) \
	DEF("\t", TOK_TAB) \
	DEF("\n", TOK_NEWLINE) \
	DEF("\r", TOK_CARRIAGE_RETURN) \
	DEF("\f", TOK_FORM_FEED) \
	DEF("\v", TOK_VERTICAL_TAB)

#define DEF_GROUPING_TOKS(DEF) \
	DEF("(", TOK_PAREN_OPEN) \
	DEF(")", TOK_PAREN_CLOSE) \
	DEF("{", TOK_BRACE_OPEN) \
	DEF("}", TOK_BRACE_CLOSE) \
	DEF("[", TOK_BRACKET_OPEN) \
	DEF("]", TOK_BRACKET_CLOSE)

#define DEF_ACCESS_TOKS(DEF) \
	DEF("->", TOK_ARROW) \
	DEF(".",  TOK_DOT)

#define DEF_STATEMENT_TOKS(DEF) \
	DEF(";", TOK_SEMICOLON) \
	DEF(",", TOK_COMMA) \
	DEF(":", TOK_COLON)

#define DEF_ARITHMETIC_TOKS(DEF) \
	DEF("++", TOK_INCREMENT) \
	DEF("--", TOK_DECREMENT) \
	DEF("+",  TOK_PLUS) \
	DEF("-",  TOK_MINUS) \
	DEF("*",  TOK_STAR) \
	DEF("/",  TOK_SLASH) \
	DEF("%",  TOK_PERCENT)

#define DEF_BITWISE_TOKS(DEF) \
	DEF("<<=", TOK_LEFT_SHIFT_ASSIGN) \
	DEF(">>=", TOK_RIGHT_SHIFT_ASSIGN) \
	DEF("<<",  TOK_LEFT_SHIFT) \
	DEF(">>",  TOK_RIGHT_SHIFT) \
	DEF("&",   TOK_AMPERSAND) \
	DEF("|",   TOK_PIPE) \
	DEF("^",   TOK_CARET) \
	DEF("~",   TOK_TILDE)

#define DEF_LOGICAL_TOKS(DEF) \
	DEF("&&", TOK_LOGICAL_AND) \
	DEF("||", TOK_LOGICAL_OR) \
	DEF("!",  TOK_EXCLAMATION)

#define DEF_COMPARISON_TOKS(DEF) \
	DEF("<=", TOK_LESS_EQUAL) \
	DEF(">=", TOK_GREATER_EQUAL) \
	DEF("==", TOK_EQUAL_EQUAL) \
	DEF("!=", TOK_NOT_EQUAL) \
	DEF("<",  TOK_LESS) \
	DEF(">",  TOK_GREATER)

#define DEF_ASSIGNMENT_TOKS(DEF) \
	DEF("+=",  TOK_PLUS_ASSIGN) \
	DEF("-=",  TOK_MINUS_ASSIGN) \
	DEF("*=",  TOK_STAR_ASSIGN) \
	DEF("/=",  TOK_SLASH_ASSIGN) \
	DEF("%=",  TOK_PERCENT_ASSIGN) \
	DEF("&=",  TOK_AMPERSAND_ASSIGN) \
	DEF("|=",  TOK_PIPE_ASSIGN) \
	DEF("^=",  TOK_CARET_ASSIGN) \
	DEF("=",   TOK_ASSIGN)

#define DEF_OTHER_OPERATOR_TOKS(DEF) \
	DEF("?",   TOK_QUESTION) \
	DEF("...", TOK_ELLIPSIS)

#define DEF_STRING_DELIMITER_TOKS(DEF) \
	DEF("\"", TOK_DOUBLE_QUOTE) \
	DEF("'",  TOK_SINGLE_QUOTE)

#define DEF_COMMENT_DELIMITER_TOKS(DEF) \
	DEF("/*", TOK_COMMENT_OPEN) \
	DEF("*/", TOK_COMMENT_CLOSE) \
	DEF("//", TOK_LINE_COMMENT)

#define DEF_ALL_CATEGORY_TOKS(DEF) \
	DEF(PREPROCESS_TOKS) \
	DEF(KEYWORD_TOKS) \
	DEF(TYPE_TOKS) \
	DEF(STDTYPE_TOKS) \
	DEF(WHITESPACE_TOKS) \
	DEF(GROUPING_TOKS) \
	DEF(ACCESS_TOKS) \
	DEF(STATEMENT_TOKS) \
	DEF(ARITHMETIC_TOKS) \
	DEF(BITWISE_TOKS) \
	DEF(LOGICAL_TOKS) \
	DEF(COMPARISON_TOKS) \
	DEF(ASSIGNMENT_TOKS) \
	DEF(OTHER_OPERATOR_TOKS) \
	DEF(STRING_DELIMITER_TOKS) \
	DEF(COMMENT_DELIMITER_TOKS)

/*
 * Lexer
 */ 
#define DEF_ENUM_TOK_DEFINITION(_name, _tok) _tok,
#define DEF_ALL_ENUM_TOK_DEFINITION(_cat) DEF_##_cat(DEF_ENUM_TOK_DEFINITION)
typedef enum TOK { 
	TOK_NONE,
	DEF_ALL_CATEGORY_TOKS(DEF_ALL_ENUM_TOK_DEFINITION) 
	TOK_COUNT,
} TOK;

#define DEF_LEN_TOK_DEFINITION(_name, _tok) [_tok] = sizeof(_name) - 1,
#define DEF_ALL_LEN_TOK_DEFINITION(_cat) DEF_##_cat(DEF_LEN_TOK_DEFINITION)
static const int TOK_NAME_LEN[] = { 
	DEF_ALL_CATEGORY_TOKS(DEF_ALL_LEN_TOK_DEFINITION) 
};

#define DEF_STRING_TOK_DEFINITION(_name, _tok) case _tok: return #_tok " " #_name;
#define DEF_ALL_STRING_TOK_DEFINITION(_cat) DEF_##_cat(DEF_STRING_TOK_DEFINITION)
static const char* string_TOK(TOK tok) {
	switch(tok) {
		case TOK_NONE: return "TOK_NONE";
		DEF_ALL_CATEGORY_TOKS(DEF_ALL_STRING_TOK_DEFINITION)
		default: return "TOK N/A";
	}
}

typedef struct TokenDefintion {
	const char* name;
	TOK tok;
} TokenDefintion;
#define DEF_ARRAY_TOK_DEFINITION(_name, _token) (TokenDefintion){ _name, _token },
#define DEF_ALL_ARRAY_TOK_DEFINITION(_cat)  static const TokenDefintion _cat[] = { DEF_##_cat(DEF_ARRAY_TOK_DEFINITION) };
DEF_ALL_CATEGORY_TOKS(DEF_ALL_ARRAY_TOK_DEFINITION)

typedef u32 tok_hash;
typedef u8  token_hash_prefix;
typedef struct TokenKey {
	tok_hash a : 12;
	tok_hash b : 12;
	u8 len       : 4;
} TokenKey;
#define MAP_CAPACITY 4096
#define MAP_PREFIX_CAPACITY 256
#define MAP_PAGE_CAPACITY 16
#define TOK_MAX_SIZE 16
#define TOK_MAX_END  15
#define TOK_MASK 0x0FFF // 12 bit mask

static TOK TOK_MAP_A[MAP_PAGE_CAPACITY][MAP_CAPACITY];
static TOK TOK_MAP_B[MAP_PAGE_CAPACITY][MAP_CAPACITY];

#define TOK_HASH_SEED 0
#define TOK_HASH_DJB2(_h, _c)  ((((_h) << 5) + (_h) + (_c)) * 33) 
#define TOK_HASH_FNV1A(_h, _c) (((_h) ^ (_c)) * 16777619UL)

/* Calc token key hashes via range or null termination */
static TokenKey CalcTokenKey(const char *str, int iStart, int iEnd)
{
	int range = iEnd - iStart;
	str += iStart; char c; u8 len = 0;
	tok_hash ha = TOK_HASH_SEED; 
	tok_hash hb = TOK_HASH_SEED; 
	while ((c = *str++) && range-->= 0) {
		ha = TOK_HASH_DJB2(ha, c); hb = TOK_HASH_FNV1A(hb, c); len++;
	}
	return (TokenKey){ ha, hb, len };
}

static RESULT ContructTokenMap(TOK category, int tokenCount, const TokenDefintion* tokens)
{
	for (int iTkn = 0; iTkn < tokenCount; iTkn++) {
		TokenKey k = CalcTokenKey(tokens[iTkn].name, 0, TOK_MAX_END);
		TOK tokA = TOK_MAP_A[k.len][k.a];
		TOK tokB = TOK_MAP_B[k.len][k.b];
		if (tokA != TOK_NONE || tokB != TOK_NONE) {
			LOG_ERR("Type Hash Collision! %s %d %d %d %s\n", tokens[iTkn].name, k.a, k.b, k.len, string_TOK(category));
			return RESULT_COLLISION;
		}
		TOK_MAP_A[k.len][k.a] = category;
		TOK_MAP_B[k.len][k.b] = category;
		LOG("%s %d %d %d %s\n", tokens[iTkn].name, k.a, k.b, k.len, string_TOK(category));
	}
	return RESULT_SUCCESS;
}

typedef struct MapTok {
	TOK      tok;
	tok_hash hash; // full hash
} MapTok;
static MapTok TOK_MAP[MAP_PAGE_CAPACITY][MAP_CAPACITY];


static tok_hash CalcTokKey(const char *str, int iStart, int iEnd)
{
	tok_hash h = str[iStart];  // if len is 1 then hash is ascii code
	str += iStart + 1;  // do not hash first char
	int range = iEnd - iStart;
	char c; while ((c = *str++) && range-->= 0) h = TOK_HASH_DJB2(h, c);
	return h;
}

#define TOK_MAP_HASH_MASK 0x0FFF // 12 bit mask = 4096
#define TOK_MAP_PAGE_MASK 0x000F //  4 bit mask = 16
static RESULT ContructTokMap(int tokenCount, const TokenDefintion* tokens)
{
	for (int iTkn = 0; iTkn < tokenCount; iTkn++) {
		TOK tok = tokens[iTkn].tok;
		int len = TOK_NAME_LEN[tok];
		tok_hash hash = CalcTokKey(tokens[iTkn].name, 0, len - 1);
		u16 k = hash & TOK_MAP_HASH_MASK;
		u8  p = len & TOK_MAP_PAGE_MASK;
		MapTok* pMapTok = &TOK_MAP[p][k];
		if (pMapTok->tok != TOK_NONE) {
			LOG_ERR("Type Hash Collision! %s k: %d p: %d hash: %d\n", tokens[iTkn].name, k, p, hash);
			return RESULT_COLLISION;
		}
		*pMapTok = (MapTok){ tok, hash };
		LOG("%s=%d k: %d p: %d hash: %d\n", string_TOK(tok), (u16)tok, k, p, hash);
	}
	return RESULT_SUCCESS;
}

/*
 * CodeBox
 */
#define MAX_INPUT_CHARS      2048
#define TEXT_BUFFER_CAPACITY 65536 * 2

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

#define TOK_MAX_INCREMENT 15
typedef struct PACKED TextMeta {
	TOK_CATEGORY token : 6;

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

	TOK* pTextTok;
	int* pTextTokStart;
	int* pTextTokLen;
	TOK_CATEGORY* pTextCategory;

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

static inline Vector2 GetWorldToBoxLocal(Vector2 point, Rectangle rect)
{
    return (Vector2){ point.x - rect.x, point.y - rect.y };
}

static inline Vector2 GetBoxLocalToWorld(Vector2 point, Rectangle rect)
{
    return (Vector2){ point.x + rect.x, point.y + rect.y };
}

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

static RESULT ProcessMeta2(CodeBox* pCode) 
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverride-init"

#define PROCESS_CHAR_TOK TOK_COUNT // set to TOK_COUNT so it is last entry
#define PROCESS_COMMENT_TOK TOK_COUNT + 1 // set to TOK_COUNT so it is last entry
#define DEF_DISPATCH(_name, _tok)  [_tok] = &&_tok,
#define DEF_ALL_DISPATCH(_cat) DEF_##_cat(DEF_DISPATCH)
	static void *codeDispatch[] = {
		[TOK_NONE] = &&TOK_NONE,
		[PROCESS_CHAR_TOK] = &&PROCESS_CHAR,
		[PROCESS_COMMENT_TOK] = &&PROCESS_COMMENT,
		DEF_ALL_CATEGORY_TOKS(DEF_ALL_DISPATCH)
	};
	static int codeDispatchCount = COUNT(codeDispatch);
#undef DEF_DISPATCH
#undef DEF_ALL_DISPATCH

	static void *commentDispatch[] = {
		[0 ... TOK_COUNT] = &&PROCESS_COMMENT,
		[TOK_NONE] = &&PROCESS_COMMENT,
		[TOK_COMMENT_CLOSE] = &&TOK_COMMENT_CLOSE,
	};
	static int commentDispatchCount = COUNT(commentDispatch);

#pragma GCC diagnostic pop

	// TODO move in anon struct
	const int     count      = pCode->textCount;
	char*         pText      = pCode->pText;
	TextMeta*     pTextMeta  = pCode->pTextMeta;
	TOK*          pTextTok   = pCode->pTextTok;
	TOK_CATEGORY* pTextCategory = pCode->pTextCategory;

	struct {
		int len;
		int iStart;
		TOK tok;
		TOK_CATEGORY category;
	} pend;

	struct {
		tok_hash cur;
		int len;
	} hash;

	struct {
		int i;
		char c;
		TOK tok;
		bool preprocess;
    	bool comment;
	} step = { .i = -1 };

#define SET_CHAR_TOK(_cat) { pTextTok[step.i] = step.tok; pTextCategory[step.i] = _cat; }
#define SET_RANGE_TOK(_cat) { \
	int _len = TOK_NAME_LEN[step.tok]; int _iStart = (step.i - _len) + 1; \
	FILL(pTextTok + _iStart, step.tok, _len); FILL(pTextCategory + _iStart, _cat, _len); \
}

#define WRITE_PEND()        { FILL(pTextTok + pend.iStart, pend.tok, pend.len); FILL(pTextCategory + pend.iStart, pend.category, pend.len); }
#define SET_PEND(_cat) { pend.len = TOK_NAME_LEN[step.tok]; pend.iStart = (step.i - pend.len) + 1; pend.tok = step.tok; pend.category = _cat; }
#define CLEAR_PEND()        { memset(&pend, 0, sizeof(pend)); }

/* Set hash to start at current step. */
#define RESTART_HASH()      { hash = (typeof(hash)){ step.c, 1 }; }
/* Zero hash. */
#define CLEAR_HASH()        { memset(&hash, 0, sizeof(hash)); }

/* Single Char Delimit. Set known char token. Write any pending token. Clear pending and hash. */
#define DELIMIT_CHAR(_cat) SET_CHAR_TOK(_cat); WRITE_PEND(); CLEAR_PEND(); CLEAR_HASH(); 

/* Begin Pending Token Range. Write any pending token if new category and restart hash to current. Set pending to current.*/ // TODO I could get rid of if with another jump table
#define BEGIN_PEND(_cat)   if (pend.category != TOK_CATEGORY_OPERATOR) { WRITE_PEND(); RESTART_HASH(); } SET_PEND(_cat);

/* Delimit Pending Token Range. Set known token range. Clear pending and hash.*/
#define DELIMIT_PEND(_cat) SET_RANGE_TOK(TOK_CATEGORY_OPERATOR); CLEAR_PEND(); CLEAR_HASH(); 

#define GOTO_NEXT(_dispatch) { \
	if (step.i == count) return RESULT_SUCCESS; \
	step.c = pText[++step.i]; \
	hash.cur = (++hash.len == 1) ? (tok_hash)step.c : TOK_HASH_DJB2(hash.cur, step.c);  \
	MapTok mt = TOK_MAP[hash.len & TOK_MAP_PAGE_MASK][hash.cur & TOK_MAP_HASH_MASK]; \
	step.tok = mt.hash == hash.cur ? mt.tok : TOK_NONE; \
	goto *_dispatch[step.tok]; \
}

	CLEAR_PEND(); CLEAR_HASH();

PROCESS_CHAR:
	GOTO_NEXT(codeDispatch);

TOK_NONE:
	MapTok cmt = TOK_MAP[1][(u8)step.c];
	step.tok = cmt.tok == TOK_NONE ? PROCESS_CHAR_TOK : cmt.tok;
	goto *codeDispatch[step.tok];

/* PREPROCESS_TOKS */
TOK_PP_INCLUDE:
TOK_PP_DEFINE:
TOK_PP_IFNDEF:
TOK_PP_IFDEF:
TOK_PP_ENDIF:
TOK_PP_UNDEF:
TOK_PP_ELIF:
TOK_PP_ELSE:
TOK_PP_ERROR:
TOK_PP_PRAGMA:
TOK_PP_LINE:
TOK_PP_IF:
TOK_PP_HASH_HASH:
	SET_PEND(TOK_CATEGORY_PREPROCESS);
	GOTO_NEXT(codeDispatch);

TOK_PP_HASH:
	SET_PEND(TOK_CATEGORY_PREPROCESS);
	GOTO_NEXT(codeDispatch);

/* KEYWORD_TOKS */
TOK_STATIC_ASSERT:
TOK_THREAD_LOCAL:
TOK_IMAGINARY:
TOK_NORETURN:
TOK_COMPLEX:
TOK_GENERIC:
TOK_ALIGNOF:
TOK_ALIGNAS:
TOK_ATOMIC:
TOK_CONTINUE:
TOK_VOLATILE:
TOK_REGISTER:
TOK_RESTRICT:
TOK_TYPEDEF:
TOK_DEFAULT:
TOK_TYPEOF:
TOK_SWITCH:
TOK_STATIC:
TOK_SIZEOF:
TOK_RETURN:
TOK_INLINE:
TOK_EXTERN:
TOK_WHILE:
TOK_CONST:
TOK_BREAK:
TOK_GOTO:
TOK_ELSE:
TOK_CASE:
TOK_AUTO:
TOK_FOR:
TOK_IF:
TOK_DO:
	SET_PEND(TOK_CATEGORY_KEYWORD);
	GOTO_NEXT(codeDispatch);

/* TYPE_TOKS */
TOK_UNSIGNED:
TOK_STRUCT:
TOK_SIGNED:
TOK_DOUBLE:
TOK_FLOAT:
TOK_SHORT:
TOK_BOOL:
TOK_UNION:
TOK_VOID:
TOK_LONG:
TOK_CHAR:
TOK_ENUM:
TOK_INT:
TOK_PTRDIFF_T:
TOK_UINT64_T:
TOK_UINT32_T:
TOK_UINT16_T:
TOK_INT64_T:
TOK_INT32_T:
TOK_INT16_T:
TOK_WCHAR_T:
TOK_UINT8_T:
TOK_SIZE_T:
TOK_INT8_T:
	SET_PEND(TOK_CATEGORY_TYPE);
	GOTO_NEXT(codeDispatch);

/* WHITESPACE_TOKS */
TOK_SPACE:
TOK_TAB:
TOK_NEWLINE:
TOK_CARRIAGE_RETURN:
TOK_FORM_FEED:
TOK_VERTICAL_TAB:
	DELIMIT_CHAR(TOK_CATEGORY_WHITESPACE);
	GOTO_NEXT(codeDispatch);

/* GROUPING_TOKS */
TOK_PAREN_OPEN:
TOK_PAREN_CLOSE:
TOK_BRACE_OPEN:
TOK_BRACE_CLOSE:
TOK_BRACKET_OPEN:
TOK_BRACKET_CLOSE:
	DELIMIT_CHAR(TOK_CATEGORY_SCOPE);
	GOTO_NEXT(codeDispatch);

/* ACCESS_TOKS */
TOK_ARROW:
	DELIMIT_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);
TOK_DOT:
	BEGIN_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);

/* STATEMENT_TOKS */
TOK_SEMICOLON:
TOK_COMMA:
TOK_COLON:
	DELIMIT_CHAR(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);	

/* ARITHMETIC_TOKS */
TOK_INCREMENT: // ++
TOK_DECREMENT: // --
	DELIMIT_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);

TOK_PLUS:      // +
TOK_MINUS:     // -
TOK_STAR:      // *
TOK_SLASH:     // /
TOK_PERCENT:   // %
	BEGIN_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);

/* BITWISE_TOKS */
TOK_LEFT_SHIFT_ASSIGN:  // <<=
TOK_RIGHT_SHIFT_ASSIGN: // >>=
	DELIMIT_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);

TOK_LEFT_SHIFT:         // <<
TOK_RIGHT_SHIFT:        // >>
	SET_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);

TOK_AMPERSAND:          // &
TOK_PIPE:               // |
TOK_CARET:              // ^
TOK_TILDE:              // ~
	BEGIN_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);

/* LOGICAL_TOKS */
TOK_LOGICAL_AND: // &&
TOK_LOGICAL_OR:  // ||
	DELIMIT_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);

TOK_EXCLAMATION: // !
	DELIMIT_CHAR(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);

/* COMPARISON_TOKS */
TOK_LESS_EQUAL:    // <=
TOK_GREATER_EQUAL: // >=
TOK_EQUAL_EQUAL:   // ==
TOK_NOT_EQUAL:     // !=
	DELIMIT_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);
TOK_LESS:          // <
TOK_GREATER:       // >
	BEGIN_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);

/* ASSIGNMENT_TOKS */
TOK_PLUS_ASSIGN:      // +=
TOK_MINUS_ASSIGN:     // -=
TOK_STAR_ASSIGN:      // *=
TOK_SLASH_ASSIGN:     // /=
TOK_PERCENT_ASSIGN:   // %=
TOK_AMPERSAND_ASSIGN: // &=
TOK_PIPE_ASSIGN:      // |=
TOK_CARET_ASSIGN:     // ^=
	DELIMIT_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);
TOK_ASSIGN: // =
	BEGIN_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);

/* DEF_OTHER_OPERATOR_TOKS */
TOK_QUESTION:
	DELIMIT_CHAR(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);

TOK_ELLIPSIS:
	DELIMIT_PEND(TOK_CATEGORY_OPERATOR);
	GOTO_NEXT(codeDispatch);

/* DEF_STRING_DELIMITER_TOKS */
TOK_DOUBLE_QUOTE:
TOK_SINGLE_QUOTE:
	DELIMIT_CHAR(TOK_CATEGORY_QUOTE);
	GOTO_NEXT(codeDispatch);

/* COMMENT_DELIMITER_TOKS */
TOK_LINE_COMMENT:
TOK_COMMENT_OPEN:
	DELIMIT_PEND(TOK_CATEGORY_COMMENT);
	GOTO_NEXT(commentDispatch);

PROCESS_COMMENT:
	DELIMIT_CHAR(TOK_CATEGORY_COMMENT);
	GOTO_NEXT(commentDispatch);

TOK_COMMENT_CLOSE:
	GOTO_NEXT(codeDispatch);

	return 0;
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
						meta.token = TOK_CATEGORY_NONE;
						meta.BLOCK_COMMENT = 0; 
						goto next;
					}	
					goto metaAndNext;

				case '\n': 
					meta.token = TOK_CATEGORY_WHITESPACE;
					pMeta[iC] = meta;
					meta.token = TOK_CATEGORY_COMMENT;
					meta.LINE_COMMENT = 0;
					goto next;

				case ' ': 
				case '\t': 
					meta.token = TOK_CATEGORY_WHITESPACE;
					pMeta[iC] = meta;
					meta.token = TOK_CATEGORY_COMMENT;
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
					meta.token     = TOK_CATEGORY_ESCAPE;
					pMeta[iC]      = meta;
					pMeta[iC + 1]  = meta;
					meta.token     = TOK_CATEGORY_TEXT;
					goto skipAndNext;

				case '\'':
					switch (pc) 
					{
					case '\'':
						goto metaAndNext;

					default:
						meta.token = TOK_CATEGORY_QUOTE;
						pMeta[iC]  = meta;
						meta.token = TOK_CATEGORY_NONE;
						meta.QUOTE = 0;
						goto next;
					}

				case '"':
					switch (pc) 
					{
					case '\'':
						goto metaAndNext;

					default:
						meta.token = TOK_CATEGORY_QUOTE;
						pMeta[iC]  = meta;
						meta.token = TOK_CATEGORY_NONE;
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
					goto metaAndNext;

				/* Start Single Char Token */
				case true  | false << 1 | true  << 2:
					iStrt = iC;
					FALLTHROUGH;

				/* End Token */
				case false | false << 1 | true  << 2:
					int iEnd = iC;
					TokenKey k = CalcTokenKey(pText, iStrt, iEnd);
					TOK tokA = TOK_MAP_A[k.len][k.a];
					TOK tokB = TOK_MAP_B[k.len][k.b];
					// TOK tok = tokA == tokB ? tokA : TOK_CATEGORY_NONE;
					TOK tok = tokA;
					bool isPreprocess = (meta.token == TOK_CATEGORY_PREPROCESS);
					meta.token = tokA;
					meta.PREPROCESS = isPreprocess | meta.PREPROCESS;
					for (int i = iStrt; i <= iEnd; ++i) {
						pMeta[i].token      = meta.token;
						pMeta[i].PREPROCESS = meta.PREPROCESS;
						pMeta[i].iTokenStartOffset = i - iStrt;
						pMeta[i].iTokenEndOffset   = iEnd - i;
					}
					goto next;
				// Put all tokens operators etc in hash lists and look up purely based on that with computed gotos for differing logic
				// This needs a mechanism to determine << ++ etc.
			}

			/* Test Char */
			switch (c) 
			{
				/* Token Chars */
				// case ',':
				// case '.':
				// case ';':
				// case '@':
				// case '_':
				// case '`':
				// case 'a'...'z':
				// case 'A'...'Z':
				// case '0'...'9':
				default: goto metaAndNext;

				/* Increment */
			#define INCREMENT_CASE(_add, _sub, _scope, _token) \
				case _add: \
					meta._scope += (meta._scope < TOK_MAX_INCREMENT); \
					meta.token = _token; \
					goto metaAndNext; \
				case _sub: \
					meta.token = _token; \
					pMeta[iC]  = meta; \
					meta._scope -= (meta._scope > 0);  \
					goto next;

				/* Scopes */
				INCREMENT_CASE('[', ']', SCOPE_BRACKET, TOK_CATEGORY_SCOPE)
				INCREMENT_CASE('{', '}', SCOPE_CURLY,   TOK_CATEGORY_SCOPE)
				INCREMENT_CASE('(', ')', SCOPE_PAREN,   TOK_CATEGORY_SCOPE)

			#undef INCREMENT_CASE

				/* Whitespace */
				case '\n':
					if (meta.PREPROCESS && pc != '\\') {
						meta.token = TOK_CATEGORY_WHITESPACE;
						pMeta[iC]  = meta;
						meta.PREPROCESS = 0;
						goto next;
					}
					meta.token = TOK_CATEGORY_WHITESPACE;
					goto metaAndNext;

				case ' ' :
				case '\0':
				case '\t':
				case '\r': // Carriage return
				case '\v': // Vertical tab
				case '\f': // Form feed
					meta.token = TOK_CATEGORY_WHITESPACE;
					goto metaAndNext;

				/* Comment or Operator */
				case '/':
					switch (nc) 
					{
						case '/':
							meta = (TextMeta){.token = TOK_CATEGORY_COMMENT, .LINE_COMMENT = 1, .BLOCK_COMMENT = meta.BLOCK_COMMENT};
							goto metaAndNext;
						case '*':
							meta.token = TOK_CATEGORY_COMMENT;
							meta.BLOCK_COMMENT = 1;
							goto metaAndNext;
						default:
							meta.token = TOK_CATEGORY_OPERATOR;
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
					meta.token = TOK_CATEGORY_OPERATOR;
					goto metaAndNext;

				/* Quotes */
				case '"':
				case '\'':
					meta.token = TOK_CATEGORY_QUOTE;
					meta.QUOTE = true; 
					pMeta[iC]  = meta; 
					meta.token = TOK_CATEGORY_TEXT;
					goto next;

				/* Preprocess */
				case '#':
					switch (nc) 
					{
						case '#':
							meta.token = TOK_CATEGORY_PREPROCESS; 
							pMeta[iC]   = meta; 
							pMeta[iC+1] = meta;						
							goto skipAndNext;

						default:
							meta.token = TOK_CATEGORY_PREPROCESS;
							goto metaAndNext;
					}

				case '\\':
					if (meta.PREPROCESS && nc == '\n') {
						meta.token = TOK_CATEGORY_CONTINUE;   
						pMeta[iC] = meta;
						meta.token = TOK_CATEGORY_WHITESPACE; 
						pMeta[iC+1] = meta;
						meta.token = TOK_CATEGORY_PREPROCESS;
						goto skipAndNext;
					}
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
static void CodeSyncCaretToMark(CodeBox* pCode, u8 iCaret)
{
	memcpy(pCode->pCarets + iCaret, &pCode->mark, sizeof(CodePos));
}

/* Sync Specified Caret to Current Mark Row */
static void CodeSyncCaretToMarkRow(CodeBox* pCode, u8 iCaret)
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
#define DEF_ALL_CONSTRUCT_TOK_MAP(_cat) REQUIRE(ContructTokMap(COUNT(_cat), _cat));
	DEF_ALL_CATEGORY_TOKS(DEF_ALL_CONSTRUCT_TOK_MAP)
#undef DEF_ALL_CONSTRUCT_TOK_MAP

	// REQUIRE(ContructTokMap(COUNT(PREPROCESS_TOKS), PREPROCESS_TOKS));
	// REQUIRE(ContructTokMap(COUNT(TYPE_TOKS),       TYPE_TOKS));
	// REQUIRE(ContructTokMap(COUNT(KEYWORD_TOKS),    KEYWORD_TOKS));	
	// REQUIRE(ContructTokMap(COUNT(WHITESPACE_TOKS), WHITESPACE_TOKS));	
	// REQUIRE(ContructTokMap(COUNT(GROUPING_TOKS),   GROUPING_TOKS));	
	// REQUIRE(ContructTokMap(COUNT(ASSIGNMENT_TOKS), ASSIGNMENT_TOKS));	

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
	pCode->pBoxRows    = XCALLOC(text.boxRowCount, CodeRow);
	pCode->pCarets     = XCALLOC(text.boxRowCount, CodePos); 
	pCode->caretCount = 1;

	/* File Load */
	{
		pCode->pText = XCALLOC(TEXT_BUFFER_CAPACITY, char);
		pCode->pTextRows = XCALLOC(TEXT_BUFFER_CAPACITY, CodeRow);
		pCode->pTextTok = XCALLOC(TEXT_BUFFER_CAPACITY, TOK);
		pCode->pTextTokStart = XCALLOC(TEXT_BUFFER_CAPACITY, int);
		pCode->pTextTokLen = XCALLOC(TEXT_BUFFER_CAPACITY, int);
		pCode->pTextCategory = XCALLOC(TEXT_BUFFER_CAPACITY, TOK_CATEGORY);
		pCode->pTextMeta = XCALLOC(TEXT_BUFFER_CAPACITY, TextMeta);

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

		// ProcessMeta(&text);
		ProcessMeta2(&text);
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
	{
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
					CodeSyncCaretToMark(pCode, 0);
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
						CodeSyncCaretToMarkRow(pCode, 0);
						CodeBoxFocusMark(pCode);
					}

					break;
				}

				/* Move Right Keys */
				case KEY_RIGHT: 
				case KEY_D | KEY_ALT_MOD:
					if (caret.index >= pCode->textCount) break;
					CodeSetMarkIndex(pCode, mark.index + 1);
					CodeSyncCaretToMark(pCode, 0);
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
						CodeSyncCaretToMarkRow(pCode, 0);
						CodeBoxFocusMark(pCode);
					}

					break;
				}

				/* Move Up Keys */
				case KEY_UP: 
				case KEY_W | KEY_ALT_MOD:{
					pMark->row--;
					CodeSyncCaretToMarkRow(pCode, 0);
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
					CodeSyncCaretToMarkRow(pCode, 0);
					CodeBoxFocusMark(pCode);
					break;
				}

				/* Move Down Keys */
				case KEY_DOWN: 
				case KEY_S | KEY_ALT_MOD: {
					pMark->row++;
					CodeSyncCaretToMarkRow(pCode, 0);
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
					CodeSyncCaretToMarkRow(pCode, 0);
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
		bool    boxHovering = CheckCollisionPointRec(hoverPos, textBox);
		Vector2 hoverBoxPos = GetWorldToBoxLocal(hoverPos, textBox);

		int iHoverBoxCol =  hoverBoxPos.x / fontXSpacing;
		int iHoverBoxRow =  hoverBoxPos.y / fontYSpacing;
		int iHoverCol    =  iHoverBoxCol;
		int iHoverRow    =  pCode->focusStartRow + iHoverBoxRow;
		CodeRow hoverRow = pCode->pTextRows[iHoverRow];
		int iHoverChar = MIN(hoverRow.startIndex + iHoverBoxCol, hoverRow.endIndex);

		// DrawText(TextFormat("frameTime: %f/", GetFrameTime()), 512, 0, 20, GRAY);
		DrawText(TextFormat("col: %i >row: %i pCaret[0].index: %i hoverPos: x%.1f y%.1f c%i r%i", 
			pCode->mark.col, pCode->mark.row, pCode->pCarets[0].index, hoverBoxPos.x, hoverBoxPos.y, iHoverBoxCol, iHoverBoxRow), 0, 0, 20, DARKGRAY);

		DrawRectangleRec(textBox, COLOR_BACKGROUND);
		DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, boxHovering ? COLOR_CARET : DARKGRAY);

		Color textColor = COLOR_TEXT;
		Color caretColor = BLANK;
		Vector2 scanFoundPosition = { -1, -1};

		const char* pText = pCode->pText;
		const TextMeta* pTextMeta  = pCode->pTextMeta;
		const TOK_CATEGORY* pTextCategory = pCode->pTextCategory;
		int boxRowCount = pCode->boxRowCount;
		int boxColCount = pCode->boxColCount;
		int iChar = pCode->focusStartRowIndex;

		for (int iRow = 0; iRow < boxRowCount; ++iRow) {
			// int tabCount = 0;
			// for (int iCol = 0; iCol < boxColCount - (tabCount * tabWidth); ++iCol) {
			char     currentChar;
			TextMeta currentMeta;
			TOK_CATEGORY currentToken;
			for (int iCol = 0; iCol < boxColCount; ++iCol) {
				currentChar  = pText[iChar];
				currentMeta  = pTextMeta[iChar];
				currentToken = pTextCategory[iChar];

				Vector2 position = {
					// textBox.x + (fontXSpacing * iCol) + (tabCount * fontXSpacing * 4), 
					textBox.x + (fontXSpacing * iCol), 
					textBox.y + (fontYSpacing * iRow)
				};										
				Rectangle rect = {position.x, position.y, fontXSpacing, fontYSpacing};

				// if (iChar == text.pActiveCaret->index) {
				// 	caretColor = COLOR_CARET;
				// 	caretPosition = position;
				// 	DEBUG_LOG_ONCE("%s %d %d\n", string_TOK(m.tok), m.QUOTE, Delimiter(currentChar));
				// }

				if (iChar == command.scanFoundIndex) 
					scanFoundPosition = position;

				// #define GENERATE_BITMASK(_type) ((m._type > 0) << TEXT_META_TYPE_##_type ) | 
				// u16 mask = (u16)META_TYPES(GENERATE_BITMASK) 0;
				// #undef GENERATE_BITMASK

				#define COLOR_A(_color, _a) (Color){_color.r, _color.g, _color.b, _a}

				if (currentMeta.SCOPE_PAREN > 0) {
					DrawRectangleRec(rect, COLOR_A(WHITE, currentMeta.SCOPE_PAREN * 10));
				}

				// if (m.BLOCK_COMMENT) {
				// 	DrawRectangleRec(rect, COLOR_A(BLUE, 10));
				// }

				if (currentMeta.PREPROCESS) {
					DrawRectangleRec(rect, COLOR_A(COLOR_PREPROCESS, 20));
				}

				if (currentMeta.QUOTE) {
					DrawRectangleRec(rect, COLOR_A(COLOR_QUOTE, 50));
				}

				char displayChar = currentChar;
				switch (currentChar) 
				{
					case '\0':
						goto FinishDrawingText;

					/* Whitespace */
					case ' ':
						displayChar =  '_';
						goto DrawChar;

					case '\t':
						// // Step more spaces for tab width
						// rect.width += (tabCount * fontXSpacing * tabWidth);
						// tabCount++;
						displayChar = '-';
						goto DrawChar;

					case '\r':
					case '\v':
					case '\f':
					case '\n':
						iCol = boxColCount;
						displayChar =  '\\';
						goto DrawChar;

				DrawChar:
					default:
						int codePointSize;
						int codePoint = GetCodepoint(&displayChar, &codePointSize);
						Color color = TOK_CATEGORY_COLOR[currentToken];
						DrawTextCodepoint(font, codePoint, position, fontSize, color);
						iChar++;
						break;
				}									
			}
			
			// If we are wrapping not on a newline, skip index to next new line so text doesn't wrap
			if (currentChar != '\n') iChar = TextFindCharForward(pText, iChar, '\n') + 1;
		}      
		FinishDrawingText:

		/*
		 * Hover
		 */
		if (boxHovering) {
			Vector2 hoverSnapBoxPos = (Vector2){ (iHoverBoxCol * fontXSpacing), (iHoverBoxRow * fontYSpacing) };
			Vector2 hoverSnapPos    = GetBoxLocalToWorld(hoverSnapBoxPos, textBox);
			DrawRectangleRec((Rectangle){hoverSnapPos.x, hoverSnapPos.y, fontXSpacing, fontYSpacing}, COLOR_HOVER);

			TextMeta hoverMeta = pCode->pTextMeta[iHoverChar];

			int iHoverStartCol = iHoverCol - hoverMeta.iTokenStartOffset;
			int iHoverEndCol   = iHoverCol + hoverMeta.iTokenEndOffset;

			Vector2 startBoxPos = (Vector2){ (iHoverStartCol   * fontXSpacing), (iHoverBoxRow * fontYSpacing) };
			Vector2 endBoxPos   = (Vector2){ ((iHoverEndCol+1) * fontXSpacing), (iHoverBoxRow * fontYSpacing) };
			Vector2 startPos    = GetBoxLocalToWorld(startBoxPos, textBox);
			Vector2 endPos      = GetBoxLocalToWorld(endBoxPos,   textBox);
			DrawRectangleRec((Rectangle){ startPos.x, startPos.y, endPos.x - startPos.x, fontYSpacing }, COLOR_HOVER);

			if (input.lMouse) {
				pCode->mark.col = iHoverCol;
				pCode->mark.row = iHoverRow;
				CodeSyncCaretToMarkRow(pCode, 0);

				char c = pCode->pText[pCode->pCarets[0].index];
				TOK tok = pCode->pTextTok[pCode->pCarets[0].index];
				TOK_CATEGORY tc = pCode->pTextCategory[pCode->pCarets[0].index];
				TextMeta m = pCode->pTextMeta[pCode->pCarets[0].index];
				DEBUG_LOG_ONCE("%s %s %d %d start: %d end: %d\n", string_TOK(tok), string_TOK_CATEGORY(tc), m.QUOTE, Delimiter(c), m.iTokenStartOffset, m.iTokenEndOffset);
			}
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



