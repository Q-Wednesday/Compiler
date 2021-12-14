/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_TINT = 258,
     T_TDOUBLE = 259,
     T_TFLOAT = 260,
     T_TCHAR = 261,
     T_TBOOL = 262,
     T_TVOID = 263,
     T_TSTRING = 264,
     T_EXTERN = 265,
     T_RETURN = 266,
     T_IDENTIFIER = 267,
     T_INTEGER = 268,
     T_DOUBLE = 269,
     T_LITERAL = 270,
     T_ASSIGN = 271,
     T_CEQUAL = 272,
     T_CNEQUAL = 273,
     T_CLT = 274,
     T_CLE = 275,
     T_CGT = 276,
     T_CGE = 277,
     T_TFOR = 278,
     T_TWHILE = 279,
     T_IF = 280,
     T_ELSE = 281,
     T_LPAREN = 282,
     T_RPAREN = 283,
     T_LBRACE = 284,
     T_RBRACE = 285,
     T_LBRACKET = 286,
     T_RBRACKET = 287,
     T_SEMICOLON = 288,
     LOWER_THAN_ELSE = 289,
     T_MINUS = 290,
     T_PLUS = 291,
     T_DIV = 292,
     T_MULT = 293,
     T_COMMA = 294,
     T_DOT = 295
   };
#endif
/* Tokens.  */
#define T_TINT 258
#define T_TDOUBLE 259
#define T_TFLOAT 260
#define T_TCHAR 261
#define T_TBOOL 262
#define T_TVOID 263
#define T_TSTRING 264
#define T_EXTERN 265
#define T_RETURN 266
#define T_IDENTIFIER 267
#define T_INTEGER 268
#define T_DOUBLE 269
#define T_LITERAL 270
#define T_ASSIGN 271
#define T_CEQUAL 272
#define T_CNEQUAL 273
#define T_CLT 274
#define T_CLE 275
#define T_CGT 276
#define T_CGE 277
#define T_TFOR 278
#define T_TWHILE 279
#define T_IF 280
#define T_ELSE 281
#define T_LPAREN 282
#define T_RPAREN 283
#define T_LBRACE 284
#define T_RBRACE 285
#define T_LBRACKET 286
#define T_RBRACKET 287
#define T_SEMICOLON 288
#define LOWER_THAN_ELSE 289
#define T_MINUS 290
#define T_PLUS 291
#define T_DIV 292
#define T_MULT 293
#define T_COMMA 294
#define T_DOT 295




/* Copy the first part of user declarations.  */
#line 1 "grammar.y"

#include "ASTNodes.h"
#include <stdio.h>
#include <iostream>
#include <string>

