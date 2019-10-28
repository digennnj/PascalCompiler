/* A Bison parser, made by GNU Bison 3.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "SPparser.y"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include "symbol_table.h"

extern "C" int yylex();
extern "C" int yyparse();
extern FILE * yyin;

int line_no = 1;
std::ofstream outFile;

std::map<std::string,Variable> symbolTable;

extern char *convert_to_int(const char *val);
extern char *convert_to_real(const char *val);


void assign(char[], char[]);
void assign_char(char[], char[]);
void assign_int(char[], char[]);
void assign_real(char[], char[]);
void decl_id (char[], std::string);
void decl_int(char[]);
void decl_real(char[]);
void decl_char(char[]);
void finish();
char * gen_infix(char [], char [], char []);
void read_id (char []);
void write_expr(char []);
void error(const char []);
void yyerror(const char []);

#line 109 "SPparser.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PASCAL_TAB_H_INCLUDED
# define YY_YY_PASCAL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    VAR = 259,
    START = 260,
    END = 261,
    READ = 262,
    WRITE = 263,
    ASSIGNOP = 264,
    INTLITERAL = 265,
    REALLITERAL = 266,
    INTTYPE = 267,
    REALTYPE = 268,
    CHARTYPE = 269,
    CHARACTER = 270,
    LPAREN = 271,
    RPAREN = 272,
    COMMA = 273,
    SQUOTE = 274,
    PERIOD = 275,
    SEMICOLON = 276,
    COLON = 277,
    PLUSOP = 278,
    MINUSOP = 279,
    MULTIPLYOP = 280,
    DIVIDEOP = 281,
    ID = 282,
    SNGLLNCOMMENT = 283,
    MULTILNCOMMENTOPEN = 284,
    MULTILNCOMMENTCLOSE = 285,
    MODOP = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "SPparser.y"

       int ival;
       char * sval;
       

#line 190 "SPparser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PASCAL_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  112

#define YYUNDEFTOK  2
#define YYMAXUTOK   286

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    64,    64,    66,    66,    67,    68,    68,
      69,    70,    70,    71,    72,    72,    73,    75,    76,    78,
      79,    80,    81,    81,    83,    84,    86,    87,    88,    88,
      89,    89,    91,    92,    94,    95,    96,    96,    97,    97,
      99,   100,   106,   106,   107,   107,   108,   108,   109,   109,
     111,   113,   115,   117,   118,   120,   121,   123,   125,   126,
     127,   129,   131,   135,   136,   137,   139,   141,   142,   144,
     145,   147,   149,   151,   153,   155,   157,   158,   160
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "VAR", "START", "END", "READ",
  "WRITE", "ASSIGNOP", "INTLITERAL", "REALLITERAL", "INTTYPE", "REALTYPE",
  "CHARTYPE", "CHARACTER", "LPAREN", "RPAREN", "COMMA", "SQUOTE", "PERIOD",
  "SEMICOLON", "COLON", "PLUSOP", "MINUSOP", "MULTIPLYOP", "DIVIDEOP",
  "ID", "SNGLLNCOMMENT", "MULTILNCOMMENTOPEN", "MULTILNCOMMENTCLOSE",
  "MODOP", "$accept", "program", "$@1", "$@2", "variables", "$@3", "$@4",
  "$@5", "$@6", "c_list", "c_decl", "$@7", "i_list", "i_decl", "$@8",
  "$@9", "r_list", "r_decl", "$@10", "$@11", "statement_list", "statement",
  "$@12", "$@13", "$@14", "$@15", "id_list", "expr_list", "expression",
  "expr", "term", "lparen", "rparen", "add_op", "ident", "system_goal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF -74

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define YYTABLE_NINF -69

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -74,   -74,    21,    43,   -74,    71,    24,    24,    24,
      52,    58,   -74,   -15,   -74,    50,    -3,   -74,    73,     7,
     -74,    77,    71,   -74,    24,    83,    25,    24,    93,    33,
      24,    99,    51,   -74,     5,   -74,    71,   -74,    13,    35,
     -74,   -74,    70,   -74,    64,   -74,   -74,    71,    69,   -74,
      79,   -74,   -74,    71,    81,    85,   -74,   -74,    89,    89,
     -74,     3,   -74,    98,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,    64,    12,   -74,   -74,   -74,   -74,   -74,    24,
      64,    88,   -74,    54,   -74,   -74,   -74,    20,   -74,    28,
     -74,   -74,    90,    91,    92,   -74,    24,    94,    64,    95,
      96,    97,   100,   101,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,    78,     0,     0,     1,     0,    77,    77,    77,
       5,     0,    76,     0,    24,    26,     0,    32,    34,     0,
      17,    19,     0,     3,    77,     8,    60,    77,    11,    60,
      77,    14,    60,     6,    77,    25,     0,    63,    64,    66,
      67,    30,    57,    58,    60,    62,    33,     0,    63,    64,
      66,    38,    18,     0,    63,    64,    66,    22,    68,    68,
      52,    77,    40,     0,     9,    29,    31,    71,    72,    73,
      74,    75,    65,    70,    12,    37,    39,    15,    23,    77,
      60,     0,    41,    60,    59,    69,    61,    70,    53,    70,
      55,     4,    63,    64,    66,    42,    77,     0,    60,     0,
       0,     0,     0,     0,    54,    50,    56,    51,    45,    47,
      49,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -74,   -74,   -74,   -74,   -14,   -74,   -74,   -74,   -74,   -74,
      80,   -74,   -74,   102,   -74,   -74,   -74,    82,   -74,   -74,
     -74,    53,   -74,   -74,   -74,   -74,   -74,   -74,   -25,   -74,
      47,    18,   -73,   -74,    -7,   -74
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     4,    34,    11,    22,    36,    47,    53,    19,
      20,    78,    13,    14,    65,    66,    16,    17,    75,    76,
      61,    62,   103,   100,   101,   102,    87,    89,    41,    42,
      43,    44,    86,    72,    45,     3
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      15,    18,    21,    24,    51,     1,    25,    57,    33,    81,
      58,    59,    58,    59,    97,    27,    99,    15,    28,    73,
      18,     5,    64,    21,    60,    30,    60,    63,    31,    85,
      12,   -28,    12,    74,   -28,    37,    38,    85,    96,    77,
      39,    40,   -68,    48,    49,    85,    98,     6,    50,    40,
     -68,    12,    12,   -27,    63,    90,   -27,    -7,    95,    26,
      12,    54,    55,    23,    92,    93,    56,    40,   -68,    94,
      40,   -68,    88,   106,    37,    49,    79,    80,    12,    56,
      40,    12,    29,     7,     8,     9,    32,   -36,   -10,   104,
     -36,    12,    10,    67,    68,    69,    70,   -35,   -13,   -21,
     -35,    71,   -21,   -20,   -16,    40,   -20,    83,    91,    46,
      52,   -44,   -46,   -48,    82,   105,   107,   108,   109,    84,
       0,   110,   111,     0,     0,     0,    35
};

static const yytype_int8 yycheck[] =
{
       7,     8,     9,    18,    29,     3,    21,    32,    22,     6,
       7,     8,     7,     8,    87,    18,    89,    24,    21,    44,
      27,     0,    36,    30,    21,    18,    21,    34,    21,    17,
      27,    18,    27,    47,    21,    10,    11,    17,    18,    53,
      15,    16,    17,    10,    11,    17,    18,     4,    15,    16,
      17,    27,    27,    18,    61,    80,    21,     5,    83,     9,
      27,    10,    11,     5,    10,    11,    15,    16,    17,    15,
      16,    17,    79,    98,    10,    11,    58,    59,    27,    15,
      16,    27,     9,    12,    13,    14,     9,    18,     5,    96,
      21,    27,    21,    23,    24,    25,    26,    18,     5,    18,
      21,    31,    21,    18,     5,    16,    21,     9,    20,    27,
      30,    21,    21,    21,    61,    21,    21,    21,    21,    72,
      -1,    21,    21,    -1,    -1,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    33,    67,    34,     0,     4,    12,    13,    14,
      21,    36,    27,    44,    45,    66,    48,    49,    66,    41,
      42,    66,    37,     5,    18,    21,     9,    18,    21,     9,
      18,    21,     9,    36,    35,    45,    38,    10,    11,    15,
      16,    60,    61,    62,    63,    66,    49,    39,    10,    11,
      15,    60,    42,    40,    10,    11,    15,    60,     7,     8,
      21,    52,    53,    66,    36,    46,    47,    23,    24,    25,
      26,    31,    65,    60,    36,    50,    51,    36,    43,    63,
      63,     6,    53,     9,    62,    17,    64,    58,    66,    59,
      60,    20,    10,    11,    15,    60,    18,    64,    18,    64,
      55,    56,    57,    54,    66,    21,    60,    21,    21,    21,
      21,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    34,    35,    33,    37,    36,    36,    38,    36,
      36,    39,    36,    36,    40,    36,    36,    41,    41,    42,
      42,    42,    43,    42,    44,    44,    45,    45,    46,    45,
      47,    45,    48,    48,    49,    49,    50,    49,    51,    49,
      52,    52,    54,    53,    55,    53,    56,    53,    57,    53,
      53,    53,    53,    58,    58,    59,    59,    60,    61,    61,
      61,    62,    62,    62,    62,    62,    62,    63,    63,    64,
      64,    65,    65,    65,    65,    65,    66,    66,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     9,     0,     3,     1,     0,     5,
       3,     0,     5,     3,     0,     5,     3,     1,     3,     1,
       3,     3,     0,     4,     1,     3,     1,     3,     0,     4,
       0,     4,     1,     3,     1,     3,     0,     4,     0,     4,
       1,     2,     0,     5,     0,     5,     0,     5,     0,     5,
       5,     5,     1,     1,     3,     1,     3,     1,     1,     3,
       0,     3,     1,     1,     1,     0,     1,     1,     0,     1,
       0,     1,     1,     1,     1,     1,     1,     0,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
  case 2:
#line 64 "SPparser.y"
    {line_no++;}
#line 1369 "SPparser.tab.c"
    break;

  case 3:
#line 64 "SPparser.y"
    {line_no++;}
#line 1375 "SPparser.tab.c"
    break;

  case 4:
#line 64 "SPparser.y"
    {line_no++;}
#line 1381 "SPparser.tab.c"
    break;

  case 5:
#line 66 "SPparser.y"
    {line_no++;}
#line 1387 "SPparser.tab.c"
    break;

  case 7:
#line 67 "SPparser.y"
    {line_no++;}
#line 1393 "SPparser.tab.c"
    break;

  case 8:
#line 68 "SPparser.y"
    {line_no++;}
#line 1399 "SPparser.tab.c"
    break;

  case 10:
#line 69 "SPparser.y"
    {line_no++;}
#line 1405 "SPparser.tab.c"
    break;

  case 11:
#line 70 "SPparser.y"
    {line_no++;}
#line 1411 "SPparser.tab.c"
    break;

  case 13:
#line 71 "SPparser.y"
    {line_no++;}
#line 1417 "SPparser.tab.c"
    break;

  case 14:
#line 72 "SPparser.y"
    {line_no++;}
#line 1423 "SPparser.tab.c"
    break;

  case 16:
#line 73 "SPparser.y"
    {line_no++;}
#line 1429 "SPparser.tab.c"
    break;

  case 19:
#line 78 "SPparser.y"
    { decl_id((yyvsp[0].sval), "CHARACTER"); }
#line 1435 "SPparser.tab.c"
    break;

  case 20:
#line 79 "SPparser.y"
    { error("Cannot convert real to character"); }
#line 1441 "SPparser.tab.c"
    break;

  case 21:
#line 80 "SPparser.y"
    { error("Cannot convert integer to character"); }
#line 1447 "SPparser.tab.c"
    break;

  case 22:
#line 81 "SPparser.y"
    { decl_id((yyvsp[-2].sval), "CHARACTER"); }
#line 1453 "SPparser.tab.c"
    break;

  case 23:
#line 81 "SPparser.y"
    {assign_char((yyvsp[-3].sval),(yyvsp[-1].sval)); }
#line 1459 "SPparser.tab.c"
    break;

  case 26:
#line 86 "SPparser.y"
    { decl_id((yyvsp[0].sval), "INTEGER"); }
#line 1465 "SPparser.tab.c"
    break;

  case 27:
#line 87 "SPparser.y"
    { error("Cannot convert character to integer"); }
#line 1471 "SPparser.tab.c"
    break;

  case 28:
#line 88 "SPparser.y"
    { decl_id((yyvsp[-2].sval), "INTEGER"); }
#line 1477 "SPparser.tab.c"
    break;

  case 29:
#line 88 "SPparser.y"
    {assign_int((yyvsp[-3].sval),(yyvsp[-1].sval)); }
#line 1483 "SPparser.tab.c"
    break;

  case 30:
#line 89 "SPparser.y"
    { decl_id((yyvsp[-2].sval), "INTEGER"); }
#line 1489 "SPparser.tab.c"
    break;

  case 31:
#line 89 "SPparser.y"
    {assign_int((yyvsp[-3].sval),(yyvsp[-1].sval)); }
#line 1495 "SPparser.tab.c"
    break;

  case 34:
#line 94 "SPparser.y"
    { decl_id((yyvsp[0].sval), "REAL"); }
#line 1501 "SPparser.tab.c"
    break;

  case 35:
#line 95 "SPparser.y"
    { error("Cannot convert character to real"); }
#line 1507 "SPparser.tab.c"
    break;

  case 36:
#line 96 "SPparser.y"
    { decl_id((yyvsp[-2].sval), "REAL"); }
#line 1513 "SPparser.tab.c"
    break;

  case 37:
#line 96 "SPparser.y"
    {assign_real((yyvsp[-3].sval),(yyvsp[-1].sval)); }
#line 1519 "SPparser.tab.c"
    break;

  case 38:
#line 97 "SPparser.y"
    { decl_id((yyvsp[-2].sval), "REAL"); }
#line 1525 "SPparser.tab.c"
    break;

  case 39:
#line 97 "SPparser.y"
    {assign_real((yyvsp[-3].sval),(yyvsp[-1].sval)); }
#line 1531 "SPparser.tab.c"
    break;

  case 42:
#line 106 "SPparser.y"
    {assign((yyvsp[-2].sval),(yyvsp[0].sval));}
#line 1537 "SPparser.tab.c"
    break;

  case 43:
#line 106 "SPparser.y"
    {line_no++;}
#line 1543 "SPparser.tab.c"
    break;

  case 44:
#line 107 "SPparser.y"
    {assign_int((yyvsp[-2].sval),(yyvsp[0].sval));}
#line 1549 "SPparser.tab.c"
    break;

  case 45:
#line 107 "SPparser.y"
    {line_no++;}
#line 1555 "SPparser.tab.c"
    break;

  case 46:
#line 108 "SPparser.y"
    {assign_real((yyvsp[-2].sval),(yyvsp[0].sval));}
#line 1561 "SPparser.tab.c"
    break;

  case 47:
#line 108 "SPparser.y"
    {line_no++;}
#line 1567 "SPparser.tab.c"
    break;

  case 48:
#line 109 "SPparser.y"
    {assign_char((yyvsp[-2].sval),(yyvsp[0].sval));}
#line 1573 "SPparser.tab.c"
    break;

  case 49:
#line 109 "SPparser.y"
    {line_no++;}
#line 1579 "SPparser.tab.c"
    break;

  case 50:
#line 111 "SPparser.y"
    {line_no++;}
#line 1585 "SPparser.tab.c"
    break;

  case 51:
#line 113 "SPparser.y"
    {line_no++;}
#line 1591 "SPparser.tab.c"
    break;

  case 52:
#line 115 "SPparser.y"
    {line_no++;}
#line 1597 "SPparser.tab.c"
    break;

  case 53:
#line 117 "SPparser.y"
    {read_id((yyvsp[0].sval));}
#line 1603 "SPparser.tab.c"
    break;

  case 54:
#line 118 "SPparser.y"
    {read_id((yyvsp[0].sval));}
#line 1609 "SPparser.tab.c"
    break;

  case 55:
#line 120 "SPparser.y"
    {write_expr((yyvsp[0].sval));}
#line 1615 "SPparser.tab.c"
    break;

  case 56:
#line 121 "SPparser.y"
    {write_expr((yyvsp[0].sval));}
#line 1621 "SPparser.tab.c"
    break;

  case 57:
#line 123 "SPparser.y"
    {(yyval.sval)=strdup((yyvsp[0].sval));}
#line 1627 "SPparser.tab.c"
    break;

  case 58:
#line 125 "SPparser.y"
    {(yyval.sval)=strdup((yyvsp[0].sval));}
#line 1633 "SPparser.tab.c"
    break;

  case 59:
#line 126 "SPparser.y"
    {(yyval.sval)=strdup(gen_infix((yyvsp[-2].sval),(yyvsp[-1].sval),(yyvsp[0].sval)));}
#line 1639 "SPparser.tab.c"
    break;

  case 60:
#line 127 "SPparser.y"
    {error("EXPRESSION EXPECTED, BUT FOUND");}
#line 1645 "SPparser.tab.c"
    break;

  case 61:
#line 129 "SPparser.y"
    {(yyval.sval)=strdup((yyvsp[-1].sval));}
#line 1651 "SPparser.tab.c"
    break;

  case 62:
#line 131 "SPparser.y"
    {if (symbolTable.find((yyvsp[0].sval))==symbolTable.end()) {
                            error("SYMBOL NOT DEFINED");}
                        else {(yyval.sval)=strdup((yyvsp[0].sval));}}
#line 1659 "SPparser.tab.c"
    break;

  case 63:
#line 135 "SPparser.y"
    {(yyval.sval) = strdup(yylval.sval);}
#line 1665 "SPparser.tab.c"
    break;

  case 64:
#line 136 "SPparser.y"
    {(yyval.sval) = strdup(yylval.sval);}
#line 1671 "SPparser.tab.c"
    break;

  case 65:
#line 137 "SPparser.y"
    {error("NUMERIC VALUE EXPECTED, BUT FOUND");}
#line 1677 "SPparser.tab.c"
    break;

  case 66:
#line 139 "SPparser.y"
    {(yyval.sval)=strdup((yyvsp[0].sval));}
#line 1683 "SPparser.tab.c"
    break;

  case 68:
#line 142 "SPparser.y"
    {error("( EXPECTED , BUT FOUND");}
#line 1689 "SPparser.tab.c"
    break;

  case 70:
#line 145 "SPparser.y"
    {error(") EXPECTED , BUT FOUND");}
#line 1695 "SPparser.tab.c"
    break;

  case 71:
#line 147 "SPparser.y"
    {(yyval.sval)=strdup("Add");}
#line 1701 "SPparser.tab.c"
    break;

  case 72:
#line 149 "SPparser.y"
    {(yyval.sval)=strdup("Sub");}
#line 1707 "SPparser.tab.c"
    break;

  case 73:
#line 151 "SPparser.y"
    {(yyval.sval)=strdup("Mul");}
#line 1713 "SPparser.tab.c"
    break;

  case 74:
#line 153 "SPparser.y"
    {(yyval.sval)=strdup("Div");}
#line 1719 "SPparser.tab.c"
    break;

  case 75:
#line 155 "SPparser.y"
    {(yyval.sval)=strdup("Mod");}
#line 1725 "SPparser.tab.c"
    break;

  case 76:
#line 157 "SPparser.y"
    {(yyval.sval)=strdup(yylval.sval);}
#line 1731 "SPparser.tab.c"
    break;

  case 77:
#line 158 "SPparser.y"
    {error("IDENTIFIER EXPECTED, BUT FOUND");}
#line 1737 "SPparser.tab.c"
    break;

  case 78:
#line 160 "SPparser.y"
    { finish(); }
#line 1743 "SPparser.tab.c"
    break;


#line 1747 "SPparser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 162 "SPparser.y"

int main( int argc, char **argv )
{
	char * loc;
	if( argc != 2 )
		std::cout << "Usage: pascal inputfile\n";
	else
	{
		std::string srcFilePath = argv[1]; // assume you are not mucking with pointers
		yyin = fopen( *++argv, "r" );
		if( yyin == NULL )
		{
			std::cout << "spascal: Couldn't open " << *argv << std::endl;
			exit( 1 );
		}
		
		std::string fileName = srcFilePath.substr(0, srcFilePath.rfind('.'));
		std::string asmFileName = fileName + ".asm";

		outFile.open(asmFileName);
		yyparse();
		fclose( yyin );
		outFile.close();
	}
}

void error( const char msg[] )
{
	std::cout << "LINE " << line_no << " : " << msg << std::endl;
	exit( -1 );
}

void yyerror(const char s[]) {
  std::cout << "EEK, parse error!  Message: " << s << " on line: " << line_no << std::endl;
  // might as well halt now:
  exit(-1);
} 
