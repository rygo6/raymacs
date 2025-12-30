double T() {
	int a0 = -1;
	do {a0++;} while (a0<10);
	int b = a0-a0 - 1- 2 -3;
	int*x;
	a0--;
	return 0;
}

#define CONCAT(_a, _b, define) hello _a## _b # _a  #_a #define \
 hello

static double Test(int input) {
	static const int  x;
	float* number;
	const char * str = "Hello\n0";
	char tick = 'a';
	int output = input;
	int vala = output*output+2;
	int valb = 10 / 2;
	if (vala-->=0) 
		vala>>=vala;
	return output;
}

#define HELLO { \
	int o = 1; \
	int i = 0; /* Test */ \
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

#define STATIC_ASSERT(...) _Static_assert(__VA_ARGS__)

static const char* EscapeChar(char c) {
    switch (c) {
        case '\n': return "\\n";
        case '\t': return "\\t";
        case '\r': return "\\r";
        case '\0': return "\\0";
        case '\\': return "\\\\";
        case '\'': return "\\\'";
        case '\"': return "\\\"";
        default: 
			static char buf[2] = { '\0' ,'\0' };
			buf[0] = c;	return buf;
    }
}

/*
 * Utility
 */
typedef uint8_t       u8;
typedef uint16_t      u16;
typedef uint32_t      u32;
typedef uint64_t      u64;
typedef int8_t        i8;
typedef int16_t       i16;
typedef int32_t       i32;
typedef int64_t       i64;
typedef float         f32;
typedef double        f64;
typedef unsigned char utf8;

#define CACHE_LINE 64

#define MIN(_a, _b) \
({ \
	typeof(_a) _valA = (_a); \
	typeof(_b) _valB = (_b); \
	_valA < _valB ? _valA : _valB; \
})