extern int yylex();
CodeBlockNode* programBlock;
void yyerror(const char* msg){
    printf("Error: %s\b",msg);
}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "grammar.y"
{
    ExpressionNode* expr;
    StatementNode* stat;
    IdentifierNode* ident;
    std::string* string;
    VariableDeclaration* var_dec;
    ExprVec* exprvec;
    int token;
    CodeBlockNode* block;
    VariableVec* varvec;
    ArrayElem* elem;
}
/* Line 193 of yacc.c.  */
#line 202 "grammar.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 215 "grammar.cpp"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   246

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNRULES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    15,    18,    22,
      24,    26,    28,    32,    39,    47,    51,    53,    54,    57,
      62,    64,    66,    68,    70,    72,    74,    79,    83,    85,
      87,    89,    93,    97,   101,   105,   109,   111,   113,   115,
     117,   122,   126,   128,   129,   139,   147,   155,   163,   172,
     181,   190,   197,   203,   209
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    44,    -1,    43,    44,    -1,
      48,    33,    -1,    46,    -1,    53,    33,    -1,    11,    53,
      33,    -1,    59,    -1,    57,    -1,    58,    -1,    29,    43,
      30,    -1,    50,    49,    27,    47,    28,    45,    -1,    10,
      50,    49,    27,    47,    28,    33,    -1,    47,    39,    48,
      -1,    48,    -1,    -1,    50,    49,    -1,    50,    49,    16,
      53,    -1,    12,    -1,     3,    -1,     4,    -1,     8,    -1,
       9,    -1,    51,    -1,    50,    31,    13,    32,    -1,    49,
      16,    53,    -1,    52,    -1,    54,    -1,    49,    -1,    53,
      36,    53,    -1,    53,    35,    53,    -1,    53,    38,    53,
      -1,    53,    37,    53,    -1,    27,    53,    27,    -1,    15,
      -1,    55,    -1,    13,    -1,    14,    -1,    49,    27,    56,
      28,    -1,    56,    39,    53,    -1,    53,    -1,    -1,    23,
      27,    53,    33,    53,    33,    53,    28,    45,    -1,    23,
      27,    53,    33,    33,    28,    45,    -1,    23,    27,    33,
      53,    33,    28,    45,    -1,    23,    27,    33,    33,    53,
      28,    45,    -1,    23,    27,    53,    33,    53,    33,    28,
      45,    -1,    23,    27,    53,    33,    33,    53,    28,    45,
      -1,    23,    27,    33,    53,    33,    53,    28,    45,    -1,
      23,    27,    33,    33,    28,    45,    -1,    24,    27,    53,
      28,    45,    -1,    25,    27,    53,    28,    45,    -1,    25,
      27,    53,    28,    45,    26,    45,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    54,    55,    59,    60,    61,    62,    63,
      64,    65,    76,    79,    80,    82,    83,    84,    87,    88,
      91,    94,    95,    96,    97,    98,   101,   108,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   124,   125,
     128,   131,   132,   133,   136,   137,   138,   139,   140,   141,
     142,   143,   147,   150,   151
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_TINT", "T_TDOUBLE", "T_TFLOAT",
  "T_TCHAR", "T_TBOOL", "T_TVOID", "T_TSTRING", "T_EXTERN", "T_RETURN",
  "T_IDENTIFIER", "T_INTEGER", "T_DOUBLE", "T_LITERAL", "T_ASSIGN",
  "T_CEQUAL", "T_CNEQUAL", "T_CLT", "T_CLE", "T_CGT", "T_CGE", "T_TFOR",
  "T_TWHILE", "T_IF", "T_ELSE", "T_LPAREN", "T_RPAREN", "T_LBRACE",
  "T_RBRACE", "T_LBRACKET", "T_RBRACKET", "T_SEMICOLON", "LOWER_THAN_ELSE",
  "T_MINUS", "T_PLUS", "T_DIV", "T_MULT", "T_COMMA", "T_DOT", "$accept",
  "program", "stats", "stat", "block", "func_dec", "varvec", "var_dec",
  "ident", "typename", "array_typename", "assignmemt", "expr", "number",
  "call", "call_args", "for_stm", "while_stm", "if_stat", 0
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
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    45,    46,    46,    47,    47,    47,    48,    48,
      49,    50,    50,    50,    50,    50,    51,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      55,    56,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    57,    58,    59,    59
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     2,     3,     1,
       1,     1,     3,     6,     7,     3,     1,     0,     2,     4,
       1,     1,     1,     1,     1,     1,     4,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       4,     3,     1,     0,     9,     7,     7,     7,     8,     8,
       8,     6,     5,     5,     7
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    21,    22,    23,    24,     0,     0,    20,    38,    39,
      36,     0,     0,     0,     0,     0,     2,     3,     6,     0,
      30,     0,    25,    28,     0,    29,    37,    10,    11,     9,
       0,     0,     0,     0,     0,     0,     1,     4,     5,     0,
      43,     0,    18,     7,     0,     0,     0,     0,     0,     8,
       0,     0,     0,     0,    35,    27,    42,     0,     0,     0,
      17,    32,    31,    34,    33,    17,     0,     0,     0,     0,
       0,    40,     0,    26,    19,     0,    16,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    41,     0,     0,
      18,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    15,    14,    47,    46,     0,    45,     0,     0,
       0,    12,    54,    50,    49,    48,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    16,    17,    85,    18,    75,    19,    20,    21,
      22,    23,    24,    25,    26,    57,    27,    28,    29
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -54
static const yytype_int16 yypact[] =
{
     129,   -54,   -54,   -54,   -54,   213,   154,   -54,   -54,   -54,
     -54,   -21,   -18,     3,   154,    47,   129,   -54,   -54,    12,
      15,     1,   -54,   -54,   173,   -54,   -54,   -54,   -54,   -54,
       1,   190,     2,   154,   154,   -17,   -54,   -54,   -54,   154,
     154,    39,    30,   -54,   154,   154,   154,   154,    27,   -54,
      10,   196,    62,   147,   -54,   135,   135,    31,    23,   154,
     213,   -33,   -33,   -54,   -54,   213,    66,   202,    36,    35,
      35,   -54,   154,   -54,   135,    43,   -54,     1,    45,    35,
     151,   108,   133,   208,   129,   -54,    41,   135,    35,   213,
      52,    44,   -54,    35,    35,   162,    35,   166,   150,   104,
      35,   -54,   -54,   -54,   -54,   -54,    35,   -54,    35,    35,
     177,   -54,   -54,   -54,   -54,   -54,    35,   -54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,   -12,   -13,    -5,   -54,    22,   -53,   -19,    -4,
     -54,   -54,    -6,   -54,   -54,   -54,   -54,   -54,   -54
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      31,    30,    42,    37,    46,    47,    32,    76,    35,    33,
      54,    48,    76,     7,     7,     8,     9,    10,    44,    45,
      46,    47,     7,     8,     9,    10,    51,    52,    53,    14,
      34,    39,    41,    55,    56,    50,   102,    14,    61,    62,
      63,    64,    40,    66,    67,    38,    59,    36,     7,     8,
       9,    10,    58,    74,    65,    73,    77,    60,    90,    71,
      80,    77,    83,    14,    84,    86,    87,   100,    59,    82,
      72,    88,    99,    91,    92,    95,    97,   103,     7,     8,
       9,    10,    89,   101,    89,    77,    37,    78,   104,   105,
      69,   107,   110,    14,    79,   112,     0,    44,    45,    46,
      47,   113,     0,   114,   115,     0,     0,     1,     2,     0,
       0,   117,     3,     4,     5,     6,     7,     8,     9,    10,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
       0,    14,     1,     2,   111,    14,    94,     3,     4,     5,
       6,     7,     8,     9,    10,     7,     8,     9,    10,     0,
       0,     0,    11,    12,    13,     0,    14,     0,     0,     0,
      14,    96,     7,     8,     9,    10,     7,     8,     9,    10,
      44,    45,    46,    47,     0,    70,     0,    14,   109,    93,
       0,    14,    44,    45,    46,    47,    44,    45,    46,    47,
     106,     0,     0,     0,   108,     0,     0,    44,    45,    46,
      47,    44,    45,    46,    47,   116,    43,     0,    44,    45,
      46,    47,    44,    45,    46,    47,     1,     2,     0,     0,
       0,     3,     4,    49,     0,    44,    45,    46,    47,    68,
       0,    44,    45,    46,    47,    81,     0,    44,    45,    46,
      47,    98,     0,    44,    45,    46,    47
};

