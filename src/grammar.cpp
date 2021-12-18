/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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

#line 83 "grammar.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_GRAMMAR_HPP_INCLUDED
# define YY_YY_GRAMMAR_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    T_TFOR = 272,
    T_TWHILE = 273,
    T_IF = 274,
    T_ELSE = 275,
    T_LPAREN = 276,
    T_RPAREN = 277,
    T_LBRACE = 278,
    T_RBRACE = 279,
    T_LBRACKET = 280,
    T_RBRACKET = 281,
    T_SEMICOLON = 282,
    LOWER_THAN_ELSE = 283,
    T_PLUS = 284,
    T_MINUS = 285,
    T_MULT = 286,
    T_DIV = 287,
    T_LSHIFT = 288,
    T_RSHIFT = 289,
    T_CLT = 290,
    T_CLE = 291,
    T_CGT = 292,
    T_CGE = 293,
    T_CEQUAL = 294,
    T_CNEQUAL = 295,
    T_BITAND = 296,
    T_BITXOR = 297,
    T_BITOR = 298,
    T_LOGICALAND = 299,
    T_LOGICALOR = 300,
    T_DOT = 301,
    T_COMMA = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "grammar.y"

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

#line 196 "grammar.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_HPP_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   537

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    64,    65,    69,    70,    71,    72,    73,
      74,    75,    78,    81,    82,    84,    85,    86,    89,    90,
      91,    94,    99,   102,   103,   104,   105,   108,   112,   113,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   143,   144,   147,   150,   151,   152,
     155,   156,   157,   158,   159,   160,   161,   162,   166,   169,
     170
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_TINT", "T_TDOUBLE", "T_TFLOAT",
  "T_TCHAR", "T_TBOOL", "T_TVOID", "T_TSTRING", "T_EXTERN", "T_RETURN",
  "T_IDENTIFIER", "T_INTEGER", "T_DOUBLE", "T_LITERAL", "T_ASSIGN",
  "T_TFOR", "T_TWHILE", "T_IF", "T_ELSE", "T_LPAREN", "T_RPAREN",
  "T_LBRACE", "T_RBRACE", "T_LBRACKET", "T_RBRACKET", "T_SEMICOLON",
  "LOWER_THAN_ELSE", "T_PLUS", "T_MINUS", "T_MULT", "T_DIV", "T_LSHIFT",
  "T_RSHIFT", "T_CLT", "T_CLE", "T_CGT", "T_CGE", "T_CEQUAL", "T_CNEQUAL",
  "T_BITAND", "T_BITXOR", "T_BITOR", "T_LOGICALAND", "T_LOGICALOR",
  "T_DOT", "T_COMMA", "$accept", "program", "stats", "stat", "block",
  "func_dec", "varvec", "var_dec", "ident", "typename", "array_elem",
  "assignmemt", "expr", "number", "call", "call_args", "for_stm",
  "while_stm", "if_stat", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     117,   -64,   -64,   -64,   -64,    16,   509,   -64,   -64,   -64,
     -64,   -11,    36,    56,   509,     4,   117,   -64,   -64,   -21,
      60,    67,    66,   -64,   313,   -64,   -64,   -64,   -64,   -64,
      67,   332,     2,   509,   509,   111,   -64,   -64,   -64,   509,
     509,   509,    76,   509,   -64,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   509,    62,   -64,    48,   351,   135,   159,   -64,   406,
     406,   -17,   294,   509,    16,    71,   406,   421,   421,   434,
     434,   445,   445,   492,   492,   492,   492,   118,   118,    69,
      21,   -23,    53,   -64,    16,   479,   370,    59,    79,    79,
     -64,   509,   -64,   406,   -15,   -64,    67,    73,    -9,    79,
     183,   483,   494,   389,   117,   -64,    83,   406,    79,    16,
      -7,    88,    81,   -64,    79,    79,   207,    79,   231,   498,
     298,    79,   -64,   -64,    94,   -64,   -64,   -64,    79,   -64,
      79,    79,   255,   -64,   -64,   509,   -64,   -64,   -64,    79,
      12,   -64,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    23,    24,    25,    26,     0,     0,    22,    54,    55,
      51,     0,     0,     0,     0,     0,     2,     3,     6,     0,
      32,     0,    52,    30,     0,    31,    53,    10,    11,     9,
       0,     0,     0,     0,     0,     0,     1,     4,     5,     0,
      59,     0,    18,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,     0,     0,    50,    28,
      58,     0,     0,     0,    17,     0,    29,    33,    34,    35,
      36,    38,    37,    42,    41,    40,    39,    44,    43,    45,
      46,    47,    48,    49,    17,     0,     0,     0,     0,     0,
      56,     0,    27,    19,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    69,    57,     0,     0,
      18,    20,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    15,     0,    14,    63,    62,     0,    61,
       0,     0,     0,    12,    70,    59,    66,    65,    64,     0,
       0,    60,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,     5,   -14,   -31,   -64,    28,   -63,   -18,    -4,
     -64,   -64,    -6,   -64,   -64,    -8,   -64,   -64,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    16,    17,   115,    18,   104,    19,    20,    21,
      22,    23,    24,    25,    26,    71,    27,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    30,    37,    42,    36,   100,    38,   118,    35,    73,
      32,   105,    62,   122,     7,     8,     9,    10,    75,     1,
       2,    60,    61,    14,     3,     4,    65,    66,    67,    64,
     101,   105,   119,    69,    70,    72,   152,    76,   119,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,   133,    33,    96,   101,
       7,     8,     9,    10,    59,    60,    61,   103,   116,    14,
     106,     7,     8,     9,    10,    95,    39,    34,   123,     7,
      14,    40,    43,    94,   107,    41,   112,   132,   120,   110,
     106,   113,    73,   136,   137,   117,   139,    74,    61,   121,
     144,    75,   114,   131,   134,   126,   128,   146,   135,   147,
     148,    58,    59,    60,    61,   106,    37,   145,   151,   130,
       1,     2,   108,   142,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    68,    11,    12,    13,   150,    14,    70,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    98,     0,    57,
      58,    59,    60,    61,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    99,     0,     0,     0,     0,     0,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   124,     0,     0,     0,     0,
       0,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   138,
       0,     0,     0,     0,     0,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   140,     0,     0,     0,     0,     0,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   149,     0,     0,
       0,     0,     0,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     1,     2,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,     0,    14,
     102,     0,   143,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    63,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    97,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   111,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   129,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     7,     8,     9,    10,     7,     8,     9,    10,     0,
      14,   109,     0,     0,    14,   125,     7,     8,     9,    10,
       7,     8,     9,    10,     0,    14,   127,     0,     0,    14,
     141,     7,     8,     9,    10,     0,     0,     0,     0,     0,
      14,    55,    56,    57,    58,    59,    60,    61
};