#define MAX(_a, _b) \
({ \
	typeof(_a) _valA = (_a); \
	typeof(_b) _valB = (_b); \
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

#define NBYTES(_v)     (sizeof(_v))
#define NBITS(_v)      (sizeof(_v) * CHAR_BIT)
#define NARRAY(_array) (sizeof((_array)) / sizeof((_array)[0]))

#define UMAX(_t) (1 << NBITS(_t))
#define UMIN(_t) ((_t)0)
#define SMAX(_t) ((1 << (NBITS(_t)-1)) - 1)
#define SMIN(_t) (-(1 << (NBITS(_t)-1)))
STATIC_ASSERT(UMAX(u8) == 256);
STATIC_ASSERT(UMIN(u8) == 0);
STATIC_ASSERT(SMAX(i8) == 127);
STATIC_ASSERT(SMIN(i8) == -128);

#define XMALLOC_ALIGNED(_align, _size)\
({\
	void* _p = _aligned_malloc(_size, _align);\
	if (UNLIKELY(_p == NULL)) PANIC("XMALLOC_ALIGNED FAIL!");\
	_p;\
})

#define XCALLOC(_count, _type)\
({\
	void* _p = calloc(_count, sizeof(_type));\
	if (UNLIKELY(_p == NULL)) PANIC("XCALLOC FAIL!");\
	_p;\
})

#define ZERO(_p)             memset((void*)(_p), 0, sizeof(*_p))
#define ZERO_RANGE(_p, _len) memset((void*)(_p), 0, sizeof(*_p) * _len)

/*
 * Validation
 */
#ifdef NDEBUG
	#define ASSERT(_condition, _format, ...)
#else
	#define ASSERT(_condition, _format, ...)\
		if (UNLIKELY(!(_condition))) {\
			fprintf(stderr, "\n" ANSI_RED __FILE__ ":%d ASSERT! " #_condition " " _format "\n" ANSI_RESET, __LINE__, ##__VA_ARGS__);\
			assert((_condition) && #_condition);\
		}
#endif

#define PANIC(_format, ...)\
({\
	fprintf(stderr, "\n" ANSI_RED __FILE__ ":%d PANIC! " _format "\n" ANSI_RESET, __LINE__, ##__VA_ARGS__); \
	__builtin_trap();\
})

/* Check will goto RESULT_ERROR label on fail. */
#define CHECK(_condition, _errorResult)\
	if (UNLIKELY(!(_condition))) {\
		fprintf(stderr, "\n" ANSI_YELLOW __FILE__ ":%d TRY! " #_condition " == false! %s\n" ANSI_RESET, __LINE__, string_RESULT(_errorResult));\
		goto _errorResult;\
	}

/* Check will goto RESULT_ERROR label on fail. */
#define CHECKMSG(_condition, _errorResult, _format, ...)\
	if (UNLIKELY(!(_condition))) {\
		fprintf(stderr, "\n" ANSI_YELLOW __FILE__ ":%d TRY! " #_condition " == false! %s " _format "\n" ANSI_RESET, __LINE__, string_RESULT(_errorResult), ##__VA_ARGS__);\
		goto _errorResult;\
	}

#define MUST(_condition)\
	if (UNLIKELY(!(_condition))) {\
		fprintf(stderr, "\n" ANSI_RED __FILE__ ":%d MUST! " #_condition " == false!\n" ANSI_RESET, __LINE__);\
		__builtin_trap();\
	}

/* Require will PANIC on fail. */
#define REQUIRE(_command) \
({ \
	RESULT _result = (_command); \
	if (UNLIKELY(_result != RESULT_SUCCESS)) PANIC(#_command " == %s\n", string_RESULT(_result)); \
})

/*
 * Global Enum
 */
#define DEF_ARRAY_ITEM(_item, ...)  _item,
#define DEF_ENUM_ITEM(_item, ...)   _item __VA_OPT__(=) __VA_ARGS__,
#define DEF_STRING_ITEM(_item, ...) case _item: return #_item;
#define DEF_ENUM(_enum)\
	typedef enum PACKED _enum {\
		DEF_##_enum(DEF_ENUM_ITEM)\
	} _enum; \
	static const char* string_##_enum(_enum _item) {\
		switch(_item) {\
			DEF_##_enum(DEF_STRING_ITEM)\
			default: return #_enum " N/A";\
		}\
	}

#define DEF_RESULT(DEF)\
	DEF(RESULT_ORDER_ERROR,     -7)\
	DEF(RESULT_CAPACITY_ERROR,  -6)\
	DEF(RESULT_DUPLICATE_ERROR, -5)\
	DEF(RESULT_OFFSET_ERROR,    -4)\
	DEF(RESULT_PARSE_ERROR,     -3)\
	DEF(RESULT_COLLISION_ERROR, -2)\
	DEF(RESULT_ERROR,           -1)\
	DEF(RESULT_SUCCESS,          0)
DEF_ENUM(RESULT);

#define DEF_DIRECTION(DEF)\
	DEF(DIRECTION_NONE)\
	DEF(DIRECTION_FORWARD)\
	DEF(DIRECTION_BACKWARD)\
	DEF(DIRECTION_COUNT)
DEF_ENUM(DIRECTION);

#define DEF_SCOPE(DEF)\
	DEF(SCOPE_TAB)\
	DEF(SCOPE_DEFINE)\
	DEF(SCOPE_CURLY)\
	DEF(SCOPE_PAREN)\
	DEF(SCOPE_BRACKET)\
	DEF(SCOPE_QUOTE)\
	DEF(SCOPE_BLOCK_COMMENT)\
	DEF(SCOPE_LINE_COMMENT)\
	DEF(SCOPE_COUNT)
DEF_ENUM(SCOPE);

#define FIND_CARET_COLOR     (Color){   0, 255,   0, 255 }
#define FIND_HIGHLIGHT_COLOR (Color){   0, 255,   0, 64  }
#define COLOR_COMMAND_BOX    (Color){  20,  20,   2, 200 }
#define COLOR_TEXT_BOX       (Color){  37,  37,  38, 255 }
#define COLOR_CARET       ORANGE
#define COLOR_HOVER       (Color){   0, 255,   0, 64  }

#define COLOR_CODE        (Color){ 216, 222, 233, 255 }
#define COLOR_ERROR       (Color){ 255,   0,   0, 255 }
#define COLOR_PREPROCESS  (Color){ 135, 132, 219, 255 }
#define COLOR_CONTINUE    (Color){ 148,  99, 148, 255 }
#define COLOR_NUMBER      (Color){ 249, 174,  87, 255 }
#define COLOR_STRING      (Color){ 153, 199, 148, 255 } 
#define COLOR_COMMENT     (Color){ 166, 172, 185, 255 }  
#define COLOR_OPERATOR    (Color){ 249, 123,  87, 255 }
#define COLOR_BACKGROUND  (Color){  48,  56,  65, 255 } 
#define COLOR_WHITESPACE  (Color){  68,  76,  85, 255 } 
#define COLOR_ESCAPE      (Color){ 198, 149, 198, 255 } 
#define COLOR_TEXT        (Color){ 127, 199, 148, 255 } 
#define COLOR_QUOTE       (Color){  96, 180, 180, 255 } 
#define COLOR_SCOPE       (Color){ 206, 186, 192, 255 } 
#define COLOR_KEYWORD     (Color){ 236,  96, 102, 255 }
#define COLOR_TYPE        (Color){ 198, 149, 198, 255 }

/*
 * C11 Lexer
 */

#define DEF_TOK_CAT(DEF) \
	DEF(TOK_CAT_NONE) \
	DEF(TOK_CAT_ERROR) \
	DEF(TOK_CAT_ALPHA) \
	DEF(TOK_CAT_DIGIT) \
	DEF(TOK_CAT_TYPE) \
	DEF(TOK_CAT_KEYWORD) \
	DEF(TOK_CAT_WHITESPACE) \
	DEF(TOK_CAT_ASSIGN) \
	DEF(TOK_CAT_OPERATOR) \
	DEF(TOK_CAT_PP) \
	DEF(TOK_CAT_PP_OPERATOR) \
	DEF(TOK_CAT_CONTINUE) \
	DEF(TOK_CAT_SCOPE) \
	DEF(TOK_CAT_QUOTE) \
	DEF(TOK_CAT_TEXT) \
	DEF(TOK_CAT_ESCAPE) \
	DEF(TOK_CAT_COMMENT) \
	DEF(TOK_CAT_COUNT)
DEF_ENUM(TOK_CAT);

static Color TOK_CAT_COLOR[] = {
	[TOK_CAT_NONE]       = COLOR_ERROR,
	[TOK_CAT_ERROR]      = COLOR_ERROR,
	[TOK_CAT_ALPHA]      = COLOR_CODE,
	[TOK_CAT_DIGIT]      = COLOR_NUMBER,
	[TOK_CAT_TYPE]       = COLOR_TYPE,
	[TOK_CAT_KEYWORD]    = COLOR_KEYWORD,
	[TOK_CAT_WHITESPACE] = COLOR_WHITESPACE,
	[TOK_CAT_ASSIGN]     = COLOR_SCOPE,
	[TOK_CAT_OPERATOR]   = COLOR_OPERATOR,
	[TOK_CAT_PP]         = COLOR_PREPROCESS,
	[TOK_CAT_PP_OPERATOR]= COLOR_PREPROCESS,
	[TOK_CAT_CONTINUE]   = COLOR_CONTINUE,
	[TOK_CAT_SCOPE]      = COLOR_SCOPE,
	[TOK_CAT_QUOTE]      = COLOR_QUOTE,
	[TOK_CAT_TEXT]       = COLOR_TEXT,
	[TOK_CAT_ESCAPE]     = COLOR_ESCAPE,
	[TOK_CAT_COMMENT]    = COLOR_COMMENT,
};
STATIC_ASSERT(NARRAY(TOK_CAT_COLOR) == TOK_CAT_COUNT);

#define SKIP     "$skip"
#define RANGE    "$range"
#define OVERRIDE "$override"

#define DEF_TOK(DEF) \
	DEF(SKIP"\0"   ,TOK_NONE  ,TOK_CAT_NONE)\
	DEF(SKIP"\x15" ,TOK_ERROR ,TOK_CAT_NONE)\
	DEF(RANGE"A-Z,a-z,_" ,TOK_ALPHA_CHAR ,TOK_CAT_ALPHA)\
	DEF(RANGE"0-9"       ,TOK_DIGIT_CHAR ,TOK_CAT_DIGIT)\
	DEF("#include" ,TOK_PP_INCLUDE       ,TOK_CAT_PP)\
	DEF("#define"  ,TOK_PP_DEFINE        ,TOK_CAT_PP)\
	DEF("#ifndef"  ,TOK_PP_IFNDEF        ,TOK_CAT_PP)\
	DEF("#ifdef"   ,TOK_PP_IFDEF         ,TOK_CAT_PP)\
	DEF("#endif"   ,TOK_PP_ENDIF         ,TOK_CAT_PP)\
	DEF("#undef"   ,TOK_PP_UNDEF         ,TOK_CAT_PP)\
	DEF("#elif"    ,TOK_PP_ELIF          ,TOK_CAT_PP)\
	DEF("#else"    ,TOK_PP_ELSE          ,TOK_CAT_PP)\
	DEF("#error"   ,TOK_PP_ERROR         ,TOK_CAT_PP)\
	DEF("#pragma"  ,TOK_PP_PRAGMA        ,TOK_CAT_PP)\
	DEF("#line"    ,TOK_PP_LINE          ,TOK_CAT_PP)\
	DEF("#if"      ,TOK_PP_IF            ,TOK_CAT_PP)\
	DEF("\\\n"     ,TOK_PP_CONTINUE      ,TOK_CAT_PP_OPERATOR)\
	DEF("##"       ,TOK_DEFINE_HASH_HASH ,TOK_CAT_PP_OPERATOR)\
	DEF("#"        ,TOK_HASH             ,TOK_CAT_PP_OPERATOR)\
	DEF("\\"       ,TOK_ESCAPE           ,TOK_CAT_PP_OPERATOR)\
	DEF("_Static_assert" ,TOK_STATIC_ASSERT ,TOK_CAT_KEYWORD)\
	DEF("_Thread_local"  ,TOK_THREAD_LOCAL  ,TOK_CAT_KEYWORD)\
	DEF("_Imaginary"     ,TOK_IMAGINARY     ,TOK_CAT_KEYWORD)\
	DEF("_Noreturn"      ,TOK_NORETURN      ,TOK_CAT_KEYWORD)\
	DEF("_Complex"       ,TOK_COMPLEX       ,TOK_CAT_KEYWORD)\
	DEF("_Generic"       ,TOK_GENERIC       ,TOK_CAT_KEYWORD)\
	DEF("_Alignof"       ,TOK_ALIGNOF       ,TOK_CAT_KEYWORD)\
	DEF("_Alignas"       ,TOK_ALIGNAS       ,TOK_CAT_KEYWORD)\
	DEF("_Atomic"        ,TOK_ATOMIC        ,TOK_CAT_KEYWORD)\
	DEF("continue"       ,TOK_CONTINUE      ,TOK_CAT_KEYWORD)\
	DEF("volatile"       ,TOK_VOLATILE      ,TOK_CAT_KEYWORD)\
	DEF("register"       ,TOK_REGISTER      ,TOK_CAT_KEYWORD)\
	DEF("restrict"       ,TOK_RESTRICT      ,TOK_CAT_KEYWORD)\
	DEF("typedef"        ,TOK_TYPEDEF       ,TOK_CAT_KEYWORD)\
	DEF("default"        ,TOK_DEFAULT       ,TOK_CAT_KEYWORD)\
	DEF("typeof"         ,TOK_TYPEOF        ,TOK_CAT_KEYWORD)\
	DEF("switch"         ,TOK_SWITCH        ,TOK_CAT_KEYWORD)\
	DEF("static"         ,TOK_STATIC        ,TOK_CAT_KEYWORD)\
	DEF("sizeof"         ,TOK_SIZEOF        ,TOK_CAT_KEYWORD)\
	DEF("return"         ,TOK_RETURN        ,TOK_CAT_KEYWORD)\
	DEF("inline"         ,TOK_INLINE        ,TOK_CAT_KEYWORD)\
	DEF("extern"         ,TOK_EXTERN        ,TOK_CAT_KEYWORD)\
	DEF("while"          ,TOK_WHILE         ,TOK_CAT_KEYWORD)\
	DEF("const"          ,TOK_CONST         ,TOK_CAT_KEYWORD)\
	DEF("break"          ,TOK_BREAK         ,TOK_CAT_KEYWORD)\
	DEF("goto"           ,TOK_GOTO          ,TOK_CAT_KEYWORD)\
	DEF("else"           ,TOK_ELSE          ,TOK_CAT_KEYWORD)\
	DEF("case"           ,TOK_CASE          ,TOK_CAT_KEYWORD)\
	DEF("auto"           ,TOK_AUTO          ,TOK_CAT_KEYWORD)\
	DEF("for"            ,TOK_FOR           ,TOK_CAT_KEYWORD)\
	DEF("if"             ,TOK_IF            ,TOK_CAT_KEYWORD)\
	DEF("do"             ,TOK_DO            ,TOK_CAT_KEYWORD)\
	DEF("unsigned"  ,TOK_UNSIGNED  ,TOK_CAT_TYPE)\
	DEF("struct"    ,TOK_STRUCT    ,TOK_CAT_TYPE)\
	DEF("signed"    ,TOK_SIGNED    ,TOK_CAT_TYPE)\
	DEF("double"    ,TOK_DOUBLE    ,TOK_CAT_TYPE)\
	DEF("float"     ,TOK_FLOAT     ,TOK_CAT_TYPE)\
	DEF("short"     ,TOK_SHORT     ,TOK_CAT_TYPE)\
	DEF("_Bool"     ,TOK_BOOL      ,TOK_CAT_TYPE)\
	DEF("union"     ,TOK_UNION     ,TOK_CAT_TYPE)\
	DEF("void"      ,TOK_VOID      ,TOK_CAT_TYPE)\
	DEF("long"      ,TOK_LONG      ,TOK_CAT_TYPE)\
	DEF("char"      ,TOK_CHAR      ,TOK_CAT_TYPE)\
	DEF("enum"      ,TOK_ENUM      ,TOK_CAT_TYPE)\
	DEF("int"       ,TOK_INT       ,TOK_CAT_TYPE)\
	DEF("ptrdiff_t" ,TOK_PTRDIFF_T ,TOK_CAT_TYPE)\
	DEF("uint64_t"  ,TOK_UINT64_T  ,TOK_CAT_TYPE)\
	DEF("uint32_t"  ,TOK_UINT32_T  ,TOK_CAT_TYPE)\
	DEF("uint16_t"  ,TOK_UINT16_T  ,TOK_CAT_TYPE)\
	DEF("int64_t"   ,TOK_INT64_T   ,TOK_CAT_TYPE)\
	DEF("int32_t"   ,TOK_INT32_T   ,TOK_CAT_TYPE)\
	DEF("int16_t"   ,TOK_INT16_T   ,TOK_CAT_TYPE)\
	DEF("wchar_t"   ,TOK_WCHAR_T   ,TOK_CAT_TYPE)\
	DEF("uint8_t"   ,TOK_UINT8_T   ,TOK_CAT_TYPE)\
	DEF("size_t"    ,TOK_SIZE_T    ,TOK_CAT_TYPE)\
	DEF("int8_t"    ,TOK_INT8_T    ,TOK_CAT_TYPE)\
	DEF(" "   ,TOK_SPACE           ,TOK_CAT_WHITESPACE)\
	DEF("\t"  ,TOK_TAB             ,TOK_CAT_WHITESPACE)\
	DEF("\n"  ,TOK_NEWLINE         ,TOK_CAT_WHITESPACE)\
	DEF("\r"  ,TOK_CARRIAGE_RETURN ,TOK_CAT_WHITESPACE)\
	DEF("\f"  ,TOK_FORM_FEED       ,TOK_CAT_WHITESPACE)\
	DEF("\v"  ,TOK_VERTICAL_TAB    ,TOK_CAT_WHITESPACE)\
	DEF("("   ,TOK_PAREN_OPEN    ,TOK_CAT_SCOPE)\
	DEF(")"   ,TOK_PAREN_CLOSE   ,TOK_CAT_SCOPE)\
	DEF("{"   ,TOK_BRACE_OPEN    ,TOK_CAT_SCOPE)\
	DEF("}"   ,TOK_BRACE_CLOSE   ,TOK_CAT_SCOPE)\
	DEF("["   ,TOK_BRACKET_OPEN  ,TOK_CAT_SCOPE)\
	DEF("]"   ,TOK_BRACKET_CLOSE ,TOK_CAT_SCOPE)\
	DEF("->"  ,TOK_ARROW              ,TOK_CAT_ASSIGN)\
	DEF("."   ,TOK_DOT                ,TOK_CAT_ASSIGN)\
	DEF(";"   ,TOK_SEMICOLON          ,TOK_CAT_ASSIGN)\
	DEF(","   ,TOK_COMMA              ,TOK_CAT_ASSIGN)\
	DEF(":"   ,TOK_COLON              ,TOK_CAT_ASSIGN)\
	DEF("++"  ,TOK_INCREMENT          ,TOK_CAT_OPERATOR)\
	DEF("--"  ,TOK_DECREMENT          ,TOK_CAT_OPERATOR)\
	DEF("+"   ,TOK_PLUS               ,TOK_CAT_OPERATOR)\
	DEF("-"   ,TOK_MINUS              ,TOK_CAT_OPERATOR)\
	DEF("*"   ,TOK_STAR               ,TOK_CAT_OPERATOR)\
	DEF("/"   ,TOK_SLASH              ,TOK_CAT_OPERATOR)\
	DEF("%"   ,TOK_PERCENT            ,TOK_CAT_OPERATOR)\
	DEF("<<=" ,TOK_LEFT_SHIFT_ASSIGN  ,TOK_CAT_OPERATOR)\
	DEF(">>=" ,TOK_RIGHT_SHIFT_ASSIGN ,TOK_CAT_OPERATOR)\
	DEF("<<"  ,TOK_LEFT_SHIFT         ,TOK_CAT_OPERATOR)\
	DEF(">>"  ,TOK_RIGHT_SHIFT        ,TOK_CAT_OPERATOR)\
	DEF("&"   ,TOK_AMPERSAND          ,TOK_CAT_OPERATOR)\
	DEF("|"   ,TOK_PIPE               ,TOK_CAT_OPERATOR)\
	DEF("^"   ,TOK_CARET              ,TOK_CAT_OPERATOR)\
	DEF("~"   ,TOK_TILDE              ,TOK_CAT_OPERATOR)\
	DEF("&&"  ,TOK_LOGICAL_AND        ,TOK_CAT_OPERATOR)\
	DEF("||"  ,TOK_LOGICAL_OR         ,TOK_CAT_OPERATOR)\
	DEF("!"   ,TOK_EXCLAMATION        ,TOK_CAT_OPERATOR)\
	DEF("<="  ,TOK_LESS_EQUAL         ,TOK_CAT_OPERATOR)\
	DEF(">="  ,TOK_GREATER_EQUAL      ,TOK_CAT_OPERATOR)\
	DEF("=="  ,TOK_EQUAL_EQUAL        ,TOK_CAT_OPERATOR)\
	DEF("!="  ,TOK_NOT_EQUAL          ,TOK_CAT_OPERATOR)\
	DEF("<"   ,TOK_LESS               ,TOK_CAT_OPERATOR)\
	DEF(">"   ,TOK_GREATER            ,TOK_CAT_OPERATOR)\
	DEF("?"   ,TOK_QUESTION           ,TOK_CAT_OPERATOR)\
	DEF("..." ,TOK_ELLIPSIS           ,TOK_CAT_OPERATOR)\
	DEF("+="  ,TOK_PLUS_ASSIGN        ,TOK_CAT_OPERATOR)\
	DEF("-="  ,TOK_MINUS_ASSIGN       ,TOK_CAT_OPERATOR)\
	DEF("*="  ,TOK_STAR_ASSIGN        ,TOK_CAT_OPERATOR)\
	DEF("/="  ,TOK_SLASH_ASSIGN       ,TOK_CAT_OPERATOR)\
	DEF("%="  ,TOK_PERCENT_ASSIGN     ,TOK_CAT_OPERATOR)\
	DEF("&="  ,TOK_AMPERSAND_ASSIGN   ,TOK_CAT_OPERATOR)\
	DEF("|="  ,TOK_PIPE_ASSIGN        ,TOK_CAT_OPERATOR)\
	DEF("^="  ,TOK_CARET_ASSIGN       ,TOK_CAT_OPERATOR)\
	DEF("="   ,TOK_ASSIGN             ,TOK_CAT_OPERATOR)\
	DEF("\""  ,TOK_DOUBLE_QUOTE        ,TOK_CAT_QUOTE)\
	DEF("'"   ,TOK_SINGLE_QUOTE        ,TOK_CAT_QUOTE)\
	DEF("/*"  ,TOK_COMMENT_OPEN        ,TOK_CAT_COMMENT)\
	DEF("//"  ,TOK_LINE_COMMENT        ,TOK_CAT_COMMENT)

#define DEF_TOK_COMMENT(DEF)\
	DEF(SKIP"\0"   ,TOK_COMMENT_NONE  ,TOK_CAT_NONE)\
	DEF(SKIP"\x15" ,TOK_COMMENT_ERROR ,TOK_CAT_NONE)\
	DEF(RANGE" ,\t" ,TOK_COMMENT_WITESPACE ,TOK_CAT_WHITESPACE)\
	DEF(RANGE"!-~"  ,TOK_COMMENT_CHAR ,TOK_CAT_COMMENT)\
	DEF(OVERRIDE"*" ,TOK_COMMENT_STAR ,TOK_CAT_COMMENT)\
	DEF("*/"        ,TOK_COMMENT_CLOSE     ,TOK_CAT_COMMENT)\
	DEF("\n"        ,TOK_COMMENT_NEWLINE   ,TOK_CAT_WHITESPACE)

#define DEF_TOK_QUOTE(DEF)\
	DEF(SKIP"\0"   ,TOK_QUOTE_NONE  ,TOK_CAT_NONE)\
	DEF(SKIP"\x15" ,TOK_QUOTE_ERROR ,TOK_CAT_ERROR)\
	DEF(RANGE" -~,\t" ,TOK_QUOTE_CHAR ,TOK_CAT_TEXT)\
	DEF(OVERRIDE"\"" ,TOK_QUOTE_DOUBLE_CLOSE ,TOK_CAT_QUOTE)\
	DEF(OVERRIDE"\'" ,TOK_QUOTE_SINGLE_CLOSE ,TOK_CAT_QUOTE)\
	DEF(OVERRIDE"\\" ,TOK_ESCAPE_ESCAPE      ,TOK_CAT_ESCAPE)\
	DEF("\\'"  ,TOK_ESCAPE_SINGLE_QUOTE ,TOK_CAT_ESCAPE)\
	DEF("\\\"" ,TOK_ESCAPE_DOUBLE_QUOTE ,TOK_CAT_ESCAPE)\
	DEF("\\?"  ,TOK_ESCAPE_QUESTION     ,TOK_CAT_ESCAPE)\
	DEF("\\\\" ,TOK_ESCAPE_BACKSLASH    ,TOK_CAT_ESCAPE)\
	DEF("\\a"  ,TOK_ESCAPE_ALERT        ,TOK_CAT_ESCAPE)\
	DEF("\\b"  ,TOK_ESCAPE_BACKSPACE    ,TOK_CAT_ESCAPE)\
	DEF("\\f"  ,TOK_ESCAPE_FORMFEED     ,TOK_CAT_ESCAPE)\
	DEF("\\n"  ,TOK_ESCAPE_NEWLINE      ,TOK_CAT_ESCAPE)\
	DEF("\\r"  ,TOK_ESCAPE_CARRIAGE     ,TOK_CAT_ESCAPE)\
	DEF("\\t"  ,TOK_ESCAPE_TAB          ,TOK_CAT_ESCAPE)\
	DEF("\\v"  ,TOK_ESCAPE_VTAB         ,TOK_CAT_ESCAPE)\
	DEF("\\x"  ,TOK_ESCAPE_HEX_START    ,TOK_CAT_ESCAPE)\
	DEF("\\u"  ,TOK_ESCAPE_UNICODE_4    ,TOK_CAT_ESCAPE)\
	DEF("\\U"  ,TOK_ESCAPE_UNICODE_8    ,TOK_CAT_ESCAPE)\
	DEF("\n" ,TOK_QUOTE_NEWLINE ,TOK_CAT_ERROR)

#define TK_ASCII_BEGIN 32
#define TK_ASCII_END   126
#define TK_ASCII_RANGE TK_ASCII_BEGIN ... TK_ASCII_END

#define TK_KEYWORD_BEGIN 128
#define TK_KEYWORD_END   255
#define TK_KEYWORD_RANGE TK_KEYWORD_BEGIN ... TK_KEYWORD_END

#define DEF_TK(DEF)\
    /*Frie Traverse*/\
    DEF(TK_NONE,         /*NUL*/'\x00')\
    DEF(TK_SPARSE_CHAR,  /*SOH*/'\x01')\
    DEF(TK_PACKED_CHAR,  /*STX*/'\x02')\
	DEF(TK_DELIMIT,      /*ETX*/'\x03')\
	DEF(TK_MUNCH,        /*EOT*/'\x04')\
    DEF(TK_ERR,          /*ENQ*/'\x05')\
	/* White Spaces */\
	DEF(TK_TAB,            /*9*/'\t')\
	DEF(TK_VERTICAL_TAB,  /*10*/'\v')\
	DEF(TK_NEWLINE,       /*10*/'\n')\
	DEF(TK_FORM_FEED,     /*12*/'\f')\
	DEF(TK_CARR_RETURN,   /*13*/'\r')\
    /*ASCII 32-126*/\
    DEF(TK_SPACE,         /*32*/' ')\
    DEF(TK_BANG,          /*33*/'!')\
    DEF(TK_DQUOTE,        /*34*/'"')\
    DEF(TK_HASH,          /*35*/'#')\
    DEF(TK_DOLLAR,        /*36*/'$')\
    DEF(TK_PERCENT,       /*37*/'%')\
    DEF(TK_AMP,           /*38*/'&')\
    DEF(TK_SQUOTE,        /*39*/'\'')\
    DEF(TK_LPAREN,        /*40*/'(')\
    DEF(TK_RPAREN,        /*41*/')')\
    DEF(TK_STAR,          /*42*/'*')\
    DEF(TK_PLUS,          /*43*/'+')\
    DEF(TK_COMMA,         /*44*/',')\
    DEF(TK_MINUS,         /*45*/'-')\
    DEF(TK_DOT,           /*46*/'.')\
    DEF(TK_SLASH,         /*47*/'/')\
    DEF(TK_0,             /*48*/'0')\
    DEF(TK_1,             /*49*/'1')\
    DEF(TK_2,             /*50*/'2')\
    DEF(TK_3,             /*51*/'3')\
    DEF(TK_4,             /*52*/'4')\
    DEF(TK_5,             /*53*/'5')\
    DEF(TK_6,             /*54*/'6')\
    DEF(TK_7,             /*55*/'7')\
    DEF(TK_8,             /*56*/'8')\
    DEF(TK_9,             /*57*/'9')\
    DEF(TK_COLON,         /*58*/':')\
    DEF(TK_SEMICOLON,     /*59*/';')\
    DEF(TK_LT,            /*60*/'<')\
    DEF(TK_EQ,            /*61*/'=')\
    DEF(TK_GT,            /*62*/'>')\
    DEF(TK_QUESTION,      /*63*/'?')\
    DEF(TK_AT,            /*64*/'@')\
    DEF(TK_A,             /*65*/'A')\
    DEF(TK_B,             /*66*/'B')\
    DEF(TK_C,             /*67*/'C')\
    DEF(TK_D,             /*68*/'D')\
    DEF(TK_E,             /*69*/'E')\
    DEF(TK_F,             /*70*/'F')\
    DEF(TK_G,             /*71*/'G')\
    DEF(TK_H,             /*72*/'H')\
    DEF(TK_I,             /*73*/'I')\
    DEF(TK_J,             /*74*/'J')\
    DEF(TK_K,             /*75*/'K')\
    DEF(TK_L,             /*76*/'L')\
    DEF(TK_M,             /*77*/'M')\
    DEF(TK_N,             /*78*/'N')\
    DEF(TK_O,             /*79*/'O')\
    DEF(TK_P,             /*80*/'P')\
    DEF(TK_Q,             /*81*/'Q')\
    DEF(TK_R,             /*82*/'R')\
    DEF(TK_S,             /*83*/'S')\
    DEF(TK_T,             /*84*/'T')\
    DEF(TK_U,             /*85*/'U')\
    DEF(TK_V,             /*86*/'V')\
    DEF(TK_W,             /*87*/'W')\
    DEF(TK_X,             /*88*/'X')\
    DEF(TK_Y,             /*89*/'Y')\
    DEF(TK_Z,             /*90*/'Z')\
    DEF(TK_LBRACKET,      /*91*/'[')\
    DEF(TK_BACKSLASH,     /*92*/'\\')\
    DEF(TK_RBRACKET,      /*93*/']')\
    DEF(TK_CARET,         /*94*/'^')\
    DEF(TK_UNDERSCORE,    /*95*/'_')\
    DEF(TK_BACKTICK,      /*96*/'`')\
    DEF(TK_a,             /*97*/'a')\
    DEF(TK_b,             /*98*/'b')\
    DEF(TK_c,             /*99*/'c')\
    DEF(TK_d,            /*100*/'d')\
    DEF(TK_e,            /*101*/'e')\
    DEF(TK_f,            /*102*/'f')\
    DEF(TK_g,            /*103*/'g')\
    DEF(TK_h,            /*104*/'h')\
    DEF(TK_i,            /*105*/'i')\
    DEF(TK_j,            /*106*/'j')\
    DEF(TK_k,            /*107*/'k')\
    DEF(TK_l,            /*108*/'l')\
    DEF(TK_m,            /*109*/'m')\
    DEF(TK_n,            /*110*/'n')\
    DEF(TK_o,            /*111*/'o')\
    DEF(TK_p,            /*112*/'p')\
    DEF(TK_q,            /*113*/'q')\
    DEF(TK_r,            /*114*/'r')\
    DEF(TK_s,            /*115*/'s')\
    DEF(TK_t,            /*116*/'t')\
    DEF(TK_u,            /*117*/'u')\
    DEF(TK_v,            /*118*/'v')\
    DEF(TK_w,            /*119*/'w')\
    DEF(TK_x,            /*120*/'x')\
    DEF(TK_y,            /*121*/'y')\
    DEF(TK_z,            /*122*/'z')\
    DEF(TK_LBRACE,       /*123*/'{')\
    DEF(TK_PIPE,         /*124*/'|')\
    DEF(TK_RBRACE,       /*125*/'}')\
    DEF(TK_TILDE,        /*126*/'~')\
    /* Keywords 128+ */\
	/* PreProcess */\
	DEF(TK_PP_INCLUDE, TK_KEYWORD_BEGIN)\
	DEF(TK_PP_DEFINE)\
	DEF(TK_PP_IFNDEF)\
	DEF(TK_PP_IFDEF)\
	DEF(TK_PP_ENDIF)\
	DEF(TK_PP_UNDEF)\
	DEF(TK_PP_ELIF)\
	DEF(TK_PP_ELSE)\
	DEF(TK_PP_ERROR)\
	DEF(TK_PP_PRAGMA)\
	DEF(TK_PP_LINE)\
	DEF(TK_PP_IF)\
	DEF(TK_PP_HASH_HASH)\
	DEF(TK_PP_HASH)\
	/* Keyword */\
	DEF(TK_STATIC_ASSERT)\
	DEF(TK_THREAD_LOCAL)\
	DEF(TK_IMAGINARY)\
	DEF(TK_NORETURN)\
	DEF(TK_COMPLEX)\
	DEF(TK_GENERIC)\
	DEF(TK_ALIGNOF)\
	DEF(TK_ALIGNAS)\
	DEF(TK_ATOMIC)\
	DEF(TK_CONTINUE)\
	DEF(TK_VOLATILE)\
	DEF(TK_REGISTER)\
	DEF(TK_RESTRICT)\
	DEF(TK_TYPEDEF)\
	DEF(TK_DEFAULT)\
	DEF(TK_TYPEOF)\
	DEF(TK_SWITCH)\
	DEF(TK_STATIC)\
	DEF(TK_SIZEOF)\
	DEF(TK_RETURN)\
	DEF(TK_INLINE)\
	DEF(TK_EXTERN)\
	DEF(TK_WHILE)\
	DEF(TK_CONST)\
	DEF(TK_BREAK)\
	DEF(TK_GOTO)\
	DEF(TK_ELSE)\
	DEF(TK_CASE)\
	DEF(TK_AUTO)\
	DEF(TK_FOR)\
	DEF(TK_IF)\
	DEF(TK_DO)\
	/* Types */\
	DEF(TK_UNSIGNED)\
	DEF(TK_STRUCT)\
	DEF(TK_SIGNED)\
	DEF(TK_DOUBLE)\
	DEF(TK_FLOAT)\
	DEF(TK_SHORT)\
	DEF(TK_BOOL)\
	DEF(TK_UNION)\
	DEF(TK_VOID)\
	DEF(TK_LONG)\
	DEF(TK_CHAR)\
	DEF(TK_ENUM)\
	DEF(TK_INT)\
	DEF(TK_PTRDIFF_T)\
	DEF(TK_UINT64_T)\
	DEF(TK_UINT32_T)\
	DEF(TK_UINT16_T)\
	DEF(TK_INT64_T)\
	DEF(TK_INT32_T)\
	DEF(TK_INT16_T)\
	DEF(TK_WCHAR_T)\
	DEF(TK_UINT8_T)\
	DEF(TK_SIZE_T)\
	DEF(TK_INT8_T)\
	/* Operators */\
    DEF(TK_INC,           /* ++ */)\
    DEF(TK_DEC,           /* -- */)\
    DEF(TK_ARROW,         /* -> */)\
    DEF(TK_LSHIFT,        /* << */)\
    DEF(TK_RSHIFT,        /* >> */)\
    DEF(TK_LE,            /* <= */)\
    DEF(TK_GE,            /* >= */)\
    DEF(TK_EQ_EQ,         /* == */)\
    DEF(TK_NE,            /* != */)\
    DEF(TK_AND,           /* && */)\
    DEF(TK_OR,            /* || */)\
    DEF(TK_ADD_ASSIGN,    /* += */)\
    DEF(TK_SUB_ASSIGN,    /* -= */)\
    DEF(TK_MUL_ASSIGN,    /* *= */)\
    DEF(TK_DIV_ASSIGN,    /* /= */)\
    DEF(TK_MOD_ASSIGN,    /* %= */)\
    DEF(TK_AND_ASSIGN,    /* &= */)\
    DEF(TK_OR_ASSIGN,     /* |= */)\
    DEF(TK_XOR_ASSIGN,    /* ^= */)\
    DEF(TK_LSHIFT_ASSIGN, /* <<=*/)\
    DEF(TK_RSHIFT_ASSIGN, /* >>=*/)\
    DEF(TK_ELLIPSIS,      /* ...*/)\
    DEF(TK_HASH_HASH,     /* ## */)\
	DEF(TK_COUNT)
DEF_ENUM(TK);
STATIC_ASSERT((TK_COUNT-1) <= TK_KEYWORD_END, "Not setup to support more than 256 tokens!");

#define DELIM "\x03"

#define DEF_TK_PP(DEF)\
	DEF("#",  TK_PP_HASH,     TOK_CAT_ESCAPE)\
	DEF("##", TK_PP_HASH_HASH, TOK_CAT_ESCAPE)

// Prompt Claude:
// Fill in the rest of the C11 keywords, types and operators in this format
#define DEF_TK_INPUT(DEF)\
	DEF("+",        TK_PLUS,  TOK_CAT_OPERATOR)\
	DEF("=",        TK_EQ,    TOK_CAT_ASSIGN)\
	DEF("#if"DELIM, TK_PP_IF, TOK_CAT_PP)\
	DEF("do"DELIM,  TK_DO,    TOK_CAT_KEYWORD)\
	DEF("int"DELIM, TK_INT,   TOK_CAT_TYPE)
	
// Claude Output:
#define DEF_TK_BASE(DEF)\
    DEF("!",                   TK_BANG,          TOK_CAT_OPERATOR)\
    DEF("%",                   TK_PERCENT,       TOK_CAT_OPERATOR)\
    DEF("&",                   TK_AMP,           TOK_CAT_OPERATOR)\
    DEF("(",                   TK_LPAREN,        TOK_CAT_OPERATOR)\
    DEF(")",                   TK_RPAREN,        TOK_CAT_OPERATOR)\
    DEF("*",                   TK_STAR,          TOK_CAT_OPERATOR)\
    DEF("+",                   TK_PLUS,          TOK_CAT_OPERATOR)\
    DEF(",",                   TK_COMMA,         TOK_CAT_OPERATOR)\
    DEF("-",                   TK_MINUS,         TOK_CAT_OPERATOR)\
    DEF(".",                   TK_DOT,           TOK_CAT_OPERATOR)\
    DEF("/",                   TK_SLASH,         TOK_CAT_OPERATOR)\
    DEF(":",                   TK_COLON,         TOK_CAT_OPERATOR)\
    DEF(";",                   TK_SEMICOLON,     TOK_CAT_OPERATOR)\
    DEF("<",                   TK_LT,            TOK_CAT_OPERATOR)\
    DEF("=",                   TK_EQ,            TOK_CAT_OPERATOR)\
    DEF(">",                   TK_GT,            TOK_CAT_OPERATOR)\
    DEF("?",                   TK_QUESTION,      TOK_CAT_OPERATOR)\
    DEF("[",                   TK_LBRACKET,      TOK_CAT_OPERATOR)\
    DEF("]",                   TK_RBRACKET,      TOK_CAT_OPERATOR)\
    DEF("^",                   TK_CARET,         TOK_CAT_OPERATOR)\
    DEF("{",                   TK_LBRACE,        TOK_CAT_OPERATOR)\
    DEF("|",                   TK_PIPE,          TOK_CAT_OPERATOR)\
    DEF("}",                   TK_RBRACE,        TOK_CAT_OPERATOR)\
    DEF("~",                   TK_TILDE,         TOK_CAT_OPERATOR)\
    DEF("++",                  TK_INC,           TOK_CAT_OPERATOR)\
    DEF("--",                  TK_DEC,           TOK_CAT_OPERATOR)\
    DEF("->",                  TK_ARROW,         TOK_CAT_OPERATOR)\
    DEF("<<",                  TK_LSHIFT,        TOK_CAT_OPERATOR)\
    DEF(">>",                  TK_RSHIFT,        TOK_CAT_OPERATOR)\
    DEF("<=",                  TK_LE,            TOK_CAT_OPERATOR)\
    DEF(">=",                  TK_GE,            TOK_CAT_OPERATOR)\
    DEF("==",                  TK_EQ_EQ,         TOK_CAT_OPERATOR)\
    DEF("!=",                  TK_NE,            TOK_CAT_OPERATOR)\
    DEF("&&",                  TK_AND,           TOK_CAT_OPERATOR)\
    DEF("||",                  TK_OR,            TOK_CAT_OPERATOR)\
    DEF("+=",                  TK_ADD_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("-=",                  TK_SUB_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("*=",                  TK_MUL_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("/=",                  TK_DIV_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("%=",                  TK_MOD_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("&=",                  TK_AND_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("|=",                  TK_OR_ASSIGN,     TOK_CAT_OPERATOR)\
    DEF("^=",                  TK_XOR_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("<<=",                 TK_LSHIFT_ASSIGN, TOK_CAT_OPERATOR)\
    DEF(">>=",                 TK_RSHIFT_ASSIGN, TOK_CAT_OPERATOR)\
    DEF("...",                 TK_ELLIPSIS,      TOK_CAT_OPERATOR)\
	DEF(";",                   TK_SEMICOLON,     TOK_CAT_ASSIGN)\
	DEF("=",                   TK_EQ,            TOK_CAT_ASSIGN)\
	DEF("#",                   TK_HASH,          TOK_CAT_ESCAPE)\
	DEF("##",                  TK_HASH_HASH,     TOK_CAT_ESCAPE)\
	DEF("#ifndef"DELIM,        TK_PP_IFNDEF,     TOK_CAT_PP)\
	DEF("#ifdef"DELIM,         TK_PP_IFDEF,      TOK_CAT_PP)\
	DEF("#if"DELIM,            TK_PP_IF,         TOK_CAT_PP)\
	DEF("#elif"DELIM,          TK_PP_ELIF,       TOK_CAT_PP)\
	DEF("#line"DELIM,          TK_PP_LINE,       TOK_CAT_PP)\
	DEF("#else"DELIM,          TK_PP_ELSE,       TOK_CAT_PP)\
	DEF("#error"DELIM,         TK_PP_ERROR,      TOK_CAT_PP)\
	DEF("#undef"DELIM,         TK_PP_UNDEF,      TOK_CAT_PP)\
	DEF("#endif"DELIM,         TK_PP_ENDIF,      TOK_CAT_PP)\
	DEF("#pragma"DELIM,        TK_PP_PRAGMA,     TOK_CAT_PP)\
	DEF("#define"DELIM,        TK_PP_DEFINE,     TOK_CAT_PP)\
	DEF("#include"DELIM,       TK_PP_INCLUDE,    TOK_CAT_PP)\
	DEF("do"DELIM,             TK_DO,            TOK_CAT_KEYWORD)\
	DEF("if"DELIM,             TK_IF,            TOK_CAT_KEYWORD)\
	DEF("for"DELIM,            TK_FOR,           TOK_CAT_KEYWORD)\
	DEF("auto"DELIM,           TK_AUTO,          TOK_CAT_KEYWORD)\
	DEF("case"DELIM,           TK_CASE,          TOK_CAT_KEYWORD)\
	DEF("else"DELIM,           TK_ELSE,          TOK_CAT_KEYWORD)\
	DEF("goto"DELIM,           TK_GOTO,          TOK_CAT_KEYWORD)\
	DEF("break"DELIM,          TK_BREAK,         TOK_CAT_KEYWORD)\
	DEF("const"DELIM,          TK_CONST,         TOK_CAT_KEYWORD)\
	DEF("while"DELIM,          TK_WHILE,         TOK_CAT_KEYWORD)\
	DEF("typeof"DELIM,         TK_TYPEOF,        TOK_CAT_KEYWORD)\
	DEF("switch"DELIM,         TK_SWITCH,        TOK_CAT_KEYWORD)\
	DEF("static"DELIM,         TK_STATIC,        TOK_CAT_KEYWORD)\
	DEF("inline"DELIM,         TK_INLINE,        TOK_CAT_KEYWORD)\
	DEF("sizeof"DELIM,         TK_SIZEOF,        TOK_CAT_KEYWORD)\
	DEF("return"DELIM,         TK_RETURN,        TOK_CAT_KEYWORD)\
	DEF("extern"DELIM,         TK_EXTERN,        TOK_CAT_KEYWORD)\
	DEF("typedef"DELIM,        TK_TYPEDEF,       TOK_CAT_KEYWORD)\
	DEF("default"DELIM,        TK_DEFAULT,       TOK_CAT_KEYWORD)\
	DEF("_Atomic"DELIM,        TK_ATOMIC,        TOK_CAT_KEYWORD)\
	DEF("register"DELIM,       TK_REGISTER,      TOK_CAT_KEYWORD)\
	DEF("volatile"DELIM,       TK_VOLATILE,      TOK_CAT_KEYWORD)\
	DEF("continue"DELIM,       TK_CONTINUE,      TOK_CAT_KEYWORD)\
	DEF("restrict"DELIM,       TK_RESTRICT,      TOK_CAT_KEYWORD)\
	DEF("_Alignas"DELIM,       TK_ALIGNAS,       TOK_CAT_KEYWORD)\
	DEF("_Alignof"DELIM,       TK_ALIGNOF,       TOK_CAT_KEYWORD)\
	DEF("_Generic"DELIM,       TK_GENERIC,       TOK_CAT_KEYWORD)\
	DEF("_Complex"DELIM,       TK_COMPLEX,       TOK_CAT_KEYWORD)\
	DEF("_Noreturn"DELIM,      TK_NORETURN,      TOK_CAT_KEYWORD)\
	DEF("_Imaginary"DELIM,     TK_IMAGINARY,     TOK_CAT_KEYWORD)\
	DEF("_Thread_local"DELIM,  TK_THREAD_LOCAL,  TOK_CAT_KEYWORD)\
	DEF("_Static_assert"DELIM, TK_STATIC_ASSERT, TOK_CAT_KEYWORD)\
	DEF("int"DELIM,            TK_INT,           TOK_CAT_TYPE)\
	DEF("enum"DELIM,           TK_ENUM,          TOK_CAT_TYPE)\
	DEF("char"DELIM,           TK_CHAR,          TOK_CAT_TYPE)\
	DEF("long"DELIM,           TK_LONG,          TOK_CAT_TYPE)\
	DEF("void"DELIM,           TK_VOID,          TOK_CAT_TYPE)\
	DEF("bool"DELIM,           TK_BOOL,          TOK_CAT_TYPE)\
	DEF("union"DELIM,          TK_UNION,         TOK_CAT_TYPE)\
	DEF("float"DELIM,          TK_FLOAT,         TOK_CAT_TYPE)\
	DEF("short"DELIM,          TK_SHORT,         TOK_CAT_TYPE)\
	DEF("_Bool"DELIM,          TK_BOOL,          TOK_CAT_TYPE)\
	DEF("signed"DELIM,         TK_SIGNED,        TOK_CAT_TYPE)\
	DEF("struct"DELIM,         TK_STRUCT,        TOK_CAT_TYPE)\
	DEF("double"DELIM,         TK_DOUBLE,        TOK_CAT_TYPE)\
	DEF("size_t"DELIM,         TK_SIZE_T,        TOK_CAT_TYPE)\
	DEF("int8_t"DELIM,         TK_INT8_T,        TOK_CAT_TYPE)\
	DEF("uint8_t"DELIM,        TK_UINT8_T,       TOK_CAT_TYPE)\
	DEF("wchar_t"DELIM,        TK_WCHAR_T,       TOK_CAT_TYPE)\
	DEF("int16_t"DELIM,        TK_INT16_T,       TOK_CAT_TYPE)\
	DEF("int32_t"DELIM,        TK_INT32_T,       TOK_CAT_TYPE)\
	DEF("int64_t"DELIM,        TK_INT64_T,       TOK_CAT_TYPE)\
	DEF("uint16_t"DELIM,       TK_UINT16_T,      TOK_CAT_TYPE)\
	DEF("uint32_t"DELIM,       TK_UINT32_T,      TOK_CAT_TYPE)\
	DEF("unsigned"DELIM,       TK_UNSIGNED,      TOK_CAT_TYPE)\
	DEF("uint64_t"DELIM,       TK_UINT64_T,      TOK_CAT_TYPE)\
	DEF("ptrdiff_t"DELIM,      TK_PTRDIFF_T,     TOK_CAT_TYPE)

	// DEF("\\\n"      ,TOK_PREPROCESS_CONTINUE      ,TOK_CAT_PP_OPERATOR)

typedef struct TokDef {
	const char* name;
	int len;
	int tok;
	int cat;
} TokDef;

#define STR_LEN(_str) (sizeof(_str) - 1)
#define DEF_TOK_ENUM_ITEM(_name, _tok, _cat) _tok,
#define DEF_TOK_STRING_ITEM(_name, _tok, _cat) case _tok: return #_tok"("_name")";
#define DEF_TOK_DEFINITION_ITEM(_name, _tok, _cat) (TokDef){ _name, (int)STR_LEN(_name), (int)_tok, (int)_cat },
#define DEF_TOK_METHODS(_tokdef) \
	typedef enum PACKED _tokdef { \
		_tokdef##_ASCII = 128, \
		DEF_##_tokdef(DEF_TOK_ENUM_ITEM) \
		_tokdef##_COUNT, \
	} _tokdef; \
	static const char* string_##_tokdef(_tokdef _item) { \
		switch(_item) { \
			DEF_##_tokdef(DEF_TOK_STRING_ITEM) \
			default: return #_tokdef "_N/A"; \
		} \
	} \
	static const TokDef _tokdef##_DEFINITIONS[] = { \
		DEF_##_tokdef(DEF_TOK_DEFINITION_ITEM) \
	};


DEF_TOK_METHODS(TOK)
DEF_TOK_METHODS(TOK_COMMENT)
DEF_TOK_METHODS(TOK_QUOTE)


// typedef enum PACKED TK_PP {
// 	DEF_TK_PP(DEF_TOK_ENUM_ITEM)
// 	TK_PP_COUNT,
// } TK_PP;
// static const char* string_TK_PP(TK item) {
// 	switch(item) {
// 		DEF_TK_PP(DEF_TOK_STRING_ITEM)
// 		default: return "TK_PP_NA";
// 	}
// }
static const TokDef TK_PP_DEFINITIONS[]   = { DEF_TK_PP(DEF_TOK_DEFINITION_ITEM)   };
static const TokDef TK_BASE_DEFINITIONS[] = { DEF_TK_BASE(DEF_TOK_DEFINITION_ITEM) };


/*
	We will have Sparse Trie and Packed Trie
	at a certain point it can switch past a certain density
	that density should probably had to do with scan time
	will have to test to compare

	Traverse
	Store index of first fail.
	If tE hit, go back to first fail.
	Shift all right by 1.
	Insert new char. Succ = open index at end. Fail = 1.
	Each fail before current char increment by 1.
	Go to new index at end. Insert rest of new char

	tok:
		t0=#if_
		t1=#def_
		t2=#ifdef_

	Words Added:
		if
		def
		ifdef

	idx   0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7
	char  #  d  i  f  d  _ t0 tE  e  f  _ t2 tE  e  f  _ t1 tE
	succ  1  7  1  2  9  1        1  1  1        1  1  1
	fail  6  5  4  4  3  2        4  3  2        4  3  2
*/

/*
 * Flat Trie
 */

// #define FRIE_DEBUG
#ifdef FRIE_DEBUG
	#define FRIE_LOG(...) printf(__VA_ARGS__)
#else
	#define FRIE_LOG(...)
#endif

#define DEF_CHAR(DEF) \
	DEF(CHAR_IDENT) \
	DEF(CHAR_ALPHA) \
	DEF(CHAR_DIGIT) \
	DEF(CHAR_LOWER) \
	DEF(CHAR_UPPER) \
	DEF(CHAR_SPACE) \
	DEF(CHAR_NEWLINE)
DEF_ENUM(CHAR);

static const bool IDENT_CHAR[128] = {
    ['a'...'z'] = 1,
    ['A'...'Z'] = 1,
    ['0'...'9'] = 1,
    ['_'] = 1,
};

// TODO do I want this?
static const u8 CHAR_FLAGS[128] = {
    ['a'...'z'] = CHAR_IDENT | CHAR_ALPHA | CHAR_LOWER,
    ['A'...'Z'] = CHAR_IDENT | CHAR_ALPHA | CHAR_UPPER,
    ['0'...'9'] = CHAR_IDENT | CHAR_DIGIT,
    ['_']       = CHAR_IDENT,
    [' ']       = CHAR_SPACE,
    ['\t']      = CHAR_SPACE,
    ['\n']      = CHAR_SPACE | CHAR_NEWLINE,
};

#define IS_DELIM_TOKEN(_c)   (_c == TK_DELIMIT || _c == TK_MUNCH)
#define IS_ERROR_TOKEN(_c)     (_c == TK_ERR)
#define IS_KEYWORD_TOKEN(_c) (_c >= TK_KEYWORD_BEGIN)
#define IS_TOKEN(_c)         (IS_DELIM_TOKEN(_c) || IS_KEYWORD_TOKEN(_c) || IS_ERROR_TOKEN(_c))

#define IS_IDENT_CHAR(_c) IDENT_CHAR[(u8)(_c)]
#define IS_DELIM_CHAR(_c) !IDENT_CHAR[(u8)(_c)]

#define IS_DIGIT_CHAR(_c) (CHAR_FLAGS[(u8)(_c)] & CHAR_DIGIT)
#define IS_SPACE_CHAR(_c) (CHAR_FLAGS[(u8)(_c)] & CHAR_SPACE)

#define DEF_DISPATCH(_name, _tok, _cat) [_tok] = &&_tok,
#define DISPATCH_ASCII_CHAR_RANGE ' ' ... '~' // 32 ... 126 

#define TRIE_MAX_PACKED_OFFSET  4096  // 12 bit
#define TRIE_MAX_SPARSE_OFFSET  65536 // 16 bit
#define MAX_TOKEN_SIZE 16
typedef union PACKED FrieNode {
	/* First 128 ASCII chars are sparse nodes. Char value is index. */
	struct PACKED { 
		u32  succ : 16; // Amount to jump.
		u32  cat  : 8;  // Token Category
		u32  tok  : 4;  // Special Token Value. 0-6 Special Frie Token. Only 4 bits needed.
		u32  pad  : 4;  // 4 more bit available
	} sparse;
	/* All tokens past first 128 ASCII chars are packed nodes. Can contain TK_DELIMIT or TK_MUNCH nodes. */
	struct PACKED { 
		u32  val  : 8;  // Token Value. 0-6 Special Frie Token. 32-128 ASCII Tokens. >128 Keyword Tokens
		u32  succ : 12; // offset to jump on success
		u32  fail : 12; // offset to jump on fail
	} packed;
	/* Endpoint token node. Error or Keword token. Trie exits when ecnountering these. */
	struct PACKED {
		u32   val : 8;  // Token Value. 0-6 Special Frie Token. 32-128 ASCII Tokens. >128 Keyword Tokens
		u32   cat : 8;  // token category
		u32   len : 6;  // token word length
		u32   pad : 10; // 10 more bits available
	} terminator;
	u32 raw; // Must use u32 for everything to ensure union packs to 4 bytes. Differing types makes the compiler add arbitrary packing.
} FrieNode;
STATIC_ASSERT(sizeof(FrieNode) == 4);

static FrieNode TOK_BASE_FRIE[1024];
static FrieNode TOK_PP_FRIE[1024];

static void FrieLog(FrieNode* trie)
{
	FrieNode t;
	LOG("FrieNode Size:%llu sparse:%llu packed:%llu terminator:%llu\n", sizeof(t), sizeof(t.sparse), sizeof(t.packed), sizeof(t.terminator));
	LOG("Frie:\n");
	int iNode = 32; FrieNode node = trie[iNode]; 
	fprintf(stderr, "Sparse Table: " ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "index" ANSI_RESET ANSI_WHITE "char" ANSI_DIM ANSI_ITALIC ANSI_YELLOW "SuccessTarget\n "ANSI_RESET);
	while ( iNode < TK_KEYWORD_BEGIN) {
		fprintf(stderr, ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "%d" ANSI_RESET ANSI_WHITE "%c" ANSI_DIM ANSI_ITALIC ANSI_YELLOW "%d" ANSI_RESET ANSI_BRIGHT_BLACK "%c" ANSI_RESET, iNode, iNode, node.sparse.succ, iNode == 127 ? '\n' : '|');
		node = trie[++iNode];
	}
	fprintf(stderr, "Packed Trie: " ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "index" ANSI_RESET ANSI_WHITE "char/token" ANSI_DIM ANSI_GREEN "SuccessOffset" ANSI_ITALIC ANSI_YELLOW "SuccessTarget" ANSI_RESET ANSI_DIM ANSI_RED "FailOffset" ANSI_RESET ANSI_ITALIC ANSI_DIM ANSI_YELLOW "FailTarget\n" ANSI_RESET);
	while (node.packed.val != '\0' || iNode < 128) {
		if (IS_DELIM_TOKEN(node.packed.val)) 
			fprintf(stderr, ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "%d" ANSI_RESET ANSI_WHITE "%s" ANSI_DIM ANSI_GREEN "%d" ANSI_ITALIC ANSI_YELLOW "%d" ANSI_RESET ANSI_DIM ANSI_RED "%d" ANSI_RESET ANSI_ITALIC ANSI_DIM ANSI_YELLOW "%d" ANSI_BRIGHT_BLACK "|" ANSI_RESET, iNode, string_TK(node.packed.val), node.packed.succ, node.packed.succ+iNode, node.packed.fail, node.packed.fail+iNode);
		else if (IS_TOKEN(node.packed.val)) 
			fprintf(stderr, ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "%d" ANSI_RESET ANSI_WHITE "%s" ANSI_DIM ANSI_BRIGHT_BLACK "%c" ANSI_RESET, iNode, string_TK(node.terminator.val), node.terminator.val == TK_ERR ? '\n' : '|');
		else  			       
			fprintf(stderr, ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "%d" ANSI_RESET ANSI_WHITE "%c" ANSI_DIM ANSI_GREEN "%d" ANSI_ITALIC ANSI_YELLOW "%d" ANSI_RESET ANSI_DIM ANSI_RED "%d" ANSI_RESET ANSI_ITALIC ANSI_DIM ANSI_YELLOW "%d" ANSI_BRIGHT_BLACK "|" ANSI_RESET, iNode, node.packed.val, node.packed.succ, node.packed.succ+iNode, node.packed.fail, node.packed.fail+iNode);
		node = trie[++iNode];
	}
	fprintf(stderr, "\n");
}

static TK FrieGet(const char *pText, FrieNode *pFrie) 
{
	FRIE_LOG("Checking Frie for %s\n", pText);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverride-init"
	static void *codeDispatch[] = {	
		[0 ... TOK_COUNT] = &&TK_NONE,
		[TK_ERR]          = &&TK_ERR,
		[TK_DELIMIT]      = &&TK_DELIMIT,
		[TK_PACKED_CHAR]  = &&TK_PACKED_CHAR,
		[TK_SPARSE_CHAR]  = &&TK_SPARSE_CHAR,
		[TK_NEWLINE]      = &&TK_SPARSE_CHAR,
		[TK_TAB]          = &&TK_SPARSE_CHAR,
		[TK_ASCII_RANGE]  = &&TK_PACKED_CHAR,
		[TK_KEYWORD_RANGE] = &&TK_ALL,
	};
#pragma GCC diagnostic pop

	void **disp  = codeDispatch;	

	struct {
		int  iT;
		int  iN;
		FrieNode n;
		char cT;
		TK   tk;
	} step;
	ZERO(&step);

	step.cT = pText[0];
	step.n = pFrie[(u8)step.cT];

TK_SPARSE_CHAR:
	{
		FRIE_LOG("TK_SPARSE_CHAR iT:%-4d iN:%-4d %4d:%s %s %s %s jump%d ", step.iT, step.iN, step.cT, EscapeChar(step.cT),  string_TK(step.cT), string_TK(step.n.sparse.tok), string_TOK_CAT(step.n.sparse.cat), step.n.sparse.succ);
		step.tk = step.cT; // Store last valid token
		// Retrieve next char first to use in setup of next node dispatch.
		step.iT++; step.cT = pText[step.iT]; 
		// Setup next node dispatch.
		step.iN = step.n.sparse.succ > 0 && step.cT > 0 ? step.n.sparse.succ : step.cT;
		TK tk   = step.n.sparse.tok; // Must dispatch from this node token value.
		step.n  = pFrie[step.iN];
		FRIE_LOG("dispatch-->%s\n", string_TK(tk));
		goto *disp[tk];
	}

TK_PACKED_CHAR: 
	{
		FRIE_LOG("TK_PACKED_CHAR iT:%-4d iN:%-4d %4d:%s==", step.iT, step.iN, step.cT, EscapeChar(step.cT));
		FRIE_LOG("%s:%-4d ", EscapeChar(step.n.packed.val), step.n.packed.val);
		// Determine node match and retrieve next node.
		bool match = step.n.packed.val == step.cT;
		step.iN += match ? step.n.packed.succ : step.n.packed.fail;
		step.n   = pFrie[step.iN];
		// Progress to next text char if matched.
		step.iT += match; step.cT = pText[step.iT];
		FRIE_LOG("dispatch-->%d:%s\n", step.iN, string_TK(step.n.packed.val));
		goto *disp[step.n.packed.val];
	}

TK_DELIMIT: 
	{
		FRIE_LOG("TK_DELIMIT     iT:%-4d iN:%-4d %4d:%s==", step.iT, step.iN, step.cT, EscapeChar(step.cT));
		FRIE_LOG("%s:%-4d ", EscapeChar(step.n.packed.val), step.n.packed.val);
		bool delim = IS_DELIM_CHAR(step.cT);
		step.iN += delim ? step.n.packed.succ : step.n.packed.fail;
		step.n   = pFrie[step.iN];
		FRIE_LOG("dispatch-->%s\n", string_TK(step.n.packed.val));
		goto *disp[step.n.packed.val];
	}

TK_ALL:
	step.tk = step.n.terminator.val; // Store last valid token
	FRIE_LOG("Token found %d %s\n", step.tk, string_TK(step.tk));
	return step.tk;

TK_ERR:
TK_NONE:
	FRIE_LOG("No token found! %d %s\n", step.tk, string_TK(step.tk));
	return step.tk;
}

/* Shift all frie nodes right by 1 updating all offsets. */
static void FrieShift(FrieNode* pFrie, int iInsertNode, int iEndNode)
{
	// Shift all to right by 1 to make room for new char condition.
	FRIE_LOG("Shift 1 dst:%d src:%d len:%d\n", iInsertNode+1, iInsertNode, iEndNode - iInsertNode);
	memmove(pFrie + iInsertNode + 1, pFrie + iInsertNode, (iEndNode - iInsertNode) * sizeof(FrieNode));

	// Increment sparse ascii jump values if they would have jumped past current insertion
	for (int iNodePrev = 0; iNodePrev < TK_KEYWORD_BEGIN; iNodePrev++) {
		FrieNode *pPrevNode = pFrie + iNodePrev;
		if (pPrevNode->sparse.succ > iInsertNode) { 
			FRIE_LOG("Increment sparse i%d %c succ%d\n", iNodePrev, iNodePrev, pPrevNode->sparse.succ);
			pPrevNode->sparse.succ++;
		}
	}

	// Increment all fail succ values in prior trie steps if they would have jumped past current insertion
	for (int iNodePrev = TK_KEYWORD_BEGIN; iNodePrev < iInsertNode; iNodePrev++) {
		FrieNode *pPrevNode = pFrie + iNodePrev;
		int diff = iInsertNode - iNodePrev;
		if (IS_KEYWORD_TOKEN(pPrevNode->packed.val)) continue;
		if (pPrevNode->packed.succ > diff) {
			pPrevNode->packed.succ++;
			FRIE_LOG("Increment succ i%d %c succ%d\n", iNodePrev, pPrevNode->packed.val, pPrevNode->packed.succ);
		}
		if (pPrevNode->packed.fail > diff) {
			pPrevNode->packed.fail++;
			FRIE_LOG("Increment fail i%d %c fail%d\n", iNodePrev, pPrevNode->packed.val, pPrevNode->packed.fail);
		}
	}
}

static RESULT ConstructFrie(int tokCount, const TokDef* tokDefs, int frieCapacity, FrieNode* pFrie) 
{
	CHECK(frieCapacity > 256, RESULT_CAPACITY_ERROR);
	ZERO_RANGE(pFrie, frieCapacity);

	for (int i = '!'; i <= '/'; ++i) pFrie[i] = (FrieNode){ .sparse.cat = TOK_CAT_OPERATOR }; 
	for (int i = '0'; i <= '9'; ++i) pFrie[i] = (FrieNode){ .sparse.cat = TOK_CAT_DIGIT }; 
	for (int i = 'A'; i <= 'Z'; ++i) pFrie[i] = (FrieNode){ .sparse.cat = TOK_CAT_ALPHA }; 
	for (int i = 'a'; i <= 'z'; ++i) pFrie[i] = (FrieNode){ .sparse.cat = TOK_CAT_ALPHA }; 
	pFrie['\t'] = (FrieNode){ .sparse.cat = TOK_CAT_WHITESPACE }; 
	pFrie['\n'] = (FrieNode){ .sparse.cat = TOK_CAT_WHITESPACE }; 
	pFrie[' ']  = (FrieNode){ .sparse.cat = TOK_CAT_WHITESPACE }; 
	pFrie['^']  = (FrieNode){ .sparse.cat = TOK_CAT_OPERATOR }; 
	pFrie['[']  = (FrieNode){ .sparse.cat = TOK_CAT_SCOPE }; 
	pFrie[']']  = (FrieNode){ .sparse.cat = TOK_CAT_SCOPE }; 
	pFrie['{']  = (FrieNode){ .sparse.cat = TOK_CAT_SCOPE }; 
	pFrie['}']  = (FrieNode){ .sparse.cat = TOK_CAT_SCOPE }; 
	pFrie['(']  = (FrieNode){ .sparse.cat = TOK_CAT_SCOPE }; 
	pFrie[')']  = (FrieNode){ .sparse.cat = TOK_CAT_SCOPE }; 
	pFrie['_']  = (FrieNode){ .sparse.cat = TOK_CAT_ALPHA }; 
	pFrie['\\'] = (FrieNode){ .sparse.cat = TOK_CAT_ESCAPE }; 

	int iTok = 0;
	int iEndNode = TK_KEYWORD_BEGIN;

NextTok: 
#ifdef FRIE_DEBUG
	FrieLog(pFrie);
#endif

	if (iTok == tokCount) goto RESULT_SUCCESS;
	TokDef def = tokDefs[iTok];
	int iNode = 0; int iName = 0; int iNodeFirstFail = TK_KEYWORD_BEGIN; int iNodeFirstJump = 0; 
	bool delim = def.name[def.len-1] == TK_DELIMIT;

NextNameChar: 
	char cName = def.name[iName];
	if (cName == '\0' && iName == 0) {
		LOG_WARN("Trying to add empty token!\n");
		iTok++; 
		goto NextTok;
	}
	char cNameNext= def.name[iName+1];

	if (iName == 0) {
		FrieNode *pNode = pFrie + cName;
		FrieNode node = *pNode;

		// One char token
		if (cNameNext == '\0') {
			FRIE_LOG("One Char Token i%d %c end%d %s\n", (u8)cName, cName, iEndNode, def.name);
			pNode->sparse.cat = def.cat;
			iTok++; 
			goto NextTok;
		}

		// Already added. Jump.
		if (node.sparse.succ > 0) {
			FRIE_LOG("Entry Jump i%d %c end%d %s\n", (u8)cName, cName, iEndNode, def.name);
			iNode = node.sparse.succ;
			iName++;
			goto NextNameChar;
		}		

		// Add new token
		FRIE_LOG("New Entry i%d %c end%d %s\n", (u8)cName, cName, iEndNode, def.name);
		CHECKMSG(iEndNode < TRIE_MAX_SPARSE_OFFSET, RESULT_OFFSET_ERROR, "end offset:%d", iEndNode);
		pNode->sparse.succ = iEndNode;
		pNode->sparse.tok  = TK_PACKED_CHAR;
		iNode = iEndNode; 
		iName++;
		goto NextNameChar;
	}

	{
		FrieNode node  = pFrie[iNode];
		// Encounter a token, must shift to the right and fill in new token.
		if (IS_TOKEN(node.packed.val)) { 
			// CHECKMSG(node.tok.val == TK_ERR || node.tok.val == TK_NONE, RESULT_DUPLICATE_ERROR, "Trying to write token in non-empty node!");

			// FRIE_LOG("Insert Tok i%d firstfail%d end%d %s\n", iNode, iNodeFirstFail, iEndNode, def.name);
			if (iNodeFirstFail != TK_KEYWORD_BEGIN)	iNode = iNodeFirstFail;

			FRIE_LOG("Insert Char i%d %c end%d %s\n", iNode, cName, iEndNode, def.name);
			FrieShift(pFrie, iNode, iEndNode);
			iEndNode++; CHECK(iEndNode < frieCapacity, RESULT_CAPACITY_ERROR);
			u16 succ = iEndNode - iNode;
			CHECKMSG(succ < TRIE_MAX_PACKED_OFFSET, RESULT_OFFSET_ERROR, "succ offset:%d", succ);
			pFrie[iNode] = (FrieNode){ 
				.packed.val   = cName, 
				.packed.succ  = succ, 
				.packed.fail  = 1 
			};
			iName++; iNode = iEndNode;
			goto NextNameChar;
		}

		// Encounter delimit char, must shift to the right and fill in new token.
		if (cName == TK_DELIMIT) {
			FRIE_LOG("Delimit Insert i%d end%d %s\n", iNode, iEndNode, def.name);
			FrieShift(pFrie, iNode, iEndNode);
			bool insertingAtEnd = iEndNode == iNode;
			iEndNode++; CHECK(iEndNode < frieCapacity, RESULT_CAPACITY_ERROR);
			u16 succ = iEndNode - iNode;
			CHECKMSG(succ < TRIE_MAX_PACKED_OFFSET, RESULT_OFFSET_ERROR, "succ offset:%d", succ);
			u16 fail = insertingAtEnd ? succ + 1 : 1; // If inserting at end ERR token is 1 after succ, otherwise fail to next node
			CHECKMSG(fail < TRIE_MAX_PACKED_OFFSET, RESULT_OFFSET_ERROR, "fail offset:%d", fail);
			pFrie[iNode] = (FrieNode){ 
				.packed.val   = TK_DELIMIT, 
				.packed.succ  = succ, 
				.packed.fail  = fail,
			};
			delim = true;
			iName++; iNode = iEndNode;
			goto NextNameChar;
		}

		// End of Token Name. Write token go to next token!
		if (cName == '\0') {
			CHECKMSG(iNode == iEndNode, RESULT_ORDER_ERROR, "Trying to inset shorter token after longer token! %s %s", def.name, string_TK(def.tok));
			FRIE_LOG("Finish Token i%d end%d len%d %s %s\n", iNode, iEndNode, iName - delim, def.name, string_TK(def.tok));
			pFrie[iNode++] = (FrieNode){ .terminator.val = def.tok, .terminator.cat = def.cat, .terminator.len = iName - delim};
			pFrie[iNode++] = (FrieNode){ .terminator.val = TK_ERR,  .terminator.cat = TOK_CAT_ERROR, .terminator.len = 1 };
			iTok++;	iEndNode = iNode;
			goto NextTok;
		}

		// Token char succesfully match with existing trie char
		if (cName == node.packed.val) {
			FRIE_LOG("Char Succ i%d jump%d end%d %s %c==%c\n", iNode, node.packed.succ, iEndNode, def.name, cName, node.packed.val);
			iNodeFirstFail = TK_KEYWORD_BEGIN;
			iNode += node.packed.succ; iName++;
			goto NextNameChar;
		} 

		// Token char fail to match with existing trie char
		if (iNode < iEndNode) {
			FRIE_LOG("Char Fail i%d jump%d end%d %s %c==%c\n", iNode, node.packed.fail, iEndNode, def.name, cName, node.packed.val);
			if (iNodeFirstFail == TK_KEYWORD_BEGIN) iNodeFirstFail = iNode;
			iNode += node.packed.fail;
			goto NextNameChar;
		}

		{
			u16 fail = (def.len + 1) - iName - delim; // +1 as err comes after tok
			CHECKMSG(fail < TRIE_MAX_PACKED_OFFSET, RESULT_OFFSET_ERROR, "fail offset:%d", fail);
			FRIE_LOG("Add Char iT:%d iN:%d fail:%d end:%d delim%d len:%d %s %c\n", iNode, iName, fail, iEndNode, delim, def.len, def.name, cName);
			pFrie[iNode] = (FrieNode){ 
				.packed.val   = cName, 
				.packed.succ  = 1, 
				.packed.fail  = fail,
			};
			iNode++; iEndNode++; iName++;
			goto NextNameChar;
		}
	}

RESULT_ORDER_ERROR:
	LOG_ERR("Trie capacity reached! %d %s\n", iNode, def.name);
	FrieLog(pFrie);
	return RESULT_CAPACITY_ERROR;

RESULT_CAPACITY_ERROR:
	LOG_ERR("Trie capacity reached! %d %s\n", iNode, def.name);
	FrieLog(pFrie);
	return RESULT_CAPACITY_ERROR;

RESULT_DUPLICATE_ERROR:
	LOG_ERR("Trying insert the same token twice! %d %s\n", iNode, def.name);
	FrieLog(pFrie);
	return RESULT_DUPLICATE_ERROR;

RESULT_OFFSET_ERROR:
	LOG_ERR("Trying to add offset greater than TRIE_MAX_OFFSET. %d %s\n", iNode, def.name);
	FrieLog(pFrie);
	return RESULT_OFFSET_ERROR;

RESULT_SUCCESS:
	FrieLog(pFrie);
	for (int i = 0; i < tokCount; ++i) {
		TK tk = FrieGet(tokDefs[i].name, pFrie);
		LOG("%s expected:%s\n", string_TK(tk), string_TK(tokDefs[i].tok));
		MUST(tk == tokDefs[i].tok);
	}
	return RESULT_SUCCESS;
}

typedef u32 tok_hash;
#define MAP_HASH_CAPACITY 1024
#define MAP_PAGE_CAPACITY 8
typedef struct MapTok {
	u8  tok;
	u8  cat;
	u8  len;
	tok_hash hash;
} MapTok;

static MapTok TOK_MAP[MAP_PAGE_CAPACITY][MAP_HASH_CAPACITY] = { { [0 ... MAP_HASH_CAPACITY-1] = { .tok = (int)TOK_ERROR } } };
static MapTok TOK_COMMENT_MAP[MAP_PAGE_CAPACITY][MAP_HASH_CAPACITY]  = { { [0 ... MAP_HASH_CAPACITY-1] = { .tok = (int)TOK_COMMENT_ERROR } } };
static MapTok TOK_QUOTE_MAP[MAP_PAGE_CAPACITY][MAP_HASH_CAPACITY]  = { { [0 ... MAP_HASH_CAPACITY-1] = { .tok = (int)TOK_QUOTE_ERROR } } };

//                        0x4444333322221111
#define TOK_MAP_HASH_MASK 0b0000001111111111 // 10 bit mask = 1024
#define KEY_FROM_HASH(_hash) (_hash & TOK_MAP_HASH_MASK)
#define PAGE_FROM_LEN(_len) MIN(_len-1, MAP_PAGE_CAPACITY-1)
#define TOK_HASH_DJB2(_h, _c)  ((((_h) << 5) + (_h) + (_c)) * 33) 
#define TOK_HASH_FNV1A(_h, _c) (((_h) ^ (_c)) * 16777619UL)
#define TOK_HASH(_h, _c) TOK_HASH_DJB2(_h, _c)

static tok_hash CalcTokKey(const char *str, int iStart, int iEnd)
{
	if (iEnd == 0) return str[iStart]; // if len is 1 then hash is ascii code
	tok_hash h = str[iStart];  
	str += iStart + 1;
	int range = iEnd - iStart;
	char c; while ((c = *str++) && range-->= 0) h = TOK_HASH(h, c);
	return h;
}

static RESULT AddTokenToMap(MapTok (*tokMap)[MAP_HASH_CAPACITY], const char*(*string_OUT)(u8), const char* name, int len, TOK tok, TOK_CAT cat, bool override) 
{
	tok_hash hash = CalcTokKey(name, 0, len - 1);
	u8 p = PAGE_FROM_LEN(len); u16 k = KEY_FROM_HASH(hash);
	LOG("%.*s(%d) = %s(%d) len:%d p: %d hash: %d\n", len, name, k, string_OUT(tok), (u16)tok, len, p, hash);
	MapTok* pMapTok = &tokMap[p][k];
	if (!override && pMapTok->tok != 0 && pMapTok->tok != (int)TOK_COMMENT_ERROR && pMapTok->tok != (int)TOK_ERROR) 
		return RESULT_COLLISION_ERROR;

	*pMapTok = (MapTok){ tok, cat, len, hash };
	return RESULT_SUCCESS;
}

static RESULT ContructTokMap(MapTok (*tokMap)[MAP_HASH_CAPACITY], const char*(*string_OUT)(u8), int tokenCount, const TokDef* tokDefs)
{
	for (int iTkn = 0; iTkn < tokenCount; iTkn++) {
		TokDef td = tokDefs[iTkn];
		if (td.name[0] != '$') goto ProcessHash;
		if (memcmp(td.name, SKIP, STR_LEN(SKIP)) == 0) goto ProcessSkip;
		if (memcmp(td.name, RANGE, STR_LEN(RANGE)) == 0) goto ProcessHashRange;
		if (memcmp(td.name, OVERRIDE, STR_LEN(OVERRIDE)) == 0) goto ProcessOverride;
		continue;

	ProcessSkip:
		LOG("Processing Skip Expression: %s\n", td.name);
		continue;

	ProcessHashRange:
		LOG("Processing Range Expression: %s\n", td.name);
		char buffer[64]; strcpy(buffer, td.name + sizeof(RANGE) - 1);
		char* range = strtok(buffer, ",");
		while (range != NULL) {
			LOG("Range: %s\n", range);
			switch (range[1])
			{
				case '-':
					for (char c = range[0]; c < range[2]+1; ++c)
						REQUIRE(AddTokenToMap(tokMap, string_OUT, &c, 1, td.tok, td.cat, false));
					break;
				case '\0': REQUIRE(AddTokenToMap(tokMap, string_OUT, range, 1, td.tok, td.cat, false)); break;
				default:   PANIC("Malformed range expression!");
			}
		    range = strtok(NULL, ",");
		}
		continue;

	ProcessOverride:
		REQUIRE(AddTokenToMap(tokMap, string_OUT, td.name + STR_LEN(OVERRIDE), td.len -STR_LEN(OVERRIDE), td.tok, td.cat, true));
		continue;

	ProcessHash:
		REQUIRE(AddTokenToMap(tokMap, string_OUT, td.name, td.len, td.tok, td.cat, false));
		continue;
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
	TOK_CAT token : 6;

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
	TOK_CAT* pTextCat;

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

static inline Vector2 GetWorldToBoxLocal(Vector2 point, Rectangle rect) {
    return (Vector2){ point.x - rect.x, point.y - rect.y };
}

static inline Vector2 GetBoxLocalToWorld(Vector2 point, Rectangle rect) {
    return (Vector2){ point.x + rect.x, point.y + rect.y };
}

/*
 * CodeBox Lex
 */

static RESULT ProcessTrieMeta(CodeBox* pCode) 
{
	LOG("Process Meta. Token Count: %d\n", TK_COUNT);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverride-init"

	static void *codeDispatch[] = {	
		[0 ... TOK_COUNT]  = &&TK_ERR,
		[TK_DELIMIT]       = &&TK_DELIMIT,
		[TK_PACKED_CHAR]   = &&TK_PACKED_CHAR,
		[TK_SPARSE_CHAR]   = &&TK_SPARSE_CHAR,
		[TK_NEWLINE]       = &&TK_SPARSE_CHAR,
		[TK_TAB]           = &&TK_SPARSE_CHAR,
		[TK_ASCII_RANGE]   = &&TK_PACKED_CHAR,
		[TK_KEYWORD_RANGE] = &&TK_ALL,
	};

#pragma GCC diagnostic pop

	void **disp  = codeDispatch;
	FrieNode* pFrie = TOK_BASE_FRIE;
	
	const int textCount  = pCode->textCount;
	char	  *pText     = pCode->pText;
	TextMeta  *pTextMeta = pCode->pTextMeta;
	TOK       *pTextTok  = pCode->pTextTok;
	TOK_CAT   *pTextCat  = pCode->pTextCat;

	int total = 0;
	const int totalMax = 512;

	struct {
		int  iT;
		int  iN;
		FrieNode n;
		char cT;
		TOK_CAT cat;
	} step;
	ZERO(&step);

	step.cT = pText[0];
	step.n = pFrie[(u8)step.cT];
	goto TK_SPARSE_CHAR;

TK_ERR:
TK_NONE:
	step.iN = step.cT;
	step.n = pFrie[step.iN];
TK_SPARSE_CHAR:
	{
		// printf("TK_SPARSE_CHAR iT:%-4d iN:%-4d %4d:%s -->sparse %d cat:%s  ", step.iT, step.iN, step.cT, EscapeChar(step.cT), step.n.sparse.succ, string_TOK_CAT(step.n.sparse.cat));
		pTextCat[step.iT] = step.n.sparse.cat;
		pTextTok[step.iT] = step.cT;

		// retrieve next char first to use in setup of next node step state
		step.iT++;  // Sparse is success or fail explicity so you always increment text index.
		if (step.iT == textCount) return RESULT_SUCCESS;
	    // if (total++ > totalMax) return RESULT_SUCCESS;
		step.cT = pText[step.iT]; // Load char for next step;

		// step.iTBegin = step.iT; could do this to set individual char cat afterwards

		// Discern if sparse node is a match and needs packed comparison. 
		step.iN = step.n.sparse.succ > 0 ? step.n.sparse.succ : step.cT;
		u8 tk = step.n.sparse.tok;
		step.cat = step.n.sparse.cat;
		step.n = pFrie[step.iN]; // Load node for next step;
		// printf("dispatch-->%s\n", string_TK(step.n.packed.val));
		goto *disp[tk];
	}

TK_PACKED_CHAR:
	{
		bool match = step.n.packed.val == step.cT;
		// printf("TK_PACKED_CHAR iT:%-4d iN:%-4d %4d:%s==", step.iT, step.iN, step.cT, EscapeChar(step.cT));
		// printf("%s:%-4d match:%d %s ", EscapeChar(step.n.packed.val), step.n.packed.val, match, string_TOK_CAT(step.n.sparse.cat));
		pTextCat[step.iT] = step.cat; pTextTok[step.iT] = step.cT; // TODO figure way to not need to set this each time?
		step.iN += match ? step.n.packed.succ : step.n.packed.fail;
		step.n = pFrie[step.iN]; // Load node for next step;
		// printf("dispatch-->%s\n", string_TK(step.tk));

		// If match progress text index. Unless we are going to a token. This does waste an increment and pText lookup on fail condiiton.
		step.iT += match;
		if (step.iT == textCount) return RESULT_SUCCESS;
	    // if (total++ > totalMax) return RESULT_SUCCESS;
		step.cT = pText[step.iT]; // Load char for next step;
		goto *disp[step.n.packed.val];
	}

TK_DELIMIT: 
	{
		bool delimiter = IS_DELIM_CHAR(step.cT);
		// printf("TK_DELIMIT     iT:%-4d iN:%-4d %4d:%s delim:%d %s ", step.iT, step.iN, step.cT, EscapeChar(step.cT), IS_DELIM_CHAR(step.cT), string_TOK_CAT(step.n.sparse.cat));
		step.iN += delimiter ? step.n.packed.succ : step.n.packed.fail;
		step.n = pFrie[step.iN]; // Load node for next step;
		// printf("dispatch-->%s\n", string_TK(step.n.packed.val));
		goto *disp[step.n.packed.val];
	}

TK_ALL:
	{
		u8 len = step.n.terminator.len;
		// printf("%s iT:%d iN:%d fill:%d len:%d cat:%s \n", string_TK(step.n.terminator.val), step.iT, step.iN, step.iT - len, len, string_TOK_CAT(step.n.terminator.cat));
		FILL(pTextCat + step.iT - len, step.n.terminator.cat, len);
		FILL(pTextTok + step.iT - len, step.n.terminator.val, len);
		step.iN = step.cT;
		step.n = pFrie[step.iN];
		goto TK_SPARSE_CHAR;
	}

	return RESULT_SUCCESS;
}

static RESULT ProcessHashMeta(CodeBox* pCode) 
{
	/*
	 * Dispatch Tables
	 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverride-init"
#define DEF_DISPATCH(_name, _tok, _cat) [_tok] = &&_tok,

	static void *codeDispatch[] = {	
		DEF_TOK(DEF_DISPATCH)
		[TOK_DEFINE_HASH_HASH] = &&TOK_ERROR,
		[TOK_ESCAPE]           = &&TOK_ERROR,
		[TOK_PP_DEFINE]        = &&TOK_ERROR,
		[TOK_PP_INCLUDE]       = &&TOK_ERROR,
		[TOK_PP_IFNDEF]        = &&TOK_ERROR,
		[TOK_PP_IFDEF]         = &&TOK_ERROR,
		[TOK_PP_ENDIF]         = &&TOK_ERROR,
		[TOK_PP_UNDEF]         = &&TOK_ERROR,
		[TOK_PP_ELIF]          = &&TOK_ERROR,
		[TOK_PP_ELSE]          = &&TOK_ERROR,
		[TOK_PP_ERROR]         = &&TOK_ERROR,
		[TOK_PP_PRAGMA]        = &&TOK_ERROR,
		[TOK_PP_LINE]          = &&TOK_ERROR,
		[TOK_PP_IF]            = &&TOK_ERROR,
	};

	static void *preprocessDispatch[] = {	
		DEF_TOK(DEF_DISPATCH)
		[TOK_DEFINE_HASH_HASH] = &&TOK_ERROR,
		[TOK_DIGIT_CHAR]       = &&TOK_ERROR,
		[TOK_HASH]             = &&TOK_ERROR,
		[TOK_SPACE]            = &&TOK_PP_SPACE,
		[TOK_ALPHA_CHAR]       = &&TOK_PP_ALPHA_CHAR,
		[TOK_PP_DEFINE]        = &&TOK_PP_DEFINE,
		[TOK_PP_INCLUDE]       = &&TOK_PP_INCLUDE,
		[TOK_PP_IFNDEF]        = &&TOK_PP_IFNDEF,
		[TOK_PP_IFDEF]         = &&TOK_PP_IFDEF,
		[TOK_PP_ENDIF]         = &&TOK_PP_ENDIF,
		[TOK_PP_UNDEF]         = &&TOK_PP_UNDEF,
		[TOK_PP_ELIF]          = &&TOK_PP_ELIF,
		[TOK_PP_ELSE]          = &&TOK_PP_ELSE,
		[TOK_PP_ERROR]         = &&TOK_PP_ERROR,
		[TOK_PP_PRAGMA]        = &&TOK_PP_PRAGMA,
		[TOK_PP_LINE]          = &&TOK_PP_LINE,
		[TOK_PP_IF]            = &&TOK_PP_IF,
	};

	static void *defineDispatch[] = {
		DEF_TOK(DEF_DISPATCH)	
		[TOK_NEWLINE]    = &&TOK_DEFINE_NEWLINE,
		[TOK_HASH]    = &&TOK_DEFINE_HASH,
	};

	static void *quoteDispatch[] = {
		DEF_TOK_QUOTE(DEF_DISPATCH)
	};

	static void *commentDispatch[] = {
		DEF_TOK_COMMENT(DEF_DISPATCH)
	};

#undef DEF_DISPATCH
#pragma GCC diagnostic pop

	// TODO move in anon struct
	const int count     = pCode->textCount;
	char *pText         = pCode->pText;
	TextMeta *pTextMeta = pCode->pTextMeta;
	TOK     *pTextTok   = pCode->pTextTok;
	TOK_CAT *pTextCat   = pCode->pTextCat;
	void **pdisp = codeDispatch;
	void **disp  = codeDispatch;
	MapTok (*ptokmap)[MAP_HASH_CAPACITY] = TOK_MAP;
	MapTok (*tokmap)[MAP_HASH_CAPACITY]  = TOK_MAP;

	struct {
		int len;
		int iStart;
		TOK tok;
		TOK_CAT cat;
		TOK_CAT alphaNumCat;
	} pend;

	struct {
		tok_hash cur;
		int len;
	} hash;

	struct {
		int i;
		char c;
		MapTok mt;
		int tok;
		bool blockComment;
		bool doubleQuote;
		bool preprocessing;
	} step = { .i = -1 };

#define SET_CHAR_TOK()  { pTextTok[step.i] = step.tok; pTextCat[step.i] = step.mt.cat; }
#define SET_RANGE_TOK() { int len = step.mt.len; int _iStart = (step.i - len) + 1; FILL(pTextTok + _iStart, step.tok, len); FILL(pTextCat + _iStart, step.mt.cat, len); }

/* Set hash to start at current step. */
#define RESTART_HASH() { hash = (typeof(hash)){ step.c, 1 }; }
/* Zero hash. */
#define CLEAR_HASH()   { memset(&hash, 0, sizeof(hash)); }

/* Single Char Delimit. Set known char token. Write any pending token. Clear pending and hash. */
#define DELIMIT_CHAR() { WRITE_PEND(); CLEAR_PEND(); CLEAR_HASH(); SET_CHAR_TOK(); }

#define WRITE_PEND() { FILL(pTextTok + pend.iStart, pend.tok, pend.len); FILL(pTextCat + pend.iStart, pend.cat, pend.len); }
#define CLEAR_PEND() { memset(&pend, 0, sizeof(pend)); }

/* Set Pending Token. Tokens which start or end with a delimiter can use this. The delimiter at the end will write the token if still valid. i.e. keywords */
#define SET_PEND() { pend.len = hash.len; pend.iStart = (step.i - hash.len) + 1; pend.tok = step.tok; pend.cat = step.mt.cat; }

/* Delimit and begin pending token at current position. Tokens which may not start with a delimiter use this to explicitly delimit on first token. i.e #define */ // TODO I could get rid of if with another jump table???
#define DELIMIT_BEGIN_PEND() if (pend.cat != step.mt.cat) { WRITE_PEND(); RESTART_HASH(); pend.alphaNumCat = TOK_CAT_NONE; } SET_PEND();
/* Delimit and end token at current position. Tokens which cannot rely on a following delimiter need to use this. i.e. operators */
#define DELIMIT_END_PEND()   SET_RANGE_TOK(); CLEAR_PEND(); CLEAR_HASH(); 

#define GOTO_NEXT() { \
	if (step.i == count) return RESULT_SUCCESS; \
	step.c   = pText[++step.i]; \
	hash.cur = (++hash.len == 1) ? (tok_hash)step.c : TOK_HASH(hash.cur, step.c);  \
	step.mt  = tokmap[PAGE_FROM_LEN(hash.len)][KEY_FROM_HASH(hash.cur)]; \
	step.tok = step.mt.hash == hash.cur ? step.mt.tok : 0; \
	goto *disp[step.tok]; \
}

	/* Begin */
	CLEAR_PEND(); 
	CLEAR_HASH();
	GOTO_NEXT();

/* If isTok token jump to single char. */
TOK_QUOTE_NONE:
TOK_COMMENT_NONE:
TOK_NONE: 
	step.mt  = tokmap[0][(u8)step.c]; 
	step.tok = step.mt.tok;
	goto *disp[step.tok];

TOK_COMMENT_ERROR:
TOK_QUOTE_ERROR:
TOK_ERROR:
	pTextTok[step.i] = TOK_ERROR; 
	pTextCat[step.i] = TOK_CAT_ERROR;
	DELIMIT_END_PEND();
	GOTO_NEXT();

/*
 * Range Delimiter Terminated
 */
TOK_ALPHA_CHAR:
TOK_DIGIT_CHAR:
	// Delimit chars switch from none, to digit, to alphanumeric. 
	// Needed to catch # * / operators without spaces between them.
	if (pend.alphaNumCat == TOK_CAT_NONE) {
		WRITE_PEND(); 
		RESTART_HASH(); 
		pend.cat = step.mt.cat; // Store cat from first char to apply to whole
		pend.alphaNumCat = step.mt.cat;
		pend.iStart = (step.i - hash.len) + 1; 
		pend.tok = step.tok;
	} 
	pend.len = hash.len; 
	GOTO_NEXT();

TOK_QUOTE_CHAR:
TOK_PP_ALPHA_CHAR:
TOK_PP_INCLUDE:
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
TOK_LEFT_SHIFT:  // <<
TOK_RIGHT_SHIFT: // >>
	SET_PEND();
	GOTO_NEXT();

/*
 * Single Char Delimiter
 */
TOK_PP_SPACE:
	disp = codeDispatch;
	goto SingleCharDelimiter;

TOK_DEFINE_NEWLINE:	
	disp = codeDispatch;

SingleCharDelimiter:
TOK_NEWLINE:
TOK_SPACE:
TOK_TAB:
TOK_CARRIAGE_RETURN:
TOK_FORM_FEED:
TOK_VERTICAL_TAB:
TOK_SEMICOLON:
TOK_COMMA:
TOK_COLON:
TOK_DOT:
TOK_PAREN_OPEN:
TOK_PAREN_CLOSE:
TOK_BRACE_OPEN:
TOK_BRACE_CLOSE:
TOK_BRACKET_OPEN:
TOK_BRACKET_CLOSE:
TOK_EXCLAMATION:
TOK_QUESTION:
TOK_COMMENT_WITESPACE:
TOK_COMMENT_CHAR:
	DELIMIT_CHAR();
	GOTO_NEXT();

/*
 *  Range Begin Explicit Delimiter
 */
TOK_HASH: 
	disp = preprocessDispatch;

TOK_ESCAPE_ESCAPE:
TOK_DEFINE_HASH:
TOK_ESCAPE:
TOK_PLUS:               // +
TOK_MINUS:              // -
TOK_STAR:               // *
TOK_SLASH:              // /
TOK_PERCENT:            // %
TOK_AMPERSAND:          // &
TOK_PIPE:               // |
TOK_CARET:              // ^
TOK_TILDE:              // ~
TOK_LESS:               // <
TOK_GREATER:            // >
TOK_ASSIGN:             // =
	DELIMIT_BEGIN_PEND();
	GOTO_NEXT();

/*
 *  Range End Explicit Delimiter
 */
TOK_PP_DEFINE:
	disp = defineDispatch; 

TOK_DEFINE_HASH_HASH:   // ##
TOK_PP_CONTINUE:        // \\n
TOK_ARROW:              // ->
TOK_INCREMENT:          // ++
TOK_DECREMENT:          // --
TOK_LEFT_SHIFT_ASSIGN:  // <<=
TOK_RIGHT_SHIFT_ASSIGN: // >>=
TOK_LOGICAL_AND:        // &&
TOK_LOGICAL_OR:         // ||
TOK_LESS_EQUAL:         // <=
TOK_GREATER_EQUAL:      // >=
TOK_EQUAL_EQUAL:        // ==
TOK_NOT_EQUAL:          // !=
TOK_PLUS_ASSIGN:        // +=
TOK_MINUS_ASSIGN:       // -=
TOK_STAR_ASSIGN:        // *=
TOK_SLASH_ASSIGN:       // /=
TOK_PERCENT_ASSIGN:     // %=
TOK_AMPERSAND_ASSIGN:   // &=
TOK_PIPE_ASSIGN:        // |=
TOK_CARET_ASSIGN:       // ^=
TOK_ELLIPSIS:           // ...
TOK_ESCAPE_SINGLE_QUOTE:
TOK_ESCAPE_DOUBLE_QUOTE:
TOK_ESCAPE_QUESTION:
TOK_ESCAPE_BACKSLASH:
TOK_ESCAPE_ALERT:
TOK_ESCAPE_BACKSPACE:
TOK_ESCAPE_FORMFEED:
TOK_ESCAPE_NEWLINE:
TOK_ESCAPE_CARRIAGE:
TOK_ESCAPE_TAB:
TOK_ESCAPE_VTAB:
TOK_ESCAPE_HEX_START:
TOK_ESCAPE_UNICODE_4:
TOK_ESCAPE_UNICODE_8:
	DELIMIT_END_PEND();
	GOTO_NEXT();

/*
 *  Comment Lex
 */
TOK_COMMENT_OPEN: // /*
	step.blockComment = true;
TOK_LINE_COMMENT: // //
    pdisp = disp;
    ptokmap = tokmap;
    disp = commentDispatch;
    tokmap = TOK_COMMENT_MAP;
	DELIMIT_END_PEND();
	GOTO_NEXT();

TOK_COMMENT_STAR:
	if (!step.blockComment) goto TOK_COMMENT_WITESPACE;	
	DELIMIT_BEGIN_PEND();
	GOTO_NEXT();

TOK_COMMENT_NEWLINE: // */
	if (step.blockComment) goto TOK_COMMENT_WITESPACE;	
TOK_COMMENT_CLOSE:   // */
	step.blockComment = false;
    disp = pdisp;
    tokmap = ptokmap;
	DELIMIT_END_PEND();
	GOTO_NEXT();

/*
 *  Quote Lex
 */
/* STRING_TOKS */
TOK_DOUBLE_QUOTE:
	step.doubleQuote = true;
TOK_SINGLE_QUOTE:
    pdisp = disp;
    ptokmap = tokmap;
    disp = quoteDispatch;
    tokmap = TOK_QUOTE_MAP;
	DELIMIT_CHAR();
	GOTO_NEXT();

TOK_QUOTE_NEWLINE:
	DELIMIT_CHAR();
	GOTO_NEXT();

TOK_QUOTE_SINGLE_CLOSE:
	if (step.doubleQuote) goto TOK_QUOTE_CHAR;	
TOK_QUOTE_DOUBLE_CLOSE:
	step.doubleQuote = false;
    disp = pdisp;
    tokmap = ptokmap;
	DELIMIT_CHAR();
	GOTO_NEXT();

	return 0;
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
	REQUIRE(ConstructFrie(NARRAY(TK_BASE_DEFINITIONS), TK_BASE_DEFINITIONS, NARRAY(TOK_BASE_FRIE), TOK_BASE_FRIE));
	// ConstructFrie(NARRAY(TK_PP_DEFINITIONS),   TK_PP_DEFINITIONS,   NARRAY(TOK_PP_FRIE),   TOK_PP_FRIE);

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
		pCode->pTextCat = XCALLOC(TEXT_BUFFER_CAPACITY, TOK_CAT);
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
		LOG("Loaded Buffer Size %d\n", pCode->textCount);
		ASSERT(text.textCount < TEXT_BUFFER_CAPACITY, "Loaded buffer size too big!");

		memcpy(pCode->pText, loadedFile, pCode->textCount + 1);
		free(loadedFile);

		ProcessTrieMeta(pCode);
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
		const TOK_CAT* pTextCat = pCode->pTextCat;
		int boxRowCount = pCode->boxRowCount;
		int boxColCount = pCode->boxColCount;
		int iChar = pCode->focusStartRowIndex;

		for (int iRow = 0; iRow < boxRowCount; ++iRow) {
			// int tabCount = 0;
			// for (int iCol = 0; iCol < boxColCount - (tabCount * tabWidth); ++iCol) {
			char     currentChar;
			TextMeta currentMeta;
			TOK_CAT currentToken;
			for (int iCol = 0; iCol < boxColCount; ++iCol) {
				currentChar  = pText[iChar];
				currentMeta  = pTextMeta[iChar];
				currentToken = pTextCat[iChar];

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
						Color color = TOK_CAT_COLOR[currentToken];
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
				TOK_CAT tc = pCode->pTextCat[pCode->pCarets[0].index];
				TextMeta m = pCode->pTextMeta[pCode->pCarets[0].index];
				DEBUG_LOG_ONCE("%s %s %d start: %d end: %d\n", string_TK((TK)tok), string_TOK_CAT(tc), m.QUOTE, m.iTokenStartOffset, m.iTokenEndOffset);
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



