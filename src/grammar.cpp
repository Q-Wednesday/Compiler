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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   535

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

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
      74,    75,    76,    79,    82,    83,    85,    86,    87,    90,
      93,    98,    99,   100,   103,   106,   107,   108,   109,   110,
     113,   117,   118,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   148,   149,   152,
     155,   156,   157,   160,   161,   162,   163,   164,   165,   166,
     167,   171,   174,   175
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
  "func_dec", "varvec", "array_dec", "var_dec", "ident", "typename",
  "array_elem", "assignmemt", "expr", "number", "call", "call_args",
  "for_stm", "while_stm", "if_stat", YY_NULLPTR
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

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     436,   -65,   -65,   -65,   -65,   -65,    97,    73,   -65,   -65,
     -65,   -65,   -14,   -10,     1,    73,     4,   436,   -65,   -65,
      13,    31,     0,     2,     8,   -65,   317,   -65,   -65,   -65,
     -65,   -65,     2,   336,     5,    73,    73,   115,   -65,   -65,
     -65,   -65,    73,    73,    73,    57,    73,   -65,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    50,   -65,    49,   355,   139,
     163,   -65,   429,   429,   -17,   298,    73,    97,    -3,   429,
     444,   444,   457,   457,   468,   468,   490,   490,   490,   490,
     121,   121,   144,    71,    54,    30,   -65,    97,   108,   374,
      53,    56,    56,   -65,    73,   -65,   429,   -16,   -65,     2,
      51,   -65,   -13,    56,   187,   119,   502,   393,   436,   -65,
      63,   429,    56,    97,    65,    80,    75,   -65,    56,    56,
     211,    56,   235,   506,   302,    56,   -65,   -65,    81,    89,
     -65,   -65,   -65,    56,   -65,    56,    56,   259,   -65,   -65,
      73,   -65,   -65,   -65,    56,    -9,   -65,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    25,    26,    29,    27,    28,     0,     0,    24,    57,
      58,    54,     0,     0,     0,     0,     0,     2,     3,     7,
       0,     0,    35,     0,    55,    33,     0,    34,    56,    11,
      12,    10,     0,     0,     0,     0,     0,     0,     1,     4,
       6,     5,     0,    62,     0,    21,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,     0,     0,     0,
       0,    53,    31,    61,     0,     0,     0,    18,     0,    32,
      36,    37,    38,    39,    41,    40,    45,    44,    43,    42,
      47,    46,    48,    49,    50,    51,    52,    18,     0,     0,
       0,     0,     0,    59,     0,    30,    22,     0,    17,     0,
       0,    23,     0,     0,     0,     0,     0,     0,     0,    71,
      72,    60,     0,     0,    21,    19,     0,    70,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    16,     0,     0,
      15,    66,    65,     0,    64,     0,     0,     0,    13,    73,
      62,    69,    68,    67,     0,     0,    63,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,     6,   -15,   -18,   -65,    38,   -65,   -64,   -20,
      -5,   -65,   -65,    -7,   -65,   -65,   -12,   -65,   -65,   -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    16,    17,    18,   119,    19,   107,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    74,    29,    30,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    32,    39,    45,    38,   103,   122,    34,    37,   126,
     110,    35,    65,   108,     8,   157,    42,     8,     9,    10,
      11,    43,    36,   111,    46,    44,    15,    68,    69,    70,
     104,   123,    67,   108,   123,    72,    73,    75,   104,    79,
      40,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    41,   137,
      99,     8,     9,    10,    11,     8,     9,    10,    11,   106,
      15,    97,   109,    76,    15,    64,    98,   125,    77,   118,
     116,    76,    78,   135,   120,     8,     9,    10,    11,   124,
     138,   114,   109,   117,    15,   127,   139,   121,    63,    64,
       1,     2,   140,     3,   136,     4,     5,   111,   130,   132,
     141,   142,   150,   144,    62,    63,    64,   149,   109,    39,
       8,     9,    10,    11,   134,   151,   147,   152,   153,    15,
     113,     8,     9,    10,    11,   112,   156,    71,   155,     0,
      15,   129,     0,    73,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   101,    60,    61,    62,    63,    64,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   102,    61,    62,    63,    64,
       0,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   128,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   143,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   145,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   154,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     1,     2,     0,     3,     0,
       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
      13,    14,     0,    15,   105,     0,   148,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    47,     0,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    66,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   100,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   115,     0,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     133,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     1,
       2,     0,     3,     0,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    12,    13,    14,     0,    15,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     8,     9,    10,    11,     8,     9,
      10,    11,     0,    15,   131,     0,     0,    15,   146,    58,
      59,    60,    61,    62,    63,    64
};

