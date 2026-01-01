//0123456789

/* 
 * Test
 */
#ifdef A
#endif

double T() {
	char *str = "Hello\n\x01!\\";
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
 * Lex
 */

#define DEF_TOK_CAT(DEF) \
	DEF(TOK_CAT_NONE) \
	DEF(TOK_CAT_ERROR) \
	DEF(TOK_CAT_ALPHA) \
	DEF(TOK_CAT_DIGIT) \
	DEF(TOK_CAT_TYPE) \
	DEF(TOK_CAT_KEYWORD) \
	DEF(TOK_CAT_WHITESPACE) \
	DEF(TOK_CAT_STATEMENT) \
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
	[TOK_CAT_STATEMENT]  = COLOR_SCOPE,
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

#define TK_CAPACITY 256

#define TK_SECIAL_BEGIN 0
#define TK_SECIAL_END   5
#define TK_SECIAL_RANGE TK_SECIAL_BEGIN ... TK_FRIE_SECIAL_END

#define TK_WHITESPACE_BEGIN 9
#define TK_WHITESPACE_END   13
#define TK_WHITE_RANGE TK_WHITESPACE_BEGIN ... TK_WHITESPACE_END

#define TK_ASCII_BEGIN 32
#define TK_ASCII_END   126
#define TK_ASCII_RANGE TK_ASCII_BEGIN ... TK_ASCII_END

#define TK_KEYWORD_BEGIN 128
#define TK_KEYWORD_END   255
#define TK_KEYWORD_RANGE TK_KEYWORD_BEGIN ... TK_KEYWORD_END

#define TK_BEGIN 0
#define TK_END   TK_KEYWORD_END
#define TK_RANGE TK_BEGIN ... TK_END

#define DEF_TK(DEF)\
    /*Frie Special */\
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
    DEF(TK_SPACE,         /*32*/' ' )\
    DEF(TK_BANG,          /*33*/'!' )\
    DEF(TK_DQUOTE,        /*34*/'"' )\
    DEF(TK_HASH,          /*35*/'#' )\
    DEF(TK_DOLLAR,        /*36*/'$' )\
    DEF(TK_PERCENT,       /*37*/'%' )\
    DEF(TK_AMP,           /*38*/'&' )\
    DEF(TK_SQUOTE,        /*39*/'\'')\
    DEF(TK_LPAREN,        /*40*/'(' )\
    DEF(TK_RPAREN,        /*41*/')' )\
    DEF(TK_STAR,          /*42*/'*' )\
    DEF(TK_PLUS,          /*43*/'+' )\
    DEF(TK_COMMA,         /*44*/',' )\
    DEF(TK_MINUS,         /*45*/'-' )\
    DEF(TK_DOT,           /*46*/'.' )\
    DEF(TK_SLASH,         /*47*/'/' )\
    DEF(TK_0,             /*48*/'0' )\
    DEF(TK_1,             /*49*/'1' )\
    DEF(TK_2,             /*50*/'2' )\
    DEF(TK_3,             /*51*/'3' )\
    DEF(TK_4,             /*52*/'4' )\
    DEF(TK_5,             /*53*/'5' )\
    DEF(TK_6,             /*54*/'6' )\
    DEF(TK_7,             /*55*/'7' )\
    DEF(TK_8,             /*56*/'8' )\
    DEF(TK_9,             /*57*/'9' )\
    DEF(TK_COLON,         /*58*/':' )\
    DEF(TK_SEMICOLON,     /*59*/';' )\
    DEF(TK_LT,            /*60*/'<' )\
    DEF(TK_EQ,            /*61*/'=' )\
    DEF(TK_GT,            /*62*/'>' )\
    DEF(TK_QUESTION,      /*63*/'?' )\
    DEF(TK_AT,            /*64*/'@' )\
    DEF(TK_A,             /*65*/'A' )\
    DEF(TK_B,             /*66*/'B' )\
    DEF(TK_C,             /*67*/'C' )\
    DEF(TK_D,             /*68*/'D' )\
    DEF(TK_E,             /*69*/'E' )\
    DEF(TK_F,             /*70*/'F' )\
    DEF(TK_G,             /*71*/'G' )\
    DEF(TK_H,             /*72*/'H' )\
    DEF(TK_I,             /*73*/'I' )\
    DEF(TK_J,             /*74*/'J' )\
    DEF(TK_K,             /*75*/'K' )\
    DEF(TK_L,             /*76*/'L' )\
    DEF(TK_M,             /*77*/'M' )\
    DEF(TK_N,             /*78*/'N' )\
    DEF(TK_O,             /*79*/'O' )\
    DEF(TK_P,             /*80*/'P' )\
    DEF(TK_Q,             /*81*/'Q' )\
    DEF(TK_R,             /*82*/'R' )\
    DEF(TK_S,             /*83*/'S' )\
    DEF(TK_T,             /*84*/'T' )\
    DEF(TK_U,             /*85*/'U' )\
    DEF(TK_V,             /*86*/'V' )\
    DEF(TK_W,             /*87*/'W' )\
    DEF(TK_X,             /*88*/'X' )\
    DEF(TK_Y,             /*89*/'Y' )\
    DEF(TK_Z,             /*90*/'Z' )\
    DEF(TK_LBRACKET,      /*91*/'[' )\
    DEF(TK_BACKSLASH,     /*92*/'\\')\
    DEF(TK_RBRACKET,      /*93*/']' )\
    DEF(TK_CARET,         /*94*/'^' )\
    DEF(TK_UNDERSCORE,    /*95*/'_' )\
    DEF(TK_BACKTICK,      /*96*/'`' )\
    DEF(TK_a,             /*97*/'a' )\
    DEF(TK_b,             /*98*/'b' )\
    DEF(TK_c,             /*99*/'c' )\
    DEF(TK_d,            /*100*/'d' )\
    DEF(TK_e,            /*101*/'e' )\
    DEF(TK_f,            /*102*/'f' )\
    DEF(TK_g,            /*103*/'g' )\
    DEF(TK_h,            /*104*/'h' )\
    DEF(TK_i,            /*105*/'i' )\
    DEF(TK_j,            /*106*/'j' )\
    DEF(TK_k,            /*107*/'k' )\
    DEF(TK_l,            /*108*/'l' )\
    DEF(TK_m,            /*109*/'m' )\
    DEF(TK_n,            /*110*/'n' )\
    DEF(TK_o,            /*111*/'o' )\
    DEF(TK_p,            /*112*/'p' )\
    DEF(TK_q,            /*113*/'q' )\
    DEF(TK_r,            /*114*/'r' )\
    DEF(TK_s,            /*115*/'s' )\
    DEF(TK_t,            /*116*/'t' )\
    DEF(TK_u,            /*117*/'u' )\
    DEF(TK_v,            /*118*/'v' )\
    DEF(TK_w,            /*119*/'w' )\
    DEF(TK_x,            /*120*/'x' )\
    DEF(TK_y,            /*121*/'y' )\
    DEF(TK_z,            /*122*/'z' )\
    DEF(TK_LBRACE,       /*123*/'{' )\
    DEF(TK_PIPE,         /*124*/'|' )\
    DEF(TK_RBRACE,       /*125*/'}' )\
    DEF(TK_TILDE,        /*126*/'~' )\
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
	DEF(TK_HASH_HASH)\
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
	/* Type */\
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
	/* Operator */\
    DEF(TK_INC,           /* ++  */)\
    DEF(TK_DEC,           /* --  */)\
    DEF(TK_ARROW,         /* ->  */)\
    DEF(TK_LSHIFT,        /* <<  */)\
    DEF(TK_RSHIFT,        /* >>  */)\
    DEF(TK_LE,            /* <=  */)\
    DEF(TK_GE,            /* >=  */)\
    DEF(TK_EQ_EQ,         /* ==  */)\
    DEF(TK_NE,            /* !=  */)\
    DEF(TK_AND,           /* &&  */)\
    DEF(TK_OR,            /* ||  */)\
    DEF(TK_ADD_ASSIGN,    /* +=  */)\
    DEF(TK_SUB_ASSIGN,    /* -=  */)\
    DEF(TK_MUL_ASSIGN,    /* *=  */)\
    DEF(TK_DIV_ASSIGN,    /* /=  */)\
    DEF(TK_MOD_ASSIGN,    /* %=  */)\
    DEF(TK_AND_ASSIGN,    /* &=  */)\
    DEF(TK_OR_ASSIGN,     /* |=  */)\
    DEF(TK_XOR_ASSIGN,    /* ^=  */)\
    DEF(TK_LSHIFT_ASSIGN, /* <<= */)\
    DEF(TK_RSHIFT_ASSIGN, /* >>= */)\
    DEF(TK_ELLIPSIS,      /* ... */)\
	/* Comment */\
	DEF(TK_LCOMMENT)\
    DEF(TK_RCOMMENT)\
    DEF(TK_COMMENT)\
	/* Escape Code */\
    DEF(TK_ESC_NULL,      /* \\0  NUL */)\
    DEF(TK_ESC_ALERT,     /* \\a  BEL */)\
    DEF(TK_ESC_BACKSPACE, /* \\b  BS  */)\
    DEF(TK_ESC_TAB,       /* \\t  TAB */)\
    DEF(TK_ESC_NEWLINE,   /* \\n  LF  */)\
    DEF(TK_ESC_VTAB,      /* \\v  VT  */)\
    DEF(TK_ESC_FORMFEED,  /* \\f  FF  */)\
    DEF(TK_ESC_RETURN,    /* \\r  CR  */)\
    DEF(TK_ESC_BACKSLASH, /* \\\\ \\  */)\
    DEF(TK_ESC_SQUOTE,    /* \\'  '   */)\
    DEF(TK_ESC_DQUOTE,    /* \\\  "   */)\
    DEF(TK_ESC_QUESTION,  /* \\?  ?   */)\
	DEF(TK_ESC_HEX,       /* \\x      */)\
    DEF(TK_ESC_UNICODE4,  /* \\u      */)\
    DEF(TK_ESC_UNICODE8,  /* \\U      */)\
	DEF(TK_COUNT)
DEF_ENUM(TK);
STATIC_ASSERT(TK_COUNT < TK_CAPACITY, "Not setup to support more than 256 tokens!");

#define DELIM "\x03"

#define DEF_TK_BASE(DEF)\
    /* Whitespace */\
    DEF("\t", TK_TAB,          TOK_CAT_WHITESPACE)\
    DEF("\v", TK_VERTICAL_TAB, TOK_CAT_WHITESPACE)\
    DEF("\n", TK_NEWLINE,      TOK_CAT_WHITESPACE)\
    DEF("\f", TK_FORM_FEED,    TOK_CAT_WHITESPACE)\
    DEF("\r", TK_CARR_RETURN,  TOK_CAT_WHITESPACE)\
    DEF(" ",  TK_SPACE,        TOK_CAT_WHITESPACE)\
    /* Digit */\
    DEF("0", TK_0, TOK_CAT_DIGIT)\
    DEF("1", TK_1, TOK_CAT_DIGIT)\
    DEF("2", TK_2, TOK_CAT_DIGIT)\
    DEF("3", TK_3, TOK_CAT_DIGIT)\
    DEF("4", TK_4, TOK_CAT_DIGIT)\
    DEF("5", TK_5, TOK_CAT_DIGIT)\
    DEF("6", TK_6, TOK_CAT_DIGIT)\
    DEF("7", TK_7, TOK_CAT_DIGIT)\
    DEF("8", TK_8, TOK_CAT_DIGIT)\
    DEF("9", TK_9, TOK_CAT_DIGIT)\
    /* Uppercase Alpha */\
    DEF("A", TK_A, TOK_CAT_ALPHA)\
    DEF("B", TK_B, TOK_CAT_ALPHA)\
    DEF("C", TK_C, TOK_CAT_ALPHA)\
    DEF("D", TK_D, TOK_CAT_ALPHA)\
    DEF("E", TK_E, TOK_CAT_ALPHA)\
    DEF("F", TK_F, TOK_CAT_ALPHA)\
    DEF("G", TK_G, TOK_CAT_ALPHA)\
    DEF("H", TK_H, TOK_CAT_ALPHA)\
    DEF("I", TK_I, TOK_CAT_ALPHA)\
    DEF("J", TK_J, TOK_CAT_ALPHA)\
    DEF("K", TK_K, TOK_CAT_ALPHA)\
    DEF("L", TK_L, TOK_CAT_ALPHA)\
    DEF("M", TK_M, TOK_CAT_ALPHA)\
    DEF("N", TK_N, TOK_CAT_ALPHA)\
    DEF("O", TK_O, TOK_CAT_ALPHA)\
    DEF("P", TK_P, TOK_CAT_ALPHA)\
    DEF("Q", TK_Q, TOK_CAT_ALPHA)\
    DEF("R", TK_R, TOK_CAT_ALPHA)\
    DEF("S", TK_S, TOK_CAT_ALPHA)\
    DEF("T", TK_T, TOK_CAT_ALPHA)\
    DEF("U", TK_U, TOK_CAT_ALPHA)\
    DEF("V", TK_V, TOK_CAT_ALPHA)\
    DEF("W", TK_W, TOK_CAT_ALPHA)\
    DEF("X", TK_X, TOK_CAT_ALPHA)\
    DEF("Y", TK_Y, TOK_CAT_ALPHA)\
    DEF("Z", TK_Z, TOK_CAT_ALPHA)\
    /* Lowercase Alpha */\
    DEF("a", TK_a, TOK_CAT_ALPHA)\
    DEF("b", TK_b, TOK_CAT_ALPHA)\
    DEF("c", TK_c, TOK_CAT_ALPHA)\
    DEF("d", TK_d, TOK_CAT_ALPHA)\
    DEF("e", TK_e, TOK_CAT_ALPHA)\
    DEF("f", TK_f, TOK_CAT_ALPHA)\
    DEF("g", TK_g, TOK_CAT_ALPHA)\
    DEF("h", TK_h, TOK_CAT_ALPHA)\
    DEF("i", TK_i, TOK_CAT_ALPHA)\
    DEF("j", TK_j, TOK_CAT_ALPHA)\
    DEF("k", TK_k, TOK_CAT_ALPHA)\
    DEF("l", TK_l, TOK_CAT_ALPHA)\
    DEF("m", TK_m, TOK_CAT_ALPHA)\
    DEF("n", TK_n, TOK_CAT_ALPHA)\
    DEF("o", TK_o, TOK_CAT_ALPHA)\
    DEF("p", TK_p, TOK_CAT_ALPHA)\
    DEF("q", TK_q, TOK_CAT_ALPHA)\
    DEF("r", TK_r, TOK_CAT_ALPHA)\
    DEF("s", TK_s, TOK_CAT_ALPHA)\
    DEF("t", TK_t, TOK_CAT_ALPHA)\
    DEF("u", TK_u, TOK_CAT_ALPHA)\
    DEF("v", TK_v, TOK_CAT_ALPHA)\
    DEF("w", TK_w, TOK_CAT_ALPHA)\
    DEF("x", TK_x, TOK_CAT_ALPHA)\
    DEF("y", TK_y, TOK_CAT_ALPHA)\
    DEF("z", TK_z, TOK_CAT_ALPHA)\
	/* Other Alpha */\
    DEF("_",  TK_UNDERSCORE, TOK_CAT_ALPHA)\
    DEF("\\", TK_BACKSLASH,  TOK_CAT_ALPHA)\
    DEF("@",  TK_AT,         TOK_CAT_ALPHA)\
    DEF("&",  TK_AMP,        TOK_CAT_ALPHA)\
    DEF("$",  TK_DOLLAR,     TOK_CAT_ALPHA)\
    /* Brace */\
	DEF("[", TK_LBRACKET, TOK_CAT_OPERATOR)\
    DEF("]", TK_RBRACKET, TOK_CAT_OPERATOR)\
    DEF("{", TK_LBRACE,   TOK_CAT_OPERATOR)\
    DEF("}", TK_RBRACE,   TOK_CAT_OPERATOR)\
    DEF("(", TK_LPAREN,   TOK_CAT_OPERATOR)\
    DEF(")", TK_RPAREN,   TOK_CAT_OPERATOR)\
	/* Quote */\
	DEF("\"", TK_DQUOTE,  TOK_CAT_QUOTE)\
	DEF("\'", TK_SQUOTE,   TOK_CAT_QUOTE)\
    DEF("`",  TK_BACKTICK, TOK_CAT_QUOTE)\
	/* Comment */\
	DEF("/*", TK_LCOMMENT, TOK_CAT_COMMENT)\
    DEF("//", TK_COMMENT,  TOK_CAT_COMMENT)\
	/* Operator */\
    DEF("|",   TK_PIPE,          TOK_CAT_OPERATOR)\
    DEF("!",   TK_BANG,          TOK_CAT_OPERATOR)\
    DEF("%",   TK_PERCENT,       TOK_CAT_OPERATOR)\
    DEF("*",   TK_STAR,          TOK_CAT_OPERATOR)\
    DEF("+",   TK_PLUS,          TOK_CAT_OPERATOR)\
    DEF(",",   TK_COMMA,         TOK_CAT_OPERATOR)\
    DEF("-",   TK_MINUS,         TOK_CAT_OPERATOR)\
    DEF(".",   TK_DOT,           TOK_CAT_OPERATOR)\
    DEF("/",   TK_SLASH,         TOK_CAT_OPERATOR)\
    DEF("<",   TK_LT,            TOK_CAT_OPERATOR)\
    DEF("=",   TK_EQ,            TOK_CAT_OPERATOR)\
    DEF(">",   TK_GT,            TOK_CAT_OPERATOR)\
    DEF("^",   TK_CARET,         TOK_CAT_OPERATOR)\
    DEF("~",   TK_TILDE,         TOK_CAT_OPERATOR)\
    DEF("++",  TK_INC,           TOK_CAT_OPERATOR)\
    DEF("--",  TK_DEC,           TOK_CAT_OPERATOR)\
    DEF("->",  TK_ARROW,         TOK_CAT_OPERATOR)\
    DEF("<<",  TK_LSHIFT,        TOK_CAT_OPERATOR)\
    DEF(">>",  TK_RSHIFT,        TOK_CAT_OPERATOR)\
    DEF("<=",  TK_LE,            TOK_CAT_OPERATOR)\
    DEF(">=",  TK_GE,            TOK_CAT_OPERATOR)\
    DEF("==",  TK_EQ_EQ,         TOK_CAT_OPERATOR)\
    DEF("!=",  TK_NE,            TOK_CAT_OPERATOR)\
    DEF("&&",  TK_AND,           TOK_CAT_OPERATOR)\
    DEF("||",  TK_OR,            TOK_CAT_OPERATOR)\
    DEF("+=",  TK_ADD_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("-=",  TK_SUB_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("*=",  TK_MUL_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("/=",  TK_DIV_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("%=",  TK_MOD_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("&=",  TK_AND_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("|=",  TK_OR_ASSIGN,     TOK_CAT_OPERATOR)\
    DEF("^=",  TK_XOR_ASSIGN,    TOK_CAT_OPERATOR)\
    DEF("<<=", TK_LSHIFT_ASSIGN, TOK_CAT_OPERATOR)\
    DEF(">>=", TK_RSHIFT_ASSIGN, TOK_CAT_OPERATOR)\
	DEF("=",   TK_EQ,            TOK_CAT_OPERATOR)\
	/* Statement */\
    DEF("?",   TK_QUESTION,      TOK_CAT_STATEMENT)\
    DEF(":",   TK_COLON,         TOK_CAT_STATEMENT)\
    DEF("...", TK_ELLIPSIS,      TOK_CAT_STATEMENT)\
	DEF(";",   TK_SEMICOLON,     TOK_CAT_STATEMENT)\
	/* Pre Process */\
	DEF("#",             TK_HASH,          TOK_CAT_PP)\
	DEF("##",            TK_HASH_HASH,     TOK_CAT_PP)\
	DEF("#ifndef"DELIM,  TK_PP_IFNDEF,     TOK_CAT_PP)\
	DEF("#ifdef"DELIM,   TK_PP_IFDEF,      TOK_CAT_PP)\
	DEF("#if"DELIM,      TK_PP_IF,         TOK_CAT_PP)\
	DEF("#elif"DELIM,    TK_PP_ELIF,       TOK_CAT_PP)\
	DEF("#line"DELIM,    TK_PP_LINE,       TOK_CAT_PP)\
	DEF("#else"DELIM,    TK_PP_ELSE,       TOK_CAT_PP)\
	DEF("#error"DELIM,   TK_PP_ERROR,      TOK_CAT_PP)\
	DEF("#undef"DELIM,   TK_PP_UNDEF,      TOK_CAT_PP)\
	DEF("#endif"DELIM,   TK_PP_ENDIF,      TOK_CAT_PP)\
	DEF("#pragma"DELIM,  TK_PP_PRAGMA,     TOK_CAT_PP)\
	DEF("#define"DELIM,  TK_PP_DEFINE,     TOK_CAT_PP)\
	DEF("#include"DELIM, TK_PP_INCLUDE,    TOK_CAT_PP)\
	/* Keyword */\
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
	/* Type */\
	DEF("int"DELIM,       TK_INT,           TOK_CAT_TYPE)\
	DEF("enum"DELIM,      TK_ENUM,          TOK_CAT_TYPE)\
	DEF("char"DELIM,      TK_CHAR,          TOK_CAT_TYPE)\
	DEF("long"DELIM,      TK_LONG,          TOK_CAT_TYPE)\
	DEF("void"DELIM,      TK_VOID,          TOK_CAT_TYPE)\
	DEF("bool"DELIM,      TK_BOOL,          TOK_CAT_TYPE)\
	DEF("union"DELIM,     TK_UNION,         TOK_CAT_TYPE)\
	DEF("float"DELIM,     TK_FLOAT,         TOK_CAT_TYPE)\
	DEF("short"DELIM,     TK_SHORT,         TOK_CAT_TYPE)\
	DEF("_Bool"DELIM,     TK_BOOL,          TOK_CAT_TYPE)\
	DEF("signed"DELIM,    TK_SIGNED,        TOK_CAT_TYPE)\
	DEF("struct"DELIM,    TK_STRUCT,        TOK_CAT_TYPE)\
	DEF("double"DELIM,    TK_DOUBLE,        TOK_CAT_TYPE)\
	DEF("size_t"DELIM,    TK_SIZE_T,        TOK_CAT_TYPE)\
	DEF("int8_t"DELIM,    TK_INT8_T,        TOK_CAT_TYPE)\
	DEF("uint8_t"DELIM,   TK_UINT8_T,       TOK_CAT_TYPE)\
	DEF("wchar_t"DELIM,   TK_WCHAR_T,       TOK_CAT_TYPE)\
	DEF("int16_t"DELIM,   TK_INT16_T,       TOK_CAT_TYPE)\
	DEF("int32_t"DELIM,   TK_INT32_T,       TOK_CAT_TYPE)\
	DEF("int64_t"DELIM,   TK_INT64_T,       TOK_CAT_TYPE)\
	DEF("uint16_t"DELIM,  TK_UINT16_T,      TOK_CAT_TYPE)\
	DEF("uint32_t"DELIM,  TK_UINT32_T,      TOK_CAT_TYPE)\
	DEF("unsigned"DELIM,  TK_UNSIGNED,      TOK_CAT_TYPE)\
	DEF("uint64_t"DELIM,  TK_UINT64_T,      TOK_CAT_TYPE)\
	DEF("ptrdiff_t"DELIM, TK_PTRDIFF_T,     TOK_CAT_TYPE)

#define DEF_TK_QUOTE(DEF)\
    /* Whitespace */\
    DEF("\t", TK_TAB,          TOK_CAT_WHITESPACE)\
    DEF("\v", TK_VERTICAL_TAB, TOK_CAT_WHITESPACE)\
    DEF("\n", TK_NEWLINE,      TOK_CAT_WHITESPACE)\
    DEF("\f", TK_FORM_FEED,    TOK_CAT_WHITESPACE)\
    DEF("\r", TK_CARR_RETURN,  TOK_CAT_WHITESPACE)\
    DEF(" ",  TK_SPACE,        TOK_CAT_WHITESPACE)\
    /* Digit */\
    DEF("0", TK_0, TOK_CAT_TEXT)\
    DEF("1", TK_1, TOK_CAT_TEXT)\
    DEF("2", TK_2, TOK_CAT_TEXT)\
    DEF("3", TK_3, TOK_CAT_TEXT)\
    DEF("4", TK_4, TOK_CAT_TEXT)\
    DEF("5", TK_5, TOK_CAT_TEXT)\
    DEF("6", TK_6, TOK_CAT_TEXT)\
    DEF("7", TK_7, TOK_CAT_TEXT)\
    DEF("8", TK_8, TOK_CAT_TEXT)\
    DEF("9", TK_9, TOK_CAT_TEXT)\
    /* Uppercase Alpha */\
    DEF("A", TK_A, TOK_CAT_TEXT)\
    DEF("B", TK_B, TOK_CAT_TEXT)\
    DEF("C", TK_C, TOK_CAT_TEXT)\
    DEF("D", TK_D, TOK_CAT_TEXT)\
    DEF("E", TK_E, TOK_CAT_TEXT)\
    DEF("F", TK_F, TOK_CAT_TEXT)\
    DEF("G", TK_G, TOK_CAT_TEXT)\
    DEF("H", TK_H, TOK_CAT_TEXT)\
    DEF("I", TK_I, TOK_CAT_TEXT)\
    DEF("J", TK_J, TOK_CAT_TEXT)\
    DEF("K", TK_K, TOK_CAT_TEXT)\
    DEF("L", TK_L, TOK_CAT_TEXT)\
    DEF("M", TK_M, TOK_CAT_TEXT)\
    DEF("N", TK_N, TOK_CAT_TEXT)\
    DEF("O", TK_O, TOK_CAT_TEXT)\
    DEF("P", TK_P, TOK_CAT_TEXT)\
    DEF("Q", TK_Q, TOK_CAT_TEXT)\
    DEF("R", TK_R, TOK_CAT_TEXT)\
    DEF("S", TK_S, TOK_CAT_TEXT)\
    DEF("T", TK_T, TOK_CAT_TEXT)\
    DEF("U", TK_U, TOK_CAT_TEXT)\
    DEF("V", TK_V, TOK_CAT_TEXT)\
    DEF("W", TK_W, TOK_CAT_TEXT)\
    DEF("X", TK_X, TOK_CAT_TEXT)\
    DEF("Y", TK_Y, TOK_CAT_TEXT)\
    DEF("Z", TK_Z, TOK_CAT_TEXT)\
    /* Lowercase Alpha */\
    DEF("a", TK_a, TOK_CAT_TEXT)\
    DEF("b", TK_b, TOK_CAT_TEXT)\
    DEF("c", TK_c, TOK_CAT_TEXT)\
    DEF("d", TK_d, TOK_CAT_TEXT)\
    DEF("e", TK_e, TOK_CAT_TEXT)\
    DEF("f", TK_f, TOK_CAT_TEXT)\
    DEF("g", TK_g, TOK_CAT_TEXT)\
    DEF("h", TK_h, TOK_CAT_TEXT)\
    DEF("i", TK_i, TOK_CAT_TEXT)\
    DEF("j", TK_j, TOK_CAT_TEXT)\
    DEF("k", TK_k, TOK_CAT_TEXT)\
    DEF("l", TK_l, TOK_CAT_TEXT)\
    DEF("m", TK_m, TOK_CAT_TEXT)\
    DEF("n", TK_n, TOK_CAT_TEXT)\
    DEF("o", TK_o, TOK_CAT_TEXT)\
    DEF("p", TK_p, TOK_CAT_TEXT)\
    DEF("q", TK_q, TOK_CAT_TEXT)\
    DEF("r", TK_r, TOK_CAT_TEXT)\
    DEF("s", TK_s, TOK_CAT_TEXT)\
    DEF("t", TK_t, TOK_CAT_TEXT)\
    DEF("u", TK_u, TOK_CAT_TEXT)\
    DEF("v", TK_v, TOK_CAT_TEXT)\
    DEF("w", TK_w, TOK_CAT_TEXT)\
    DEF("x", TK_x, TOK_CAT_TEXT)\
    DEF("y", TK_y, TOK_CAT_TEXT)\
    DEF("z", TK_z, TOK_CAT_TEXT)\
	/* Other Alpha */\
	DEF("~",         TK_TILDE,     TOK_CAT_TEXT)\
    DEF("{",         TK_LBRACE,    TOK_CAT_TEXT)\
    DEF("}",         TK_RBRACE,    TOK_CAT_TEXT)\
    DEF("!" /*33*/,  TK_BANG,      TOK_CAT_TEXT)\
    DEF("#" /*35*/,  TK_HASH,      TOK_CAT_TEXT)\
    DEF("$" /*36*/,  TK_DOLLAR,    TOK_CAT_TEXT)\
    DEF("%" /*37*/,  TK_PERCENT,   TOK_CAT_TEXT)\
    DEF("&" /*38*/,  TK_AMP,       TOK_CAT_TEXT)\
    DEF("(" /*40*/,  TK_LPAREN,    TOK_CAT_TEXT)\
    DEF(")" /*41*/,  TK_RPAREN,    TOK_CAT_TEXT)\
    DEF("*" /*42*/,  TK_STAR,      TOK_CAT_TEXT)\
    DEF("+" /*43*/,  TK_PLUS,      TOK_CAT_TEXT)\
    DEF("," /*44*/,  TK_COMMA,     TOK_CAT_TEXT)\
    DEF("-" /*45*/,  TK_MINUS,     TOK_CAT_TEXT)\
    DEF("." /*46*/,  TK_DOT,       TOK_CAT_TEXT)\
    DEF("/" /*47*/,  TK_SLASH,     TOK_CAT_TEXT)\
    DEF(":" /*58*/,  TK_COLON,     TOK_CAT_TEXT)\
    DEF(";" /*59*/,  TK_SEMICOLON, TOK_CAT_TEXT)\
    DEF("<" /*60*/,  TK_LT,        TOK_CAT_TEXT)\
    DEF("=" /*61*/,  TK_EQ,        TOK_CAT_TEXT)\
    DEF(">" /*62*/,  TK_GT,        TOK_CAT_TEXT)\
    DEF("?" /*63*/,  TK_QUESTION,  TOK_CAT_TEXT)\
    DEF("@" /*64*/,  TK_AT,        TOK_CAT_TEXT)\
    DEF("[" /*91*/,  TK_LBRACKET,  TOK_CAT_TEXT)\
    DEF("]" /*93*/,  TK_RBRACKET,  TOK_CAT_TEXT)\
    DEF("^" /*94*/,  TK_CARET,     TOK_CAT_TEXT)\
    DEF("_" /*95*/,  TK_UNDERSCORE,TOK_CAT_TEXT)\
	DEF("|",         TK_PIPE,      TOK_CAT_TEXT)\
	/* Quote */\
	DEF("\"",  TK_DQUOTE,   TOK_CAT_QUOTE)\
	DEF("\'",  TK_SQUOTE,   TOK_CAT_QUOTE)\
    DEF("`",   TK_BACKTICK, TOK_CAT_QUOTE)\
	/* Escape */\
    DEF("\\"  /*92*/,  TK_BACKSLASH,     TOK_CAT_ESCAPE)\
    DEF("\\0" /*NUL*/, TK_ESC_NULL,      TOK_CAT_ESCAPE)\
    DEF("\\a" /*BEL*/, TK_ESC_ALERT,     TOK_CAT_ESCAPE)\
    DEF("\\b" /*BS*/,  TK_ESC_BACKSPACE, TOK_CAT_ESCAPE)\
    DEF("\\t" /*TAB*/, TK_ESC_TAB,       TOK_CAT_ESCAPE)\
    DEF("\\n" /*LF*/,  TK_ESC_NEWLINE,   TOK_CAT_ESCAPE)\
    DEF("\\v" /*VT*/,  TK_ESC_VTAB,      TOK_CAT_ESCAPE)\
    DEF("\\f" /*FF*/,  TK_ESC_FORMFEED,  TOK_CAT_ESCAPE)\
    DEF("\\r" /*CR*/,  TK_ESC_RETURN,    TOK_CAT_ESCAPE)\
    DEF("\\\\"/*\\*/,  TK_ESC_BACKSLASH, TOK_CAT_ESCAPE)\
    DEF("\\'" /*'*/,   TK_ESC_SQUOTE,    TOK_CAT_ESCAPE)\
    DEF("\\\""/*"*/,   TK_ESC_DQUOTE,    TOK_CAT_ESCAPE)\
    DEF("\\?" /*?*/,   TK_ESC_QUESTION,  TOK_CAT_ESCAPE)\
    /* Hex Prefix */\
    DEF("\\x", TK_ESC_HEX, TOK_CAT_ESCAPE)\
    /* Unicode Prefix */\
    DEF("\\u", TK_ESC_UNICODE4, TOK_CAT_ESCAPE)\
    DEF("\\U", TK_ESC_UNICODE8, TOK_CAT_ESCAPE)

	/*
     Octal Prefix TODO how to highlight whole octal? \
    DEF("\\0",         TK_ESC_OCT,      TOK_CAT_ESCAPE)\
    DEF("\\1",         TK_ESC_OCT,      TOK_CAT_ESCAPE)\
    DEF("\\2",         TK_ESC_OCT,      TOK_CAT_ESCAPE)\
    DEF("\\3",         TK_ESC_OCT,      TOK_CAT_ESCAPE)\
    DEF("\\4",         TK_ESC_OCT,      TOK_CAT_ESCAPE)\
    DEF("\\5",         TK_ESC_OCT,      TOK_CAT_ESCAPE)\
    DEF("\\6",         TK_ESC_OCT,      TOK_CAT_ESCAPE)\
    DEF("\\7",         TK_ESC_OCT,      TOK_CAT_ESCAPE)\
	*/

#define DEF_TK_COMMENT(DEF)\
    /* Whitespace */\
    DEF("\t", TK_TAB,          TOK_CAT_WHITESPACE)\
    DEF("\v", TK_VERTICAL_TAB, TOK_CAT_WHITESPACE)\
    DEF("\n", TK_NEWLINE,      TOK_CAT_WHITESPACE)\
    DEF("\f", TK_FORM_FEED,    TOK_CAT_WHITESPACE)\
    DEF("\r", TK_CARR_RETURN,  TOK_CAT_WHITESPACE)\
    DEF(" ",  TK_SPACE,        TOK_CAT_WHITESPACE)\
	/* Comment */\
	DEF("*/", TK_RCOMMENT, TOK_CAT_COMMENT)\
    /* Digit */\
    DEF("0", TK_0, TOK_CAT_COMMENT)\
    DEF("1", TK_1, TOK_CAT_COMMENT)\
    DEF("2", TK_2, TOK_CAT_COMMENT)\
    DEF("3", TK_3, TOK_CAT_COMMENT)\
    DEF("4", TK_4, TOK_CAT_COMMENT)\
    DEF("5", TK_5, TOK_CAT_COMMENT)\
    DEF("6", TK_6, TOK_CAT_COMMENT)\
    DEF("7", TK_7, TOK_CAT_COMMENT)\
    DEF("8", TK_8, TOK_CAT_COMMENT)\
    DEF("9", TK_9, TOK_CAT_COMMENT)\
    /* Uppercase Alpha */\
    DEF("A", TK_A, TOK_CAT_COMMENT)\
    DEF("B", TK_B, TOK_CAT_COMMENT)\
    DEF("C", TK_C, TOK_CAT_COMMENT)\
    DEF("D", TK_D, TOK_CAT_COMMENT)\
    DEF("E", TK_E, TOK_CAT_COMMENT)\
    DEF("F", TK_F, TOK_CAT_COMMENT)\
    DEF("G", TK_G, TOK_CAT_COMMENT)\
    DEF("H", TK_H, TOK_CAT_COMMENT)\
    DEF("I", TK_I, TOK_CAT_COMMENT)\
    DEF("J", TK_J, TOK_CAT_COMMENT)\
    DEF("K", TK_K, TOK_CAT_COMMENT)\
    DEF("L", TK_L, TOK_CAT_COMMENT)\
    DEF("M", TK_M, TOK_CAT_COMMENT)\
    DEF("N", TK_N, TOK_CAT_COMMENT)\
    DEF("O", TK_O, TOK_CAT_COMMENT)\
    DEF("P", TK_P, TOK_CAT_COMMENT)\
    DEF("Q", TK_Q, TOK_CAT_COMMENT)\
    DEF("R", TK_R, TOK_CAT_COMMENT)\
    DEF("S", TK_S, TOK_CAT_COMMENT)\
    DEF("T", TK_T, TOK_CAT_COMMENT)\
    DEF("U", TK_U, TOK_CAT_COMMENT)\
    DEF("V", TK_V, TOK_CAT_COMMENT)\
    DEF("W", TK_W, TOK_CAT_COMMENT)\
    DEF("X", TK_X, TOK_CAT_COMMENT)\
    DEF("Y", TK_Y, TOK_CAT_COMMENT)\
    DEF("Z", TK_Z, TOK_CAT_COMMENT)\
    /* Lowercase Alpha */\
    DEF("a", TK_a, TOK_CAT_COMMENT)\
    DEF("b", TK_b, TOK_CAT_COMMENT)\
    DEF("c", TK_c, TOK_CAT_COMMENT)\
    DEF("d", TK_d, TOK_CAT_COMMENT)\
    DEF("e", TK_e, TOK_CAT_COMMENT)\
    DEF("f", TK_f, TOK_CAT_COMMENT)\
    DEF("g", TK_g, TOK_CAT_COMMENT)\
    DEF("h", TK_h, TOK_CAT_COMMENT)\
    DEF("i", TK_i, TOK_CAT_COMMENT)\
    DEF("j", TK_j, TOK_CAT_COMMENT)\
    DEF("k", TK_k, TOK_CAT_COMMENT)\
    DEF("l", TK_l, TOK_CAT_COMMENT)\
    DEF("m", TK_m, TOK_CAT_COMMENT)\
    DEF("n", TK_n, TOK_CAT_COMMENT)\
    DEF("o", TK_o, TOK_CAT_COMMENT)\
    DEF("p", TK_p, TOK_CAT_COMMENT)\
    DEF("q", TK_q, TOK_CAT_COMMENT)\
    DEF("r", TK_r, TOK_CAT_COMMENT)\
    DEF("s", TK_s, TOK_CAT_COMMENT)\
    DEF("t", TK_t, TOK_CAT_COMMENT)\
    DEF("u", TK_u, TOK_CAT_COMMENT)\
    DEF("v", TK_v, TOK_CAT_COMMENT)\
    DEF("w", TK_w, TOK_CAT_COMMENT)\
    DEF("x", TK_x, TOK_CAT_COMMENT)\
    DEF("y", TK_y, TOK_CAT_COMMENT)\
    DEF("z", TK_z, TOK_CAT_COMMENT)\
    /* Other Alpha */\
    DEF("{",         TK_LBRACE,    TOK_CAT_COMMENT)\
    DEF("}",         TK_RBRACE,    TOK_CAT_COMMENT)\
    DEF("!" /*33*/,  TK_BANG,      TOK_CAT_COMMENT)\
    DEF("\""/*34*/,  TK_DQUOTE,    TOK_CAT_COMMENT)\
    DEF("#" /*35*/,  TK_HASH,      TOK_CAT_COMMENT)\
    DEF("$" /*36*/,  TK_DOLLAR,    TOK_CAT_COMMENT)\
    DEF("%" /*37*/,  TK_PERCENT,   TOK_CAT_COMMENT)\
    DEF("&" /*38*/,  TK_AMP,       TOK_CAT_COMMENT)\
    DEF("\'"/*39*/,  TK_SQUOTE,    TOK_CAT_COMMENT)\
    DEF("(" /*40*/,  TK_LPAREN,    TOK_CAT_COMMENT)\
    DEF(")" /*41*/,  TK_RPAREN,    TOK_CAT_COMMENT)\
    DEF("*" /*42*/,  TK_STAR,      TOK_CAT_COMMENT)\
    DEF("+" /*43*/,  TK_PLUS,      TOK_CAT_COMMENT)\
    DEF("," /*44*/,  TK_COMMA,     TOK_CAT_COMMENT)\
    DEF("-" /*45*/,  TK_MINUS,     TOK_CAT_COMMENT)\
    DEF("." /*46*/,  TK_DOT,       TOK_CAT_COMMENT)\
    DEF("/" /*47*/,  TK_SLASH,     TOK_CAT_COMMENT)\
    DEF(":" /*58*/,  TK_COLON,     TOK_CAT_COMMENT)\
    DEF(";" /*59*/,  TK_SEMICOLON, TOK_CAT_COMMENT)\
    DEF("<" /*60*/,  TK_LT,        TOK_CAT_COMMENT)\
    DEF("=" /*61*/,  TK_EQ,        TOK_CAT_COMMENT)\
    DEF(">" /*62*/,  TK_GT,        TOK_CAT_COMMENT)\
    DEF("?" /*63*/,  TK_QUESTION,  TOK_CAT_COMMENT)\
    DEF("@" /*64*/,  TK_AT,        TOK_CAT_COMMENT)\
    DEF("[" /*91*/,  TK_LBRACKET,  TOK_CAT_COMMENT)\
    DEF("]" /*93*/,  TK_RBRACKET,  TOK_CAT_COMMENT)\
    DEF("^" /*94*/,  TK_CARET,     TOK_CAT_COMMENT)\
    DEF("_" /*95*/,  TK_UNDERSCORE,TOK_CAT_COMMENT)\
    DEF("`" /*96*/,  TK_BACKTICK,  TOK_CAT_COMMENT)\
	DEF("|",         TK_PIPE,      TOK_CAT_COMMENT)\
	DEF("\\"/*92*/,  TK_BACKSLASH, TOK_CAT_COMMENT)

typedef struct TokDef {
	const char* name;
	int len;
	int tok;
	int cat;
} TokDef;

#define STR_LEN(_str) (sizeof(_str) - 1)
#define DEF_TOK_DEFINITION_ITEM(_name, _tok, _cat) (TokDef){ _name, (int)STR_LEN(_name), (int)_tok, (int)_cat },

static const TokDef TK_BASE_DEFINITIONS[]    = { DEF_TK_BASE(DEF_TOK_DEFINITION_ITEM)    };
static const TokDef TK_QUOTE_DEFINITIONS[]   = { DEF_TK_QUOTE(DEF_TOK_DEFINITION_ITEM)   };
static const TokDef TK_COMMENT_DEFINITIONS[] = { DEF_TK_COMMENT(DEF_TOK_DEFINITION_ITEM) };


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

#define IS_DELIM_TOKEN(_c)   (_c == TK_DELIMIT || _c == TK_MUNCH)
#define IS_SPECIAL_TOKEN(_c) (_c <= TK_FRIE_SECIAL_END)
#define IS_ERROR_TOKEN(_c)   (_c == TK_ERR)
#define IS_KEYWORD_TOKEN(_c) (_c >= TK_KEYWORD_BEGIN)
#define IS_TOKEN(_c)         (((i8)_c) <= TK_SECIAL_END)

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
		u32  stok : 4;  // Special Token Value. 0-6 Special Frie Token. Only 4 bits needed.
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
static FrieNode TOK_QUOTE_FRIE[1024];
static FrieNode TOK_COMMENT_FRIE[1024];

static void FrieLog(FrieNode* trie)
{
	LOG("Frie:\n");
	int iNode = 0; FrieNode node = trie[iNode]; 
	fprintf(stderr, "Sparse Table: " ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "index" ANSI_RESET ANSI_WHITE "char" ANSI_DIM ANSI_ITALIC ANSI_YELLOW "SuccessTarget\n "ANSI_RESET);
	while ( iNode < TK_KEYWORD_BEGIN) {
		fprintf(stderr, ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "%d" ANSI_RESET ANSI_WHITE "%s" ANSI_DIM ANSI_ITALIC ANSI_YELLOW "%d" ANSI_RESET ANSI_WHITE "%s" ANSI_BRIGHT_BLACK "|" ANSI_RESET, iNode, string_CHAR(iNode), node.sparse.succ, string_TK(node.sparse.stok));
		node = trie[++iNode];
	}

	fprintf(stderr, "\nPacked Trie: " ANSI_DIM ANSI_YELLOW ANSI_UNDERLINE "index" ANSI_RESET ANSI_WHITE "char/token" ANSI_DIM ANSI_GREEN "SuccessOffset" ANSI_ITALIC ANSI_YELLOW "SuccessTarget" ANSI_RESET ANSI_DIM ANSI_RED "FailOffset" ANSI_RESET ANSI_ITALIC ANSI_DIM ANSI_YELLOW "FailTarget\n" ANSI_RESET);
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
	LOG("Checking Frie for %s\n", pText);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverride-init"
	static void *codeDispatch[TK_CAPACITY] = {	
		[TK_RANGE]         = &&TK_ERR,
		[TK_ERR]           = &&TK_ERR,
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

	struct PACKED {
		int      iT;
		int      iN;
		FrieNode nd;
		char     cT;
		TK       tk;
	} step; ZERO(&step);

	step.cT = pText[0];
	step.nd = pFrie[(u8)step.cT];

TK_SPARSE_CHAR:
	{
		FRIE_LOG("TK_SPARSE_CHAR iT:%-4d iN:%-4d %4d:%s %s %s %s jump%d ", step.iT, step.iN, step.cT, string_CHAR(step.cT),  string_TK(step.cT), string_TK(step.nd.sparse.stok), string_TOK_CAT(step.nd.sparse.cat), step.nd.sparse.succ);
		step.tk = step.cT; // Store last valid token
		// Retrieve next char first to use in setup of next node dispatch.
		step.iT++; step.cT = pText[step.iT]; 
		// Setup next node dispatch.
		step.iN = step.nd.sparse.succ > 0 ? step.nd.sparse.succ : step.cT;
		TK tk   = step.cT > 0 ? step.nd.sparse.stok : TK_NONE; // Must dispatch from this node token value.
		step.nd = pFrie[step.iN];
		FRIE_LOG("dispatch-->%s\n", string_TK(tk));
		goto *disp[tk];
	}

TK_PACKED_CHAR: 
	{
		FRIE_LOG("TK_PACKED_CHAR iT:%-4d iN:%-4d %4d:%s==", step.iT, step.iN, step.cT, string_CHAR(step.cT));
		FRIE_LOG("%s:%-4d ", string_CHAR(step.nd.packed.val), step.nd.packed.val);
		// Determine node match and retrieve next node.
		bool match = step.nd.packed.val == step.cT;
		step.iN += match ? step.nd.packed.succ : step.nd.packed.fail;
		step.nd   = pFrie[step.iN];
		// Progress to next text char if matched.
		step.iT += match; step.cT = pText[step.iT];
		FRIE_LOG("dispatch-->%d:%s\n", step.iN, string_TK(step.nd.packed.val));
		goto *disp[step.nd.packed.val];
	}

TK_DELIMIT: 
	{
		FRIE_LOG("TK_DELIMIT     iT:%-4d iN:%-4d %4d:%s==", step.iT, step.iN, step.cT, string_CHAR(step.cT));
		FRIE_LOG("%s:%-4d ", string_CHAR(step.nd.packed.val), step.nd.packed.val);
		bool delim = IS_DELIM_CHAR(step.cT);
		step.iN += delim ? step.nd.packed.succ : step.nd.packed.fail;
		step.nd   = pFrie[step.iN];
		FRIE_LOG("dispatch-->%s\n", string_TK(step.nd.packed.val));
		goto *disp[step.nd.packed.val];
	}

TK_ALL:
	step.tk = step.nd.terminator.val; // Store last valid token
	LOG("Token found %d %s\n", step.tk, string_TK(step.tk));
	return step.tk;

TK_ERR:
TK_NONE:
	LOG("No token found! %d %s\n", step.tk, string_TK(step.tk));
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

	int iTok = 0;
	int iEndNode = TK_KEYWORD_BEGIN;

NextTok: 
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
			CHECKMSG(pNode->sparse.stok != TK_SPARSE_CHAR, RESULT_DUPLICATE_ERROR, "Trying to insert single char token twice! %s %s %s", def.name, string_CHAR(cName), string_TK(def.tok));
			// If token is already jumping to packed char then a longer token has been set
			if (pNode->sparse.stok != TK_PACKED_CHAR) pNode->sparse.stok = TK_SPARSE_CHAR;
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
		pNode->sparse.stok = TK_PACKED_CHAR;
		iNode = iEndNode; 
		iName++;
		goto NextNameChar;
	}

	{
		FrieNode node  = pFrie[iNode];
		// Encounter a token, must shift to the right and fill in new token.
		if (IS_KEYWORD_TOKEN(node.packed.val) || IS_ERROR_TOKEN(node.packed.val)) { 
			// CHECKMSG(node.tok.val == TK_ERR || node.tok.val == TK_NONE, RESULT_DUPLICATE_ERROR, "Trying to write token in non-empty node!");

			// FRIE_LOG("Insert Tok i%d firstfail%d end%d %s\n", iNode, iNodeFirstFail, iEndNode, def.name);
			if (iNodeFirstFail != TK_KEYWORD_BEGIN)	iNode = iNodeFirstFail;

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
				.packed.val  = TK_DELIMIT, 
				.packed.succ = succ, 
				.packed.fail = fail,
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
	for (int i = 0; i < tokCount; ++i) {
		TK tk = FrieGet(tokDefs[i].name, pFrie);
		LOG("%s expected:%s\n", string_TK(tk), string_TK(tokDefs[i].tok));
		MUST(tk == tokDefs[i].tok);
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

	TK*  pTextTok;
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

	static void *codeDispatch[TK_CAPACITY] = {	
		[TK_RANGE]         = &&TK_ERR,
		[TK_WHITE_RANGE]   = &&TK_SPARSE_CHAR,
		[TK_ASCII_RANGE]   = &&TK_SPARSE_CHAR,
		[TK_KEYWORD_RANGE] = &&TK_ALL,
		[TK_SQUOTE]        = &&TK_OPEN_SQUOTE,
		[TK_DQUOTE]        = &&TK_OPEN_DQUOTE,
		[TK_LCOMMENT]      = &&TK_OPEN_BLOCK_COMMENT,
		[TK_RCOMMENT]      = &&TK_ERR,
		[TK_COMMENT]       = &&TK_OPEN_LINE_COMMENT,
		[TK_SPARSE_CHAR]   = &&TK_SPARSE_CHAR,
		[TK_PACKED_CHAR]   = &&TK_PACKED_CHAR,
		[TK_DELIMIT]       = &&TK_DELIMIT,
		[TK_NONE]          = &&TK_NONE,
		[TK_ERR]           = &&TK_ERR,
	};

#pragma GCC diagnostic pop

	const int  textCount = pCode->textCount;
	char	  *pText     = pCode->pText;
	TextMeta  *pTextMeta = pCode->pTextMeta;
	TK        *pTextTok  = pCode->pTextTok;
	TOK_CAT   *pTextCat  = pCode->pTextCat;
	FrieNode  *pFrie     = TOK_BASE_FRIE;
	void     **disp      = codeDispatch;

	struct PACKED {
		int      iT;
		int      iN;
		FrieNode nd;
		char     cT;
		TOK_CAT  startCat;
	} step;	ZERO(&step);

	step.cT = pText[0];
	step.nd = pFrie[(u8)step.cT];
	goto TK_SPARSE_CHAR;

TK_NONE:
	// No token means we reached end of file.
	return RESULT_SUCCESS;

TK_CLOSE_QUOTE:
	codeDispatch[TK_SQUOTE] = &&TK_OPEN_SQUOTE;
	codeDispatch[TK_DQUOTE] = &&TK_OPEN_DQUOTE;
	pFrie = TOK_BASE_FRIE;
	goto TK_SPARSE_TOKEN;

TK_OPEN_SQUOTE:
	codeDispatch[TK_SQUOTE] = &&TK_CLOSE_QUOTE;
	codeDispatch[TK_DQUOTE] = &&TK_ERR;
	pFrie = TOK_QUOTE_FRIE;
	goto TK_SPARSE_TOKEN;

TK_OPEN_DQUOTE:
	codeDispatch[TK_SQUOTE] = &&TK_ERR;
	codeDispatch[TK_DQUOTE] = &&TK_CLOSE_QUOTE;
	pFrie = TOK_QUOTE_FRIE;
	goto TK_SPARSE_TOKEN;

TK_CLOSE_BLOCK_COMMENT:
	// FRIE_LOG("TK_CLOSE_BLOCK_COMMENT\n");
	codeDispatch[TK_LCOMMENT] = &&TK_OPEN_BLOCK_COMMENT;
	codeDispatch[TK_RCOMMENT] = &&TK_ERR;
	codeDispatch[TK_COMMENT]  = &&TK_OPEN_LINE_COMMENT;
	codeDispatch[TK_SQUOTE]   = &&TK_OPEN_SQUOTE;
	codeDispatch[TK_DQUOTE]   = &&TK_OPEN_DQUOTE;
	pFrie = TOK_BASE_FRIE;
	goto TK_ALL;

TK_OPEN_BLOCK_COMMENT:
	// FRIE_LOG("TK_OPEN_BLOCK_COMMENT\n");
	codeDispatch[TK_LCOMMENT] = &&TK_ERR;
	codeDispatch[TK_RCOMMENT] = &&TK_CLOSE_BLOCK_COMMENT;
	codeDispatch[TK_COMMENT]  = &&TK_ERR;
	codeDispatch[TK_SQUOTE]   = &&TK_ERR;
	codeDispatch[TK_DQUOTE]   = &&TK_ERR;
	pFrie = TOK_COMMENT_FRIE;
	goto TK_ALL;

TK_CLOSE_LINE_COMMENT:
	// FRIE_LOG("TK_CLOSE_LINE_COMMENT\n");
	codeDispatch[TK_LCOMMENT] = &&TK_OPEN_BLOCK_COMMENT;
	codeDispatch[TK_RCOMMENT] = &&TK_ERR;
	codeDispatch[TK_COMMENT]  = &&TK_OPEN_LINE_COMMENT;
	codeDispatch[TK_NEWLINE]  = &&TK_ERR;
	codeDispatch[TK_SQUOTE]   = &&TK_OPEN_SQUOTE;
	codeDispatch[TK_DQUOTE]   = &&TK_OPEN_DQUOTE;
	pFrie = TOK_BASE_FRIE;
	goto TK_SPARSE_TOKEN;

TK_OPEN_LINE_COMMENT:
	// FRIE_LOG("TK_OPEN_LINE_COMMENT\n");
	codeDispatch[TK_LCOMMENT] = &&TK_ERR;
	codeDispatch[TK_RCOMMENT] = &&TK_ERR;
	codeDispatch[TK_COMMENT]  = &&TK_ERR;
	codeDispatch[TK_NEWLINE]  = &&TK_CLOSE_LINE_COMMENT;
	codeDispatch[TK_SQUOTE]   = &&TK_ERR;
	codeDispatch[TK_DQUOTE]   = &&TK_ERR;
	pFrie = TOK_COMMENT_FRIE;
	goto TK_ALL;

TK_SPARSE_TOKEN:
	pTextCat[step.iT] = step.nd.sparse.cat;	pTextTok[step.iT] = step.cT;
	step.cT = pText[++step.iT]; 
	step.iN = step.cT < 0 ? TK_ERR : step.cT; 
	step.nd = pFrie[step.iN]; 
	goto *disp[step.iN];

TK_ERR:
	// If token ended up at error reset node index to sparse char and load in next node.
	step.iN = step.cT < 0 ? TK_ERR : step.cT; 
	step.nd = pFrie[step.iN];
TK_SPARSE_CHAR:
	{
		FRIE_LOG("TK_SPARSE_CHAR iT:%-4d iN:%-4d %4d:%s -->sparse %d cat:%s ", step.iT, step.iN, step.cT, string_CHAR(step.cT), step.nd.sparse.succ, string_TOK_CAT(step.nd.sparse.cat));
		// Apply current node meta.
		pTextCat[step.iT] = step.nd.sparse.cat;	pTextTok[step.iT] = step.cT;
		step.startCat = step.nd.sparse.cat;

		// step.iTBegin = step.iT; could do this to set individual char cat afterwards

		// Retrieve next char first to use as token for sparse jump
		step.cT = pText[++step.iT];
		// if (step.iT >= 32) return RESULT_SUCCESS;

		// If we match stok jumps to packed to conitnue checking. Otherwise token is sparse char.
		bool match = step.nd.sparse.succ > 0 ;
		u8 cT = step.cT < 0 ? TK_SPARSE_CHAR : step.cT;
		u8 disptk = match ? step.nd.sparse.stok : cT;

		// Retrieve node for next step. If we match succ is offset into packed char. 
		step.iN = match ? step.nd.sparse.succ : step.cT;
		step.nd = pFrie[step.iN]; 
		FRIE_LOG("dispatch-->iN:%d %s %s\n", step.iN, string_TK(disptk), match ? "" : string_TOK_CAT(step.nd.sparse.cat));
		goto *disp[disptk];
	}

TK_PACKED_CHAR:
	{
		FRIE_LOG("TK_PACKED_CHAR iT:%-4d iN:%-4d %4d:%s==", step.iT, step.iN, step.cT, string_CHAR(step.cT));
		FRIE_LOG("%s:%-4d match:%d ", string_CHAR(step.nd.packed.val), step.nd.packed.val, step.nd.packed.val == step.cT);
		pTextCat[step.iT] = step.startCat; pTextTok[step.iT] = step.cT; // TODO figure way to not need to set this each time? We set individually then overwrite if it matches.

		// Load node for next step;
		bool match = step.nd.packed.val == step.cT;
		step.iN += match ? step.nd.packed.succ : step.nd.packed.fail;
		step.nd = pFrie[step.iN]; 

		// If match progress text index. Unless we are going to a token. This does waste an increment and pText lookup on fail condiiton.
		step.iT += match; 
		step.cT = pText[step.iT];

		// Single char tokens can only come from sparse chars. If we are traversing packed chars treat all single char tokens as TK_PACKED_CHAR.
		u8 disptk = IS_TOKEN(step.nd.packed.val) ? step.nd.packed.val : TK_PACKED_CHAR;
		FRIE_LOG("dispatch-->%s\n", string_TK(disptk));
		goto *disp[disptk];
	}

TK_DELIMIT: 
	{
		bool delimiter = IS_DELIM_CHAR(step.cT);
		FRIE_LOG("TK_DELIMIT     iT:%-4d iN:%-4d %4d:%s delim:%d %s ", step.iT, step.iN, step.cT, string_CHAR(step.cT), IS_DELIM_CHAR(step.cT), string_TOK_CAT(step.nd.sparse.cat));
		// Load node for next step;
		step.iN += delimiter ? step.nd.packed.succ : step.nd.packed.fail;
		step.nd = pFrie[step.iN]; 
		u8 disptk = IS_TOKEN(step.nd.packed.val) ? step.nd.packed.val : TK_PACKED_CHAR;
		FRIE_LOG("dispatch-->%s\n", string_TK(step.nd.packed.val));
		goto *disp[disptk];
	}

TK_ALL:
	{
		u8 len = step.nd.terminator.len;
		FRIE_LOG("%s iT:%d iN:%d fill:%d len:%d cat:%s \n", string_TK(step.nd.terminator.val), step.iT, step.iN, step.iT - len, len, string_TOK_CAT(step.nd.terminator.cat));
		FILL(pTextCat + step.iT - len, step.nd.terminator.cat, len);
		FILL(pTextTok + step.iT - len, step.nd.terminator.val, len);
		step.iN = step.cT < 0 ? TK_ERR : step.cT; 
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
	REQUIRE(ConstructFrie(NARRAY(TK_BASE_DEFINITIONS),    TK_BASE_DEFINITIONS,    NARRAY(TOK_BASE_FRIE),    TOK_BASE_FRIE));
	REQUIRE(ConstructFrie(NARRAY(TK_QUOTE_DEFINITIONS),   TK_QUOTE_DEFINITIONS,   NARRAY(TOK_QUOTE_FRIE),   TOK_QUOTE_FRIE));
	REQUIRE(ConstructFrie(NARRAY(TK_COMMENT_DEFINITIONS), TK_COMMENT_DEFINITIONS, NARRAY(TOK_COMMENT_FRIE), TOK_COMMENT_FRIE));

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
		pCode->pTextTok = XCALLOC(TEXT_BUFFER_CAPACITY, TK);
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
				TK tok = pCode->pTextTok[pCode->pCarets[0].index];
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



