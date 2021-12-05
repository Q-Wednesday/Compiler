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
%token<string> T_TINT T_TDOUBLE T_TFLOAT T_TCHAR T_TBOOL T_TVOID T_EXTERN T_RETURN

%token<string> T_IDENTIFIER T_INTEGER T_DOUBLE T_LITERAL

%token  T_ASSIGN T_CEQUAL T_CNEQUAL T_CLT T_CLE T_CGT T_CGE

%token  T_LPAREN T_RPAREN  T_LBRACE T_RBRACE T_LBRACKET T_RBRACKET

%left T_PLUS T_MINUS  //上下顺序表示优先级，left表示左结合
%left T_MULT T_DIV  

%left T_DOT T_COMMA T_SEMICOLON

%type<expr> expr assignmemt
%type<ident> ident typename
%type<stat> stat var_dec

%%
stat        :   var_dec 
            |   expr T_SEMICOLON
            ;

var_dec     :   typename ident  { $$=new VariableDeclaration($1,$2);}
            |   typename ident T_ASSIGN expr { $$=new VariableDeclaration($1,$2,$4);}
            ;

ident       :   T_IDENTIFIER    { $$=new IdentifierNode(*$1); delete $1;}
            ;

typename    :   T_TINT  { $$ = NEW IdentifierNode(*$1); delete $1;}
            |   T_TDOUBLE   { $$ = NEW IdentifierNode(*$1); delete $1; }
            ;  
assignmemt  :   ident T_ASSIGN expr { $$=new AssignmentNode($1,$3);}
            ;

expr        :   assignmemt  {$$=$1; }
            ;
%%

int main(){
    return yyparse();
}