static const yytype_int8 yycheck[] =
{
       6,     5,    21,    16,    37,    38,    27,    60,    14,    27,
      27,    30,    65,    12,    12,    13,    14,    15,    35,    36,
      37,    38,    12,    13,    14,    15,    32,    33,    34,    27,
      27,    16,    31,    39,    40,    33,    89,    27,    44,    45,
      46,    47,    27,    33,    50,    33,    16,     0,    12,    13,
      14,    15,    13,    59,    27,    32,    60,    27,    77,    28,
      66,    65,    68,    27,    29,    70,    72,    26,    16,    33,
      39,    28,    84,    28,    79,    81,    82,    33,    12,    13,
      14,    15,    39,    88,    39,    89,    99,    65,    93,    94,
      28,    96,    98,    27,    28,   100,    -1,    35,    36,    37,
      38,   106,    -1,   108,   109,    -1,    -1,     3,     4,    -1,
      -1,   116,     8,     9,    10,    11,    12,    13,    14,    15,
      12,    13,    14,    15,    -1,    -1,    -1,    23,    24,    25,
      -1,    27,     3,     4,    30,    27,    28,     8,     9,    10,
      11,    12,    13,    14,    15,    12,    13,    14,    15,    -1,
      -1,    -1,    23,    24,    25,    -1,    27,    -1,    -1,    -1,
      27,    28,    12,    13,    14,    15,    12,    13,    14,    15,
      35,    36,    37,    38,    -1,    28,    -1,    27,    28,    28,
      -1,    27,    35,    36,    37,    38,    35,    36,    37,    38,
      28,    -1,    -1,    -1,    28,    -1,    -1,    35,    36,    37,
      38,    35,    36,    37,    38,    28,    33,    -1,    35,    36,
      37,    38,    35,    36,    37,    38,     3,     4,    -1,    -1,
      -1,     8,     9,    33,    -1,    35,    36,    37,    38,    33,
      -1,    35,    36,    37,    38,    33,    -1,    35,    36,    37,
      38,    33,    -1,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     8,     9,    10,    11,    12,    13,    14,
      15,    23,    24,    25,    27,    42,    43,    44,    46,    48,
      49,    50,    51,    52,    53,    54,    55,    57,    58,    59,
      50,    53,    27,    27,    27,    53,     0,    44,    33,    16,
      27,    31,    49,    33,    35,    36,    37,    38,    49,    33,
      33,    53,    53,    53,    27,    53,    53,    56,    13,    16,
      27,    53,    53,    53,    53,    27,    33,    53,    33,    28,
      28,    28,    39,    32,    53,    47,    48,    50,    47,    28,
      53,    33,    33,    53,    29,    45,    45,    53,    28,    39,
      49,    28,    45,    28,    28,    53,    28,    53,    33,    43,
      26,    45,    48,    33,    45,    45,    28,    45,    28,    28,
      53,    30,    45,    45,    45,    45,    28,    45
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 51 "grammar.y"
    { programBlock = (yyvsp[(1) - (1)].block);;}
    break;

  case 3:
#line 54 "grammar.y"
    { (yyval.block) = new CodeBlockNode(); (yyval.block)->statements->push_back(shared_ptr<StatementNode>((yyvsp[(1) - (1)].stat)));;}
    break;

  case 4:
#line 55 "grammar.y"
    { (yyval.block)->statements->push_back(shared_ptr<StatementNode>((yyvsp[(2) - (2)].stat)));;}
    break;

  case 5:
#line 59 "grammar.y"
    {(yyval.stat)=(yyvsp[(1) - (2)].stat);;}
    break;

  case 6:
#line 60 "grammar.y"
    {(yyval.stat)=(yyvsp[(1) - (1)].stat);;}
    break;

  case 7:
#line 61 "grammar.y"
    {(yyval.stat)=new ExpressionStatement(shared_ptr<ExpressionNode>((yyvsp[(1) - (2)].expr)));;}
    break;

  case 8:
#line 62 "grammar.y"
    {(yyval.stat)=new ReturnNode(shared_ptr<ExpressionNode>((yyvsp[(2) - (3)].expr)));;}
    break;

  case 10:
#line 64 "grammar.y"
    {(yyval.stat)=(yyvsp[(1) - (1)].stat);;}
    break;

  case 11:
#line 65 "grammar.y"
    {(yyval.stat)=(yyvsp[(1) - (1)].stat);;}
    break;

  case 12:
#line 76 "grammar.y"
    { (yyval.block) = (yyvsp[(2) - (3)].block);;}
    break;

  case 13:
#line 79 "grammar.y"
    { (yyval.stat) = new FunctionDeclaration(shared_ptr<IdentifierNode>((yyvsp[(1) - (6)].ident)),shared_ptr<IdentifierNode>((yyvsp[(2) - (6)].ident)),shared_ptr<VariableVec>((yyvsp[(4) - (6)].varvec)),shared_ptr<CodeBlockNode>((yyvsp[(6) - (6)].block)));;}
    break;

  case 14:
#line 80 "grammar.y"
    { (yyval.stat) = new FunctionDeclaration(shared_ptr<IdentifierNode>((yyvsp[(2) - (7)].ident)),shared_ptr<IdentifierNode>((yyvsp[(3) - (7)].ident)),shared_ptr<VariableVec>((yyvsp[(5) - (7)].varvec)),nullptr,true);;}
    break;

  case 15:
#line 82 "grammar.y"
    {(yyval.varvec)->push_back(shared_ptr<VariableDeclaration>((yyvsp[(3) - (3)].var_dec)));;}
    break;

  case 16:
#line 83 "grammar.y"
    {(yyval.varvec) = new VariableVec(); (yyval.varvec)->push_back(shared_ptr<VariableDeclaration>((yyvsp[(1) - (1)].var_dec)));;}
    break;

  case 17:
#line 84 "grammar.y"
    {(yyval.varvec) = new VariableVec();;}
    break;

  case 18:
#line 87 "grammar.y"
    { (yyval.stat)=new VariableDeclaration(shared_ptr<IdentifierNode>((yyvsp[(1) - (2)].ident)),shared_ptr<IdentifierNode>((yyvsp[(2) - (2)].ident)));;}
    break;

  case 19:
#line 88 "grammar.y"
    { (yyval.stat)=new VariableDeclaration(shared_ptr<IdentifierNode>((yyvsp[(1) - (4)].ident)),shared_ptr<IdentifierNode>((yyvsp[(2) - (4)].ident)),shared_ptr<ExpressionNode>((yyvsp[(4) - (4)].expr)));;}
    break;

  case 20:
#line 91 "grammar.y"
    { (yyval.ident)=new IdentifierNode(*(yyvsp[(1) - (1)].string));cout<<"ident"<<endl; delete (yyvsp[(1) - (1)].string);;}
    break;

  case 21:
#line 94 "grammar.y"
    { (yyval.ident) = new IdentifierNode(*(yyvsp[(1) - (1)].string)); delete (yyvsp[(1) - (1)].string);;}
    break;

  case 22:
#line 95 "grammar.y"
    { (yyval.ident) = new IdentifierNode(*(yyvsp[(1) - (1)].string)); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 23:
#line 96 "grammar.y"
    {(yyval.ident) = new IdentifierNode(*(yyvsp[(1) - (1)].string)); delete (yyvsp[(1) - (1)].string); ;}
    break;

  case 24:
#line 97 "grammar.y"
    {(yyval.ident) = new IdentifierNode(*(yyvsp[(1) - (1)].string)); delete (yyvsp[(1) - (1)].string);;}
    break;

  case 26:
#line 101 "grammar.y"
    {(yyvsp[(1) - (4)].ident)->isArray = true; (yyvsp[(1) - (4)].ident)->array_size = atol((yyvsp[(3) - (4)].string)->c_str()); (yyval.ident) = (yyvsp[(1) - (4)].ident);;}
    break;

  case 27:
#line 108 "grammar.y"
    { (yyval.expr)=new AssignmentNode(shared_ptr<IdentifierNode>((yyvsp[(1) - (3)].ident)),shared_ptr<ExpressionNode>((yyvsp[(3) - (3)].expr)));;}
    break;

  case 28:
#line 112 "grammar.y"
    {(yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 29:
#line 113 "grammar.y"
    {(yyval.expr)=(yyvsp[(1) - (1)].expr);;}
    break;

  case 30:
#line 114 "grammar.y"
    {(yyval.expr)=(yyvsp[(1) - (1)].ident);;}
    break;

  case 31:
#line 115 "grammar.y"
    {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[(1) - (3)].expr)), (yyvsp[(2) - (3)].token), shared_ptr<ExpressionNode>((yyvsp[(3) - (3)].expr)));;}
    break;

  case 32:
#line 116 "grammar.y"
    {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[(1) - (3)].expr)), (yyvsp[(2) - (3)].token), shared_ptr<ExpressionNode>((yyvsp[(3) - (3)].expr)));;}
    break;

  case 33:
#line 117 "grammar.y"
    {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[(1) - (3)].expr)), (yyvsp[(2) - (3)].token), shared_ptr<ExpressionNode>((yyvsp[(3) - (3)].expr)));;}
    break;

  case 34:
#line 118 "grammar.y"
    {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[(1) - (3)].expr)), (yyvsp[(2) - (3)].token), shared_ptr<ExpressionNode>((yyvsp[(3) - (3)].expr)));;}
    break;

  case 35:
#line 119 "grammar.y"
    {(yyval.expr)=(yyvsp[(2) - (3)].expr);;}
    break;

  case 36:
#line 120 "grammar.y"
    {(yyval.expr)=new LiteralNode(*(yyvsp[(1) - (1)].string));delete (yyvsp[(1) - (1)].string);;}
    break;

  case 37:
#line 121 "grammar.y"
    {(yyval.expr)=(yyvsp[(1) - (1)].expr);;}
    break;

  case 38:
#line 124 "grammar.y"
    {(yyval.expr)=new IntegerNode(stoi(*(yyvsp[(1) - (1)].string)));delete (yyvsp[(1) - (1)].string);;}
    break;

  case 39:
#line 125 "grammar.y"
    {(yyval.expr)=new DoubleNode(stod(*(yyvsp[(1) - (1)].string)));delete (yyvsp[(1) - (1)].string);;}
    break;

  case 40:
