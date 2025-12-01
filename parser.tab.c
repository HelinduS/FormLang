/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Remove quotes from strings
char *strip_quotes(char *str) {
    int len = strlen(str);
    if (len >= 2 && str[0] == '"' && str[len-1] == '"') {
        char *new_str = malloc(len-1);
        strncpy(new_str, str+1, len-2);
        new_str[len-2] = '\0';
        free(str);
        return new_str;
    }
    return str;
}

// Field and attribute state variables
int textarea_rows = 0, textarea_cols = 0;
char *textarea_default = NULL, *field_pattern = NULL;
FILE *output;
void yyerror(const char *s);
int yylex(void);

#define MAX_OPTIONS 10
char *radio_options[MAX_OPTIONS]; int option_count = 0;
char *dropdown_default = NULL;
int dropdown_required = 0;
char *dropdown_options[MAX_OPTIONS];
int dropdown_option_count = 0;
int min_value = 0, max_value = 0;
int has_min = 0, has_max = 0;
char *date_min = NULL, *date_max = NULL;
int is_required = 0, is_checked = 0, has_options = 0;
char *password_pattern = NULL;
char *file_accept = NULL;

#line 110 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FORM = 3,                       /* FORM  */
  YYSYMBOL_SECTION = 4,                    /* SECTION  */
  YYSYMBOL_FIELD = 5,                      /* FIELD  */
  YYSYMBOL_REQUIRED = 6,                   /* REQUIRED  */
  YYSYMBOL_MIN = 7,                        /* MIN  */
  YYSYMBOL_MAX = 8,                        /* MAX  */
  YYSYMBOL_DEFAULT = 9,                    /* DEFAULT  */
  YYSYMBOL_ROWS = 10,                      /* ROWS  */
  YYSYMBOL_COLS = 11,                      /* COLS  */
  YYSYMBOL_PATTERN = 12,                   /* PATTERN  */
  YYSYMBOL_OPTIONS = 13,                   /* OPTIONS  */
  YYSYMBOL_ACCEPT = 14,                    /* ACCEPT  */
  YYSYMBOL_VALIDATE = 15,                  /* VALIDATE  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_ERROR = 17,                     /* ERROR  */
  YYSYMBOL_TEXT = 18,                      /* TEXT  */
  YYSYMBOL_TEXTAREA = 19,                  /* TEXTAREA  */
  YYSYMBOL_NUMBER = 20,                    /* NUMBER  */
  YYSYMBOL_EMAIL = 21,                     /* EMAIL  */
  YYSYMBOL_CHECKBOX = 22,                  /* CHECKBOX  */
  YYSYMBOL_RADIO = 23,                     /* RADIO  */
  YYSYMBOL_DATE = 24,                      /* DATE  */
  YYSYMBOL_DROPDOWN = 25,                  /* DROPDOWN  */
  YYSYMBOL_PASSWORD = 26,                  /* PASSWORD  */
  YYSYMBOL_FILETYPE = 27,                  /* FILETYPE  */
  YYSYMBOL_META = 28,                      /* META  */
  YYSYMBOL_IDENTIFIER = 29,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 30,                    /* STRING  */
  YYSYMBOL_BOOLEAN = 31,                   /* BOOLEAN  */
  YYSYMBOL_NUM = 32,                       /* NUM  */
  YYSYMBOL_LBRACE = 33,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 34,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 35,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 36,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 37,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 38,                     /* COLON  */
  YYSYMBOL_EQUALS = 39,                    /* EQUALS  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_ERROR_TOKEN = 41,               /* ERROR_TOKEN  */
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_form = 44,                      /* form  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_46_2 = 46,                      /* $@2  */
  YYSYMBOL_meta_list = 47,                 /* meta_list  */
  YYSYMBOL_meta_line = 48,                 /* meta_line  */
  YYSYMBOL_section_list = 49,              /* section_list  */
  YYSYMBOL_section = 50,                   /* section  */
  YYSYMBOL_field_list = 51,                /* field_list  */
  YYSYMBOL_field = 52,                     /* field  */
  YYSYMBOL_field_name = 53,                /* field_name  */
  YYSYMBOL_field_type = 54,                /* field_type  */
  YYSYMBOL_attribute_list = 55,            /* attribute_list  */
  YYSYMBOL_attribute = 56,                 /* attribute  */
  YYSYMBOL_dropdown_option_list = 57,      /* dropdown_option_list  */
  YYSYMBOL_string_list = 58,               /* string_list  */
  YYSYMBOL_validate_block_opt = 59,        /* validate_block_opt  */
  YYSYMBOL_validate_block = 60,            /* validate_block  */
  YYSYMBOL_validate_content_list = 61,     /* validate_content_list  */
  YYSYMBOL_validate_statement = 62,        /* validate_statement  */
  YYSYMBOL_validate_condition = 63         /* validate_condition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    59,    56,    68,    70,    73,    82,    83,
      86,    90,    91,    95,   171,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   219,   220,   224,
     225,   226,   227,   228,   229,   230,   231,   237,   243,   244,
     245,   246,   247,   251,   253,   257,   262,   269,   271,   275,
     278,   280,   284,   318
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FORM", "SECTION",
  "FIELD", "REQUIRED", "MIN", "MAX", "DEFAULT", "ROWS", "COLS", "PATTERN",
  "OPTIONS", "ACCEPT", "VALIDATE", "IF", "ERROR", "TEXT", "TEXTAREA",
  "NUMBER", "EMAIL", "CHECKBOX", "RADIO", "DATE", "DROPDOWN", "PASSWORD",
  "FILETYPE", "META", "IDENTIFIER", "STRING", "BOOLEAN", "NUM", "LBRACE",
  "RBRACE", "LBRACKET", "RBRACKET", "SEMICOLON", "COLON", "EQUALS",
  "COMMA", "ERROR_TOKEN", "'<'", "$accept", "form", "$@1", "$@2",
  "meta_list", "meta_line", "section_list", "section", "field_list",
  "field", "field_name", "field_type", "attribute_list", "attribute",
  "dropdown_option_list", "string_list", "validate_block_opt",
  "validate_block", "validate_content_list", "validate_statement",
  "validate_condition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       0,     6,    38,     9,   -29,   -29,   -29,    11,    15,   -29,
      36,    17,    39,    55,   -29,    41,    42,    43,    44,   -29,
      35,   -29,   -29,   -29,   -29,    -4,     7,    28,   -29,   -29,
      45,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,    46,    31,    47,    40,    49,    60,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,    -1,   -29,    52,   -29,     8,    48,   -29,    50,    51,
      53,    54,    56,    57,    58,    59,   -29,    61,   -29,   -29,
      65,   -28,    -6,     2,    62,    68,    71,    67,    73,   -29,
     -11,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,    74,   -29,   -29,    75,   -29,    -9,   -29,   -29,    76,
     -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     5,     8,     0,     6,
       3,     0,     0,    57,     9,     0,     0,     0,     0,    58,
       0,    11,    60,     4,     7,     0,     0,     0,    10,    12,
       0,    59,    61,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    15,     0,     0,     0,     0,     0,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,    63,     0,    14,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,    52,     0,    13,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    62,    48,    40,    49,    41,    46,    42,    44,    45,
      47,     0,    51,    43,     0,    53,     0,    56,    50,     0,
      54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,    13,     7,     9,    10,    14,    25,    29,
      44,    61,    65,    79,   106,    90,    18,    19,    26,    32,
      46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,    27,    92,     1,    93,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    30,    94,   103,    95,   108,   -37,   104,
      28,   109,    96,    97,   -37,     3,   -37,    76,     4,     8,
      12,    31,     5,    77,    11,    78,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    15,    43,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    16,    60,
      17,    20,    24,    48,    45,    21,    22,    63,    23,     0,
      49,    62,    66,     0,    47,    80,     0,     0,     0,    81,
      82,    89,    83,    84,    98,    85,    86,    87,    88,    91,
      99,   100,   101,   102,   105,   107,   110
};

static const yytype_int8 yycheck[] =
{
       1,     5,    30,     3,    32,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    16,    30,    36,    32,    36,    29,    40,
      34,    40,    30,    31,    35,    29,    37,    29,     0,    28,
       4,    34,    33,    35,    29,    37,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    39,    29,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    29,    29,
      15,    30,    37,    42,    29,    33,    33,    17,    34,    -1,
      33,    32,    30,    -1,    38,    37,    -1,    -1,    -1,    39,
      39,    30,    39,    39,    32,    39,    39,    39,    39,    34,
      32,    30,    35,    30,    30,    30,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    44,    29,     0,    33,    45,    47,    28,    48,
      49,    29,     4,    46,    50,    39,    29,    15,    59,    60,
      30,    33,    33,    34,    37,    51,    61,     5,    34,    52,
      16,    34,    62,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    29,    53,    29,    63,    38,    42,    33,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      29,    54,    32,    17,     1,    55,    30,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    29,    35,    37,    56,
      37,    39,    39,    39,    39,    39,    39,    39,    39,    30,
      58,    34,    30,    32,    30,    32,    30,    31,    32,    32,
      30,    35,    30,    36,    40,    30,    57,    30,    36,    40,
      30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    45,    46,    44,    47,    47,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      61,    61,    62,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     9,     0,     2,     5,     0,     2,
       5,     0,     2,     6,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     3,     1,     1,     3,     1,     3,     0,     1,     4,
       0,     2,     7,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 56 "parser.y"
                            {
    fprintf(output, "<form name=\"%s\">\n", (yyvsp[-1].str));
    }
#line 1237 "parser.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 59 "parser.y"
                           {
        fprintf(output, "<button type=\"submit\">Submit</button>\n</form>\n"); 
        free((yyvsp[-4].str));
    }
#line 1246 "parser.tab.c"
    break;

  case 4: /* form: FORM IDENTIFIER LBRACE $@1 meta_list section_list $@2 validate_block_opt RBRACE  */