static const yytype_int16 yycheck[] =
{
       6,     5,    16,    21,     0,    22,    27,    22,    14,    16,
      21,    74,    30,    22,    12,    13,    14,    15,    25,     3,
       4,    44,    45,    21,     8,     9,    32,    33,    34,    27,
      47,    94,    47,    39,    40,    41,    24,    43,    47,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   119,    21,    64,    47,
      12,    13,    14,    15,    43,    44,    45,    73,    99,    21,
      74,    12,    13,    14,    15,    27,    16,    21,   109,    12,
      21,    21,    16,    21,    13,    25,    27,   118,   106,    95,
      94,    97,    16,   124,   125,   101,   127,    21,    45,    26,
     131,    25,    23,    20,    16,   111,   112,   138,    27,   140,
     141,    42,    43,    44,    45,   119,   130,    23,   149,   114,
       3,     4,    94,   129,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    22,    17,    18,    19,   145,    21,   145,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    22,    -1,    41,
      42,    43,    44,    45,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,     3,     4,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    19,    -1,    21,
      26,    -1,    24,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    27,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    12,    13,    14,    15,    12,    13,    14,    15,    -1,
      21,    22,    -1,    -1,    21,    22,    12,    13,    14,    15,
      12,    13,    14,    15,    -1,    21,    22,    -1,    -1,    21,
      22,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      21,    39,    40,    41,    42,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     8,     9,    10,    11,    12,    13,    14,
      15,    17,    18,    19,    21,    49,    50,    51,    53,    55,
      56,    57,    58,    59,    60,    61,    62,    64,    65,    66,
      57,    60,    21,    21,    21,    60,     0,    51,    27,    16,
      21,    25,    56,    16,    27,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    56,    27,    27,    60,    60,    60,    22,    60,
      60,    63,    60,    16,    21,    25,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    21,    27,    60,    27,    22,    22,
      22,    47,    26,    60,    54,    55,    57,    13,    54,    22,
      60,    27,    27,    60,    23,    52,    52,    60,    22,    47,
      56,    26,    22,    52,    22,    22,    60,    22,    60,    27,
      50,    20,    52,    55,    16,    27,    52,    52,    22,    52,
      22,    22,    60,    24,    52,    23,    52,    52,    52,    22,
      63,    52,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    52,    53,    53,    54,    54,    54,    55,    55,
      55,    55,    56,    57,    57,    57,    57,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    62,    63,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    66,
      66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     2,     3,     1,
       1,     1,     3,     6,     7,     3,     1,     0,     2,     4,
       5,     9,     1,     1,     1,     1,     1,     4,     3,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     4,     3,     1,     0,
       9,     7,     7,     7,     8,     8,     8,     6,     5,     5,
       7
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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
  case 2:
#line 61 "grammar.y"
                    { programBlock = (yyvsp[0].block);}
#line 1551 "grammar.cpp"
    break;

  case 3:
#line 64 "grammar.y"
                   { (yyval.block) = new CodeBlockNode(); (yyval.block)->statements->push_back(shared_ptr<StatementNode>((yyvsp[0].stat)));}
#line 1557 "grammar.cpp"
    break;

  case 4:
#line 65 "grammar.y"
                         { (yyval.block)->statements->push_back(shared_ptr<StatementNode>((yyvsp[0].stat)));}
#line 1563 "grammar.cpp"
    break;

  case 5:
#line 69 "grammar.y"
                                        {(yyval.stat)=(yyvsp[-1].stat);}
#line 1569 "grammar.cpp"
    break;

  case 6:
#line 70 "grammar.y"
                                        {(yyval.stat)=(yyvsp[0].stat);}
#line 1575 "grammar.cpp"
    break;

  case 7:
#line 71 "grammar.y"
                                        {(yyval.stat)=new ExpressionStatement(shared_ptr<ExpressionNode>((yyvsp[-1].expr)));}
#line 1581 "grammar.cpp"
    break;

  case 8:
#line 72 "grammar.y"
                                          {(yyval.stat)=new ReturnNode(shared_ptr<ExpressionNode>((yyvsp[-1].expr)));}
#line 1587 "grammar.cpp"
    break;

  case 10:
#line 74 "grammar.y"
                                        {(yyval.stat)=(yyvsp[0].stat);}
#line 1593 "grammar.cpp"
    break;

  case 11:
#line 75 "grammar.y"
                                        {(yyval.stat)=(yyvsp[0].stat);}
#line 1599 "grammar.cpp"
    break;

  case 12:
#line 78 "grammar.y"
                                        { (yyval.block) = (yyvsp[-1].block);}
#line 1605 "grammar.cpp"
    break;

  case 13:
#line 81 "grammar.y"
                                                             { (yyval.stat) = new FunctionDeclaration(shared_ptr<IdentifierNode>((yyvsp[-5].ident)),shared_ptr<IdentifierNode>((yyvsp[-4].ident)),shared_ptr<VariableVec>((yyvsp[-2].varvec)),shared_ptr<CodeBlockNode>((yyvsp[0].block)));}
#line 1611 "grammar.cpp"
    break;

  case 14:
#line 82 "grammar.y"
                                                                            { (yyval.stat) = new FunctionDeclaration(shared_ptr<IdentifierNode>((yyvsp[-5].ident)),shared_ptr<IdentifierNode>((yyvsp[-4].ident)),shared_ptr<VariableVec>((yyvsp[-2].varvec)),nullptr,true);}
#line 1617 "grammar.cpp"
    break;

  case 15:
#line 84 "grammar.y"
                                       {(yyval.varvec)->push_back(shared_ptr<VariableDeclaration>((yyvsp[0].var_dec)));}
#line 1623 "grammar.cpp"
    break;

  case 16:
#line 85 "grammar.y"
                        {(yyval.varvec) = new VariableVec(); (yyval.varvec)->push_back(shared_ptr<VariableDeclaration>((yyvsp[0].var_dec)));}
#line 1629 "grammar.cpp"
    break;

  case 17:
#line 86 "grammar.y"
                              {(yyval.varvec) = new VariableVec();}
#line 1635 "grammar.cpp"
    break;

  case 18:
#line 89 "grammar.y"
                                { (yyval.stat)=new VariableDeclaration(shared_ptr<IdentifierNode>((yyvsp[-1].ident)),shared_ptr<IdentifierNode>((yyvsp[0].ident)));}
#line 1641 "grammar.cpp"
    break;

  case 19:
#line 90 "grammar.y"
                                            { (yyval.stat)=new VariableDeclaration(shared_ptr<IdentifierNode>((yyvsp[-3].ident)),shared_ptr<IdentifierNode>((yyvsp[-2].ident)),shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1647 "grammar.cpp"
    break;

  case 20:
#line 91 "grammar.y"
                                                               {
                    (yyval.stat)=new ArrayInitialzation(make_shared<VariableDeclaration>(shared_ptr<IdentifierNode>((yyvsp[-4].ident)),shared_ptr<IdentifierNode>((yyvsp[-3].ident))),make_shared<ExprVec>());(yyvsp[-3].ident)->isArray=true; (yyvsp[-3].ident)->array_size = atol((yyvsp[-1].string)->c_str());
                }
#line 1655 "grammar.cpp"
    break;

  case 21:
#line 94 "grammar.y"
                                                                                                     {
                (yyval.stat)=new ArrayInitialzation(make_shared<VariableDeclaration>(shared_ptr<IdentifierNode>((yyvsp[-8].ident)),shared_ptr<IdentifierNode>((yyvsp[-7].ident))),shared_ptr<ExprVec>((yyvsp[-1].exprvec)));(yyvsp[-7].ident)->isArray=true; (yyvsp[-7].ident)->array_size = atol((yyvsp[-5].string)->c_str());
                }
#line 1663 "grammar.cpp"
    break;

  case 22:
#line 99 "grammar.y"
                                { (yyval.ident)=new IdentifierNode(*(yyvsp[0].string));cout<<"ident"<<endl; delete (yyvsp[0].string);}
#line 1669 "grammar.cpp"
    break;

  case 23:
#line 102 "grammar.y"
                        { (yyval.ident) = new IdentifierNode(*(yyvsp[0].string)); delete (yyvsp[0].string);}
#line 1675 "grammar.cpp"
    break;

  case 24:
#line 103 "grammar.y"
                            { (yyval.ident) = new IdentifierNode(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1681 "grammar.cpp"
    break;

  case 25:
#line 104 "grammar.y"
                         {(yyval.ident) = new IdentifierNode(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1687 "grammar.cpp"
    break;

  case 26:
#line 105 "grammar.y"
                          {(yyval.ident) = new IdentifierNode(*(yyvsp[0].string)); delete (yyvsp[0].string);}
#line 1693 "grammar.cpp"
    break;

  case 27:
#line 108 "grammar.y"
                                              {(yyval.elem) = new ArrayElem(shared_ptr<IdentifierNode>((yyvsp[-3].ident)), shared_ptr<ExpressionNode>((yyvsp[-1].expr))); }
#line 1699 "grammar.cpp"
    break;

  case 28:
#line 112 "grammar.y"
                                    { (yyval.expr)=new AssignmentNode(shared_ptr<IdentifierNode>((yyvsp[-2].ident)),shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1705 "grammar.cpp"
    break;

  case 29:
#line 113 "grammar.y"
                                         { (yyval.expr)=new ArrayAssignment(shared_ptr<ArrayElem>((yyvsp[-2].elem)),shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1711 "grammar.cpp"
    break;

  case 30:
#line 117 "grammar.y"
                            {(yyval.expr)=(yyvsp[0].expr); }
#line 1717 "grammar.cpp"
    break;

  case 31:
#line 118 "grammar.y"
                        {(yyval.expr)=(yyvsp[0].expr);}
#line 1723 "grammar.cpp"
    break;

  case 32:
#line 119 "grammar.y"
                        {(yyval.expr)=(yyvsp[0].ident);}
#line 1729 "grammar.cpp"
    break;

  case 33:
#line 120 "grammar.y"
                                 {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1735 "grammar.cpp"
    break;

  case 34:
#line 121 "grammar.y"
                                  {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1741 "grammar.cpp"
    break;

  case 35:
#line 122 "grammar.y"
                                 {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1747 "grammar.cpp"
    break;

  case 36:
#line 123 "grammar.y"
                                {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1753 "grammar.cpp"
    break;

  case 37:
#line 124 "grammar.y"
                                   {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1759 "grammar.cpp"
    break;

  case 38:
#line 125 "grammar.y"
                                   {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1765 "grammar.cpp"
    break;

  case 39:
#line 126 "grammar.y"
                                {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1771 "grammar.cpp"
    break;

  case 40:
#line 127 "grammar.y"
                                {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1777 "grammar.cpp"
    break;

  case 41:
#line 128 "grammar.y"
                                {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1783 "grammar.cpp"
    break;

  case 42:
#line 129 "grammar.y"
                                {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1789 "grammar.cpp"
    break;

  case 43:
#line 130 "grammar.y"
                                    {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1795 "grammar.cpp"
    break;

  case 44:
#line 131 "grammar.y"
                                   {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1801 "grammar.cpp"
    break;

  case 45:
#line 132 "grammar.y"
                                   {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1807 "grammar.cpp"
    break;

  case 46:
#line 133 "grammar.y"
                                   {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1813 "grammar.cpp"
    break;

  case 47:
#line 134 "grammar.y"
                                  {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1819 "grammar.cpp"
    break;

  case 48:
#line 135 "grammar.y"
                                       {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1825 "grammar.cpp"
    break;

  case 49:
#line 136 "grammar.y"
                                      {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1831 "grammar.cpp"
    break;

  case 50:
#line 137 "grammar.y"
                                       {(yyval.expr)=(yyvsp[-1].expr);}
#line 1837 "grammar.cpp"
    break;

  case 51:
#line 138 "grammar.y"
                           {(yyval.expr)=new LiteralNode(*(yyvsp[0].string));delete (yyvsp[0].string);}
#line 1843 "grammar.cpp"
    break;

  case 52:
#line 139 "grammar.y"
                           {(yyval.expr)=(yyvsp[0].elem);}
#line 1849 "grammar.cpp"
    break;

  case 53:
#line 140 "grammar.y"
                     {(yyval.expr)=(yyvsp[0].expr);}
#line 1855 "grammar.cpp"
    break;

  case 54:
#line 143 "grammar.y"
                          {(yyval.expr)=new IntegerNode(stoi(*(yyvsp[0].string)));delete (yyvsp[0].string);}
#line 1861 "grammar.cpp"
    break;

  case 55:
#line 144 "grammar.y"
                          {(yyval.expr)=new DoubleNode(stod(*(yyvsp[0].string)));delete (yyvsp[0].string);}
#line 1867 "grammar.cpp"
    break;

  case 56:
#line 147 "grammar.y"
                                                  {(yyval.expr)= new CallFunctionNode(shared_ptr<IdentifierNode>((yyvsp[-3].ident)),shared_ptr<ExprVec>((yyvsp[-1].exprvec)));}
#line 1873 "grammar.cpp"
    break;

  case 57:
#line 150 "grammar.y"
                                       {(yyval.exprvec)->push_back(shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1879 "grammar.cpp"
    break;

  case 58:
#line 151 "grammar.y"
                        {(yyval.exprvec)= new ExprVec();(yyval.exprvec)->push_back(shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1885 "grammar.cpp"
    break;

  case 59:
#line 152 "grammar.y"
                             {(yyval.exprvec)= new ExprVec();}
#line 1891 "grammar.cpp"
    break;

  case 60:
#line 155 "grammar.y"
                                                                                  {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),shared_ptr<ExpressionNode>((yyvsp[-6].expr)),shared_ptr<ExpressionNode>((yyvsp[-4].expr)),shared_ptr<ExpressionNode>((yyvsp[-2].expr)));}
#line 1897 "grammar.cpp"
    break;

  case 61:
#line 156 "grammar.y"
                                                                        {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),shared_ptr<ExpressionNode>((yyvsp[-4].expr)),nullptr,nullptr);}
#line 1903 "grammar.cpp"
    break;

  case 62:
#line 157 "grammar.y"
                                                                        {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),nullptr,shared_ptr<ExpressionNode>((yyvsp[-3].expr)),nullptr);}
#line 1909 "grammar.cpp"
    break;

  case 63:
#line 158 "grammar.y"
                                                                        {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),nullptr,nullptr,shared_ptr<ExpressionNode>((yyvsp[-2].expr)));}
#line 1915 "grammar.cpp"
    break;

  case 64:
#line 159 "grammar.y"
                                                                             {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),shared_ptr<ExpressionNode>((yyvsp[-5].expr)),shared_ptr<ExpressionNode>((yyvsp[-3].expr)),nullptr);}
#line 1921 "grammar.cpp"
    break;

  case 65:
#line 160 "grammar.y"
                                                                             {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),shared_ptr<ExpressionNode>((yyvsp[-5].expr)),nullptr,shared_ptr<ExpressionNode>((yyvsp[-2].expr)));}
#line 1927 "grammar.cpp"
    break;

  case 66:
#line 161 "grammar.y"
                                                                             {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),nullptr,shared_ptr<ExpressionNode>((yyvsp[-4].expr)),shared_ptr<ExpressionNode>((yyvsp[-2].expr)));}
#line 1933 "grammar.cpp"
    break;

  case 67:
#line 162 "grammar.y"
                                                                   {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),nullptr,nullptr,nullptr);}
#line 1939 "grammar.cpp"
    break;

  case 68:
#line 166 "grammar.y"
                                                  {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),nullptr,shared_ptr<ExpressionNode>((yyvsp[-2].expr)),nullptr);}
#line 1945 "grammar.cpp"
    break;

  case 69:
#line 169 "grammar.y"
                                                                  {(yyval.stat) = new IfNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)),shared_ptr<CodeBlockNode>((yyvsp[0].block)),nullptr);}
#line 1951 "grammar.cpp"
    break;

  case 70:
#line 170 "grammar.y"
                                                         {(yyval.stat) = new IfNode(shared_ptr<ExpressionNode>((yyvsp[-4].expr)),shared_ptr<CodeBlockNode>((yyvsp[-2].block)),shared_ptr<CodeBlockNode>((yyvsp[0].block)));}
#line 1957 "grammar.cpp"
    break;


#line 1961 "grammar.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp);
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
#line 173 "grammar.y"


// int main(){

//     #ifdef YYDEBUG
//       yydebug = 0;
//     #endif
//     yyparse();
//     cout<<programBlock->getNodeType()<<endl;
//     programBlock->graphGen(cout);
//     return 0;
// }
