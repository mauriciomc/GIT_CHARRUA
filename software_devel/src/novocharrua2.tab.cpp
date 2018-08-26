
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "novocharrua2.ypp"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_A 200
#define TAM_B 1000
#define TAM_PADRAO 33

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" char *yytext;


void yyerror(const char*);
void int2bin(char str1[],int dec);
int procura_var (char str[]);
char procura_label_str (char str[]);
int procura_label (char str[]);

int i=0;
int j=0;
int linha_atual=1;

extern "C" int linha_atual2;

char labels[TAM_B][TAM_A];
int labels_linhas[TAM_B];
int ind_labels=0;

char variaveis[TAM_B][TAM_A];
int variaveis_linhas[TAM_B];
int ind_variaveis=0;

char escrita[TAM_B][TAM_PADRAO];
int ind_escrita=0;

char str_aux[TAM_PADRAO];
char str_aux2[TAM_PADRAO-6];




/* Line 189 of yacc.c  */
#line 119 "novocharrua2.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     IDENTIFIER = 259,
     INSTR_NOP = 260,
     INSTR_STO = 261,
     INSTR_LD = 262,
     INSTR_LDI = 263,
     INSTR_ADD = 264,
     INSTR_ADDI = 265,
     INSTR_SUB = 266,
     INSTR_SUBI = 267,
     INSTR_BEQ = 268,
     INSTR_BNE = 269,
     INSTR_BGT = 270,
     INSTR_BGE = 271,
     INSTR_BLT = 272,
     INSTR_BLE = 273,
     INSTR_JMP = 274,
     INSTR_NOT = 275,
     INSTR_AND = 276,
     INSTR_ANDI = 277,
     INSTR_OR = 278,
     INSTR_ORI = 279,
     INSTR_XOR = 280,
     INSTR_XORI = 281,
     INSTR_SLL = 282,
     INSTR_SRL = 283,
     INSTR_STOV = 284,
     INSTR_LDV = 285,
     INSTR_RETURN = 286,
     INSTR_RETINT = 287,
     INSTR_CALL = 288,
     INSTR_UMUL = 289,
     INSTR_UMULI = 290,
     INSTR_SMUL = 291,
     INSTR_SMULI = 292,
     INSTR_UDIV = 293,
     INSTR_UDIVI = 294,
     INSTR_SDIV = 295,
     INSTR_SDIVI = 296,
     INSTR_ADDV = 297,
     INSTR_SUBV = 298,
     INSTR_ANDV = 299,
     INSTR_ORV = 300,
     INSTR_XORV = 301,
     INSTR_UMULV = 302,
     INSTR_SMULV = 303,
     INSTR_UDIVV = 304,
     INSTR_SDIVV = 305,
     INSTR_INDWR = 306,
     INSTR_COREWR = 307,
     INSTR_BC = 308,
     INSTR_BNC = 309,
     INSTR_BOV = 310,
     INSTR_BNO = 311,
     COMMA = 312,
     COLON = 313,
     SEMICOLON = 314,
     HIFEN = 315,
     INIC_DADOS = 316,
     INIC_INST = 317
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 46 "novocharrua2.ypp"

        int ival;
        float fval;
        char *sval;
        char sym;