#line 63 "parser.y"
                             {

    }
#line 1254 "parser.tab.c"
    break;

  case 7: /* meta_line: META IDENTIFIER EQUALS STRING SEMICOLON  */
#line 74 "parser.y"
    {
        // Output meta as HTML comment
        char *unquoted = strip_quotes((yyvsp[-1].str));
        fprintf(output, "<!-- Meta: %s = %s -->\n", (yyvsp[-3].str), unquoted);
        free((yyvsp[-3].str)); free(unquoted);
    }
#line 1265 "parser.tab.c"
    break;

  case 10: /* section: SECTION IDENTIFIER LBRACE field_list RBRACE  */
#line 87 "parser.y"
    { free((yyvsp[-3].str)); }
#line 1271 "parser.tab.c"
    break;

  case 13: /* field: FIELD field_name COLON field_type attribute_list SEMICOLON  */
#line 96 "parser.y"
    {
        if (strcmp((yyvsp[-2].str), "text") == 0) {
            fprintf(output, "<label>%s: <input type=\"text\" name=\"%s\"%s", (yyvsp[-4].str), (yyvsp[-4].str), is_required ? " required" : "");
            if (field_pattern) fprintf(output, " pattern=\"%s\"", field_pattern);
            fprintf(output, "></label><br>\n");
        } else if (strcmp((yyvsp[-2].str), "number") == 0) {
            fprintf(output, "<label>%s: <input type=\"number\" name=\"%s\"", (yyvsp[-4].str), (yyvsp[-4].str));
            if (is_required) fprintf(output, " required");
            if (has_min) fprintf(output, " min=\"%d\"", min_value);
            if (has_max) fprintf(output, " max=\"%d\"", max_value);
            fprintf(output, "></label><br>\n");
        } else if (strcmp((yyvsp[-2].str), "email") == 0) {
            fprintf(output, "<label>%s: <input type=\"email\" name=\"%s\"%s", (yyvsp[-4].str), (yyvsp[-4].str), is_required ? " required" : "");
            if (field_pattern) fprintf(output, " pattern=\"%s\"", field_pattern);
            fprintf(output, "></label><br>\n");
        } else if (strcmp((yyvsp[-2].str), "checkbox") == 0) {
            fprintf(output, "<label><input type=\"checkbox\" name=\"%s\"%s> %s</label><br>\n",
                    (yyvsp[-4].str), is_checked ? " checked" : "", (yyvsp[-4].str));
        } else if (strcmp((yyvsp[-2].str), "radio") == 0) {
            fprintf(output, "<label>%s:</label><br>\n", (yyvsp[-4].str));
            for (int i = 0; i < option_count; i++) {
                fprintf(output, "<input type=\"radio\" name=\"%s\" value=\"%s\"> %s<br>\n",
                        (yyvsp[-4].str), radio_options[i], radio_options[i]);
                free(radio_options[i]);
            }
            option_count = 0;
        } else if (strcmp((yyvsp[-2].str), "textarea") == 0) {
            fprintf(output, "<label>%s:<br><textarea name=\"%s\"", (yyvsp[-4].str), (yyvsp[-4].str));
            if (textarea_rows) fprintf(output, " rows=\"%d\"", textarea_rows);
            if (textarea_cols) fprintf(output, " cols=\"%d\"", textarea_cols);
            fprintf(output, ">");
            if (textarea_default) fprintf(output, "%s", textarea_default);
            fprintf(output, "</textarea></label><br>\n");
        } else if (strcmp((yyvsp[-2].str), "date") == 0) {
            fprintf(output, "<label>%s: <input type=\"date\" name=\"%s\"", (yyvsp[-4].str), (yyvsp[-4].str));
            if (is_required) fprintf(output, " required");
            if (date_min) fprintf(output, " min=\"%s\"", date_min);
            if (date_max) fprintf(output, " max=\"%s\"", date_max);
            fprintf(output, "></label><br>\n");
        } else if (strcmp((yyvsp[-2].str), "dropdown") == 0) {
            fprintf(output, "<label>%s: <select name=\"%s\"%s>\n", (yyvsp[-4].str), (yyvsp[-4].str), dropdown_required ? " required" : "");
            for (int i = 0; i < dropdown_option_count; i++) {
                if (dropdown_default && strcmp(dropdown_default, dropdown_options[i]) == 0)
                    fprintf(output, "<option value=\"%s\" selected>%s</option>\n", dropdown_options[i], dropdown_options[i]);
                else
                    fprintf(output, "<option value=\"%s\">%s</option>\n", dropdown_options[i], dropdown_options[i]);
                free(dropdown_options[i]);
            }
            fprintf(output, "</select></label><br>\n");
        } else if (strcmp((yyvsp[-2].str), "password") == 0) {
            fprintf(output, "<label>%s: <input type=\"password\" name=\"%s\"%s", (yyvsp[-4].str), (yyvsp[-4].str), is_required ? " required" : "");
            if (password_pattern) fprintf(output, " pattern=\"%s\"", password_pattern);
            fprintf(output, "></label><br>\n");
        } else if (strcmp((yyvsp[-2].str), "file") == 0) {
            fprintf(output, "<label>%s: <input type=\"file\" name=\"%s\"%s", (yyvsp[-4].str), (yyvsp[-4].str), is_required ? " required" : "");
            if (file_accept) fprintf(output, " accept=\"%s\"", file_accept);
            fprintf(output, "></label><br>\n");
        } else {
            fprintf(stderr, "Error: Unknown field type '%s' in field '%s'.\n", (yyvsp[-2].str), (yyvsp[-4].str));
        }
        // Reset all attribute variables after each field
        is_required = 0; has_min = 0; has_max = 0;
        min_value = 0; max_value = 0; is_checked = 0;
        has_options = 0;
        textarea_rows = 0; textarea_cols = 0;
        if (textarea_default) { free(textarea_default); textarea_default = NULL; }
        if (field_pattern) { free(field_pattern); field_pattern = NULL; }
        if (dropdown_default) { free(dropdown_default); dropdown_default = NULL; }
        dropdown_required = 0; dropdown_option_count = 0;
        if (date_min) { free(date_min); date_min = NULL; }
        if (date_max) { free(date_max); date_max = NULL; }
        if (password_pattern) { free(password_pattern); password_pattern = NULL; }
        if (file_accept) { free(file_accept); file_accept = NULL; }
        free((yyvsp[-4].str)); free((yyvsp[-2].str));
    }