static const yytype_int16 yycheck[] =
{
       7,     6,    17,    23,     0,    22,    22,    21,    15,    22,
      13,    21,    32,    77,    12,    24,    16,    12,    13,    14,
      15,    21,    21,    26,    16,    25,    21,    34,    35,    36,
      47,    47,    27,    97,    47,    42,    43,    44,    47,    46,
      27,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    27,   123,
      67,    12,    13,    14,    15,    12,    13,    14,    15,    76,
      21,    21,    77,    16,    21,    45,    27,    26,    21,    23,
      27,    16,    25,    20,   102,    12,    13,    14,    15,   109,
      25,    98,    97,   100,    21,   113,    16,   104,    44,    45,
       3,     4,    27,     6,   122,     8,     9,    26,   115,   116,
     128,   129,    23,   131,    43,    44,    45,   135,   123,   134,
      12,    13,    14,    15,   118,   143,   133,   145,   146,    21,
      22,    12,    13,    14,    15,    97,   154,    22,   150,    -1,
      21,    22,    -1,   150,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    22,    41,    42,    43,    44,    45,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    22,    42,    43,    44,    45,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,     3,     4,    -1,     6,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    19,    -1,    21,    26,    -1,    24,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,     3,
       4,    -1,     6,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    19,    -1,    21,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    12,    13,    14,    15,    12,    13,
      14,    15,    -1,    21,    22,    -1,    -1,    21,    22,    39,
      40,    41,    42,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     6,     8,     9,    10,    11,    12,    13,
      14,    15,    17,    18,    19,    21,    49,    50,    51,    53,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    65,
      66,    67,    58,    61,    21,    21,    21,    61,     0,    51,
      27,    27,    16,    21,    25,    57,    16,    27,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    57,    27,    27,    61,    61,
      61,    22,    61,    61,    64,    61,    16,    21,    25,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    21,    27,    61,
      27,    22,    22,    22,    47,    26,    61,    54,    56,    58,
      13,    26,    54,    22,    61,    27,    27,    61,    23,    52,
      52,    61,    22,    47,    57,    26,    22,    52,    22,    22,
      61,    22,    61,    27,    50,    20,    52,    56,    25,    16,
      27,    52,    52,    22,    52,    22,    22,    61,    24,    52,
      23,    52,    52,    52,    22,    64,    52,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    52,    53,    53,    54,    54,    54,    55,
      55,    56,    56,    56,    57,    58,    58,    58,    58,    58,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    63,
      64,    64,    64,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     1,     2,     3,
       1,     1,     1,     3,     6,     7,     3,     1,     0,     5,
       9,     2,     4,     4,     1,     1,     1,     1,     1,     1,
       4,     3,     3,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     4,
       3,     1,     0,     9,     7,     7,     7,     8,     8,     8,
       6,     5,     5,     7
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
                                        {(yyval.stat)=(yyvsp[-1].stat);}
#line 1575 "grammar.cpp"
    break;

  case 7:
#line 71 "grammar.y"
                                        {(yyval.stat)=(yyvsp[0].stat);}
#line 1581 "grammar.cpp"
    break;

  case 8:
#line 72 "grammar.y"
                                        {(yyval.stat)=new ExpressionStatement(shared_ptr<ExpressionNode>((yyvsp[-1].expr)));}
#line 1587 "grammar.cpp"
    break;

  case 9:
#line 73 "grammar.y"
                                          {(yyval.stat)=new ReturnNode(shared_ptr<ExpressionNode>((yyvsp[-1].expr)));}
#line 1593 "grammar.cpp"
    break;

  case 10:
#line 74 "grammar.y"
                                        {(yyval.stat)=(yyvsp[0].stat);}
#line 1599 "grammar.cpp"
    break;

  case 11:
#line 75 "grammar.y"
                                        {(yyval.stat)=(yyvsp[0].stat);}
#line 1605 "grammar.cpp"
    break;

  case 12:
#line 76 "grammar.y"
                                        {(yyval.stat)=(yyvsp[0].stat);}
#line 1611 "grammar.cpp"
    break;

  case 13:
#line 79 "grammar.y"
                                        { (yyval.block) = (yyvsp[-1].block);}
#line 1617 "grammar.cpp"
    break;

  case 14:
#line 82 "grammar.y"
                                                             { (yyval.stat) = new FunctionDeclaration(shared_ptr<IdentifierNode>((yyvsp[-5].ident)),shared_ptr<IdentifierNode>((yyvsp[-4].ident)),shared_ptr<VariableVec>((yyvsp[-2].varvec)),shared_ptr<CodeBlockNode>((yyvsp[0].block)));}
#line 1623 "grammar.cpp"
    break;

  case 15:
#line 83 "grammar.y"
                                                                            { (yyval.stat) = new FunctionDeclaration(shared_ptr<IdentifierNode>((yyvsp[-5].ident)),shared_ptr<IdentifierNode>((yyvsp[-4].ident)),shared_ptr<VariableVec>((yyvsp[-2].varvec)),nullptr,true);}
#line 1629 "grammar.cpp"
    break;

  case 16:
#line 85 "grammar.y"
                                       {(yyval.varvec)->push_back(shared_ptr<VariableDeclaration>((yyvsp[0].var_dec)));}
#line 1635 "grammar.cpp"
    break;

  case 17:
#line 86 "grammar.y"
                        {(yyval.varvec) = new VariableVec(); (yyval.varvec)->push_back(shared_ptr<VariableDeclaration>((yyvsp[0].var_dec)));}
#line 1641 "grammar.cpp"
    break;

  case 18:
#line 87 "grammar.y"
                              {(yyval.varvec) = new VariableVec();}
#line 1647 "grammar.cpp"
    break;

  case 19:
#line 90 "grammar.y"
                                                               {
                    (yyval.stat)=new ArrayInitialzation(make_shared<VariableDeclaration>(shared_ptr<IdentifierNode>((yyvsp[-4].ident)),shared_ptr<IdentifierNode>((yyvsp[-3].ident))),make_shared<ExprVec>());(yyvsp[-3].ident)->isArray=true; (yyvsp[-3].ident)->array_size = atol((yyvsp[-1].string)->c_str());
                }
#line 1655 "grammar.cpp"
    break;

  case 20:
#line 93 "grammar.y"
                                                                                                     {
                (yyval.stat)=new ArrayInitialzation(make_shared<VariableDeclaration>(shared_ptr<IdentifierNode>((yyvsp[-8].ident)),shared_ptr<IdentifierNode>((yyvsp[-7].ident))),shared_ptr<ExprVec>((yyvsp[-1].exprvec)));(yyvsp[-7].ident)->isArray=true; (yyvsp[-7].ident)->array_size = atol((yyvsp[-5].string)->c_str());
                }
#line 1663 "grammar.cpp"
    break;

  case 21:
#line 98 "grammar.y"
                                { (yyval.stat)=new VariableDeclaration(shared_ptr<IdentifierNode>((yyvsp[-1].ident)),shared_ptr<IdentifierNode>((yyvsp[0].ident)));}
#line 1669 "grammar.cpp"
    break;

  case 22:
#line 99 "grammar.y"
                                            { (yyval.stat)=new VariableDeclaration(shared_ptr<IdentifierNode>((yyvsp[-3].ident)),shared_ptr<IdentifierNode>((yyvsp[-2].ident)),shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1675 "grammar.cpp"
    break;

  case 23:
#line 100 "grammar.y"
                                                     {(yyval.stat)= (yyval.stat)=new VariableDeclaration(shared_ptr<IdentifierNode>((yyvsp[-3].ident)),shared_ptr<IdentifierNode>((yyvsp[-2].ident)));(yyvsp[-3].ident)->isArray=true;(yyvsp[-2].ident)->isArray=true;}
#line 1681 "grammar.cpp"
    break;

  case 24:
#line 103 "grammar.y"
                                { (yyval.ident)=new IdentifierNode(*(yyvsp[0].string));cout<<"ident"<<endl; delete (yyvsp[0].string);}
#line 1687 "grammar.cpp"
    break;

  case 25:
#line 106 "grammar.y"
                        { (yyval.ident) = new IdentifierNode(*(yyvsp[0].string)); delete (yyvsp[0].string);}
#line 1693 "grammar.cpp"
    break;

  case 26:
#line 107 "grammar.y"
                            { (yyval.ident) = new IdentifierNode(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1699 "grammar.cpp"
    break;

  case 27:
#line 108 "grammar.y"
                         {(yyval.ident) = new IdentifierNode(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1705 "grammar.cpp"
    break;

  case 28:
#line 109 "grammar.y"
                          {(yyval.ident) = new IdentifierNode(*(yyvsp[0].string)); delete (yyvsp[0].string);}
#line 1711 "grammar.cpp"
    break;

  case 29:
#line 110 "grammar.y"
                        {(yyval.ident) = new IdentifierNode(*(yyvsp[0].string)); delete (yyvsp[0].string);}
#line 1717 "grammar.cpp"
    break;

  case 30:
#line 113 "grammar.y"
                                              {(yyval.elem) = new ArrayElem(shared_ptr<IdentifierNode>((yyvsp[-3].ident)), shared_ptr<ExpressionNode>((yyvsp[-1].expr))); }
#line 1723 "grammar.cpp"
    break;

  case 31:
#line 117 "grammar.y"
                                    { (yyval.expr)=new AssignmentNode(shared_ptr<IdentifierNode>((yyvsp[-2].ident)),shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1729 "grammar.cpp"
    break;

  case 32:
#line 118 "grammar.y"
                                         { (yyval.expr)=new ArrayAssignment(shared_ptr<ArrayElem>((yyvsp[-2].elem)),shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1735 "grammar.cpp"
    break;

  case 33:
#line 122 "grammar.y"
                            {(yyval.expr)=(yyvsp[0].expr); }
#line 1741 "grammar.cpp"
    break;

  case 34:
#line 123 "grammar.y"
                        {(yyval.expr)=(yyvsp[0].expr);}
#line 1747 "grammar.cpp"
    break;

  case 35:
#line 124 "grammar.y"
                        {(yyval.expr)=(yyvsp[0].ident);}
#line 1753 "grammar.cpp"
    break;

  case 36:
#line 125 "grammar.y"
                                 {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1759 "grammar.cpp"
    break;

  case 37:
#line 126 "grammar.y"
                                  {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1765 "grammar.cpp"
    break;

  case 38:
#line 127 "grammar.y"
                                 {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1771 "grammar.cpp"
    break;

  case 39:
#line 128 "grammar.y"
                                {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1777 "grammar.cpp"
    break;

  case 40:
#line 129 "grammar.y"
                                   {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1783 "grammar.cpp"
    break;

  case 41:
#line 130 "grammar.y"
                                   {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1789 "grammar.cpp"
    break;

  case 42:
#line 131 "grammar.y"
                                {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1795 "grammar.cpp"
    break;

  case 43:
#line 132 "grammar.y"
                                {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1801 "grammar.cpp"
    break;

  case 44:
#line 133 "grammar.y"
                                {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1807 "grammar.cpp"
    break;

  case 45:
#line 134 "grammar.y"
                                {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1813 "grammar.cpp"
    break;

  case 46:
#line 135 "grammar.y"
                                    {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1819 "grammar.cpp"
    break;

  case 47:
#line 136 "grammar.y"
                                   {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1825 "grammar.cpp"
    break;

  case 48:
#line 137 "grammar.y"
                                   {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1831 "grammar.cpp"
    break;

  case 49:
#line 138 "grammar.y"
                                   {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1837 "grammar.cpp"
    break;

  case 50:
#line 139 "grammar.y"
                                  {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1843 "grammar.cpp"
    break;

  case 51:
#line 140 "grammar.y"
                                       {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1849 "grammar.cpp"
    break;

  case 52:
#line 141 "grammar.y"
                                      {(yyval.expr)=new BinaryOperationNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)), (yyvsp[-1].token), shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1855 "grammar.cpp"
    break;

  case 53:
#line 142 "grammar.y"
                                       {(yyval.expr)=(yyvsp[-1].expr);}
#line 1861 "grammar.cpp"
    break;

  case 54:
#line 143 "grammar.y"
                           {(yyval.expr)=new LiteralNode(*(yyvsp[0].string));delete (yyvsp[0].string);}
#line 1867 "grammar.cpp"
    break;

  case 55:
#line 144 "grammar.y"
                           {(yyval.expr)=(yyvsp[0].elem);}
#line 1873 "grammar.cpp"
    break;

  case 56:
#line 145 "grammar.y"
                     {(yyval.expr)=(yyvsp[0].expr);}
#line 1879 "grammar.cpp"
    break;

  case 57:
#line 148 "grammar.y"
                          {(yyval.expr)=new IntegerNode(stoi(*(yyvsp[0].string)));delete (yyvsp[0].string);}
#line 1885 "grammar.cpp"
    break;

  case 58:
#line 149 "grammar.y"
                          {(yyval.expr)=new DoubleNode(stod(*(yyvsp[0].string)));delete (yyvsp[0].string);}
#line 1891 "grammar.cpp"
    break;

  case 59:
#line 152 "grammar.y"
                                                  {(yyval.expr)= new CallFunctionNode(shared_ptr<IdentifierNode>((yyvsp[-3].ident)),shared_ptr<ExprVec>((yyvsp[-1].exprvec)));}
#line 1897 "grammar.cpp"
    break;

  case 60:
#line 155 "grammar.y"
                                       {(yyval.exprvec)->push_back(shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1903 "grammar.cpp"
    break;

  case 61:
#line 156 "grammar.y"
                        {(yyval.exprvec)= new ExprVec();(yyval.exprvec)->push_back(shared_ptr<ExpressionNode>((yyvsp[0].expr)));}
#line 1909 "grammar.cpp"
    break;

  case 62:
#line 157 "grammar.y"
                             {(yyval.exprvec)= new ExprVec();}
#line 1915 "grammar.cpp"
    break;

  case 63:
#line 160 "grammar.y"
                                                                                  {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),shared_ptr<ExpressionNode>((yyvsp[-6].expr)),shared_ptr<ExpressionNode>((yyvsp[-4].expr)),shared_ptr<ExpressionNode>((yyvsp[-2].expr)));}
#line 1921 "grammar.cpp"
    break;

  case 64:
#line 161 "grammar.y"
                                                                        {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),shared_ptr<ExpressionNode>((yyvsp[-4].expr)),nullptr,nullptr);}
#line 1927 "grammar.cpp"
    break;

  case 65:
#line 162 "grammar.y"
                                                                        {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),nullptr,shared_ptr<ExpressionNode>((yyvsp[-3].expr)),nullptr);}
#line 1933 "grammar.cpp"
    break;

  case 66:
#line 163 "grammar.y"
                                                                        {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),nullptr,nullptr,shared_ptr<ExpressionNode>((yyvsp[-2].expr)));}
#line 1939 "grammar.cpp"
    break;

  case 67:
#line 164 "grammar.y"
                                                                             {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),shared_ptr<ExpressionNode>((yyvsp[-5].expr)),shared_ptr<ExpressionNode>((yyvsp[-3].expr)),nullptr);}
#line 1945 "grammar.cpp"
    break;

  case 68:
#line 165 "grammar.y"
                                                                             {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),shared_ptr<ExpressionNode>((yyvsp[-5].expr)),nullptr,shared_ptr<ExpressionNode>((yyvsp[-2].expr)));}
#line 1951 "grammar.cpp"
    break;

  case 69:
#line 166 "grammar.y"
                                                                             {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),nullptr,shared_ptr<ExpressionNode>((yyvsp[-4].expr)),shared_ptr<ExpressionNode>((yyvsp[-2].expr)));}
#line 1957 "grammar.cpp"
    break;

  case 70:
#line 167 "grammar.y"
                                                                   {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),nullptr,nullptr,nullptr);}
#line 1963 "grammar.cpp"
    break;

  case 71:
#line 171 "grammar.y"
                                                  {(yyval.stat) = new ForNode(shared_ptr<CodeBlockNode>((yyvsp[0].block)),nullptr,shared_ptr<ExpressionNode>((yyvsp[-2].expr)),nullptr);}
#line 1969 "grammar.cpp"
    break;

  case 72:
#line 174 "grammar.y"
                                                                  {(yyval.stat) = new IfNode(shared_ptr<ExpressionNode>((yyvsp[-2].expr)),shared_ptr<CodeBlockNode>((yyvsp[0].block)),nullptr);}
#line 1975 "grammar.cpp"
    break;

  case 73:
#line 175 "grammar.y"
                                                         {(yyval.stat) = new IfNode(shared_ptr<ExpressionNode>((yyvsp[-4].expr)),shared_ptr<CodeBlockNode>((yyvsp[-2].block)),shared_ptr<CodeBlockNode>((yyvsp[0].block)));}
#line 1981 "grammar.cpp"
    break;


#line 1985 "grammar.cpp"

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
#line 178 "grammar.y"


// int main(){

//     #ifdef YYDEBUG
//       yydebug = 0;
//     #endif
//     yyparse();
//     cout<<programBlock->getNodeType()<<endl;
//     programBlock->graphGen(cout);
//     return 0;
// }
