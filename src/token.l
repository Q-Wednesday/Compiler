%{
//#include "token.h" //测试用
#include "grammar.hpp"
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


"int"           {return T_TINT;}
"double"        {return T_TDOUBLE;}
"float"         {return T_TFLOAT;}
"char"          {return T_TCHAR;}
"bool"          {return T_TBOOL;}
"void"          {return T_TVOID;}
"extern"        {return T_EXTERN;}
{IDENTIFIER}     {return T_IDENTIFIER;}
{INTEGER}         {yylval=atoi(yytext); return T_INTEGER;}
{DOUBLE}        {return T_DOUBLE;}
\"(\\.|[^"])*\"      {return T_LITERAL;}

"="             {return T_ASSIGN;}

"=="            {return T_CEQUAL;}
"!="            {return T_CNEQUAL;}
"<"             {return T_CLT;}
"<="            {return T_CLE;}
">"             {return T_CGT;}
">="            {return T_CGE;}
"("             {return T_LPAREN;}
")"             {return T_RPAREN;}
"{"             {return T_LBRACE;}
"}"             {return T_RBRACE;}
"["             {return T_LBRACKET;}
"]"             {return T_RBRACKET;}
"."             {return T_DOT;}
","             {return T_COMMA;}
"+"             {return T_PLUS;}
"-"             {return T_MINUS;}
"*"             {return T_MULT;}
"/"             {return T_DIV;}
";"             {return T_SEMICOLON;}

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