#line 1351 "parser.tab.c"
    break;

  case 14: /* field: FIELD field_name COLON field_type error  */
#line 172 "parser.y"
    {
        yyerror("Invalid field declaration or missing semicolon");
        // Reset as above for error recovery
        is_required = 0; has_min = 0; has_max = 0;
        min_value = 0; max_value = 0; is_checked = 0;
        option_count = 0; textarea_rows = 0; textarea_cols = 0;
        if (textarea_default) { free(textarea_default); textarea_default = NULL; }
        if (field_pattern) { free(field_pattern); field_pattern = NULL; }
        if (dropdown_default) { free(dropdown_default); dropdown_default = NULL; }
        dropdown_required = 0; dropdown_option_count = 0;
        if (date_min) { free(date_min); date_min = NULL; }
        if (date_max) { free(date_max); date_max = NULL; }
        if (password_pattern) { free(password_pattern); password_pattern = NULL; }
        if (file_accept) { free(file_accept); file_accept = NULL; }
        free((yyvsp[-3].str)); free((yyvsp[-1].str));
    
    }
#line 1373 "parser.tab.c"
    break;

  case 15: /* field_name: IDENTIFIER  */
#line 192 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1379 "parser.tab.c"
    break;

  case 16: /* field_name: TEXT  */
