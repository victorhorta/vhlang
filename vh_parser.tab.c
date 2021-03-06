/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "vh_parser.y"

#include <stdio.h>
#include <stdlib.h>

#include "vh_tipos.h"



extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *output;
extern int line_num;

int MODO_DEBUG = 1;

int yyerror(const char *msg) {
    printf("BARRO::: linha: %d -- mensagem: %s\n", line_num, msg);
    return 0;
}

int yyerror_type(v_type t1, v_type t2) {
    printf("BARRO::: linha: %d -- mensagem: ", line_num);
    printf("Type error ao atribuir tipo %s a variavel tipo %s!\n", get_type_name(t2), get_type_name(t1));
    return 0;
}

extern void init_globais();

/* Line 371 of yacc.c  */
#line 98 "vh_parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DUP = 258,
     POP = 259,
     NEG = 260,
     IF = 261,
     ELSE = 262,
     ENDIF = 263,
     WHILE = 264,
     RETURN = 265,
     EQUALS = 266,
     AND = 267,
     OR = 268,
     LESS_THAN = 269,
     GREATER_THAN = 270,
     LESS_OR_EQUAL = 271,
     GREATER_OR_EQUAL = 272,
     NOT_EQUAL = 273,
     EQUAL_EQUAL = 274,
     PLUS = 275,
     MINUS = 276,
     TIMES = 277,
     DIVIDE = 278,
     NOT = 279,
     PLUS_PLUS = 280,
     MINUS_MINUS = 281,
     INTEGER = 282,
     STRING = 283,
     FLOAT = 284,
     BOOLEAN = 285,
     CHAR = 286,
     VAR = 287,
     COLON = 288,
     SEMI_COLON = 289,
     COMMA = 290,
     LEFT_BRACES = 291,
     RIGHT_BRACES = 292,
     LEFT_PARENTHESIS = 293,
     RIGHT_PARENTHESIS = 294,
     ID = 295,
     STRINGVAL = 296,
     TRUE = 297,
     FALSE = 298,
     CHARACTER = 299,
     NUMERALFLOAT = 300,
     NUMERALINT = 301
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 33 "vh_parser.y"

    int numeralint;
    float numeralfloat;
    int boolean;
    char character;
    char id[MAX_VAR_LENGTH];
    char* string;
    t_nonterm nonterm;
    v_type vtype;


/* Line 387 of yacc.c  */
#line 196 "vh_parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 224 "vh_parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNRULES -- Number of states.  */
#define YYNSTATES  100

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    12,    14,    16,    22,
      26,    28,    30,    32,    34,    36,    39,    41,    45,    47,
      55,    66,    71,    79,    81,    84,    88,    89,    90,    91,
      95,    99,   103,   107,   111,   115,   119,   123,   127,   131,
     135,   139,   141,   144,   147,   150,   153,   156,   159,   161,
     163,   165,   167,   169,   171,   173,   175,   177
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    50,    -1,    -1,    50,    51,    -1,
      51,    -1,    52,    -1,    53,    -1,    32,    56,    33,    54,
      34,    -1,    36,    55,    37,    -1,    27,    -1,    29,    -1,
      31,    -1,    30,    -1,    28,    -1,    55,    57,    -1,    57,
      -1,    56,    35,    64,    -1,    64,    -1,     6,    38,    61,
      39,    58,    57,     8,    -1,     6,    38,    61,    39,    58,
      57,     7,    59,    57,     8,    -1,    65,    11,    61,    34,
      -1,     9,    60,    38,    61,    39,    58,    57,    -1,    53,
      -1,    61,    34,    -1,    10,    61,    34,    -1,    -1,    -1,
      -1,    61,    12,    62,    -1,    61,    13,    62,    -1,    61,
      14,    62,    -1,    61,    15,    62,    -1,    61,    16,    62,
      -1,    61,    17,    62,    -1,    61,    19,    62,    -1,    61,
      18,    62,    -1,    61,    20,    62,    -1,    61,    21,    62,
      -1,    61,    22,    62,    -1,    61,    23,    62,    -1,    62,
      -1,    25,    62,    -1,    26,    62,    -1,    62,    25,    -1,
      62,    26,    -1,    21,    62,    -1,    24,    62,    -1,    42,
      -1,    43,    -1,    44,    -1,    41,    -1,    63,    -1,    65,
      -1,    45,    -1,    46,    -1,    40,    -1,    40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   105,   108,   109,   112,   113,   116,   177,
     181,   182,   183,   184,   185,   190,   191,   195,   241,   259,
     266,   273,   285,   293,   294,   295,   300,   305,   311,   317,
     330,   343,   356,   369,   382,   395,   408,   421,   434,   447,
     460,   473,   480,   498,   516,   534,   552,   568,   585,   592,
     599,   609,   618,   631,   639,   643,   649,   659
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DUP", "POP", "NEG", "IF", "ELSE",
  "ENDIF", "WHILE", "RETURN", "EQUALS", "AND", "OR", "LESS_THAN",
  "GREATER_THAN", "LESS_OR_EQUAL", "GREATER_OR_EQUAL", "NOT_EQUAL",
  "EQUAL_EQUAL", "PLUS", "MINUS", "TIMES", "DIVIDE", "NOT", "PLUS_PLUS",
  "MINUS_MINUS", "INTEGER", "STRING", "FLOAT", "BOOLEAN", "CHAR", "VAR",
  "COLON", "SEMI_COLON", "COMMA", "LEFT_BRACES", "RIGHT_BRACES",
  "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "ID", "STRINGVAL", "TRUE",
  "FALSE", "CHARACTER", "NUMERALFLOAT", "NUMERALINT", "$accept", "P", "BF",
  "LDE", "DE", "DV", "B", "T", "LS", "LI", "S", "MTHEN", "MELSE", "MWHILE",
  "E", "R", "NUM", "IDD", "IDU", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    50,    51,    51,    52,    53,
      54,    54,    54,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    58,    59,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    64,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     5,     3,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     7,
      10,     4,     7,     1,     2,     3,     0,     0,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     2,     5,     6,     7,
      56,     0,    18,     0,    28,     0,     0,     0,     0,     0,
      57,    51,    48,    49,    50,    54,    55,    23,     0,    16,
       0,    41,    52,    53,     4,     0,     0,     0,     0,     0,
      53,    46,    47,    42,    43,     9,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      44,    45,     0,    10,    14,    11,    13,    12,     0,    17,
       0,     0,    25,    29,    30,    31,    32,    33,    34,    36,
      35,    37,    38,    39,    40,     0,     8,    26,     0,    21,
       0,    26,     0,     0,    27,    19,    22,     0,     0,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,    27,    68,    28,    11,
      29,    90,    97,    38,    30,    31,    32,    12,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -28
