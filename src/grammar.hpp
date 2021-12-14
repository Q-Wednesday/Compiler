/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 142 "grammar.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