#line 193 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1385 "parser.tab.c"
    break;

  case 17: /* field_name: TEXTAREA  */
#line 194 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1391 "parser.tab.c"
    break;

  case 18: /* field_name: NUMBER  */
#line 195 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1397 "parser.tab.c"
    break;

  case 19: /* field_name: EMAIL  */
#line 196 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1403 "parser.tab.c"
    break;

  case 20: /* field_name: CHECKBOX  */
#line 197 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1409 "parser.tab.c"
    break;

  case 21: /* field_name: RADIO  */
#line 198 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1415 "parser.tab.c"
    break;

  case 22: /* field_name: DATE  */
#line 199 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1421 "parser.tab.c"
    break;

  case 23: /* field_name: DROPDOWN  */
#line 200 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1427 "parser.tab.c"
    break;

  case 24: /* field_name: PASSWORD  */
#line 201 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1433 "parser.tab.c"
    break;

  case 25: /* field_name: FILETYPE  */
#line 202 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1439 "parser.tab.c"
    break;

  case 26: /* field_type: TEXT  */
#line 206 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1445 "parser.tab.c"
    break;

  case 27: /* field_type: TEXTAREA  */
#line 207 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1451 "parser.tab.c"
    break;

  case 28: /* field_type: NUMBER  */
#line 208 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1457 "parser.tab.c"
    break;

  case 29: /* field_type: EMAIL  */