#line 128 "grammar.y"
    {(yyval.expr)= new CallFunctionNode(shared_ptr<IdentifierNode>((yyvsp[(1) - (4)].ident)),shared_ptr<ExprVec>((yyvsp[(3) - (4)].exprvec)));;}
    break;

  case 41:
#line 131 "grammar.y"
    {(yyval.exprvec)->push_back(shared_ptr<ExpressionNode>((yyvsp[(3) - (3)].expr)));;}
    break;

  case 42:
#line 132 "grammar.y"
    {(yyval.exprvec)= new ExprVec();(yyval.exprvec)->push_back(shared_ptr<ExpressionNode>((yyvsp[(1) - (1)].expr)));;}
    break;

  case 43:
#line 133 "grammar.y"
    {(yyval.exprvec)= new ExprVec();;}
    break;

  case 44:
#line 136 "grammar.y"
    {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[(9) - (9)].block)),shared_ptr<ExpressionNode>((yyvsp[(3) - (9)].expr)),shared_ptr<ExpressionNode>((yyvsp[(5) - (9)].expr)),shared_ptr<ExpressionNode>((yyvsp[(7) - (9)].expr)));;}
    break;

  case 45:
#line 137 "grammar.y"
    {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[(7) - (7)].block)),shared_ptr<ExpressionNode>((yyvsp[(3) - (7)].expr)),nullptr,nullptr);;}
    break;

  case 46:
