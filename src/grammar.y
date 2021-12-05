%{
#include <stdio.h>
#include "ASTNodes.h"
extern "C" int yylex();
void yyerror(const char* msg){}
%}

%union{
    ExpressionNode* expr;
    StatementNode* stat;
    IdentifierNode* ident;
    std::string* string;

}
%token<string> T_TINT T_TDOUBLE T_TFLOAT T_TCHAR T_TBOOL T_TVOID T_EXTERN

%token<string> T_IDENTIFIER T_INTEGER T_DOUBLE T_LITERAL

%token  T_ASSIGN T_CEQUAL T_CNEQUAL T_CLT T_CLE T_CGT T_CGE

%token  T_LPAREN T_RPAREN  T_LBRACE T_RBRACE T_LBRACKET T_RBRACKET

%left T_PLUS T_MINUS  //上下顺序表示优先级，left表示左结合
%left T_MULT T_DIV  

%left T_DOT T_COMMA T_SEMICOLON
%%

assignmemt  :   

%%

int main(){
    return yyparse();
}