static const yytype_int16 yypact[] =
{
     -28,     3,    15,   -28,   -18,    87,    15,   -28,   -28,   -28,
     -28,    -1,   -28,    -7,   -28,    31,    31,    31,    31,    31,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,    58,   -28,
      -4,    34,   -28,    22,   -28,    -2,   -18,    31,    10,   162,
     -28,    34,    34,    27,   -28,   -28,   -28,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,   -28,
     -28,   -28,    31,   -28,   -28,   -28,   -28,   -28,    28,   -28,
     122,    31,   -28,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,   185,   -28,   -28,   134,   -28,
      87,   -28,    13,    87,   -28,   -28,   -28,    87,    53,   -28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,   -28,   -28,    59,   -28,    48,   -28,   -28,   -28,
     -27,   -22,   -28,   -28,   -13,   -12,   -28,    42,    -5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      33,    46,    39,     3,    41,    42,    43,    44,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      94,    95,    10,    33,    70,    63,    64,    65,    66,    67,
      59,    37,    35,    62,    36,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     4,    71,    85,
       9,     5,    16,    61,     9,    17,    18,    19,    88,    60,
      61,    99,    86,    92,    13,    34,    96,    14,    15,    93,
      98,    20,    21,    22,    23,    24,    25,    26,    69,    16,
       0,     0,    17,    18,    19,    33,     0,     0,    33,     0,
       0,     0,    33,    13,     5,    45,    14,    15,    20,    21,
      22,    23,    24,    25,    26,     0,     0,     0,    16,     0,
       0,    17,    18,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     0,     0,
       0,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-28)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       5,    28,    15,     0,    16,    17,    18,    19,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       7,     8,    40,    28,    37,    27,    28,    29,    30,    31,
      34,    38,    33,    11,    35,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    32,    38,    62,
       2,    36,    21,    26,     6,    24,    25,    26,    71,    25,
      26,     8,    34,    90,     6,     6,    93,     9,    10,    91,
      97,    40,    41,    42,    43,    44,    45,    46,    36,    21,
      -1,    -1,    24,    25,    26,    90,    -1,    -1,    93,    -1,
      -1,    -1,    97,     6,    36,    37,     9,    10,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    21,    -1,
      -1,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,     0,    32,    36,    50,    51,    52,    53,
      40,    56,    64,     6,     9,    10,    21,    24,    25,    26,
      40,    41,    42,    43,    44,    45,    46,    53,    55,    57,
      61,    62,    63,    65,    51,    33,    35,    38,    60,    61,
      65,    62,    62,    62,    62,    37,    57,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    34,
      25,    26,    11,    27,    28,    29,    30,    31,    54,    64,
      61,    38,    34,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    61,    34,    39,    61,    34,
      58,    39,    57,    58,     7,     8,    57,    59,    57,     8
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
	    /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
      yychar = YYLEX;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