#line 209 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1463 "parser.tab.c"
    break;

  case 30: /* field_type: CHECKBOX  */
#line 210 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1469 "parser.tab.c"
    break;

  case 31: /* field_type: RADIO  */
#line 211 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1475 "parser.tab.c"
    break;

  case 32: /* field_type: DATE  */
#line 212 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1481 "parser.tab.c"
    break;

  case 33: /* field_type: DROPDOWN  */
#line 213 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1487 "parser.tab.c"
    break;

  case 34: /* field_type: PASSWORD  */
#line 214 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1493 "parser.tab.c"
    break;

  case 35: /* field_type: FILETYPE  */
#line 215 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1499 "parser.tab.c"
    break;

  case 36: /* field_type: IDENTIFIER  */
#line 216 "parser.y"
                 { fprintf(stderr, "Error: Unknown field type '%s'.\n", (yyvsp[0].str)); (yyval.str) = (yyvsp[0].str);}
#line 1505 "parser.tab.c"
    break;

  case 37: /* attribute_list: %empty  */
#line 219 "parser.y"
                            { }
#line 1511 "parser.tab.c"
    break;

  case 39: /* attribute: REQUIRED  */
#line 224 "parser.y"
               { is_required = 1; dropdown_required = 1; }
#line 1517 "parser.tab.c"
    break;

  case 40: /* attribute: MIN EQUALS NUM  */
#line 225 "parser.y"
                     { has_min = 1; min_value = (yyvsp[0].num); }
#line 1523 "parser.tab.c"
    break;

  case 41: /* attribute: MAX EQUALS NUM  */
#line 226 "parser.y"
                     { has_max = 1; max_value = (yyvsp[0].num); }
#line 1529 "parser.tab.c"
    break;

  case 42: /* attribute: DEFAULT EQUALS BOOLEAN  */
#line 227 "parser.y"
                             { is_checked = (strcmp((yyvsp[0].str), "true") == 0 ? 1 : 0); free((yyvsp[0].str)); }
#line 1535 "parser.tab.c"
    break;

  case 43: /* attribute: LBRACKET string_list RBRACKET  */
#line 228 "parser.y"
                                    { has_options = 1; }
#line 1541 "parser.tab.c"
    break;

  case 44: /* attribute: ROWS EQUALS NUM  */
#line 229 "parser.y"
                      { textarea_rows = (yyvsp[0].num); }
#line 1547 "parser.tab.c"
    break;

  case 45: /* attribute: COLS EQUALS NUM  */
#line 230 "parser.y"
                      { textarea_cols = (yyvsp[0].num); }
#line 1553 "parser.tab.c"
    break;

  case 46: /* attribute: DEFAULT EQUALS STRING  */
#line 231 "parser.y"
                            {
            if (textarea_default) free(textarea_default);
            if (dropdown_default) free(dropdown_default);
            textarea_default = strip_quotes((yyvsp[0].str));
            dropdown_default = strdup(textarea_default);
      }
#line 1564 "parser.tab.c"
    break;

  case 47: /* attribute: PATTERN EQUALS STRING  */
#line 237 "parser.y"
                            {
            if (field_pattern) free(field_pattern);
            if (password_pattern) free(password_pattern);
            field_pattern = strip_quotes((yyvsp[0].str));
            password_pattern = strdup(field_pattern);
      }
