//0123456789

/* 
 * Test
 */
#ifdef A
#endif

double T() {
	char *str = "Hello\n\x01!\\";
	int a0 = 1<<1;
	a0 <<= 2;
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
	const char * str = "Hello\n01234\\";
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
| Ctrl+D                    | Duplikinde line below                           |
| Ctrl+Shift+D              | Duplikinde line above                           |
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

static const char* string_CHAR(char c) {
    switch (c) {
        case '\x00': return "\\0NUL";
        case '\x01': return "\\x01SOH";
        case '\x02': return "\\x02STX";
        case '\x03': return "\\x03ETX";
        case '\x04': return "\\x04EOT";
        case '\x05': return "\\x05ENQ";
        case '\x06': return "\\x06ACK";
        case '\x07': return "\\aBEL";
        case '\x08': return "\\bBS";
        case '\x09': return "\\tTAB";
        case '\x0A': return "\\nLF";
        case '\x0B': return "\\vVT";
        case '\x0C': return "\\fFF";
        case '\x0D': return "\\rCR";
        case '\x0E': return "\\x0ESO";
        case '\x0F': return "\\x0FSI";
        case '\x10': return "\\x10DLE";
        case '\x11': return "\\x11DC1";
        case '\x12': return "\\x12DC2";
        case '\x13': return "\\x13DC3";
        case '\x14': return "\\x14DC4";
        case '\x15': return "\\x15NAK";
        case '\x16': return "\\x16SYN";
        case '\x17': return "\\x17ETB";
        case '\x18': return "\\x18CAN";
        case '\x19': return "\\x19EM";
        case '\x1A': return "\\x1ASUB";
        case '\x1B': return "\\x1BESC";
        case '\x1C': return "\\x1CFS";
        case '\x1D': return "\\x1DGS";
        case '\x1E': return "\\x1ERS";
        case '\x1F': return "\\x1FUS";
        case '\\':   return "\\\\";
        case '\'':   return "\\'";
        case '\"':   return "\\\"";
        case '\x7F': return "\\x7FDEL";
        default: {
            static char buf[2] = { '\0', '\0' };
            buf[0] = c;
            return buf;
        }
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
	#define ASSERT(_condition)
	#define ASSERTMSG(_condition, _format, ...)
#else
	#define ASSERT(_condition)\
		if (UNLIKELY(!(_condition))) {\
			fprintf(stderr, "\n" ANSI_RED __FILE__ ":%d ASSERTMSG! " #_condition " \n" ANSI_RESET, __LINE__);\
			assert((_condition) && #_condition);\
		}

	#define ASSERTMSG(_condition, _format, ...)\
		if (UNLIKELY(!(_condition))) {\
			fprintf(stderr, "\n" ANSI_RED __FILE__ ":%d ASSERTMSG! " #_condition " " _format "\n" ANSI_RESET, __LINE__, ##__VA_ARGS__);\
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
#define COLOR_BACKGROUND  (Color){  48,  56,  65, 255 } 

#define COLOR_HIGHLIGHT_CODE        (Color){ 216, 222, 233, 255 }
#define COLOR_HIGHLIGHT_ERROR       (Color){ 255,   0,   0, 255 }
#define COLOR_HIGHLIGHT_PREPROCESS  (Color){ 135, 132, 219, 255 }
#define COLOR_HIGHLIGHT_CONTINUE    (Color){ 148,  99, 148, 255 }
#define COLOR_HIGHLIGHT_NUMBER      (Color){ 249, 174,  87, 255 }
#define COLOR_HIGHLIGHT_STRING      (Color){ 153, 199, 148, 255 } 
#define COLOR_HIGHLIGHT_COMMENT     (Color){ 166, 172, 185, 255 }  
#define COLOR_HIGHLIGHT_OPERATOR    (Color){ 249, 123,  87, 255 }
#define COLOR_HIGHLIGHT_WHITESPACE  (Color){  68,  76,  85, 255 } 
#define COLOR_HIGHLIGHT_ESCAPE      (Color){ 198, 149, 198, 255 } 
#define COLOR_HIGHLIGHT_TEXT        (Color){ 127, 199, 148, 255 } 
#define COLOR_HIGHLIGHT_QUOTE       (Color){  96, 180, 180, 255 } 
#define COLOR_HIGHLIGHT_SCOPE       (Color){ 206, 186, 192, 255 } 
#define COLOR_HIGHLIGHT_KEYWORD     (Color){ 236,  96, 102, 255 }
#define COLOR_HIGHLIGHT_TYPE        (Color){ 198, 149, 198, 255 }

/*
 * Lex
 */

#define DEF_TOK_KIND(DEF) \
	DEF(TOK_KIND_NONE) \
	DEF(TOK_KIND_WHITESPACE) \
	DEF(TOK_KIND_ERROR) \
	DEF(TOK_KIND_ALPHA) \
	DEF(TOK_KIND_DIGIT) \
	DEF(TOK_KIND_LITERAL) \
	DEF(TOK_KIND_IDENTIFIER) \
	DEF(TOK_KIND_TYPE) \
	DEF(TOK_KIND_KEYWORD) \
	DEF(TOK_KIND_OPERATOR) \
	DEF(TOK_KIND_STATEMENT) \
	DEF(TOK_KIND_PP) \
	DEF(TOK_KIND_PP_OPERATOR) \
	DEF(TOK_KIND_CONTINUE) \
	DEF(TOK_KIND_SCOPE) \
	DEF(TOK_KIND_QUOTE) \
	DEF(TOK_KIND_TEXT) \
	DEF(TOK_KIND_ESCAPE) \
	DEF(TOK_KIND_COMMENT) \
	DEF(TOK_KIND_COUNT)
DEF_ENUM(TOK_KIND);

static Color TOK_KIND_COLOR[] = {
	[TOK_KIND_NONE]        = COLOR_HIGHLIGHT_ERROR,
	[TOK_KIND_ERROR]       = COLOR_HIGHLIGHT_ERROR,
	[TOK_KIND_ALPHA]       = COLOR_HIGHLIGHT_CODE,
	[TOK_KIND_LITERAL]       = COLOR_HIGHLIGHT_CODE,
	[TOK_KIND_DIGIT]       = COLOR_HIGHLIGHT_NUMBER,
	[TOK_KIND_TYPE]        = COLOR_HIGHLIGHT_TYPE,
	[TOK_KIND_KEYWORD]     = COLOR_HIGHLIGHT_KEYWORD,
	[TOK_KIND_WHITESPACE]  = COLOR_HIGHLIGHT_WHITESPACE,
	[TOK_KIND_STATEMENT]   = COLOR_HIGHLIGHT_SCOPE,
	[TOK_KIND_OPERATOR]    = COLOR_HIGHLIGHT_OPERATOR,
	[TOK_KIND_PP]          = COLOR_HIGHLIGHT_PREPROCESS,
	[TOK_KIND_PP_OPERATOR] = COLOR_HIGHLIGHT_PREPROCESS,
	[TOK_KIND_CONTINUE]    = COLOR_HIGHLIGHT_CONTINUE,
	[TOK_KIND_SCOPE]       = COLOR_HIGHLIGHT_SCOPE,
	[TOK_KIND_QUOTE]       = COLOR_HIGHLIGHT_QUOTE,
	[TOK_KIND_TEXT]        = COLOR_HIGHLIGHT_TEXT,
	[TOK_KIND_ESCAPE]      = COLOR_HIGHLIGHT_ESCAPE,
	[TOK_KIND_COMMENT]     = COLOR_HIGHLIGHT_COMMENT,
};
STATIC_ASSERT(NARRAY(TOK_KIND_COLOR) == TOK_KIND_COUNT);

#define TOK_CAPACITY 256

#define TOK_SECIAL_BEGIN 0
#define TOK_SECIAL_END   7
#define TOK_SECIAL_RANGE TOK_SPECIAL_BEGIN ... TOK_SPECIAL_END

#define TOK_WHITE_BEGIN 9
#define TOK_WHITE_END   13
#define TOK_WHITE_RANGE TOK_WHITE_BEGIN ... TOK_WHITE_END

#define TOK_ASCII_BEGIN 32
#define TOK_ASCII_END   127
#define TOK_ASCII_RANGE TOK_ASCII_BEGIN ... TOK_ASCII_END

#define TOK_VISIBLE_ASCII_BEGIN 33
#define TOK_VISIBLE_ASCII_END   126
#define TOK_VISIBLE_ASCII_RANGE TOK_VISIBLE_ASCII_BEGIN ... TOK_VISIBLE_ASCII_END

#define TOK_KEYWORD_BEGIN 128
#define TOK_KEYWORD_END   (TOK_CAPACITY - 1)
#define TOK_KEYWORD_RANGE TOK_KEYWORD_BEGIN ... TOK_KEYWORD_END

#define TOK_ALL_BEGIN 0
#define TOK_ALL_END   TOK_KEYWORD_END
#define TOK_ALL_RANGE TOK_ALL_BEGIN ... TOK_ALL_END

#define TOK_RANGE_NAME "\x06"
#define TOK_DELIM_STR  "\x03"

#define DEF_TOK(DEF)\
    /* Traverse Special */\
    DEF(TOK_NONE,         /*NUL*/'\000')\
    DEF(TOK_SPARSE_CHAR,  /*SOH*/'\001')\
    DEF(TOK_PACKED_CHAR,  /*STX*/'\002')\
	DEF(TOK_DELIMIT,      /*ETX*/'\003')\
	DEF(TOK_MUNCH,        /*EOT*/'\004')\
    DEF(TOK_ERR,          /*ENQ*/'\005')\
	/* Construct Special */\
    DEF(TOK_RANGE,        /*SUB*/'\006')\
	/* White Spaces */\
	DEF(TOK_TAB,            /*9*/'\t')\
	DEF(TOK_VERTICAL_TAB,  /*10*/'\v')\
	DEF(TOK_NEWLINE,       /*10*/'\n')\
	DEF(TOK_FORM_FEED,     /*12*/'\f')\
	DEF(TOK_CARR_RETURN,   /*13*/'\r')\
    /*ASCII 32-126*/\
    DEF(TOK_SPACE,         /*32*/' ' )\
    DEF(TOK_BANG,          /*33*/'!' )\
    DEF(TOK_DQUOTE,        /*34*/'"' )\
    DEF(TOK_HASH,          /*35*/'#' )\
    DEF(TOK_DOLLAR,        /*36*/'$' )\
    DEF(TOK_PERCENT,       /*37*/'%' )\
    DEF(TOK_AMP,           /*38*/'&' )\
    DEF(TOK_SQUOTE,        /*39*/'\'')\
    DEF(TOK_LPAREN,        /*40*/'(' )\
    DEF(TOK_RPAREN,        /*41*/')' )\
    DEF(TOK_STAR,          /*42*/'*' )\
    DEF(TOK_PLUS,          /*43*/'+' )\
    DEF(TOK_COMMA,         /*44*/',' )\
    DEF(TOK_MINUS,         /*45*/'-' )\
    DEF(TOK_DOT,           /*46*/'.' )\
    DEF(TOK_SLASH,         /*47*/'/' )\
    DEF(TOK_0,             /*48*/'0' )\
    DEF(TOK_1,             /*49*/'1' )\
    DEF(TOK_2,             /*50*/'2' )\
    DEF(TOK_3,             /*51*/'3' )\
    DEF(TOK_4,             /*52*/'4' )\
    DEF(TOK_5,             /*53*/'5' )\
    DEF(TOK_6,             /*54*/'6' )\
    DEF(TOK_7,             /*55*/'7' )\
    DEF(TOK_8,             /*56*/'8' )\
    DEF(TOK_9,             /*57*/'9' )\
    DEF(TOK_COLON,         /*58*/':' )\
    DEF(TOK_SEMICOLON,     /*59*/';' )\
    DEF(TOK_LT,            /*60*/'<' )\
    DEF(TOK_EQ,            /*61*/'=' )\
    DEF(TOK_GT,            /*62*/'>' )\
    DEF(TOK_QUESTION,      /*63*/'?' )\
    DEF(TOK_AT,            /*64*/'@' )\
    DEF(TOK_A,             /*65*/'A' )\
    DEF(TOK_B,             /*66*/'B' )\
    DEF(TOK_C,             /*67*/'C' )\
    DEF(TOK_D,             /*68*/'D' )\
    DEF(TOK_E,             /*69*/'E' )\
    DEF(TOK_F,             /*70*/'F' )\
    DEF(TOK_G,             /*71*/'G' )\
    DEF(TOK_H,             /*72*/'H' )\
    DEF(TOK_I,             /*73*/'I' )\
    DEF(TOK_J,             /*74*/'J' )\
    DEF(TOK_K,             /*75*/'K' )\
    DEF(TOK_L,             /*76*/'L' )\
    DEF(TOK_M,             /*77*/'M' )\
    DEF(TOK_N,             /*78*/'N' )\
    DEF(TOK_O,             /*79*/'O' )\
    DEF(TOK_P,             /*80*/'P' )\
    DEF(TOK_Q,             /*81*/'Q' )\
    DEF(TOK_R,             /*82*/'R' )\
    DEF(TOK_S,             /*83*/'S' )\
    DEF(TOK_T,             /*84*/'T' )\
    DEF(TOK_U,             /*85*/'U' )\
    DEF(TOK_V,             /*86*/'V' )\
    DEF(TOK_W,             /*87*/'W' )\
    DEF(TOK_X,             /*88*/'X' )\
    DEF(TOK_Y,             /*89*/'Y' )\
    DEF(TOK_Z,             /*90*/'Z' )\
    DEF(TOK_LBRACKET,      /*91*/'[' )\
    DEF(TOK_BACKSLASH,     /*92*/'\\')\
    DEF(TOK_RBRACKET,      /*93*/']' )\
    DEF(TOK_CARET,         /*94*/'^' )\
    DEF(TOK_UNDERSCORE,    /*95*/'_' )\
    DEF(TOK_BACKTICK,      /*96*/'`' )\
    DEF(TOK_a,             /*97*/'a' )\
    DEF(TOK_b,             /*98*/'b' )\
    DEF(TOK_c,             /*99*/'c' )\
    DEF(TOK_d,            /*100*/'d' )\
    DEF(TOK_e,            /*101*/'e' )\
    DEF(TOK_f,            /*102*/'f' )\
    DEF(TOK_g,            /*103*/'g' )\
    DEF(TOK_h,            /*104*/'h' )\
    DEF(TOK_i,            /*105*/'i' )\
    DEF(TOK_j,            /*106*/'j' )\
    DEF(TOK_k,            /*107*/'k' )\
    DEF(TOK_l,            /*108*/'l' )\
    DEF(TOK_m,            /*109*/'m' )\
    DEF(TOK_n,            /*110*/'n' )\
    DEF(TOK_o,            /*111*/'o' )\
    DEF(TOK_p,            /*112*/'p' )\
    DEF(TOK_q,            /*113*/'q' )\
    DEF(TOK_r,            /*114*/'r' )\
    DEF(TOK_s,            /*115*/'s' )\
    DEF(TOK_t,            /*116*/'t' )\
    DEF(TOK_u,            /*117*/'u' )\
    DEF(TOK_v,            /*118*/'v' )\
    DEF(TOK_w,            /*119*/'w' )\
    DEF(TOK_x,            /*120*/'x' )\
    DEF(TOK_y,            /*121*/'y' )\
    DEF(TOK_z,            /*122*/'z' )\
    DEF(TOK_LBRACE,       /*123*/'{' )\
    DEF(TOK_PIPE,         /*124*/'|' )\
    DEF(TOK_RBRACE,       /*125*/'}' )\
    DEF(TOK_TILDE,        /*126*/'~' )\
    /* Keywords 128+ */\
	/* PreProcess */\
	DEF(TOK_PP_INCLUDE, TOK_KEYWORD_BEGIN)\
	DEF(TOK_PP_DEFINE)\
	DEF(TOK_PP_IFNDEF)\
	DEF(TOK_PP_IFDEF)\
	DEF(TOK_PP_ENDIF)\
	DEF(TOK_PP_UNDEF)\
	DEF(TOK_PP_ELIF)\
	DEF(TOK_PP_ELSE)\
	DEF(TOK_PP_ERROR)\
	DEF(TOK_PP_PRAGMA)\
	DEF(TOK_PP_LINE)\
	DEF(TOK_PP_IF)\
	DEF(TOK_HASH_HASH)\
	/* Keyword */\
	DEF(TOK_STATIC_ASSERT)\
	DEF(TOK_THREAD_LOCAL)\
	DEF(TOK_IMAGINARY)\
	DEF(TOK_NORETURN)\
	DEF(TOK_COMPLEX)\
	DEF(TOK_GENERIC)\
	DEF(TOK_ALIGNOF)\
	DEF(TOK_ALIGNAS)\
	DEF(TOK_ATOMIC)\
	DEF(TOK_CONTINUE)\
	DEF(TOK_VOLATILE)\
	DEF(TOK_REGISTER)\
	DEF(TOK_RESTRICT)\
	DEF(TOK_TYPEDEF)\
	DEF(TOK_DEFAULT)\
	DEF(TOK_TYPEOF)\
	DEF(TOK_SWITCH)\
	DEF(TOK_STATIC)\
	DEF(TOK_SIZEOF)\
	DEF(TOK_RETURN)\
	DEF(TOK_INLINE)\
	DEF(TOK_EXTERN)\
	DEF(TOK_WHILE)\
	DEF(TOK_CONST)\
	DEF(TOK_BREAK)\
	DEF(TOK_GOTO)\
	DEF(TOK_ELSE)\
	DEF(TOK_CASE)\
	DEF(TOK_AUTO)\
	DEF(TOK_FOR)\
	DEF(TOK_IF)\
	DEF(TOK_DO)\
	/* Type */\
	DEF(TOK_UNSIGNED)\
	DEF(TOK_STRUCT)\
	DEF(TOK_SIGNED)\
	DEF(TOK_DOUBLE)\
	DEF(TOK_FLOAT)\
	DEF(TOK_SHORT)\
	DEF(TOK_BOOL)\
	DEF(TOK_UNION)\
	DEF(TOK_VOID)\
	DEF(TOK_LONG)\
	DEF(TOK_CHAR)\
	DEF(TOK_ENUM)\
	DEF(TOK_INT)\
	DEF(TOK_PTRDIFF_T)\
	DEF(TOK_UINT64_T)\
	DEF(TOK_UINT32_T)\
	DEF(TOK_UINT16_T)\
	DEF(TOK_INT64_T)\
	DEF(TOK_INT32_T)\
	DEF(TOK_INT16_T)\
	DEF(TOK_WCHAR_T)\
	DEF(TOK_UINT8_T)\
	DEF(TOK_SIZE_T)\
	DEF(TOK_INT8_T)\
	/* Operator */\
    DEF(TOK_INC,           /* ++  */)\
    DEF(TOK_DEC,           /* --  */)\
    DEF(TOK_ARROW,         /* ->  */)\
    DEF(TOK_LSHIFT,        /* <<  */)\
    DEF(TOK_RSHIFT,        /* >>  */)\
    DEF(TOK_LE,            /* <=  */)\
    DEF(TOK_GE,            /* >=  */)\
    DEF(TOK_EQ_EQ,         /* ==  */)\
    DEF(TOK_NE,            /* !=  */)\
    DEF(TOK_AND,           /* &&  */)\
    DEF(TOK_OR,            /* ||  */)\
    DEF(TOK_ADD_ASSIGN,    /* +=  */)\
    DEF(TOK_SUB_ASSIGN,    /* -=  */)\
    DEF(TOK_MUL_ASSIGN,    /* *=  */)\
    DEF(TOK_DIV_ASSIGN,    /* /=  */)\
    DEF(TOK_MOD_ASSIGN,    /* %=  */)\
    DEF(TOK_AND_ASSIGN,    /* &=  */)\
    DEF(TOK_OR_ASSIGN,     /* |=  */)\
    DEF(TOK_XOR_ASSIGN,    /* ^=  */)\
    DEF(TOK_LSHIFT_ASSIGN, /* <<= */)\
    DEF(TOK_RSHIFT_ASSIGN, /* >>= */)\
    DEF(TOK_ELLIPSIS,      /* ... */)\
	/* Comment */\
	DEF(TOK_LCOMMENT)\
    DEF(TOK_RCOMMENT)\
    DEF(TOK_COMMENT)\
	/* Escape Code */\
    DEF(TOK_ESC_NULL,      /* \\0  NUL */)\
    DEF(TOK_ESC_ALERT,     /* \\a  BEL */)\
    DEF(TOK_ESC_BACKSPACE, /* \\b  BS  */)\
    DEF(TOK_ESC_TAB,       /* \\t  TAB */)\
    DEF(TOK_ESC_NEWLINE,   /* \\n  LF  */)\
    DEF(TOK_ESC_VTAB,      /* \\v  VT  */)\
    DEF(TOK_ESC_FORMFEED,  /* \\f  FF  */)\
    DEF(TOK_ESC_RETURN,    /* \\r  CR  */)\
    DEF(TOK_ESC_BACKSLASH, /* \\\\ \\  */)\
    DEF(TOK_ESC_SQUOTE,    /* \\'  '   */)\
    DEF(TOK_ESC_DQUOTE,    /* \\\  "   */)\
    DEF(TOK_ESC_QUESTION,  /* \\?  ?   */)\
	DEF(TOK_ESC_HEX,       /* \\x      */)\
    DEF(TOK_ESC_UNICODE4,  /* \\u      */)\
    DEF(TOK_ESC_UNICODE8,  /* \\U      */)\
	DEF(TOK_COUNT)
DEF_ENUM(TOK);
STATIC_ASSERT(TOK_COUNT < TOK_CAPACITY, "Not setup to support more than 256 tokens!");

#define DLM TOK_DELIM_STR

#define DEF_TOK_BASE(DEF, DEF_RANGE)\
	DEF_RANGE('0' ... '9',  TOK_KIND_DIGIT)\
	DEF_RANGE('a' ... 'z',  TOK_KIND_ALPHA)\
	DEF_RANGE('A' ... 'Z',  TOK_KIND_ALPHA)\
	/* Whitespace */\
	DEF("\t", TOK_TAB,     TOK_KIND_WHITESPACE)\
	DEF("\n", TOK_NEWLINE, TOK_KIND_WHITESPACE)\
	DEF(" ",  TOK_SPACE,   TOK_KIND_WHITESPACE)\
	/* Other Alpha */\
    DEF("_",  TOK_UNDERSCORE, TOK_KIND_ALPHA)\
    DEF("\\", TOK_BACKSLASH,  TOK_KIND_ALPHA)\
    DEF("@",  TOK_AT,         TOK_KIND_ALPHA)\
    DEF("&",  TOK_AMP,        TOK_KIND_ALPHA)\
    DEF("$",  TOK_DOLLAR,     TOK_KIND_ALPHA)\
    /* Brace */\
	DEF("[", TOK_LBRACKET, TOK_KIND_OPERATOR)\
    DEF("]", TOK_RBRACKET, TOK_KIND_OPERATOR)\
    DEF("{", TOK_LBRACE,   TOK_KIND_OPERATOR)\
    DEF("}", TOK_RBRACE,   TOK_KIND_OPERATOR)\
    DEF("(", TOK_LPAREN,   TOK_KIND_OPERATOR)\
    DEF(")", TOK_RPAREN,   TOK_KIND_OPERATOR)\
	/* Quote */\
	DEF("\"", TOK_DQUOTE,   TOK_KIND_QUOTE)\
	DEF("\'", TOK_SQUOTE,   TOK_KIND_QUOTE)\
    DEF("`",  TOK_BACKTICK, TOK_KIND_QUOTE)\
	/* Comment */\
	DEF("/*", TOK_LCOMMENT, TOK_KIND_COMMENT)\
    DEF("//", TOK_COMMENT,  TOK_KIND_COMMENT)\
	/* Operator */\
    DEF("|",   TOK_PIPE,          TOK_KIND_OPERATOR)\
    DEF("!",   TOK_BANG,          TOK_KIND_OPERATOR)\
    DEF("%",   TOK_PERCENT,       TOK_KIND_OPERATOR)\
    DEF("*",   TOK_STAR,          TOK_KIND_OPERATOR)\
    DEF("+",   TOK_PLUS,          TOK_KIND_OPERATOR)\
    DEF(",",   TOK_COMMA,         TOK_KIND_OPERATOR)\
    DEF("-",   TOK_MINUS,         TOK_KIND_OPERATOR)\
    DEF(".",   TOK_DOT,           TOK_KIND_OPERATOR)\
    DEF("/",   TOK_SLASH,         TOK_KIND_OPERATOR)\
    DEF("<",   TOK_LT,            TOK_KIND_OPERATOR)\
    DEF("=",   TOK_EQ,            TOK_KIND_OPERATOR)\
    DEF(">",   TOK_GT,            TOK_KIND_OPERATOR)\
    DEF("^",   TOK_CARET,         TOK_KIND_OPERATOR)\
    DEF("~",   TOK_TILDE,         TOK_KIND_OPERATOR)\
    DEF("++",  TOK_INC,           TOK_KIND_OPERATOR)\
    DEF("--",  TOK_DEC,           TOK_KIND_OPERATOR)\
    DEF("->",  TOK_ARROW,         TOK_KIND_OPERATOR)\
    DEF("<<",  TOK_LSHIFT,        TOK_KIND_OPERATOR)\
    DEF(">>",  TOK_RSHIFT,        TOK_KIND_OPERATOR)\
    DEF("<=",  TOK_LE,            TOK_KIND_OPERATOR)\
    DEF(">=",  TOK_GE,            TOK_KIND_OPERATOR)\
    DEF("==",  TOK_EQ_EQ,         TOK_KIND_OPERATOR)\
    DEF("!=",  TOK_NE,            TOK_KIND_OPERATOR)\
    DEF("&&",  TOK_AND,           TOK_KIND_OPERATOR)\
    DEF("||",  TOK_OR,            TOK_KIND_OPERATOR)\
    DEF("+=",  TOK_ADD_ASSIGN,    TOK_KIND_OPERATOR)\
    DEF("-=",  TOK_SUB_ASSIGN,    TOK_KIND_OPERATOR)\
    DEF("*=",  TOK_MUL_ASSIGN,    TOK_KIND_OPERATOR)\
    DEF("/=",  TOK_DIV_ASSIGN,    TOK_KIND_OPERATOR)\
    DEF("%=",  TOK_MOD_ASSIGN,    TOK_KIND_OPERATOR)\
    DEF("&=",  TOK_AND_ASSIGN,    TOK_KIND_OPERATOR)\
    DEF("|=",  TOK_OR_ASSIGN,     TOK_KIND_OPERATOR)\
    DEF("^=",  TOK_XOR_ASSIGN,    TOK_KIND_OPERATOR)\
    DEF("<<=", TOK_LSHIFT_ASSIGN, TOK_KIND_OPERATOR)\
    DEF(">>=", TOK_RSHIFT_ASSIGN, TOK_KIND_OPERATOR)\
	/* Statement */\
    DEF("?",   TOK_QUESTION,      TOK_KIND_STATEMENT)\
    DEF(":",   TOK_COLON,         TOK_KIND_STATEMENT)\
    DEF("...", TOK_ELLIPSIS,      TOK_KIND_STATEMENT)\
	DEF(";",   TOK_SEMICOLON,     TOK_KIND_STATEMENT)\
	/* Pre Process */\
	DEF("#",             TOK_HASH,          TOK_KIND_PP)\
	DEF("##",            TOK_HASH_HASH,     TOK_KIND_PP)\
	DEF("#ifndef"DLM,    TOK_PP_IFNDEF,     TOK_KIND_PP)\
	DEF("#ifdef"DLM,     TOK_PP_IFDEF,      TOK_KIND_PP)\
	DEF("#if"DLM,        TOK_PP_IF,         TOK_KIND_PP)\
	DEF("#elif"DLM,      TOK_PP_ELIF,       TOK_KIND_PP)\
	DEF("#line"DLM,      TOK_PP_LINE,       TOK_KIND_PP)\
	DEF("#else"DLM,      TOK_PP_ELSE,       TOK_KIND_PP)\
	DEF("#error"DLM,     TOK_PP_ERROR,      TOK_KIND_PP)\
	DEF("#undef"DLM,     TOK_PP_UNDEF,      TOK_KIND_PP)\
	DEF("#endif"DLM,     TOK_PP_ENDIF,      TOK_KIND_PP)\
	DEF("#pragma"DLM,    TOK_PP_PRAGMA,     TOK_KIND_PP)\
	DEF("#define"DLM,    TOK_PP_DEFINE,     TOK_KIND_PP)\
	DEF("#include"DLM,   TOK_PP_INCLUDE,    TOK_KIND_PP)\
	/* Specifier */\
	DEF("static"DLM,         TOK_STATIC,        TOK_KIND_KEYWORD)\
	DEF("extern"DLM,         TOK_EXTERN,        TOK_KIND_KEYWORD)\
	DEF("typedef"DLM,        TOK_TYPEDEF,       TOK_KIND_KEYWORD)\
	DEF("register"DLM,       TOK_REGISTER,      TOK_KIND_KEYWORD)\
	DEF("_Thread_local"DLM,  TOK_THREAD_LOCAL,  TOK_KIND_KEYWORD)\
	/* Qualifier */\
	DEF("const"DLM,          TOK_CONST,         TOK_KIND_KEYWORD)\
	DEF("volatile"DLM,       TOK_VOLATILE,      TOK_KIND_KEYWORD)\
	DEF("restrict"DLM,       TOK_RESTRICT,      TOK_KIND_KEYWORD)\
	DEF("_Atomic"DLM,        TOK_ATOMIC,        TOK_KIND_KEYWORD)\
	/* Keyword */\
	DEF("do"DLM,             TOK_DO,            TOK_KIND_KEYWORD)\
	DEF("if"DLM,             TOK_IF,            TOK_KIND_KEYWORD)\
	DEF("for"DLM,            TOK_FOR,           TOK_KIND_KEYWORD)\
	DEF("auto"DLM,           TOK_AUTO,          TOK_KIND_KEYWORD)\
	DEF("case"DLM,           TOK_CASE,          TOK_KIND_KEYWORD)\
	DEF("else"DLM,           TOK_ELSE,          TOK_KIND_KEYWORD)\
	DEF("goto"DLM,           TOK_GOTO,          TOK_KIND_KEYWORD)\
	DEF("break"DLM,          TOK_BREAK,         TOK_KIND_KEYWORD)\
	DEF("while"DLM,          TOK_WHILE,         TOK_KIND_KEYWORD)\
	DEF("typeof"DLM,         TOK_TYPEOF,        TOK_KIND_KEYWORD)\
	DEF("switch"DLM,         TOK_SWITCH,        TOK_KIND_KEYWORD)\
	DEF("inline"DLM,         TOK_INLINE,        TOK_KIND_KEYWORD)\
	DEF("sizeof"DLM,         TOK_SIZEOF,        TOK_KIND_KEYWORD)\
	DEF("return"DLM,         TOK_RETURN,        TOK_KIND_KEYWORD)\
	DEF("default"DLM,        TOK_DEFAULT,       TOK_KIND_KEYWORD)\
	DEF("continue"DLM,       TOK_CONTINUE,      TOK_KIND_KEYWORD)\
	DEF("_Alignas"DLM,       TOK_ALIGNAS,       TOK_KIND_KEYWORD)\
	DEF("_Alignof"DLM,       TOK_ALIGNOF,       TOK_KIND_KEYWORD)\
	DEF("_Generic"DLM,       TOK_GENERIC,       TOK_KIND_KEYWORD)\
	DEF("_Complex"DLM,       TOK_COMPLEX,       TOK_KIND_KEYWORD)\
	DEF("_Noreturn"DLM,      TOK_NORETURN,      TOK_KIND_KEYWORD)\
	DEF("_Imaginary"DLM,     TOK_IMAGINARY,     TOK_KIND_KEYWORD)\
	DEF("_Static_assert"DLM, TOK_STATIC_ASSERT, TOK_KIND_KEYWORD)\
	/* Type */\
	DEF("int"DLM,       TOK_INT,           TOK_KIND_TYPE)\
	DEF("enum"DLM,      TOK_ENUM,          TOK_KIND_TYPE)\
	DEF("char"DLM,      TOK_CHAR,          TOK_KIND_TYPE)\
	DEF("long"DLM,      TOK_LONG,          TOK_KIND_TYPE)\
	DEF("void"DLM,      TOK_VOID,          TOK_KIND_TYPE)\
	DEF("bool"DLM,      TOK_BOOL,          TOK_KIND_TYPE)\
	DEF("union"DLM,     TOK_UNION,         TOK_KIND_TYPE)\
	DEF("float"DLM,     TOK_FLOAT,         TOK_KIND_TYPE)\
	DEF("short"DLM,     TOK_SHORT,         TOK_KIND_TYPE)\
	DEF("_Bool"DLM,     TOK_BOOL,          TOK_KIND_TYPE)\
	DEF("signed"DLM,    TOK_SIGNED,        TOK_KIND_TYPE)\
	DEF("struct"DLM,    TOK_STRUCT,        TOK_KIND_TYPE)\
	DEF("double"DLM,    TOK_DOUBLE,        TOK_KIND_TYPE)\
	DEF("size_t"DLM,    TOK_SIZE_T,        TOK_KIND_TYPE)\
	DEF("int8_t"DLM,    TOK_INT8_T,        TOK_KIND_TYPE)\
	DEF("uint8_t"DLM,   TOK_UINT8_T,       TOK_KIND_TYPE)\
	DEF("wchar_t"DLM,   TOK_WCHAR_T,       TOK_KIND_TYPE)\
	DEF("int16_t"DLM,   TOK_INT16_T,       TOK_KIND_TYPE)\
	DEF("int32_t"DLM,   TOK_INT32_T,       TOK_KIND_TYPE)\
	DEF("int64_t"DLM,   TOK_INT64_T,       TOK_KIND_TYPE)\
	DEF("uint16_t"DLM,  TOK_UINT16_T,      TOK_KIND_TYPE)\
	DEF("uint32_t"DLM,  TOK_UINT32_T,      TOK_KIND_TYPE)\
	DEF("unsigned"DLM,  TOK_UNSIGNED,      TOK_KIND_TYPE)\
	DEF("uint64_t"DLM,  TOK_UINT64_T,      TOK_KIND_TYPE)\
	DEF("ptrdiff_t"DLM, TOK_PTRDIFF_T,     TOK_KIND_TYPE)

#define DEF_TOK_QUOTE(DEF, DEF_RANGE)\
	DEF_RANGE(TOK_ASCII_RANGE,  TOK_KIND_TEXT)\
	/* Whitespace */\
	DEF("\t", TOK_TAB,          TOK_KIND_WHITESPACE)\
	DEF("\n", TOK_NEWLINE,      TOK_KIND_WHITESPACE)\
	DEF(" ",  TOK_SPACE,        TOK_KIND_WHITESPACE)\
	/* Quote */\
	DEF("\"",  TOK_DQUOTE,   TOK_KIND_QUOTE)\
	DEF("\'",  TOK_SQUOTE,   TOK_KIND_QUOTE)\
    DEF("`",   TOK_BACKTICK, TOK_KIND_QUOTE)\
	/* Escape */\
    DEF("\\"  /*92*/,  TOK_BACKSLASH,     TOK_KIND_ESCAPE)\
    DEF("\\0" /*NUL*/, TOK_ESC_NULL,      TOK_KIND_ESCAPE)\
    DEF("\\a" /*BEL*/, TOK_ESC_ALERT,     TOK_KIND_ESCAPE)\
    DEF("\\b" /*BS*/,  TOK_ESC_BACKSPACE, TOK_KIND_ESCAPE)\
    DEF("\\t" /*TAB*/, TOK_ESC_TAB,       TOK_KIND_ESCAPE)\
    DEF("\\n" /*LF*/,  TOK_ESC_NEWLINE,   TOK_KIND_ESCAPE)\
    DEF("\\v" /*VT*/,  TOK_ESC_VTAB,      TOK_KIND_ESCAPE)\
    DEF("\\f" /*FF*/,  TOK_ESC_FORMFEED,  TOK_KIND_ESCAPE)\
    DEF("\\r" /*CR*/,  TOK_ESC_RETURN,    TOK_KIND_ESCAPE)\
    DEF("\\\\"/*\\*/,  TOK_ESC_BACKSLASH, TOK_KIND_ESCAPE)\
    DEF("\\'" /*'*/,   TOK_ESC_SQUOTE,    TOK_KIND_ESCAPE)\
    DEF("\\\""/*"*/,   TOK_ESC_DQUOTE,    TOK_KIND_ESCAPE)\
    DEF("\\?" /*?*/,   TOK_ESC_QUESTION,  TOK_KIND_ESCAPE)\
    /* Hex Prefix */\
    DEF("\\x", TOK_ESC_HEX, TOK_KIND_ESCAPE)\
    /* Unicode Prefix */\
    DEF("\\u", TOK_ESC_UNICODE4, TOK_KIND_ESCAPE)\
    DEF("\\U", TOK_ESC_UNICODE8, TOK_KIND_ESCAPE)

	/*
     Octal Prefix TODO how to highlight whole octal? \
    DEF("\\0",         TOK_ESC_OCT,      TOK_KIND_ESCAPE)\
    DEF("\\1",         TOK_ESC_OCT,      TOK_KIND_ESCAPE)\
    DEF("\\2",         TOK_ESC_OCT,      TOK_KIND_ESCAPE)\
    DEF("\\3",         TOK_ESC_OCT,      TOK_KIND_ESCAPE)\
    DEF("\\4",         TOK_ESC_OCT,      TOK_KIND_ESCAPE)\
    DEF("\\5",         TOK_ESC_OCT,      TOK_KIND_ESCAPE)\
    DEF("\\6",         TOK_ESC_OCT,      TOK_KIND_ESCAPE)\
    DEF("\\7",         TOK_ESC_OCT,      TOK_KIND_ESCAPE)\
	*/

#define DEF_TOK_COMMENT(DEF, DEF_RANGE)\
	DEF_RANGE(TOK_ASCII_RANGE,  TOK_KIND_COMMENT)\
	/* Whitespace */\
	DEF("\t", TOK_TAB,          TOK_KIND_WHITESPACE)\
	DEF("\n", TOK_NEWLINE,      TOK_KIND_WHITESPACE)\
	DEF(" ",  TOK_SPACE,        TOK_KIND_WHITESPACE)\
	/* Comment */\
	DEF("*/", TOK_RCOMMENT,     TOK_KIND_COMMENT)

typedef struct TokDef {
	char* name;
	u16 kind;
} TokDef;

#define STR_LEN(_str) (sizeof(_str) - 1)
#define DEF_TOK_DEF_ITEM(_name, _tok, _kind)  [_tok]   = (TokDef){ _name,          _kind },
#define DEF_TOK_RANGE_DEF_ITEM(_range, _kind) [_range] = (TokDef){ TOK_RANGE_NAME, _kind },

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverride-init"

static const TokDef TOK_BASE_DEFINITIONS[]    = { DEF_TOK_BASE(DEF_TOK_DEF_ITEM,    DEF_TOK_RANGE_DEF_ITEM) };
static const TokDef TOK_QUOTE_DEFINITIONS[]   = { DEF_TOK_QUOTE(DEF_TOK_DEF_ITEM,   DEF_TOK_RANGE_DEF_ITEM) };
static const TokDef TOK_COMMENT_DEFINITIONS[] = { DEF_TOK_COMMENT(DEF_TOK_DEF_ITEM, DEF_TOK_RANGE_DEF_ITEM) };

#pragma GCC diagnostic pop

/*
	We will have Sparse Trie and Packed Trie
	at a certain point it can switch past a certain density
	that density should probably had to do with scan time
	will have to test to compareww

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
	#define FRIE_LOG(...) fprintf(stderr, __VA_ARGS__)
#else
	#define FRIE_LOG(...)
#endif

static const bool IDENT_CHAR[128] = {
    ['a'...'z'] = 1,
    ['A'...'Z'] = 1,
    ['0'...'9'] = 1,
    ['_'] = 1,
};

#define IS_DELIM_TOKEN(_c)   (_c == TOK_DELIMIT || _c == TOK_MUNCH)
#define IS_SPECIAL_TOKEN(_c) (_c <= TOK_FRIE_SECIAL_END)
#define IS_ERROR_TOKEN(_c)   (_c == TOK_ERR)
#define IS_KEYWORD_TOKEN(_c) (_c >= TOK_KEYWORD_BEGIN)
#define IS_TOKEN(_c)         (((i8)_c) <= TOK_SECIAL_END)

#define IS_IDENT_CHAR(_c) IDENT_CHAR[(u8)(_c)]
#define IS_DELIM_CHAR(_c) !IDENT_CHAR[(u8)(_c)]

#define IS_DIGIT_CHAR(_c) (CHAR_FLAGS[(u8)(_c)] & CHAR_DIGIT)
#define IS_SPACE_CHAR(_c) (CHAR_FLAGS[(u8)(_c)] & CHAR_SPACE)

#define DEF_DISPATCH(_name, _tok, _kind) [_tok] = &&_tok,
#define DISPATCH_ASCII_CHAR_RANGE ' ' ... '~' // 32 ... 126 

#define TRIE_MAX_PACKED_OFFSET  4096  // 12 bit
#define TRIE_MAX_SPARSE_OFFSET  65536 // 16 bit
#define MAX_TOKEN_SIZE 16
typedef union PACKED FrieNode {
	/* First 128 ASCII chars are sparse nodes. Char value is index. */
	struct PACKED { 
		u32  succ : 16; // Amount to jump.
		u32  kind  : 8;  // Token Category
		u32  stok : 4;  // Special Token Value. 0-7 Special Frie Token. Only 4 bits needed.
		u32  pad  : 4;  // 4 more bit available
	} sparse;
	/* All tokens past first 128 ASCII chars are packed nodes. Can contain TOK_DELIMIT or TOK_MUNCH nodes. */
	struct PACKED { 
		u32  val  : 8;  // Token Value. 0-6 Special Frie Token. 32-128 ASCII Tokens. >128 Keyword Tokens
		u32  succ : 12; // offset to jump on success
		u32  fail : 12; // offset to jump on fail
	} packed;
	/* Endpoint token node. Error or Keword token. Trie exits when ecnountering these. */
	struct PACKED {
		u32   val : 8;  // Token Value. 0-6 Special Frie Token. 32-128 ASCII Tokens. >128 Keyword Tokens
		u32   kind : 8;  // token kindegory
		u32   pad : 16; // 10 more bits available
	} terminator;
	u32 raw; // Must use u32 for everything to ensure union packs to 4 bytes. Differing types makes the compiler add arbitrary packing.
} FrieNode;
STATIC_ASSERT(sizeof(FrieNode) == 4);

static FrieNode TOK_BASE_FRIE[1024];
static FrieNode TOK_QUOTE_FRIE[1024];
static FrieNode TOK_COMMENT_FRIE[1024];

static void FrieLog(FrieNode* trie)
{
	LOG("Frie:\n");
	int iNode = 0; FrieNode node = trie[iNode]; 
	fprintf(stderr, "Sparse Table: " ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "index" ANSI_RESET ANSI_WHITE "char" ANSI_DIM ANSI_ITALIC ANSI_YELLOW "SuccessTarget\n "ANSI_RESET);
	while ( iNode < TOK_KEYWORD_BEGIN) {
		fprintf(stderr, ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "%d" ANSI_RESET ANSI_WHITE "%s" ANSI_DIM ANSI_ITALIC ANSI_YELLOW "%d" ANSI_RESET ANSI_WHITE "%s" ANSI_BRIGHT_BLACK "|" ANSI_RESET, iNode, string_CHAR(iNode), node.sparse.succ, string_TOK(node.sparse.stok));
		node = trie[++iNode];
	}

	fprintf(stderr, "\nPacked Trie: " ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "index" ANSI_RESET ANSI_WHITE "char/token" ANSI_DIM ANSI_GREEN "SuccessOffset" ANSI_ITALIC ANSI_YELLOW "SuccessTarget" ANSI_RESET ANSI_DIM ANSI_RED "FailOffset" ANSI_RESET ANSI_ITALIC ANSI_DIM ANSI_YELLOW "FailTarget\n" ANSI_RESET);
	while (node.packed.val != '\0' || iNode < 128) {
		if (IS_DELIM_TOKEN(node.packed.val)) 
			fprintf(stderr, ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "%d" ANSI_RESET ANSI_WHITE "%s" ANSI_DIM ANSI_GREEN "%d" ANSI_ITALIC ANSI_YELLOW "%d" ANSI_RESET ANSI_DIM ANSI_RED "%d" ANSI_RESET ANSI_ITALIC ANSI_DIM ANSI_YELLOW "%d" ANSI_BRIGHT_BLACK "|" ANSI_RESET, iNode, string_TOK(node.packed.val), node.packed.succ, node.packed.succ+iNode, node.packed.fail, node.packed.fail+iNode);
		else if (IS_TOKEN(node.packed.val)) 
			fprintf(stderr, ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "%d" ANSI_RESET ANSI_WHITE "%s" ANSI_DIM ANSI_BRIGHT_BLACK "%c" ANSI_RESET, iNode, string_TOK(node.terminator.val), node.terminator.val == TOK_ERR ? '\n' : '|');
		else  			       
			fprintf(stderr, ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "%d" ANSI_RESET ANSI_WHITE "%c" ANSI_DIM ANSI_GREEN "%d" ANSI_ITALIC ANSI_YELLOW "%d" ANSI_RESET ANSI_DIM ANSI_RED "%d" ANSI_RESET ANSI_ITALIC ANSI_DIM ANSI_YELLOW "%d" ANSI_BRIGHT_BLACK "|" ANSI_RESET, iNode, node.packed.val, node.packed.succ, node.packed.succ+iNode, node.packed.fail, node.packed.fail+iNode);
		node = trie[++iNode];
	}
	fprintf(stderr, "\n");
}

static TOK FrieGet(const char *pText, FrieNode *pFrie) 
{
	FRIE_LOG("Checking Frie for %s\n", pText);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverride-init"
	static void *codeDispatch[TOK_CAPACITY] = {	
		[TOK_ALL_RANGE]         = &&TOK_ERR,
		[TOK_ERR]           = &&TOK_ERR,
		[TOK_DELIMIT]       = &&TOK_DELIMIT,
		[TOK_PACKED_CHAR]   = &&TOK_PACKED_CHAR,
		[TOK_SPARSE_CHAR]   = &&TOK_SPARSE_CHAR,
		[TOK_NEWLINE]       = &&TOK_SPARSE_CHAR,
		[TOK_TAB]           = &&TOK_SPARSE_CHAR,
		[TOK_ASCII_RANGE]   = &&TOK_PACKED_CHAR,
		[TOK_KEYWORD_RANGE] = &&TOK_ALL,
	};
#pragma GCC diagnostic pop

	void **disp  = codeDispatch;	

	struct PACKED {
		int      iT;
		int      iN;
		FrieNode nd;
		char     cT;
		TOK       tok;
	} step; ZERO(&step);

	step.cT = pText[0];
	step.nd = pFrie[(u8)step.cT];

TOK_SPARSE_CHAR:
	{
		FRIE_LOG("TOK_SPARSE_CHAR iT:%-4d iN:%-4d %4d:%s %s %s %s jump%d ", step.iT, step.iN, step.cT, string_CHAR(step.cT),  string_TOK(step.cT), string_TOK(step.nd.sparse.stok), string_TOK_KIND(step.nd.sparse.kind), step.nd.sparse.succ);
		step.tok = step.cT; // Store last valid token
		// Retrieve next char first to use in setup of next node dispatch.
		step.iT++; step.cT = pText[step.iT]; 
		// Setup next node dispatch.
		step.iN = step.nd.sparse.succ > 0 ? step.nd.sparse.succ : step.cT;
		TOK tok   = step.cT > 0 ? step.nd.sparse.stok : TOK_NONE; // Must dispatch from this node token value.
		step.nd = pFrie[step.iN];
		FRIE_LOG("dispatch-->%s\n", string_TOK(tok));
		goto *disp[tok];
	}

TOK_PACKED_CHAR: 
	{
		FRIE_LOG("TOK_PACKED_CHAR iT:%-4d iN:%-4d %4d:%s==", step.iT, step.iN, step.cT, string_CHAR(step.cT));
		FRIE_LOG("%s:%-4d ", string_CHAR(step.nd.packed.val), step.nd.packed.val);
		// Determine node match and retrieve next node.
		bool match = step.nd.packed.val == step.cT;
		step.iN += match ? step.nd.packed.succ : step.nd.packed.fail;
		step.nd   = pFrie[step.iN];
		// Progress to next text char if matched.
		step.iT += match; step.cT = pText[step.iT];
		FRIE_LOG("dispatch-->%d:%s\n", step.iN, string_TOK(step.nd.packed.val));
		goto *disp[step.nd.packed.val];
	}

TOK_DELIMIT: 
	{
		FRIE_LOG("TOK_DELIMIT     iT:%-4d iN:%-4d %4d:%s==", step.iT, step.iN, step.cT, string_CHAR(step.cT));
		FRIE_LOG("%s:%-4d ", string_CHAR(step.nd.packed.val), step.nd.packed.val);
		bool delim = IS_DELIM_CHAR(step.cT);
		step.iN += delim ? step.nd.packed.succ : step.nd.packed.fail;
		step.nd   = pFrie[step.iN];
		FRIE_LOG("dispatch-->%s\n", string_TOK(step.nd.packed.val));
		goto *disp[step.nd.packed.val];
	}

TOK_ALL:
	step.tok = step.nd.terminator.val; // Store last valid token
	FRIE_LOG("Token found %d %s\n", step.tok, string_TOK(step.tok));
	return step.tok;

TOK_ERR:
TOK_NONE:
	FRIE_LOG("No token found! %d %s\n", step.tok, string_TOK(step.tok));
	return step.tok;
}

static void FrieValidate(int tokCount, const TokDef* tokDefs, FrieNode* pFrie) 
{
		char sparseCharBuf[2] = { '\0', '\0' };
	for (int iTok = TOK_SECIAL_END; iTok < tokCount; ++iTok) {
		TokDef def = tokDefs[iTok];
		if (def.name == NULL) continue;
		if (def.name[0] == TOK_RANGE) {	def.name = sparseCharBuf; def.name[0] = iTok; }
		TOK tok = FrieGet(def.name, pFrie);
		LOG("%d:%s expected:%d:%s\n", tok, string_TOK(tok), iTok, string_TOK(iTok));
		MUST(tok == iTok);
	}
}

/* Shift all frie nodes right by 1 updating all offsets. */
static void FrieShift(FrieNode* pFrie, int iInsertNode, int iEndNode)
{
	// Shift all to right by 1 to make room for new char condition.
	FRIE_LOG("Shift 1 dst:%d src:%d len:%d\n", iInsertNode+1, iInsertNode, iEndNode - iInsertNode);
	memmove(pFrie + iInsertNode + 1, pFrie + iInsertNode, (iEndNode - iInsertNode) * sizeof(FrieNode));

	// Increment sparse ascii jump values if they would have jumped past current insertion
	for (int iNodePrev = 0; iNodePrev < TOK_KEYWORD_BEGIN; iNodePrev++) {
		FrieNode *pPrevNode = pFrie + iNodePrev;
		if (pPrevNode->sparse.succ > iInsertNode) { 
			FRIE_LOG("Increment sparse i%d %c succ%d\n", iNodePrev, iNodePrev, pPrevNode->sparse.succ);
			pPrevNode->sparse.succ++;
		}
	}

	// Increment all fail succ values in prior trie steps if they would have jumped past current insertion
	for (int iNodePrev = TOK_KEYWORD_BEGIN; iNodePrev < iInsertNode; iNodePrev++) {
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
	
	int iTok = 0;
	int iEndNode = TOK_KEYWORD_BEGIN;
	char sparseCharBuf[2] = { '\0', '\0' };

NextTok: 
	if (iTok == tokCount) goto RESULT_SUCCESS;
	TokDef def = tokDefs[iTok];
	if (def.name == NULL) {	iTok++; goto NextTok; }
	if (def.name[0] == TOK_RANGE) {	def.name = sparseCharBuf; def.name[0] = iTok; }
	int len = strlen(def.name); bool delim = def.name[len-1] == TOK_DELIMIT;
	int iNode = 0; int iName = 0; int iNodeFirstFail = TOK_KEYWORD_BEGIN;
	TOK tok = iTok; 

NextNameChar: 
	char cName = def.name[iName];
	if (cName == '\0' && iName == 0) {
		LOG_WARN("Trying to add empty token!\n");
		iTok++; goto NextTok;
	}
	char cNameNext= def.name[iName+1];

	if (iName == 0) {
		FrieNode *pNode = pFrie + cName;
		FrieNode node = *pNode;

		// One char token
		if (cNameNext == '\0') {
			FRIE_LOG("One Char Token i%d %c end%d %s\n", (u8)cName, cName, iEndNode, def.name);
			pNode->sparse.kind = def.kind;
			CHECKMSG(pNode->sparse.stok != TOK_SPARSE_CHAR, RESULT_DUPLICATE_ERROR, "Trying to insert single char token twice! %s %s %s", def.name, string_CHAR(cName), string_TOK(tok));
			// If token is already jumping to packed char then a longer token has been set
			if (pNode->sparse.stok != TOK_PACKED_CHAR) pNode->sparse.stok = TOK_SPARSE_CHAR;
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
		pNode->sparse.stok = TOK_PACKED_CHAR;
		iNode = iEndNode; 
		iName++;
		goto NextNameChar;
	}

	{
		FrieNode node  = pFrie[iNode];
		// Encounter a token, must shift to the right and fill in new token.
		if (IS_KEYWORD_TOKEN(node.packed.val) || IS_ERROR_TOKEN(node.packed.val)) { 
			// CHECKMSG(node.tok.val == TOK_ERR || node.tok.val == TOK_NONE, RESULT_DUPLICATE_ERROR, "Trying to write token in non-empty node!");

			// FRIE_LOG("Insert Tok i%d firstfail%d end%d %s\n", iNode, iNodeFirstFail, iEndNode, def.name);
			if (iNodeFirstFail != TOK_KEYWORD_BEGIN)	iNode = iNodeFirstFail;

			FRIE_LOG("Insert Char i%d %c end%d %s\n", iNode, cName, iEndNode, def.name);
			FrieShift(pFrie, iNode, iEndNode);
			iEndNode++; CHECK(iEndNode < frieCapacity, RESULT_CAPACITY_ERROR);
			u16 succ = iEndNode - iNode;
			CHECKMSG(succ < TRIE_MAX_PACKED_OFFSET, RESULT_OFFSET_ERROR, "succ offset:%d", succ);
			pFrie[iNode] = (FrieNode){ 
				.packed.val  = cName, 
				.packed.succ = succ, 
				.packed.fail = 1 
			};
			iName++; iNode = iEndNode;
			goto NextNameChar;
		}

		// Encounter delimit char, must shift to the right and fill in new token.
		if (cName == TOK_DELIMIT) {
			FRIE_LOG("Delimit Insert i%d end%d %s\n", iNode, iEndNode, def.name);
			FrieShift(pFrie, iNode, iEndNode);
			bool insertingAtEnd = iEndNode == iNode;
			iEndNode++; CHECK(iEndNode < frieCapacity, RESULT_CAPACITY_ERROR);
			u16 succ = iEndNode - iNode;
			CHECKMSG(succ < TRIE_MAX_PACKED_OFFSET, RESULT_OFFSET_ERROR, "succ offset:%d", succ);
			u16 fail = insertingAtEnd ? succ + 1 : 1; // If inserting at end ERR token is 1 after succ, otherwise fail to next node
			CHECKMSG(fail < TRIE_MAX_PACKED_OFFSET, RESULT_OFFSET_ERROR, "fail offset:%d", fail);
			pFrie[iNode] = (FrieNode){ 
				.packed.val  = TOK_DELIMIT, 
				.packed.succ = succ, 
				.packed.fail = fail,
			};
			delim = true;
			iName++; iNode = iEndNode;
			goto NextNameChar;
		}

		// End of Token Name. Write token go to next token!
		if (cName == '\0') {
			CHECKMSG(iNode == iEndNode, RESULT_ORDER_ERROR, "Trying to inset shorter token after longer token! %s %s", def.name, string_TOK(tok));
			FRIE_LOG("Finish Token i%d end%d len%d %s %s\n", iNode, iEndNode, iName - delim, def.name, string_TOK(tok));
			pFrie[iNode++] = (FrieNode){ .terminator.val = tok,    .terminator.kind = def.kind };
			pFrie[iNode++] = (FrieNode){ .terminator.val = TOK_ERR, .terminator.kind = TOK_KIND_ERROR };
			iTok++;	iEndNode = iNode;
			goto NextTok;
		}

		// Token char succesfully match with existing trie char
		if (cName == node.packed.val) {
			FRIE_LOG("Char Succ i%d jump%d end%d %s %c==%c\n", iNode, node.packed.succ, iEndNode, def.name, cName, node.packed.val);
			iNodeFirstFail = TOK_KEYWORD_BEGIN;
			iNode += node.packed.succ; iName++;
			goto NextNameChar;
		} 

		// Token char fail to match with existing trie char
		if (iNode < iEndNode) {
			FRIE_LOG("Char Fail i%d jump%d end%d %s %c==%c\n", iNode, node.packed.fail, iEndNode, def.name, cName, node.packed.val);
			if (iNodeFirstFail == TOK_KEYWORD_BEGIN) iNodeFirstFail = iNode;
			iNode += node.packed.fail;
			goto NextNameChar;
		}

		{
			u16 fail = (len + 1) - iName - delim; // +1 as err comes after tok
			CHECKMSG(fail < TRIE_MAX_PACKED_OFFSET, RESULT_OFFSET_ERROR, "fail offset:%d", fail);
			FRIE_LOG("Add Char iT:%d iN:%d fail:%d end:%d delim%d len:%d %s %c\n", iNode, iName, fail, iEndNode, delim, def.len, def.name, cName);
			pFrie[iNode] = (FrieNode){ 
				.packed.val  = cName, 
				.packed.succ = 1, 
				.packed.fail = fail,
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
	FrieValidate(tokCount, tokDefs, pFrie);
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

typedef struct PACKED TextMeta {
	TOK 	 tok;
	TOK_KIND kind;

	u8 SCOPE_TAB     : 4;
	u8 SCOPE_CURLY   : 4;
	u8 SCOPE_PAREN   : 4;
	u8 SCOPE_BRACKET : 4;

	u8 iTokenStartOffset : 4;
	u8 iTokenEndOffset   : 4;

	u16 iScopeStartOffset : 16;
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
	LOG("Process Meta. Token Count: %d\n", TOK_COUNT);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverride-init"

	static void *codeDispatch[TOK_CAPACITY] = {	
		[TOK_ALL_RANGE]     = &&TOK_ERR,
		[TOK_WHITE_RANGE]   = &&TOK_SPARSE_CHAR,
		[TOK_ASCII_RANGE]   = &&TOK_SPARSE_CHAR,
		[TOK_KEYWORD_RANGE] = &&TOK_ALL,
		[TOK_SQUOTE]        = &&TOK_OPEN_SQUOTE,
		[TOK_DQUOTE]        = &&TOK_OPEN_DQUOTE,
		[TOK_LCOMMENT]      = &&TOK_OPEN_BLOCK_COMMENT,
		[TOK_RCOMMENT]      = &&TOK_ERR,
		[TOK_COMMENT]       = &&TOK_OPEN_LINE_COMMENT,
		[TOK_SPARSE_CHAR]   = &&TOK_SPARSE_CHAR,
		[TOK_PACKED_CHAR]   = &&TOK_PACKED_CHAR,
		[TOK_DELIMIT]       = &&TOK_DELIMIT,
		[TOK_NONE]          = &&TOK_NONE,
		[TOK_ERR]           = &&TOK_ERR,
	};

#pragma GCC diagnostic pop

	const int  textCount = pCode->textCount;
	char	  *pText     = pCode->pText;
	TextMeta  *pMeta     = pCode->pTextMeta;
	FrieNode  *pFrie     = TOK_BASE_FRIE;
	void     **disp      = codeDispatch;

	struct PACKED {
		FrieNode nd;
		char     cT;
		int      iT;
		int      iN;
		int      iTStart;
		TOK_KIND startKind;
	} step;	ZERO(&step);

	step.cT = pText[0];
	step.nd = pFrie[(u8)step.cT];
	goto TOK_SPARSE_CHAR;

TOK_NONE:
	// No token means we reached end of file.
	return RESULT_SUCCESS;

TOK_CLOSE_QUOTE:
	codeDispatch[TOK_SQUOTE] = &&TOK_OPEN_SQUOTE;
	codeDispatch[TOK_DQUOTE] = &&TOK_OPEN_DQUOTE;
	pFrie = TOK_BASE_FRIE;
	goto TOK_SPARSE_TOKEN;

TOK_OPEN_SQUOTE:
	codeDispatch[TOK_SQUOTE] = &&TOK_CLOSE_QUOTE;
	codeDispatch[TOK_DQUOTE] = &&TOK_ERR;
	pFrie = TOK_QUOTE_FRIE;
	goto TOK_SPARSE_TOKEN;

TOK_OPEN_DQUOTE:
	codeDispatch[TOK_SQUOTE] = &&TOK_ERR;
	codeDispatch[TOK_DQUOTE] = &&TOK_CLOSE_QUOTE;
	pFrie = TOK_QUOTE_FRIE;
	goto TOK_SPARSE_TOKEN;

TOK_CLOSE_BLOCK_COMMENT:
	// FRIE_LOG("TOK_CLOSE_BLOCK_COMMENT\n");
	codeDispatch[TOK_LCOMMENT] = &&TOK_OPEN_BLOCK_COMMENT;
	codeDispatch[TOK_RCOMMENT] = &&TOK_ERR;
	codeDispatch[TOK_COMMENT]  = &&TOK_OPEN_LINE_COMMENT;
	codeDispatch[TOK_SQUOTE]   = &&TOK_OPEN_SQUOTE;
	codeDispatch[TOK_DQUOTE]   = &&TOK_OPEN_DQUOTE;
	pFrie = TOK_BASE_FRIE;
	goto TOK_ALL;

TOK_OPEN_BLOCK_COMMENT:
	// FRIE_LOG("TOK_OPEN_BLOCK_COMMENT\n");
	codeDispatch[TOK_LCOMMENT] = &&TOK_ERR;
	codeDispatch[TOK_RCOMMENT] = &&TOK_CLOSE_BLOCK_COMMENT;
	codeDispatch[TOK_COMMENT]  = &&TOK_ERR;
	codeDispatch[TOK_SQUOTE]   = &&TOK_ERR;
	codeDispatch[TOK_DQUOTE]   = &&TOK_ERR;
	pFrie = TOK_COMMENT_FRIE;
	goto TOK_ALL;

TOK_CLOSE_LINE_COMMENT:
	// FRIE_LOG("TOK_CLOSE_LINE_COMMENT\n");
	codeDispatch[TOK_LCOMMENT] = &&TOK_OPEN_BLOCK_COMMENT;
	codeDispatch[TOK_RCOMMENT] = &&TOK_ERR;
	codeDispatch[TOK_COMMENT]  = &&TOK_OPEN_LINE_COMMENT;
	codeDispatch[TOK_NEWLINE]  = &&TOK_ERR;
	codeDispatch[TOK_SQUOTE]   = &&TOK_OPEN_SQUOTE;
	codeDispatch[TOK_DQUOTE]   = &&TOK_OPEN_DQUOTE;
	pFrie = TOK_BASE_FRIE;
	goto TOK_SPARSE_TOKEN;

TOK_OPEN_LINE_COMMENT:
	// FRIE_LOG("TOK_OPEN_LINE_COMMENT\n");
	codeDispatch[TOK_LCOMMENT] = &&TOK_ERR;
	codeDispatch[TOK_RCOMMENT] = &&TOK_ERR;
	codeDispatch[TOK_COMMENT]  = &&TOK_ERR;
	codeDispatch[TOK_NEWLINE]  = &&TOK_CLOSE_LINE_COMMENT;
	codeDispatch[TOK_SQUOTE]   = &&TOK_ERR;
	codeDispatch[TOK_DQUOTE]   = &&TOK_ERR;
	pFrie = TOK_COMMENT_FRIE;
	goto TOK_ALL;

TOK_SPARSE_TOKEN:
	pMeta[step.iT].kind = step.nd.sparse.kind;	pMeta[step.iT].tok = step.cT;
	step.cT = pText[++step.iT]; 
	step.iN = step.cT < 0 ? TOK_ERR : step.cT; 
	step.nd = pFrie[step.iN]; 
	goto *disp[step.iN];

TOK_ERR:
	// If token ended up at error reset node index to sparse char and load in next node.
	step.iN = step.cT < 0 ? TOK_ERR : step.cT; 
	step.nd = pFrie[step.iN];
TOK_SPARSE_CHAR:
	{
		FRIE_LOG("TOK_SPARSE_CHAR iT:%-4d iN:%-4d %4d:%s -->sparse %d kind:%s ", step.iT, step.iN, step.cT, string_CHAR(step.cT), step.nd.sparse.succ, string_TOK_KIND(step.nd.sparse.kind));
		// Apply current node meta.
		pMeta[step.iT].kind = step.nd.sparse.kind;	pMeta[step.iT].tok = step.cT;
		step.startKind = step.nd.sparse.kind;
		step.iTStart = step.iT;

		// Retrieve next char first to use as token for sparse jump
		step.cT = pText[++step.iT];
		// if (step.iT >= 32) return RESULT_SUCCESS;

		// If we match stok jumps to packed to conitnue checking. Otherwise token is sparse char.
		bool match = step.nd.sparse.succ > 0 ;
		u8 cT = step.cT < 0 ? TOK_SPARSE_CHAR : step.cT;
		u8 disptok = match ? step.nd.sparse.stok : cT;

		// Retrieve node for next step. If we match succ is offset into packed char. 
		step.iN = match ? step.nd.sparse.succ : step.cT;
		step.nd = pFrie[step.iN]; 
		FRIE_LOG("dispatch-->iN:%d %s %s\n", step.iN, string_TOK(disptok), match ? "" : string_TOK_KIND(step.nd.sparse.kind));
		goto *disp[disptok];
	}

TOK_PACKED_CHAR:
	{
		FRIE_LOG("TOK_PACKED_CHAR iT:%-4d iN:%-4d %4d:%s==", step.iT, step.iN, step.cT, string_CHAR(step.cT));
		FRIE_LOG("%s:%-4d match:%d ", string_CHAR(step.nd.packed.val), step.nd.packed.val, step.nd.packed.val == step.cT);
		pMeta[step.iT].kind = step.startKind; pMeta[step.iT].tok = step.cT; // TODO figure way to not need to set this each time? We set individually then overwrite if it matches.

		// Load node for next step;
		bool match = step.nd.packed.val == step.cT;
		step.iN += match ? step.nd.packed.succ : step.nd.packed.fail;
		step.nd = pFrie[step.iN]; 

		// If match progress text index. Unless we are going to a token. This does waste an increment and pText lookup on fail condiiton.
		step.iT += match; 
		step.cT = pText[step.iT];

		// Single char tokens can only come from sparse chars. If we are traversing packed chars treat all single char tokens as TOK_PACKED_CHAR.
		u8 disptok = IS_TOKEN(step.nd.packed.val) ? step.nd.packed.val : TOK_PACKED_CHAR;
		FRIE_LOG("dispatch-->%s\n", string_TOK(disptok));
		goto *disp[disptok];
	}

TOK_DELIMIT: 
	{
		bool delimiter = IS_DELIM_CHAR(step.cT);
		FRIE_LOG("TOK_DELIMIT     iT:%-4d iN:%-4d %4d:%s delim:%d %s ", step.iT, step.iN, step.cT, string_CHAR(step.cT), IS_DELIM_CHAR(step.cT), string_TOK_KIND(step.nd.sparse.kind));
		// Load node for next step;
		step.iN += delimiter ? step.nd.packed.succ : step.nd.packed.fail;
		step.nd = pFrie[step.iN]; 
		u8 disptok = IS_TOKEN(step.nd.packed.val) ? step.nd.packed.val : TOK_PACKED_CHAR;
		FRIE_LOG("dispatch-->%s\n", string_TOK(step.nd.packed.val));
		goto *disp[disptok];
	}

TOK_ALL:
	{
		FRIE_LOG("%s iT:%d iN:%d fill:%d len:%d kind:%s \n", string_TOK(step.nd.terminator.val), step.iT, step.iN, step.iT - step.nd.terminator.len, step.nd.terminator.len, string_TOK_KIND(step.nd.terminator.kind));
		for (int i = step.iTStart; i < step.iT; ++i) { 
			pMeta[i].tok  = step.nd.terminator.val; 
			pMeta[i].kind = step.nd.terminator.kind; 
		}
		step.iN = step.cT < 0 ? TOK_ERR : step.cT; 
		step.nd = pFrie[step.iN];
		goto *disp[step.iN];
	}

	return RESULT_SUCCESS;
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
	REQUIRE(ConstructFrie(NARRAY(TOK_BASE_DEFINITIONS),    TOK_BASE_DEFINITIONS,    NARRAY(TOK_BASE_FRIE),    TOK_BASE_FRIE));
	REQUIRE(ConstructFrie(NARRAY(TOK_QUOTE_DEFINITIONS),   TOK_QUOTE_DEFINITIONS,   NARRAY(TOK_QUOTE_FRIE),   TOK_QUOTE_FRIE));
	REQUIRE(ConstructFrie(NARRAY(TOK_COMMENT_DEFINITIONS), TOK_COMMENT_DEFINITIONS, NARRAY(TOK_COMMENT_FRIE), TOK_COMMENT_FRIE));

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
		pCode->pText     = XCALLOC(TEXT_BUFFER_CAPACITY, char);
		pCode->pTextRows = XCALLOC(TEXT_BUFFER_CAPACITY, CodeRow);
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
		ASSERTMSG(text.textCount < TEXT_BUFFER_CAPACITY, "Loaded buffer size too big!");

		memcpy(pCode->pText, loadedFile, pCode->textCount + 1);
		free(loadedFile);

		REQUIRE(ProcessTrieMeta(pCode));
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

		Color textColor = COLOR_HIGHLIGHT_TEXT;
		Color caretColor = BLANK;
		Vector2 scanFoundPosition = { -1, -1};

		const char* pText = pCode->pText;
		const TextMeta* pMeta  = pCode->pTextMeta;
		int boxRowCount = pCode->boxRowCount;
		int boxColCount = pCode->boxColCount;
		int iChar = pCode->focusStartRowIndex;

		for (int iRow = 0; iRow < boxRowCount; ++iRow) {
			// int tabCount = 0;
			// for (int iCol = 0; iCol < boxColCount - (tabCount * tabWidth); ++iCol) {
			char     currentChar;
			TextMeta currentMeta;
			for (int iCol = 0; iCol < boxColCount; ++iCol) {
				currentChar  = pText[iChar];
				currentMeta  = pMeta[iChar];

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

				// if (currentMeta.PREPROCESS) {
				// 	DrawRectangleRec(rect, COLOR_A(COLOR_HIGHLIGHT_PREPROCESS, 20));
				// }

				// if (currentMeta.QUOTE) {
				// 	DrawRectangleRec(rect, COLOR_A(COLOR_HIGHLIGHT_QUOTE, 50));
				// }

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
						Color color = TOK_KIND_COLOR[currentMeta.kind];
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
				TextMeta m = pCode->pTextMeta[pCode->pCarets[0].index];
				DEBUG_LOG_ONCE("%s %s start: %d end: %d\n", string_TOK(m.tok), string_TOK_KIND(m.kind), m.iTokenStartOffset, m.iTokenEndOffset);
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