/* Line 214 of yacc.c  */
#line 226 "novocharrua2.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 238 "novocharrua2.tab.cpp"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  165
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNRULES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    12,    15,    18,    21,    24,
      27,    30,    33,    36,    39,    42,    45,    48,    51,    54,
      56,    59,    62,    65,    68,    71,    74,    77,    80,    83,
      86,    89,    92,    94,    96,    99,   102,   105,   108,   111,
     114,   117,   120,   123,   126,   129,   132,   135,   138,   141,
     144,   147,   150,   153,   156,   159,   162,   165,   168,   171,
     173,   175,   177,   179,   181,   183,   185,   187,   189,   191,
     193,   195,   197,   199,   201,   203,   205,   207,   209,   211,
     213,   215,   217,   219,   221,   223,   225,   227,   229,   231,
     233,   235,   237,   239,   241,   243,   245,   247,   249,   251,
     253,   255,   257,   259,   261,   263,   265,   267,   269,   271,
     273,   275,   277,   279,   281,   283,   285,   288,   291
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
     119,     0,    -1,     4,    60,     3,    -1,     4,    58,    -1,
       5,    -1,     6,     4,    -1,     7,     4,    -1,     8,     3,
      -1,     9,     4,    -1,    10,     3,    -1,    11,     4,    -1,
      12,     3,    -1,    13,     4,    -1,    14,     4,    -1,    15,
       4,    -1,    16,     4,    -1,    17,     4,    -1,    18,     4,
      -1,    19,     4,    -1,    20,    -1,    21,     4,    -1,    22,
       3,    -1,    23,     4,    -1,    24,     3,    -1,    25,     4,
      -1,    26,     3,    -1,    27,     3,    -1,    27,     4,    -1,
      28,     3,    -1,    28,     4,    -1,    29,     4,    -1,    30,
       4,    -1,    31,    -1,    32,    -1,    33,     4,    -1,    34,
       4,    -1,    35,     3,    -1,    36,     4,    -1,    37,     3,
      -1,    38,     4,    -1,    39,     3,    -1,    40,     4,    -1,
      41,     3,    -1,    42,     4,    -1,    43,     4,    -1,    44,
       4,    -1,    45,     4,    -1,    46,     4,    -1,    47,     4,
      -1,    48,     4,    -1,    49,     4,    -1,    50,     4,    -1,
      51,     3,    -1,    51,     4,    -1,    52,     3,    -1,    53,
       4,    -1,    54,     4,    -1,    55,     4,    -1,    56,     4,
      -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,    70,
      -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,    75,
      -1,    76,    -1,    77,    -1,    78,    -1,    79,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,
      -1,    91,    -1,    92,    -1,    93,    -1,    94,    -1,    95,
      -1,    96,    -1,    97,    -1,    98,    -1,    99,    -1,   100,
      -1,   101,    -1,   102,    -1,   103,    -1,   104,    -1,   105,
      -1,   106,    -1,   107,    -1,   108,    -1,   109,    -1,   110,
      -1,   111,    -1,   112,    -1,   113,    -1,   114,    -1,   115,
      -1,   116,    -1,   117,    -1,    61,    -1,    62,    -1,   118,
      -1,    64,    -1,    65,    -1,   119,   118,    -1,   119,    65,
      -1,   119,    64,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    81,    94,   108,   141,   173,   204,   236,
     267,   299,   330,   343,   356,   369,   382,   395,   408,   421,
     434,   466,   497,   529,   560,   592,   623,   651,   683,   711,
     743,   775,   807,   820,   833,   846,   878,   909,   941,   971,
    1003,  1034,  1066,  1097,  1129,  1161,  1193,  1225,  1257,  1289,
    1321,  1353,  1385,  1413,  1445,  1476,  1489,  1502,  1515,  1528,
    1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,
    1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,  1547,  1548,
    1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,  1557,  1558,
    1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,
    1569,  1570,  1571,  1572,  1573,  1574,  1575,  1576,  1577,  1578,
    1579,  1580,  1581,  1585,  1586,  1587,  1588,  1589,  1590
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENTIFIER", "INSTR_NOP",
  "INSTR_STO", "INSTR_LD", "INSTR_LDI", "INSTR_ADD", "INSTR_ADDI",
  "INSTR_SUB", "INSTR_SUBI", "INSTR_BEQ", "INSTR_BNE", "INSTR_BGT",
  "INSTR_BGE", "INSTR_BLT", "INSTR_BLE", "INSTR_JMP", "INSTR_NOT",
  "INSTR_AND", "INSTR_ANDI", "INSTR_OR", "INSTR_ORI", "INSTR_XOR",
  "INSTR_XORI", "INSTR_SLL", "INSTR_SRL", "INSTR_STOV", "INSTR_LDV",
  "INSTR_RETURN", "INSTR_RETINT", "INSTR_CALL", "INSTR_UMUL",
  "INSTR_UMULI", "INSTR_SMUL", "INSTR_SMULI", "INSTR_UDIV", "INSTR_UDIVI",
  "INSTR_SDIV", "INSTR_SDIVI", "INSTR_ADDV", "INSTR_SUBV", "INSTR_ANDV",
  "INSTR_ORV", "INSTR_XORV", "INSTR_UMULV", "INSTR_SMULV", "INSTR_UDIVV",
  "INSTR_SDIVV", "INSTR_INDWR", "INSTR_COREWR", "INSTR_BC", "INSTR_BNC",
  "INSTR_BOV", "INSTR_BNO", "COMMA", "COLON", "SEMICOLON", "HIFEN",
  "INIC_DADOS", "INIC_INST", "$accept", "variavel", "label",
  "instruction_NOP", "instruction_STO", "instruction_LD",
  "instruction_LDI", "instruction_ADD", "instruction_ADDI",
  "instruction_SUB", "instruction_SUBI", "instruction_BEQ",
  "instruction_BNE", "instruction_BGT", "instruction_BGE",
  "instruction_BLT", "instruction_BLE", "instruction_JMP",
  "instruction_NOT", "instruction_AND", "instruction_ANDI",
  "instruction_OR", "instruction_ORI", "instruction_XOR",
  "instruction_XORI", "instruction_SLL", "instruction_SRL",
  "instruction_STOV", "instruction_LDV", "instruction_RETURN",
  "instruction_RETINT", "instruction_CALL", "instruction_UMUL",
  "instruction_UMULI", "instruction_SMUL", "instruction_SMULI",
  "instruction_UDIV", "instruction_UDIVI", "instruction_SDIV",
  "instruction_SDIVI", "instruction_ADDV", "instruction_SUBV",
  "instruction_ANDV", "instruction_ORV", "instruction_XORV",
  "instruction_UMULV", "instruction_SMULV", "instruction_UDIVV",
  "instruction_SDIVV", "instruction_INDWR", "instruction_COREWR",
  "instruction_BC", "instruction_BNC", "instruction_BOV",
  "instruction_BNO", "instruction", "program", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    88,    89,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   112,   113,   114,   115,   116,   117,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   119,   119,   119,   119
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   112,   114,   115,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     113,     0,     3,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     1,   118,   117,   116,     2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int16 yypact[] =
{
      59,   -57,   -58,    -2,   114,   116,   118,   120,   121,   123,
     124,   125,   126,   127,   128,   129,   130,   -58,   131,   133,
     134,   136,   137,   139,    54,    56,   140,   141,   -58,   -58,
     142,   143,   145,   146,   148,   149,   151,   152,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   113,   165,
     166,   167,   168,   169,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,     0,   -58,   171,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,    13,    16,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,    26,   -58
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     165,   112,   114,   113,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,   134,   135,   136,
     137,    54,    55,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,   158,   159,   115,   116,
      54,    55,   117,   118,   166,   119,   120,   167,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   168,   130,   131,
       0,   132,   133,     0,   138,   139,   140,   141,   142,     0,
     143,   144,     0,   145,   146,     0,   147,   148,     0,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   160,     0,
     161,   162,   163,   164,   169
};