#line 138 "grammar.y"
    {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[(7) - (7)].block)),nullptr,shared_ptr<ExpressionNode>((yyvsp[(4) - (7)].expr)),nullptr);;}
    break;

  case 47:
#line 139 "grammar.y"
    {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[(7) - (7)].block)),nullptr,nullptr,shared_ptr<ExpressionNode>((yyvsp[(5) - (7)].expr)));;}
    break;

  case 48:
#line 140 "grammar.y"
    {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[(8) - (8)].block)),shared_ptr<ExpressionNode>((yyvsp[(3) - (8)].expr)),shared_ptr<ExpressionNode>((yyvsp[(5) - (8)].expr)),nullptr);;}
    break;

  case 49:
#line 141 "grammar.y"
    {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[(8) - (8)].block)),shared_ptr<ExpressionNode>((yyvsp[(3) - (8)].expr)),nullptr,shared_ptr<ExpressionNode>((yyvsp[(6) - (8)].expr)));;}
    break;

  case 50:
#line 142 "grammar.y"
    {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[(8) - (8)].block)),nullptr,shared_ptr<ExpressionNode>((yyvsp[(4) - (8)].expr)),shared_ptr<ExpressionNode>((yyvsp[(6) - (8)].expr)));;}
    break;

  case 51:
#line 143 "grammar.y"
    {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[(6) - (6)].block)),nullptr,nullptr,nullptr);;}
    break;

  case 52:
#line 147 "grammar.y"
    {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[(5) - (5)].block)),nullptr,shared_ptr<ExpressionNode>((yyvsp[(3) - (5)].expr)),nullptr);;}
    break;

  case 53:
#line 150 "grammar.y"
    {(yyval.stat) = new IfNode(shared_ptr<ExpressionNode>((yyvsp[(3) - (5)].expr)),shared_ptr<CodeBlockNode>((yyvsp[(5) - (5)].block)),nullptr);;}
    break;

  case 54:
#line 151 "grammar.y"
    {(yyval.stat) = new IfNode(shared_ptr<ExpressionNode>((yyvsp[(3) - (7)].expr)),shared_ptr<CodeBlockNode>((yyvsp[(5) - (7)].block)),shared_ptr<CodeBlockNode>((yyvsp[(7) - (7)].block)));;}
    break;


/* Line 1267 of yacc.c.  */
#line 1789 "grammar.cpp"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 154 "grammar.y"


// int main(){

//     #ifdef YYDEBUG
//       yydebug = 0;
//     #endif
//     yyparse();
//     cout<<programBlock->getNodeType()<<endl;
//     programBlock->graphGen(cout);
//     return 0;
// }
