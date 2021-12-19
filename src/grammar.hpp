/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    T_CHAR = 271,
    T_ASSIGN = 272,
    T_TFOR = 273,
    T_TWHILE = 274,
    T_IF = 275,
    T_ELSE = 276,
    T_LPAREN = 277,
    T_RPAREN = 278,
    T_LBRACE = 279,
    T_RBRACE = 280,
    T_LBRACKET = 281,
    T_RBRACKET = 282,
    T_SEMICOLON = 283,
    LOWER_THAN_ELSE = 284,
    T_LOGICALOR = 285,
    T_LOGICALAND = 286,
    T_CLT = 287,
    T_CLE = 288,
    T_CGT = 289,
    T_CGE = 290,
    T_PLUS = 291,
    T_MINUS = 292,
    T_MULT = 293,
    T_DIV = 294,
    T_LSHIFT = 295,
    T_RSHIFT = 296,
    T_CEQUAL = 297,
    T_CNEQUAL = 298,
    T_BITAND = 299,
    T_BITXOR = 300,
    T_BITOR = 301,
    T_DOT = 302,
    T_COMMA = 303
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

#line 119 "grammar.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_HPP_INCLUDED  */