/* Line 1787 of yacc.c  */
#line 102 "vh_parser.y"
    {generate_END();}
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 105 "vh_parser.y"
    {generate_BEGIN();}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 116 "vh_parser.y"
    {



  //////////////////////////////////////////////////////////////////
                                    // Primeiro, vamos recuperar o tipo que foi definido
                                    v_type defined_type = (yyvsp[(4) - (5)].nonterm)._.T.type;
                                    var_object temp_object;

                                    int x;
                                    for(x = 0; (yyvsp[(2) - (5)].nonterm)._.LI.positions[x] != -1; x++) {
                                      /*
                                      temp_object = get_var_object($2._.LI.positions[x]);

                                      temp_object.my_type = defined_type;
                                      set_default_values(&  temp_object);
                                      debug_var(temp_object);
                                      */

                                      set_var_type((yyvsp[(2) - (5)].nonterm)._.LI.positions[x], defined_type);

                                      debug_var(get_var_object((yyvsp[(2) - (5)].nonterm)._.LI.positions[x]));
                                    }

                                    /**var_object* temp = (var_object*)malloc(sizeof(var_object));
                                    temp = $2._.LI.ids_list;

                                    do {
                                      temp->my_type = defined_type;
                                      set_default_values(temp);
                                      temp->index = var_scan_or_append(*temp);
                                      debug_var(*temp);

                                      temp = temp->next;
                                    } while(temp != NULL);
                                    **/

                                    /*
                                    // Vamos agora iterar sobre todas as variaveis declaradas em LI
                                    var_object* temp_id = $2._.LI.ids_list;
                                    temp_id->next = $2._.LI.ids_list->next;

                                    while(temp_id != NULL) {
                                      // Setando o tipo e valores default
                                      temp_id->my_type = defined_type;
                                      set_default_values(temp_id);

                                      // Inserindo as variaveis em nosso array de variaveis e retornando o indice de cada uma delas
                                      temp_id->index = var_scan_or_append(*temp_id);
                                      debug_var(*temp_id);

                                      temp_id = temp_id->next;
                                    }
                                  
                                    // Guardando referencia para o inicio da lista
                                    $$._.DV.ids_list = (var_object*)malloc(sizeof(var_object));
                                    $$._.DV.ids_list = $2._.LI.ids_list;
                                    */
                                  }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 181 "vh_parser.y"
    { (yyval.nonterm)._.T.type = (yyvsp[(1) - (1)].vtype); printf("meu tipo: %d\n", (yyval.nonterm)._.T.type);}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 182 "vh_parser.y"
    { (yyval.nonterm)._.T.type = (yyvsp[(1) - (1)].vtype); printf("meu tipo: %d\n", (yyval.nonterm)._.T.type);}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 183 "vh_parser.y"
    { (yyval.nonterm)._.T.type = (yyvsp[(1) - (1)].vtype); printf("meu tipo: %d\n", (yyval.nonterm)._.T.type);}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 184 "vh_parser.y"
    { (yyval.nonterm)._.T.type = (yyvsp[(1) - (1)].vtype); printf("meu tipo: %d\n", (yyval.nonterm)._.T.type);}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 185 "vh_parser.y"
    { (yyval.nonterm)._.T.type = (yyvsp[(1) - (1)].vtype); printf("meu tipo: %d\n", (yyval.nonterm)._.T.type);}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 195 "vh_parser.y"
    {
                      int x;
                      printf("antes:\n");
                      for(x = 0; x < MAX_VARS; x++) {
                        (yyval.nonterm)._.LI.positions[x] = (yyvsp[(1) - (3)].nonterm)._.LI.positions[x];
                        printf("%d",(yyval.nonterm)._.LI.positions[x]);
                      }
                      printf("\n");

                      for(x = 0; (yyval.nonterm)._.LI.positions[x] != -1; x++);
                      printf("primeira posicao com -1: %d\n", x);
                      printf("valor do novo index: %d\n", (yyvsp[(3) - (3)].nonterm)._.IDD.my_ID.index);
                      (yyval.nonterm)._.LI.positions[x] = (yyvsp[(3) - (3)].nonterm)._.IDD.my_ID.index;

                      printf("depois:\n");
                      for(x = 0; x < MAX_VARS; x++) {
                        printf("%d",(yyval.nonterm)._.LI.positions[x]);
                      }
                      printf("\n\n");


                       /**$$._.LI.ids_list = (var_object*)malloc(sizeof(var_object));
                       copy_var_object($$._.LI.ids_list, *$1._.LI.ids_list);

                       var_object* temp = (var_object*)malloc(sizeof(var_object));
                       do{
                         temp = $$._.LI.ids_list->next;
                       } while(temp != NULL);

                       copy_var_object(temp, $3._.IDD.my_ID);
                       **/
                       /*
                       $3._.IDD.my_ID.next = (var_object*)malloc(sizeof(var_object));
                       copy_var_object($3._.IDD.my_ID.next, *$1._.LI.ids_list);
                       //$3._.IDD.my_ID.next = $1._.LI.ids_list;

                       //$1._.LI.ids_list = &$3._.IDD.my_ID;

                       $$._.LI.ids_list = (var_object*)malloc(sizeof(var_object));
                       copy_var_object($$._.LI.ids_list, $3._.IDD.my_ID);
                       //$$._.LI.ids_list = &$3._.IDD.my_ID;
                       */
                       //if(MODO_DEBUG)
                       //  printf("my_label: %s\n", $3._.IDD.my_ID.my_label);
                     }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 241 "vh_parser.y"
    {
                      int x;
                      for(x = 0; x < MAX_VARS; x++) {
                        (yyval.nonterm)._.LI.positions[x] = -1;
                      }
                      
                      (yyval.nonterm)._.LI.positions[0] = (yyvsp[(1) - (1)].nonterm)._.IDD.my_ID.index;
                      /*
                       $$._.LI.ids_list = (var_object*)malloc(sizeof(var_object));
                       $$._.LI.ids_list = &$1._.IDD.my_ID;
                       $$._.LI.ids_list->next = NULL;
                       
                       if(MODO_DEBUG)
                         printf("my_label: %s\n", $$._.LI.ids_list->my_label);
                      */
                     }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 259 "vh_parser.y"
    {
                                                                if(check_types((yyvsp[(3) - (7)].nonterm)._.E.my_type, IF, 0) == -1) {
                                                                  yyerror("Condicao do IF nao eh um boolean");
                                                                } else {
                                                                  generate_STRING_LF(label_creator((yyvsp[(5) - (7)].nonterm)._.MTHEN.label_index));
                                                                }
                                                              }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 266 "vh_parser.y"
    {
                                                                             if(check_types((yyvsp[(3) - (10)].nonterm)._.E.my_type, IF, 0) == -1) {
                                                                               yyerror("Condicao do IF nao eh um boolean");
                                                                             } else {
                                                                               generate_STRING_LF(label_creator((yyvsp[(8) - (10)].nonterm)._.MELSE.label_index));
                                                                             }
                                                                           }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 273 "vh_parser.y"
    {
                                          int result_type = check_types(get_var_object((yyvsp[(1) - (4)].nonterm)._.IDU.index).my_type, EQUALS, (yyvsp[(3) - (4)].nonterm)._.E.my_type);
                                          if(result_type == -1) {
                                            yyerror_type((yyvsp[(3) - (4)].nonterm)._.E.my_type, get_var_object((yyvsp[(1) - (4)].nonterm)._.IDU.index).my_type);
                                          } else {
                                            printf("OK -- %s = %s\n",  get_type_name(get_var_object((yyvsp[(1) - (4)].nonterm)._.IDU.index).my_type), get_type_name((yyvsp[(3) - (4)].nonterm)._.E.my_type)); 
                                          }
                                          //generate_STORE_REF($1._.IDU.index, $1._.IDU.my_label);
                                          generate_OP(DUP);
                                          generate_STORE_VAR((yyvsp[(1) - (4)].nonterm)._.IDU.index, (yyvsp[(1) - (4)].nonterm)._.IDU.my_label);
                                          generate_OP(POP);
                                        }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 285 "vh_parser.y"
    {
                                                                    if(check_types((yyvsp[(4) - (7)].nonterm)._.E.my_type, WHILE, 0) == -1) {
                                                                      yyerror("Condicao do WHILE nao eh um boolean");
                                                                    } else {
                                                                      generate_JMP_BW((yyvsp[(2) - (7)].nonterm)._.MWHILE.label_index);
                                                                      generate_STRING_LF(label_creator((yyvsp[(6) - (7)].nonterm)._.MTHEN.label_index));
                                                                    }
                                                                  }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 294 "vh_parser.y"
    {generate_OP(POP);}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 295 "vh_parser.y"
    {generate_STRING_LF("RET");}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 300 "vh_parser.y"
    {
         (yyval.nonterm)._.MTHEN.label_index = give_me_a_label();
         generate_TJMP_FW((yyval.nonterm)._.MTHEN.label_index);
       }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 305 "vh_parser.y"
    {
         (yyval.nonterm)._.MELSE.label_index = give_me_a_label();
         generate_JMP_FW((yyval.nonterm)._.MELSE.label_index);
         generate_STRING_LF(label_creator((yyval.nonterm)._.MELSE.label_index - 1));
       }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 311 "vh_parser.y"
    {
          (yyval.nonterm)._.MWHILE.label_index = give_me_a_label();
          generate_STRING_LF(label_creator((yyval.nonterm)._.MELSE.label_index));
        }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 317 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = 0;
                                  v_type t1 = (yyvsp[(1) - (3)].nonterm)._.E.my_type;
                                  v_type t2 = ((yyvsp[(3) - (3)].nonterm)._.R.is_var == 1 ? (yyvsp[(3) - (3)].nonterm)._.R.var.my_type : (yyvsp[(3) - (3)].nonterm)._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, AND, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    (yyval.nonterm)._.E.my_type = r_type;
                                    generate_OP(AND);
                                  }
                                }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 330 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = 0;
                                  v_type t1 = (yyvsp[(1) - (3)].nonterm)._.E.my_type;
                                  v_type t2 = ((yyvsp[(3) - (3)].nonterm)._.R.is_var == 1 ? (yyvsp[(3) - (3)].nonterm)._.R.var.my_type : (yyvsp[(3) - (3)].nonterm)._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, OR, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    (yyval.nonterm)._.E.my_type = r_type;
                                    generate_OP(OR);
                                  }
                                }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 343 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = 0;
                                  v_type t1 = (yyvsp[(1) - (3)].nonterm)._.E.my_type;
                                  v_type t2 = ((yyvsp[(3) - (3)].nonterm)._.R.is_var == 1 ? (yyvsp[(3) - (3)].nonterm)._.R.var.my_type : (yyvsp[(3) - (3)].nonterm)._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, LESS_THAN, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    (yyval.nonterm)._.E.my_type = r_type;
                                    generate_OP(LESS_THAN);
                                  }
                                }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 356 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = 0;
                                  v_type t1 = (yyvsp[(1) - (3)].nonterm)._.E.my_type;
                                  v_type t2 = ((yyvsp[(3) - (3)].nonterm)._.R.is_var == 1 ? (yyvsp[(3) - (3)].nonterm)._.R.var.my_type : (yyvsp[(3) - (3)].nonterm)._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, GREATER_THAN, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    (yyval.nonterm)._.E.my_type = r_type;
                                    generate_OP(GREATER_THAN);
                                  }
                                }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 369 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = 0;
                                  v_type t1 = (yyvsp[(1) - (3)].nonterm)._.E.my_type;
                                  v_type t2 = ((yyvsp[(3) - (3)].nonterm)._.R.is_var == 1 ? (yyvsp[(3) - (3)].nonterm)._.R.var.my_type : (yyvsp[(3) - (3)].nonterm)._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, LESS_OR_EQUAL, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    (yyval.nonterm)._.E.my_type = r_type;
                                    generate_OP(LESS_OR_EQUAL);
                                  }
                                }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 382 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = 0;
                                  v_type t1 = (yyvsp[(1) - (3)].nonterm)._.E.my_type;
                                  v_type t2 = ((yyvsp[(3) - (3)].nonterm)._.R.is_var == 1 ? (yyvsp[(3) - (3)].nonterm)._.R.var.my_type : (yyvsp[(3) - (3)].nonterm)._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, GREATER_OR_EQUAL, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    (yyval.nonterm)._.E.my_type = r_type;
                                    generate_OP(GREATER_OR_EQUAL);
                                  }
                                }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 395 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = 0;
                                  v_type t1 = (yyvsp[(1) - (3)].nonterm)._.E.my_type;
                                  v_type t2 = ((yyvsp[(3) - (3)].nonterm)._.R.is_var == 1 ? (yyvsp[(3) - (3)].nonterm)._.R.var.my_type : (yyvsp[(3) - (3)].nonterm)._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, EQUAL_EQUAL, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    (yyval.nonterm)._.E.my_type = r_type;
                                    generate_OP(EQUAL_EQUAL);
                                  }
                                }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 408 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = 0;
                                  v_type t1 = (yyvsp[(1) - (3)].nonterm)._.E.my_type;
                                  v_type t2 = ((yyvsp[(3) - (3)].nonterm)._.R.is_var == 1 ? (yyvsp[(3) - (3)].nonterm)._.R.var.my_type : (yyvsp[(3) - (3)].nonterm)._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, NOT_EQUAL, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    (yyval.nonterm)._.E.my_type = r_type;
                                    generate_OP(NOT_EQUAL);
                                  }
                                }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 421 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = 0;
                                  v_type t1 = (yyvsp[(1) - (3)].nonterm)._.E.my_type;
                                  v_type t2 = ((yyvsp[(3) - (3)].nonterm)._.R.is_var == 1 ? (yyvsp[(3) - (3)].nonterm)._.R.var.my_type : (yyvsp[(3) - (3)].nonterm)._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, PLUS, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    (yyval.nonterm)._.E.my_type = r_type;
                                    generate_OP(PLUS);
                                  }
                                }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 434 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = 0;
                                  v_type t1 = (yyvsp[(1) - (3)].nonterm)._.E.my_type;
                                  v_type t2 = ((yyvsp[(3) - (3)].nonterm)._.R.is_var == 1 ? (yyvsp[(3) - (3)].nonterm)._.R.var.my_type : (yyvsp[(3) - (3)].nonterm)._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, MINUS, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    (yyval.nonterm)._.E.my_type = r_type;
                                    generate_OP(MINUS);
                                  }
                                }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 447 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = 0;
                                  v_type t1 = (yyvsp[(1) - (3)].nonterm)._.E.my_type;
                                  v_type t2 = ((yyvsp[(3) - (3)].nonterm)._.R.is_var == 1 ? (yyvsp[(3) - (3)].nonterm)._.R.var.my_type : (yyvsp[(3) - (3)].nonterm)._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, TIMES, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    (yyval.nonterm)._.E.my_type = r_type;
                                    generate_OP(TIMES);
                                  }
                                }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 460 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = 0;
                                  v_type t1 = (yyvsp[(1) - (3)].nonterm)._.E.my_type;
                                  v_type t2 = ((yyvsp[(3) - (3)].nonterm)._.R.is_var == 1 ? (yyvsp[(3) - (3)].nonterm)._.R.var.my_type : (yyvsp[(3) - (3)].nonterm)._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, DIVIDE, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    (yyval.nonterm)._.E.my_type = r_type;
                                    generate_OP(DIVIDE);
                                  }
                                }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 473 "vh_parser.y"
    {
                                  (yyval.nonterm)._.E.is_var = (yyvsp[(1) - (1)].nonterm)._.R.is_var;
                                  (yyval.nonterm)._.E.index   = ((yyvsp[(1) - (1)].nonterm)._.R.is_var == 1 ? (yyvsp[(1) - (1)].nonterm)._.R.var.index : (yyvsp[(1) - (1)].nonterm)._.R.cnt.index);
                                  (yyval.nonterm)._.E.my_type = ((yyvsp[(1) - (1)].nonterm)._.R.is_var == 1 ? (yyvsp[(1) - (1)].nonterm)._.R.var.my_type : (yyvsp[(1) - (1)].nonterm)._.R.cnt.my_type);
                                }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 480 "vh_parser.y"
    {
                          if((yyvsp[(2) - (2)].nonterm)._.R.is_var == 0) {
                            yyerror("Cannot apply ++ to const!");
                          } else {
                            v_type t1 = (yyvsp[(2) - (2)].nonterm)._.R.var.my_type;
                            int r_type = check_types(t1, PLUS_PLUS, t1);
                            
                            if(r_type == -1)
                              yyerror("Type error!");
                            else {
                              copy_var_object(&(yyval.nonterm)._.R.var, (yyvsp[(2) - (2)].nonterm)._.R.var);
                              (yyval.nonterm)._.R.var.my_type = r_type;
                            }
                            //generate_LOAD_VAR($2._.R.var.index, $2._.R.var.my_label);
                            generate_STRING_LF("INC\nDUP");
                            generate_STORE_VAR((yyvsp[(2) - (2)].nonterm)._.R.var.index, (yyvsp[(2) - (2)].nonterm)._.R.var.my_label);
                          }
                        }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 498 "vh_parser.y"
    {
                          if((yyvsp[(2) - (2)].nonterm)._.R.is_var == 0) {
                            yyerror("Cannot apply ++ to const!");
                          } else {
                            v_type t1 = (yyvsp[(2) - (2)].nonterm)._.R.var.my_type;
                            int r_type = check_types(t1, PLUS_PLUS, t1);
                            
                            if(r_type == -1)
                              yyerror("Type error!");
                            else {
                              copy_var_object(&(yyval.nonterm)._.R.var, (yyvsp[(2) - (2)].nonterm)._.R.var);
                              (yyval.nonterm)._.R.var.my_type = r_type;
                            }
                            //generate_LOAD_VAR($2._.R.var.index, $2._.R.var.my_label);
                            generate_STRING_LF("DEC\nDUP");
                            generate_STORE_VAR((yyvsp[(2) - (2)].nonterm)._.R.var.index, (yyvsp[(2) - (2)].nonterm)._.R.var.my_label);
                          }
                        }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 516 "vh_parser.y"
    {
                          if((yyvsp[(1) - (2)].nonterm)._.R.is_var == 0) {
                            yyerror("Cannot apply ++ to const!");
                          } else {
                            v_type t1 = (yyvsp[(1) - (2)].nonterm)._.R.var.my_type;
                            int r_type = check_types(t1, PLUS_PLUS, t1);
                            
                            if(r_type == -1)
                              yyerror("Type error!");
                            else {
                              copy_var_object(&(yyval.nonterm)._.R.var, (yyvsp[(1) - (2)].nonterm)._.R.var);
                              (yyval.nonterm)._.R.var.my_type = r_type;
                            }
                            //generate_LOAD_VAR($1._.R.var.index, $1._.R.var.my_label);
                            generate_STRING_LF("DUP\nINC");
                            generate_STORE_VAR((yyvsp[(1) - (2)].nonterm)._.R.var.index, (yyvsp[(1) - (2)].nonterm)._.R.var.my_label);
                          }
                        }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 534 "vh_parser.y"
    {
                          if((yyvsp[(1) - (2)].nonterm)._.R.is_var == 0) {
                            yyerror("Cannot apply ++ to const!");
                          } else {
                            v_type t1 = (yyvsp[(1) - (2)].nonterm)._.R.var.my_type;
                            int r_type = check_types(t1, PLUS_PLUS, t1);
                            
                            if(r_type == -1)
                              yyerror("Type error!");
                            else {
                              copy_var_object(&(yyval.nonterm)._.R.var, (yyvsp[(1) - (2)].nonterm)._.R.var);
                              (yyval.nonterm)._.R.var.my_type = r_type;
                            }
                            //generate_LOAD_VAR($1._.R.var.index, $1._.R.var.my_label);
                            generate_STRING_LF("DUP\nDEC");
                            generate_STORE_VAR((yyvsp[(1) - (2)].nonterm)._.R.var.index, (yyvsp[(1) - (2)].nonterm)._.R.var.my_label);
                          }
                        }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 552 "vh_parser.y"
    {
                          v_type t1 = ((yyvsp[(2) - (2)].nonterm)._.R.is_var == 1 ? (yyvsp[(2) - (2)].nonterm)._.R.var.my_type : (yyvsp[(2) - (2)].nonterm)._.R.cnt.my_type);
                          int r_type = check_types(t1, MINUS, t1);
                          if(r_type == -1)
                              yyerror("Type error!");
                          else {
                            if((yyvsp[(2) - (2)].nonterm)._.R.is_var == 1) {
                                copy_var_object(&(yyval.nonterm)._.R.var, (yyvsp[(2) - (2)].nonterm)._.R.var);
                                (yyval.nonterm)._.R.var.my_type = check_types(t1, MINUS, t1);
                              } else {
                                copy_cnt_object(&(yyval.nonterm)._.R.cnt, (yyvsp[(2) - (2)].nonterm)._.R.cnt);
                                (yyval.nonterm)._.R.cnt.my_type = check_types(t1, MINUS, t1);
                              }
                              generate_OP(NEG);
                          }
                        }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 568 "vh_parser.y"
    {
                          // checking type
                          v_type t1 = ((yyvsp[(2) - (2)].nonterm)._.R.is_var == 1 ? (yyvsp[(2) - (2)].nonterm)._.R.var.my_type : (yyvsp[(2) - (2)].nonterm)._.R.cnt.my_type);
                          int r_type = check_types(t1, NOT, t1);
                          if(r_type == -1)
                              yyerror("Type error!");
                          else {
                            if((yyvsp[(2) - (2)].nonterm)._.R.is_var == 1) {
                                copy_var_object(&(yyval.nonterm)._.R.var, (yyvsp[(2) - (2)].nonterm)._.R.var);
                                (yyval.nonterm)._.R.var.my_type = check_types(t1, NOT, t1);
                              } else {
                                copy_cnt_object(&(yyval.nonterm)._.R.cnt, (yyvsp[(2) - (2)].nonterm)._.R.cnt);
                                (yyval.nonterm)._.R.cnt.my_type = check_types(t1, NOT, t1);
                              }
                              generate_OP(NOT);
                          }
                        }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 585 "vh_parser.y"
    {
                          (yyval.nonterm)._.R.is_var = 0;
                          (yyval.nonterm)._.R.cnt.my_type = V_BOOLEAN;
                          (yyval.nonterm)._.R.cnt.value_b = BOOLEANTRUE;
                          (yyval.nonterm)._.R.cnt.index = const_append((yyval.nonterm)._.R.cnt);
                          generate_LOAD_TRUE((yyval.nonterm)._.R.cnt.index, "TRUE");
                        }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 592 "vh_parser.y"
    {
                          (yyval.nonterm)._.R.is_var = 0;
                          (yyval.nonterm)._.R.cnt.my_type = V_BOOLEAN;
                          (yyval.nonterm)._.R.cnt.value_b = BOOLEANFALSE;
                          (yyval.nonterm)._.R.cnt.index = const_append((yyval.nonterm)._.R.cnt);
                          generate_LOAD_FALSE((yyval.nonterm)._.R.cnt.index, "FALSE");
                        }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 599 "vh_parser.y"
    {
                          (yyval.nonterm)._.R.is_var = 0;
                          (yyval.nonterm)._.R.cnt.my_type = V_CHAR;
                          (yyval.nonterm)._.R.cnt.value_c = (yyvsp[(1) - (1)].character);
                          (yyval.nonterm)._.R.cnt.index = const_append((yyval.nonterm)._.R.cnt);
                          
                          char* buffer = (char*)malloc(4*sizeof(char)+1);
                          snprintf(buffer, 4, "'%c'", (yyval.nonterm)._.R.cnt.value_c);
                          generate_LOAD_CONST((yyval.nonterm)._.R.cnt.index, buffer);
                        }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 609 "vh_parser.y"
    {
                          printf("string que veio: %s\n", (yyvsp[(1) - (1)].string));
                          (yyval.nonterm)._.R.is_var = 0;
                          (yyval.nonterm)._.R.cnt.my_type = V_STRING;
                          (yyval.nonterm)._.R.cnt.value_s = (char*)malloc(strlen((yyvsp[(1) - (1)].string)) + 1);
                          strcpy((yyval.nonterm)._.R.cnt.value_s, (yyvsp[(1) - (1)].string));
                          (yyval.nonterm)._.R.cnt.index = const_append((yyval.nonterm)._.R.cnt);
                          generate_LOAD_CONST((yyval.nonterm)._.R.cnt.index, (yyval.nonterm)._.R.cnt.value_s);
                        }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 618 "vh_parser.y"
    {
                          (yyval.nonterm)._.R.is_var = 0;
                          copy_cnt_object(&(yyval.nonterm)._.R.cnt, (yyvsp[(1) - (1)].nonterm)._.NUM.my_const);
                          (yyval.nonterm)._.R.cnt.index = const_append((yyval.nonterm)._.R.cnt);
                          debug_cnt((yyval.nonterm)._.R.cnt);
                          char* buffer = (char*)malloc(30 * sizeof(char) +1);
                          if((yyval.nonterm)._.R.cnt.my_type == V_FLOAT)
                            snprintf(buffer,50,"%f",(yyval.nonterm)._.R.cnt.value_f);
                          else 
                            snprintf(buffer,50,"%d",(yyval.nonterm)._.R.cnt.value_i);
                          
                          generate_LOAD_CONST((yyval.nonterm)._.R.cnt.index, buffer);
                        }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 631 "vh_parser.y"
    {
                          (yyval.nonterm)._.R.is_var = 1;
                          copy_var_object(&(yyval.nonterm)._.R.var, get_var_object((yyvsp[(1) - (1)].nonterm)._.IDU.index));
                          generate_LOAD_VAR((yyvsp[(1) - (1)].nonterm)._.IDU.index, (yyvsp[(1) - (1)].nonterm)._.IDU.my_label);
                        }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 639 "vh_parser.y"
    {
                       (yyval.nonterm)._.NUM.my_const.my_type = V_FLOAT;
                       (yyval.nonterm)._.NUM.my_const.value_f = (yyvsp[(1) - (1)].numeralfloat);
                     }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 643 "vh_parser.y"
    {
                       (yyval.nonterm)._.NUM.my_const.my_type = V_INT;
                       (yyval.nonterm)._.NUM.my_const.value_i = (yyvsp[(1) - (1)].numeralint);
                     }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 649 "vh_parser.y"
    {
                (yyval.nonterm)._.IDD.my_ID.my_label = (char*)malloc(sizeof(char) * MAX_VAR_LENGTH + 1);
                (yyval.nonterm)._.IDD.my_ID.next = NULL;
                strcpy((yyval.nonterm)._.IDD.my_ID.my_label, (yyvsp[(1) - (1)].id));

                (yyval.nonterm)._.IDD.my_ID.index = var_scan_or_append((yyval.nonterm)._.IDD.my_ID);
                //generate_LOAD_VAR($$._.IDD.my_ID.index, $$._.IDD.my_ID.my_label);
              }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 659 "vh_parser.y"
    {
             (yyval.nonterm)._.IDU.my_label = (char*)malloc(sizeof(char) * MAX_VAR_LENGTH + 1);
             strcpy((yyval.nonterm)._.IDU.my_label, (yyvsp[(1) - (1)].id));
             (yyval.nonterm)._.IDU.index = var_scan((yyval.nonterm)._.IDU.my_label);
             if((yyval.nonterm)._.IDU.index < 0)
               yyerror("Identificador nao encontrado!");

             //generate_LOAD_VAR($$._.IDU.index, $$._.IDU.my_label);
           }
    break;


/* Line 1787 of yacc.c  */
#line 2282 "vh_parser.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 671 "vh_parser.y"


int main(int argc, char **argv) {
  // Inicializando variaveis globais!!!
  init_globais();
  const int MAX_PATH_LENGTH = 30;

  char* default_file_name = (char*)malloc((MAX_PATH_LENGTH + 1) * sizeof(char));
  strcpy(default_file_name, "teste.file");

  char* file_name = (char*)malloc((MAX_PATH_LENGTH + 1) * sizeof(char));

  (argc == 1) ? strcpy(file_name, default_file_name) : strcpy(file_name, argv[1]);;


  FILE *myfile = fopen(file_name, "r");

  if(!myfile) {
    printf("Erro abrindo arquivo\n");
    return -1;
  } else {
    printf("Abrindo arquivo: %s\n", file_name);
  }

  if(MODO_DEBUG)
    printf("MODO_DEBUG ativado!\n-----------------\n");

  yyin = myfile;
  do {
    yyparse();
  } while(!feof(yyin));
  
  printf("---------------\nFIM DO PROGRAMA\n");
  printf("Arquivo lido com exito: %s\n", file_name);
}