#line 1575 "parser.tab.c"
    break;

  case 48: /* attribute: MIN EQUALS STRING  */
#line 243 "parser.y"
                        { date_min = strip_quotes((yyvsp[0].str)); }
#line 1581 "parser.tab.c"
    break;

  case 49: /* attribute: MAX EQUALS STRING  */
#line 244 "parser.y"
                        { date_max = strip_quotes((yyvsp[0].str)); }
#line 1587 "parser.tab.c"
    break;

  case 50: /* attribute: OPTIONS EQUALS LBRACKET dropdown_option_list RBRACKET  */
#line 245 "parser.y"
                                                            { }
#line 1593 "parser.tab.c"
    break;

  case 51: /* attribute: ACCEPT EQUALS STRING  */
#line 246 "parser.y"
                           { if (file_accept) free(file_accept); file_accept = strip_quotes((yyvsp[0].str)); }
#line 1599 "parser.tab.c"
    break;

  case 52: /* attribute: IDENTIFIER  */
#line 247 "parser.y"
                 { fprintf(stderr, "Warning: Unknown attribute '%s' ignored.\n", (yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1605 "parser.tab.c"
    break;

  case 53: /* dropdown_option_list: STRING  */
#line 252 "parser.y"
        { if (dropdown_option_count < MAX_OPTIONS) dropdown_options[dropdown_option_count++] = strip_quotes((yyvsp[0].str)); else free((yyvsp[0].str)); }
#line 1611 "parser.tab.c"
    break;

  case 54: /* dropdown_option_list: dropdown_option_list COMMA STRING  */
#line 254 "parser.y"
        { if (dropdown_option_count < MAX_OPTIONS) dropdown_options[dropdown_option_count++] = strip_quotes((yyvsp[0].str)); else free((yyvsp[0].str)); }
#line 1617 "parser.tab.c"
    break;

  case 55: /* string_list: STRING  */
#line 258 "parser.y"
    {
        if (option_count < MAX_OPTIONS) radio_options[option_count++] = strip_quotes((yyvsp[0].str));
        else free((yyvsp[0].str));
    }
#line 1626 "parser.tab.c"
    break;

  case 56: /* string_list: string_list COMMA STRING  */
#line 263 "parser.y"
    {
        if (option_count < MAX_OPTIONS) radio_options[option_count++] = strip_quotes((yyvsp[0].str));
        else free((yyvsp[0].str));
    }
#line 1635 "parser.tab.c"
    break;

  case 62: /* validate_statement: IF validate_condition LBRACE ERROR STRING SEMICOLON RBRACE  */
#line 285 "parser.y"
    {
        char *msg = strip_quotes((yyvsp[-2].str));
        // JS validation for age < N
        // Only works for `if age < N` format!
        int number = 0;
        char field[64] = "";
        // Parse $2 (which is like "age < 18")
        sscanf((yyvsp[-5].str), "%s < %d", field, &number);

        fprintf(output,
            "<script>\n"
            "document.addEventListener('DOMContentLoaded', function() {\n"
            "  var form = document.querySelector('form');\n"
            "  if(form) {\n"
            "    form.addEventListener('submit', function(e) {\n"
            "      var age = document.getElementsByName('%s')[0]?.value;\n"
            "      if (age !== undefined && age < %d) {\n"
            "        alert('%s');\n"
            "        e.preventDefault();\n"
            "      }\n"
            "    });\n"
            "  }\n"
            "});\n"
            "</script>\n",
            field, number, msg
        );

        free((yyvsp[-5].str)); free(msg);
    }
#line 1669 "parser.tab.c"
    break;

  case 63: /* validate_condition: IDENTIFIER '<' NUM  */
#line 319 "parser.y"
        {
            char buf[128];
            snprintf(buf, sizeof(buf), "%s < %d", (yyvsp[-2].str), (yyvsp[0].num));
            (yyval.str) = strdup(buf);
            free((yyvsp[-2].str));
        }
#line 1680 "parser.tab.c"
    break;


#line 1684 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 326 "parser.y"


void yyerror(const char *s) {
    extern int yylineno;
    fprintf(stderr, "Syntax error: %s at line %d\n", s, yylineno);
}

int main() {
    output = fopen("output.html", "w");
    if (!output) {
        fprintf(stderr, "Cannot open output.html\n");
        return 1;
    }
    yyparse();
    fclose(output);
    return 0;
}
