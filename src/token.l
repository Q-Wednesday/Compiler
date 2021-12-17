%{
//#include "token.h" //测试用
#include "ASTNodes.h"
#include "grammar.hpp"
#include <string>
//SAVE_TOKEN保存了所有之后在构建语法树的时候要用到匹配到的字符串的token
#define SAVE_TOKEN printf("%s\n",yytext);yylval.string = new string(yytext)
//MAKE_TOKEN仅仅保存token的值
#define MAKE_TOKEN(t) (yylval.token = t)
%}
%option noyywrap

INTEGER         ([0-9]+)
DOUBLE          ([0-9]+\.[0-9]*)
LITERAL         (\"(\\.|[^"])*\" )
IDENTIFIER      ([_a-zA-Z][_a-zA-Z0-9]*)
COMMENT         ("//"[^\n]*)

%%

[ \n\t\r]       { /* space */}
{COMMENT}       {}


"int"           {SAVE_TOKEN; return T_TINT;}
"double"        {SAVE_TOKEN; return T_TDOUBLE;}
"float"         {SAVE_TOKEN; return T_TFLOAT;}
"char"          {SAVE_TOKEN; return T_TCHAR;}
"string"        {SAVE_TOKEN; return T_TSTRING;}
"bool"          {SAVE_TOKEN; return T_TBOOL;}
"void"          {SAVE_TOKEN; return T_TVOID;}
"if"            {SAVE_TOKEN; return T_IF;}
"else"          {SAVE_TOKEN; return T_ELSE;}
"for"           {SAVE_TOKEN; return T_TFOR;}
"while"         {SAVE_TOKEN; return T_TWHILE;}
"extern"        {SAVE_TOKEN; return T_EXTERN;}
"return"        {SAVE_TOKEN; return T_RETURN;}
{IDENTIFIER}    {SAVE_TOKEN; return T_IDENTIFIER;}
{INTEGER}       {SAVE_TOKEN; return T_INTEGER;}
{DOUBLE}        {SAVE_TOKEN; return T_DOUBLE;}
\"(\\.|[^"])*\"      {SAVE_TOKEN; return T_LITERAL;}

"="             {printf("T_ASSIGN\n");return MAKE_TOKEN(T_ASSIGN);}

"=="            {return MAKE_TOKEN(T_CEQUAL);}
"!="            {return MAKE_TOKEN(T_CNEQUAL);}
"<"             {return MAKE_TOKEN(T_CLT);}
"<="            {return MAKE_TOKEN(T_CLE);}
">"             {return MAKE_TOKEN(T_CGT);}
">="            {return MAKE_TOKEN(T_CGE);}
"("             {return MAKE_TOKEN(T_LPAREN);}
")"             {return MAKE_TOKEN(T_RPAREN);}
"{"             {return MAKE_TOKEN(T_LBRACE);}
"}"             {return MAKE_TOKEN(T_RBRACE);}
"["             {return MAKE_TOKEN(T_LBRACKET);}
"]"             {return MAKE_TOKEN(T_RBRACKET);}
"."             {return MAKE_TOKEN(T_DOT);}
","             {return MAKE_TOKEN(T_COMMA);}
"+"             {return MAKE_TOKEN(T_PLUS);}
"-"             {return MAKE_TOKEN(T_MINUS);}
"*"             {return MAKE_TOKEN(T_MULT);}
"/"             {return MAKE_TOKEN(T_DIV);}
";"             {return MAKE_TOKEN(T_SEMICOLON);}
"&"             {return MAKE_TOKEN(T_BITAND);}
"&&"            {return MAKE_TOKEN(T_LOGICALAND);}
"|"             {return MAKE_TOKEN(T_BITOR);}
"||"            {return MAKE_TOKEN(T_LOGICALOR);}
"^"             {return MAKE_TOKEN(T_BITNOR);}
"<<"            {return MAKE_TOKEN(T_LSHIFT);}
">>"            {return MAKE_TOKEN(T_RSHIFT);}

%%
// int main(){
//     int token;
//     int counter=0;
//     while(token=yylex()){
//         counter++;
        
//         printf("%d:",token);
//         puts(yytext);
//         printf("\n");
//     }
//     printf("\n num of token:%d",counter);
//     return 0;
// }