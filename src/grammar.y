%{
#include "ASTNodes.h"
#include <stdio.h>
#include <iostream>
#include <string>

extern int yylex();
CodeBlockNode* programBlock;
void yyerror(const char* msg){
    printf("Error: %s\b",msg);
}
%}
%union
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
}

%token <string> T_TINT T_TDOUBLE T_TFLOAT T_TCHAR T_TBOOL T_TVOID T_EXTERN T_RETURN

%token <string> T_IDENTIFIER T_INTEGER T_DOUBLE T_LITERAL

%token <token>  T_ASSIGN T_CEQUAL T_CNEQUAL T_CLT T_CLE T_CGT T_CGE

%token <token>  T_LPAREN T_RPAREN  T_LBRACE T_RBRACE T_LBRACKET T_RBRACKET T_SEMICOLON

%left  <token> T_PLUS T_MINUS  //上下顺序表示优先级，left表示左结合
%left  <token> T_MULT T_DIV  
%left  <token> T_DOT T_COMMA 

%type <expr> expr assignmemt number call
%type <ident> ident typename 
%type <stat> stat var_dec func_dec
%type <block> stats program block
%type <varvec> varvec
%type <exprvec> call_args
%start program

%%
program     : stats { programBlock = $1;}
            ;
// 一直递归到第一个stat开始创建块
stats       : stat { $$ = new CodeBlockNode(); $$->statements->push_back(shared_ptr<StatementNode>($1));}
            | stats stat { $$->statements->push_back(shared_ptr<StatementNode>($2));}
            ;

stat        :   var_dec T_SEMICOLON     {$$=$1;}
            |   func_dec                {$$=$1;}
            |   expr T_SEMICOLON        {$$=new ExpressionStatement(shared_ptr<ExpressionNode>($1));}
            |   T_RETURN expr T_SEMICOLON {$$=new ReturnNode(shared_ptr<ExpressionNode>($2));}
            ;

block       :   T_LBRACE stats T_RBRACE { $$ = $2;}
            ;

func_dec    :  typename ident T_LPAREN varvec T_RPAREN block { $$ = new FunctionDeclaration(shared_ptr<IdentifierNode>($1),shared_ptr<IdentifierNode>($2),shared_ptr<VariableVec>($4),shared_ptr<CodeBlockNode>($6));}
            ;   
varvec      :   varvec T_COMMA var_dec {$$->push_back(shared_ptr<VariableDeclaration>($<var_dec>3));}
            |   var_dec {$$ = new VariableVec(); $$->push_back(shared_ptr<VariableDeclaration>($<var_dec>1));}
            |   /* nothing */ {$$ = new VariableVec();}
            ;

var_dec     :   typename ident  { $$=new VariableDeclaration(shared_ptr<IdentifierNode>($1),shared_ptr<IdentifierNode>($2));}
            |   typename ident T_ASSIGN expr{ $$=new VariableDeclaration(shared_ptr<IdentifierNode>($1),shared_ptr<IdentifierNode>($2),shared_ptr<ExpressionNode>($4));}
            ;

ident       :   T_IDENTIFIER    { $$=new IdentifierNode(*$1);cout<<"ident"<<endl; delete $1;}
            ;

typename    :   T_TINT  { $$ = new IdentifierNode(*$1);cout<<"type int"<<endl; delete $1;}
            |   T_TDOUBLE   { $$ = new IdentifierNode(*$1); delete $1; }
            ;  
assignmemt  :   ident T_ASSIGN expr { $$=new AssignmentNode(shared_ptr<IdentifierNode>($1),shared_ptr<ExpressionNode>($3));}
            ;

expr        :   assignmemt  {$$=$1; }
            |   number  {$$=$1;}
            |   expr T_PLUS expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_MINUS expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_MULT expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_DIV expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   T_LPAREN expr T_LPAREN {$$=$2;}
            |   T_LITERAL   {$$=new LiteralNode(*$1);delete $1;}
            |   call {$$=$1;}
            ;

number      :   T_INTEGER {$$=new IntegerNode(stoi(*$1));delete $1;}
            |   T_DOUBLE  {$$=new DoubleNode(stod(*$1));delete $1;}
            ;

call        :   ident T_LPAREN call_args T_RPAREN {$$= new CallFunctionNode(shared_ptr<IdentifierNode>($1),shared_ptr<ExprVec>($3));}
            ;

call_args   :   call_args T_COMMA expr {$$->push_back(shared_ptr<ExpressionNode>($3));}
            |   expr    {$$= new ExprVec();$$->push_back(shared_ptr<ExpressionNode>($1));}
            |   /* nothing*/ {$$= new ExprVec();}
            ;

%%

// int main(){

//     #ifdef YYDEBUG
//       yydebug = 0;
//     #endif
//     yyparse();
//     cout<<programBlock->getNodeType()<<endl;
//     programBlock->graphGen(cout);
//     return 0;
// }