static const yytype_int8 yycheck[] =
{
       0,    58,     4,    60,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     3,     4,     3,
       4,    61,    62,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     3,     4,     4,     3,
      61,    62,     4,     3,   111,     4,     3,   111,     4,     4,
       4,     4,     4,     4,     4,     4,     3,   111,     4,     3,
      -1,     4,     3,    -1,     4,     4,     4,     4,     3,    -1,
       4,     3,    -1,     4,     3,    -1,     4,     3,    -1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,    -1,
       4,     4,     4,     4,     3
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    61,    62,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    58,    60,     4,     4,     3,     4,     3,     4,
       3,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       4,     3,     4,     3,     3,     4,     3,     4,     4,     4,
       4,     4,     3,     4,     3,     4,     3,     4,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     4,
       3,     4,     4,     4,     4,     0,    64,    65,   118,     3
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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

/* Line 1455 of yacc.c  */
#line 68 "novocharrua2.ypp"
    { printf("Var encontrada! \n"); 
			 strcpy(variaveis[ind_variaveis],(yyvsp[(1) - (3)].sval));
			 printf("string da var => %s \n",variaveis[ind_variaveis]);
			 variaveis_linhas[ind_variaveis] = (yyvsp[(3) - (3)].ival);
			 printf("endereco da var => %d \n",variaveis_linhas[ind_variaveis]);			 
			 printf("indice antes => %d  ;;;;",ind_variaveis);			 
			 ind_variaveis++;
			 printf(" depois => %d \n",ind_variaveis);
			 printf("\n");
			;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 81 "novocharrua2.ypp"
    { printf("Label encontrada! \n"); 
			strcpy(labels[ind_labels],(yyvsp[(1) - (2)].sval));
			printf("string da label => %s \n",labels[ind_labels]);			 
			labels_linhas[ind_labels] = linha_atual;
			printf("linha da label => %d \n",labels_linhas[ind_labels]);
			printf("indice antes => %d  ;;;;",ind_labels);			 
			 ind_labels++;
			printf(" depois => %d  \n",ind_labels);
			printf("\n");
			;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 94 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (1)].sval));
		 strcat(str_aux,"00000000000000000000000000");
		str_aux[33]='\0';		 
		strcpy(escrita[ind_escrita],str_aux);
		printf("OPCODE  => %s \n",(yyvsp[(1) - (1)].sval));
		printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
		printf("NOP encontrado na linha %d \n",linha_atual); 
		printf("\n");
		strcpy(str_aux,"");
		linha_atual++; ind_escrita++;
		;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 108 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

		        strcat(str_aux,saux);
			str_aux[33]='\0';
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("STO encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 141 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("LD encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 173 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("LDI encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++; ind_escrita++;
			   ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 204 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("ADD encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");  strcpy(str_aux2,"");  
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 236 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("LDI encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++; ind_escrita++;
			   ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 267 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("SUB encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");  strcpy(str_aux2,"");  
			linha_atual++;  ind_escrita++;
			   ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 299 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("LDI encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++; ind_escrita++;
			   ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 330 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (2)].sval));
			strcat(str_aux,(yyvsp[(2) - (2)].sval));
			strcpy(escrita[ind_escrita],str_aux);
			printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("BEQ com LABEL %s encontrada na linha %d \n",(yyvsp[(2) - (2)].sval),linha_atual); 
			printf("\n");
			strcpy(str_aux,"");
		        linha_atual++; ind_escrita++;
		      ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 343 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (2)].sval));
			strcat(str_aux,(yyvsp[(2) - (2)].sval));
			strcpy(escrita[ind_escrita],str_aux);
			printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("BNE com LABEL %s encontrada na linha %d \n",(yyvsp[(2) - (2)].sval),linha_atual); 
			printf("\n");
			strcpy(str_aux,"");
		        linha_atual++; ind_escrita++;
		      ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 356 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (2)].sval));
			strcat(str_aux,(yyvsp[(2) - (2)].sval));
			strcpy(escrita[ind_escrita],str_aux);
			printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("BGT com LABEL %s encontrada na linha %d \n",(yyvsp[(2) - (2)].sval),linha_atual); 
			printf("\n");
			strcpy(str_aux,"");
		        linha_atual++; ind_escrita++;
		      ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 369 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (2)].sval));
			strcat(str_aux,(yyvsp[(2) - (2)].sval));
			strcpy(escrita[ind_escrita],str_aux);
			printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("BGE com LABEL %s encontrada na linha %d \n",(yyvsp[(2) - (2)].sval),linha_atual); 
			printf("\n");
			strcpy(str_aux,"");
		        linha_atual++; ind_escrita++;
		      ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 382 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (2)].sval));
			strcat(str_aux,(yyvsp[(2) - (2)].sval));
			strcpy(escrita[ind_escrita],str_aux);
			printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("BLT com LABEL %s encontrada na linha %d \n",(yyvsp[(2) - (2)].sval),linha_atual); 
			printf("\n");
			strcpy(str_aux,"");
		        linha_atual++; ind_escrita++;
		      ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 395 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (2)].sval));
			strcat(str_aux,(yyvsp[(2) - (2)].sval));
			strcpy(escrita[ind_escrita],str_aux);
			printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("BLE com LABEL %s encontrada na linha %d \n",(yyvsp[(2) - (2)].sval),linha_atual); 
			printf("\n");
			strcpy(str_aux,"");
		        linha_atual++; ind_escrita++;
		      ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 408 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (2)].sval));
			strcat(str_aux,(yyvsp[(2) - (2)].sval));
			strcpy(escrita[ind_escrita],str_aux);
			printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("JMP com LABEL %s encontrada na linha %d \n",(yyvsp[(2) - (2)].sval),linha_atual); 
			printf("\n");
			strcpy(str_aux,"");
		        linha_atual++; ind_escrita++;
		      ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 421 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (1)].sval));
		 strcat(str_aux,"00000000000000000000000000");
		 strcpy(escrita[ind_escrita],str_aux);
		printf("OPCODE  => %s \n",(yyvsp[(1) - (1)].sval));
		printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
		printf("NOT encontrado na linha %d \n",linha_atual); 
		printf("\n");
		strcpy(str_aux,"");strcpy(str_aux2,"");
		 linha_atual++;	 ind_escrita++;
		;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 434 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                           // printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("AND encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++;  ind_escrita++;
			   ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 466 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("LDI encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++;  ind_escrita++;
			   ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 497 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("OR encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++;   ind_escrita++;
			   ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 529 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("LDI encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++;   ind_escrita++;
			   ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 560 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                           // printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("XOR encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++;  ind_escrita++;
			   ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 592 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("LDI encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++;  ind_escrita++;
			   ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 623 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("LDI encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++; ind_escrita++;
			   ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 651 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                            //printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("SLL(VAR) encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");    
			linha_atual++;  ind_escrita++;
			   ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 683 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("SRL(NUM) encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++;    ind_escrita++;
			   ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 711 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("SRL(VAR) encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");  strcpy(str_aux2,"");  
			linha_atual++;  ind_escrita++;
			   ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 743 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                           // printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("STOV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");   strcpy(str_aux2,""); 
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 775 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("LDV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 807 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (1)].sval));
		 strcat(str_aux,"00000000000000000000000000");
		 strcpy(escrita[ind_escrita],str_aux);
		printf("OPCODE  => %s \n",(yyvsp[(1) - (1)].sval));
		printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
		printf("RETURN encontrado na linha %d \n",linha_atual); 
		printf("\n");
		strcpy(str_aux,"");
		 linha_atual++;	 ind_escrita++;
		;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 820 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (1)].sval));
		 strcat(str_aux,"00000000000000000000000000");
		 strcpy(escrita[ind_escrita],str_aux);
		printf("OPCODE  => %s \n",(yyvsp[(1) - (1)].sval));
		printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
		printf("RETINT encontrado na linha %d \n",linha_atual); 
		printf("\n");
		strcpy(str_aux,"");
		 linha_atual++;	ind_escrita++;
		;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 833 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (2)].sval));
			strcat(str_aux,(yyvsp[(2) - (2)].sval));
			strcpy(escrita[ind_escrita],str_aux);
			printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("CALL com LABEL %s encontrada na linha %d \n",(yyvsp[(2) - (2)].sval),linha_atual); 
			printf("\n");
			strcpy(str_aux,"");
		        linha_atual++; ind_escrita++;
		      ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 846 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("UMUL encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 878 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("UMULI encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++;  ind_escrita++;
			   ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 909 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                           // printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("SMUL encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 941 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("SMULI encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++; ind_escrita++;
			   ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 971 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("UDIV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1003 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                           // printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("UDIVI encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++; ind_escrita++;
			   ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1034 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("SDIV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1066 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("SDIVI encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++; ind_escrita++;
			   ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1097 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("ADDV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");  strcpy(str_aux2,"");  
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1129 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                           // printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("SUBV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");  strcpy(str_aux2,"");  
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1161 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("ANDV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1193 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                         //   printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("ORV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1225 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("XORV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1257 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("UMULV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 1289 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                        //    printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("SMULV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1321 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                       //     printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("UDIVV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1353 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                        //    printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("SDIVV encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");  strcpy(str_aux2,"");  
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1385 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                         //   printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("INDWR(NUM) encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++; ind_escrita++;
			   ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1413 "novocharrua2.ypp"
    { int z,m;

			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = procura_var((yyvsp[(2) - (2)].sval));
			    int2bin(str_aux2, z);
			    m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                         //   printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("INDWR(VAR) encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,""); strcpy(str_aux2,"");   
			linha_atual++; ind_escrita++;
			   ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1445 "novocharrua2.ypp"
    { int z,m;
			    strcat(str_aux,(yyvsp[(1) - (2)].sval));
			    z = (yyvsp[(2) - (2)].ival);
			    int2bin(str_aux2, z);
			m=26;
              			//completando os zeros ateh 26 bits
                            m = m - strlen(str_aux2);
                          //  printf("m = %d\n",m);

                            char saux[26]="";
                          
                            while(m!=0)
                            {
                                strcat(saux,"0");
                                m--;
                            }
                            //completa os 26 bits
                            strcat(saux,str_aux2);

				strcat(str_aux,saux);
			strcpy(escrita[ind_escrita],str_aux);
		      	printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("COREWR encontrado na linha %d \n",linha_atual); 
			printf("\n");
			strcpy(str_aux,"");strcpy(str_aux2,"");
		            linha_atual++; ind_escrita++;
			   ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1476 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (2)].sval));
			strcat(str_aux,(yyvsp[(2) - (2)].sval));
			strcpy(escrita[ind_escrita],str_aux);
			printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("BC com LABEL %s encontrada na linha %d \n",(yyvsp[(2) - (2)].sval),linha_atual); 
			printf("\n");
			strcpy(str_aux,"");
		        linha_atual++; ind_escrita++;
		      ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1489 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (2)].sval));
			strcat(str_aux,(yyvsp[(2) - (2)].sval));
			strcpy(escrita[ind_escrita],str_aux);
			printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("BNC com LABEL %s encontrada na linha %d \n",(yyvsp[(2) - (2)].sval),linha_atual); 
			printf("\n");
			strcpy(str_aux,"");
		        linha_atual++; ind_escrita++;
		      ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1502 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (2)].sval));
			strcat(str_aux,(yyvsp[(2) - (2)].sval));
			strcpy(escrita[ind_escrita],str_aux);
			printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("BOV com LABEL %s encontrada na linha %d \n",(yyvsp[(2) - (2)].sval),linha_atual); 
			printf("\n");
			strcpy(str_aux,"");
		        linha_atual++; ind_escrita++;
		      ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1515 "novocharrua2.ypp"
    { strcat(str_aux,(yyvsp[(1) - (2)].sval));
			strcat(str_aux,(yyvsp[(2) - (2)].sval));
			strcpy(escrita[ind_escrita],str_aux);
			printf("OPCODE  => %s \n",(yyvsp[(1) - (2)].sval));
			printf("STRING a ser escrita  => %s \n",escrita[ind_escrita]);
			printf("BNO com LABEL %s encontrada na linha %d \n",(yyvsp[(2) - (2)].sval),linha_atual); 
			printf("\n");
			strcpy(str_aux,"");
		        linha_atual++; ind_escrita++;
		      ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1580 "novocharrua2.ypp"
    { printf("\nachei .dados!\n\n");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1581 "novocharrua2.ypp"
    { printf("achei .inst!\n\n");}
    break;



/* Line 1455 of yacc.c  */
#line 3276 "novocharrua2.tab.cpp"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 1592 "novocharrua2.ypp"


void yyerror(const char * message)
{
   printf(message);
   printf(" linha: %d\n" , linha_atual2);
}

void int2bin(char str1[],int dec) //usa uma string de manipulacao do main
{
    char str2[26]="";

    if (dec / 2 >= 1)
    {
        int2bin(str1,dec / 2);
        sprintf(str2, "%d", (dec % 2));
        puts(str2);
        strcat(str1,str2);
    }

    if (dec == 1)
    {
        strcat(str1,"1");
    }
}

int procura_var (char str[])
{int k;
   for(k=0 ; k<TAM_B; k++ )
	{if(!strcmp(str,variaveis[k]))
	   return variaveis_linhas[k];	
	}
}

char procura_label_str(char str[])
 {
if((str[6]!='1')&&(str[6]!='0')) return 's';
   else return 'n';
}

int procura_label (char str[])
{
int k;
   for(k=0 ; k<TAM_B; k++ )
	{if(!strcmp(str,labels[k]))
	   return labels_linhas[k];	
	}
}


int main(int argc, char **argv)
{

FILE *arq_saida;

arq_saida = fopen("saida2.txt" , "w+");

char str_aux_escrita[32];

strcpy(str_aux,"");
strcpy(str_aux2,"");
strcpy(str_aux_escrita,"");

//INICIALIZACOES

for (i=0 ; i<TAM_B ; i++)
{
   strcpy(labels[i],"");  
   strcpy(variaveis[i],""); 
   strcpy(escrita[i],"valor inicial x");
   labels_linhas[i]=0;
   variaveis_linhas[i]=0;
}

  if(argc == 2)
   {
      if((yyin = fopen(argv[1], "rb")) != NULL)
      {
         yyparse();
         fclose(yyin);

	printf("\n\n ******** FIM PARSER **** \n\n ");
      }
   }




for (i=0 ; i<TAM_B ; i++)
{

if(!strcmp(escrita[i],"valor inicial x"))
	{printf("\nFim encontrado!\n");break;} 

char ch;
ch=procura_label_str(escrita[i]);

printf("\nLINHA ESCRITA => %s \n",escrita[i]);   
printf("\n =>%c \n",ch);



if (ch == 's')
{
printf("\nLABEL@@@\n");

for(j=0; j<TAM_PADRAO-6 ; j++)	 
	    str_aux2[j]=escrita[i][j+6];
printf("\nSTR ALTERADA =>%s \n",str_aux2);   

int num;
num = procura_label(str_aux2);
printf("::::linha da label::::::->%d \n",num);

strcpy(str_aux2,"");strcpy(str_aux,"");  


	int2bin(str_aux2, num);
	int m; m=26;
	//completando os zeros ateh 26 bits
	m = m - strlen(str_aux2);

        char saux[26]="";
                          
        while(m!=0)
       {
         strcat(saux,"0");
         m--;
       }
       
       //completa os 26 bits
       strcat(saux,str_aux2);
       
printf("\nSTR ALTERADA 2=>%s \n",saux);

for(j=0; j<TAM_PADRAO-6 ; j++)	 
	    escrita[i][j+6]=saux[j];
printf("\nALTERADA LABEL LINHA ESCRITA => %s \n",escrita[i]);
}

  
 
fputs(escrita[i],arq_saida);
fputc('\n',arq_saida);
}


printf("\n ***** FIM DO PROGRAMA! *****\n");

fclose(arq_saida);


return 0;
}

