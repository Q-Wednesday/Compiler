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
    ArrayElem* elem;
}

%token <string> T_TINT T_TDOUBLE T_TFLOAT T_TCHAR T_TBOOL T_TVOID T_TSTRING T_EXTERN T_RETURN 

%token <string> T_IDENTIFIER T_INTEGER T_DOUBLE T_LITERAL

%token <token>  T_ASSIGN T_TFOR T_TWHILE T_IF T_ELSE

%token <token>  T_LPAREN T_RPAREN  T_LBRACE T_RBRACE T_LBRACKET T_RBRACKET T_SEMICOLON

%nonassoc LOWER_THAN_ELSE
%nonassoc T_ELSE
%left  <token> T_PLUS T_MINUS  //上下顺序表示优先级，left表示左结合
%left  <token> T_MULT T_DIV  
%left  <token> T_LSHIFT T_RSHIFT
%left  <token> T_CLT T_CLE T_CGT T_CGE
%left  <token> T_CEQUAL T_CNEQUAL
%left  <token> T_BITAND
%left  <token> T_BITNOR
%left  <token> T_BITOR
%left  <token> T_LOGICALAND
%left  <token> T_LOGICALOR
%left  <token> T_DOT T_COMMA 
%left  T_ASSIGN

%type <expr> expr assignmemt number call
%type <ident> ident typename
%type <stat> stat var_dec func_dec for_stm while_stm if_stat
%type <block> stats program block
%type <varvec> varvec
%type <exprvec> call_args
%type <elem> array_elem
%start program

%%
program     : stats { programBlock = $1;}
            ;
// 一直递归到第一个stat开始创建块
stats       : stat { $$ = new CodeBlockNode(); $$->statements->push_back(shared_ptr<StatementNode>($1));}
            | stats stat { $$->statements->push_back(shared_ptr<StatementNode>($2));}
            ;
            //TODO block 是否可以嵌套？

stat        :   var_dec T_SEMICOLON     {$$=$1;}
            |   func_dec                {$$=$1;}
            |   expr T_SEMICOLON        {$$=new ExpressionStatement(shared_ptr<ExpressionNode>($1));}
            |   T_RETURN expr T_SEMICOLON {$$=new ReturnNode(shared_ptr<ExpressionNode>($2));}
            |   if_stat
            |   for_stm                 {$$=$1;}
            |   while_stm               {$$=$1;}
//            |   for_stm1
//            |   for_stm2
 //           |   for_stm3
  //          |   for_stm4
     //       |   for_stm5
  //          |   for_stm6
   //         |   for_stm7
   //         |   while_stm
   //         ;

block       :   T_LBRACE stats T_RBRACE { $$ = $2;}
            ;

func_dec    :  typename ident T_LPAREN varvec T_RPAREN block { $$ = new FunctionDeclaration(shared_ptr<IdentifierNode>($1),shared_ptr<IdentifierNode>($2),shared_ptr<VariableVec>($4),shared_ptr<CodeBlockNode>($6));}
            |  T_EXTERN typename ident T_LPAREN varvec T_RPAREN T_SEMICOLON { $$ = new FunctionDeclaration(shared_ptr<IdentifierNode>($2),shared_ptr<IdentifierNode>($3),shared_ptr<VariableVec>($5),nullptr,true);}
            ;   
varvec      :   varvec T_COMMA var_dec {$$->push_back(shared_ptr<VariableDeclaration>($<var_dec>3));}
            |   var_dec {$$ = new VariableVec(); $$->push_back(shared_ptr<VariableDeclaration>($<var_dec>1));}
            |   /* nothing */ {$$ = new VariableVec();}
            ;

var_dec     :   typename ident  { $$=new VariableDeclaration(shared_ptr<IdentifierNode>($1),shared_ptr<IdentifierNode>($2));}
            |   typename ident T_ASSIGN expr{ $$=new VariableDeclaration(shared_ptr<IdentifierNode>($1),shared_ptr<IdentifierNode>($2),shared_ptr<ExpressionNode>($4));}
            |   typename ident T_LBRACKET T_INTEGER T_RBRACKET {$$=new VariableDeclaration(shared_ptr<IdentifierNode>($1),shared_ptr<IdentifierNode>($2));$2->isArray=true; $2->array_size = atol($4->c_str()); }
            ;

ident       :   T_IDENTIFIER    { $$=new IdentifierNode(*$1);cout<<"ident"<<endl; delete $1;}
            ;

typename    :   T_TINT  { $$ = new IdentifierNode(*$1); delete $1;}
            |   T_TDOUBLE   { $$ = new IdentifierNode(*$1); delete $1; }
            |   T_TVOID  {$$ = new IdentifierNode(*$1); delete $1; }
            |   T_TSTRING {$$ = new IdentifierNode(*$1); delete $1;}
            ;  

array_elem : ident T_LBRACKET expr T_RBRACKET {$$ = new ArrayElem(shared_ptr<IdentifierNode>($1), shared_ptr<ExpressionNode>($3)); }
            ;
//TODO 仅支持ident数组，还需添加指针数组、结构体内数组、多维数组等

assignmemt  :   ident T_ASSIGN expr { $$=new AssignmentNode(shared_ptr<IdentifierNode>($1),shared_ptr<ExpressionNode>($3));}
            ;


expr        :   assignmemt  {$$=$1; }
            |   number  {$$=$1;}
            |   ident   {$$=$1;}
            |   expr T_PLUS expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_MINUS expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_MULT expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_DIV expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_RSHIFT expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_LSHIFT expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_CGE expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_CGT expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_CLE expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_CLT expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_CNEQUAL expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_CEQUAL expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_BITAND expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_BITNOR expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_BITOR expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_LOGICALAND expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   expr T_LOGICALOR expr {$$=new BinaryOperationNode(shared_ptr<ExpressionNode>($1), $2, shared_ptr<ExpressionNode>($3));}
            |   T_LPAREN expr T_RPAREN {$$=$2;}
            |   T_LITERAL  {$$=new LiteralNode(*$1);delete $1;}
            |   array_elem {$$=$1;}
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

for_stm :   T_TFOR T_LPAREN expr T_SEMICOLON expr T_SEMICOLON expr T_RPAREN block {$$ = new ForNode(shared_ptr<CodeBlockNode>($9),shared_ptr<ExpressionNode>($3),shared_ptr<ExpressionNode>($5),shared_ptr<ExpressionNode>($7));}
        |   T_TFOR T_LPAREN expr T_SEMICOLON T_SEMICOLON T_RPAREN block {$$ = new ForNode(shared_ptr<CodeBlockNode>($7),shared_ptr<ExpressionNode>($3),nullptr,nullptr);}
        |   T_TFOR T_LPAREN T_SEMICOLON expr T_SEMICOLON T_RPAREN block {$$ = new ForNode(shared_ptr<CodeBlockNode>($7),nullptr,shared_ptr<ExpressionNode>($4),nullptr);}
        |   T_TFOR T_LPAREN T_SEMICOLON T_SEMICOLON expr T_RPAREN block {$$ = new ForNode(shared_ptr<CodeBlockNode>($7),nullptr,nullptr,shared_ptr<ExpressionNode>($5));}
        |   T_TFOR T_LPAREN expr T_SEMICOLON expr T_SEMICOLON T_RPAREN block {$$ = new ForNode(shared_ptr<CodeBlockNode>($8),shared_ptr<ExpressionNode>($3),shared_ptr<ExpressionNode>($5),nullptr);}
        |   T_TFOR T_LPAREN expr T_SEMICOLON T_SEMICOLON expr T_RPAREN block {$$ = new ForNode(shared_ptr<CodeBlockNode>($8),shared_ptr<ExpressionNode>($3),nullptr,shared_ptr<ExpressionNode>($6));}
        |   T_TFOR T_LPAREN T_SEMICOLON expr T_SEMICOLON expr T_RPAREN block {$$ = new ForNode(shared_ptr<CodeBlockNode>($8),nullptr,shared_ptr<ExpressionNode>($4),shared_ptr<ExpressionNode>($6));}
        |   T_TFOR T_LPAREN T_SEMICOLON T_SEMICOLON T_RPAREN block {$$ = new ForNode(shared_ptr<CodeBlockNode>($6),nullptr,nullptr,nullptr);}
        ;


while_stm : T_TWHILE T_LPAREN expr T_RPAREN block {$$ = new ForNode(shared_ptr<CodeBlockNode>($5),nullptr,shared_ptr<ExpressionNode>($3),nullptr);}
          ;
//TODO if, while, for, etc. need to support the syntax like - if(true) dosth();
if_stat : T_IF T_LPAREN expr T_RPAREN block %prec LOWER_THAN_ELSE {$$ = new IfNode(shared_ptr<ExpressionNode>($3),shared_ptr<CodeBlockNode>($5),nullptr);}
        | T_IF T_LPAREN expr T_RPAREN block T_ELSE block {$$ = new IfNode(shared_ptr<ExpressionNode>($3),shared_ptr<CodeBlockNode>($5),shared_ptr<CodeBlockNode>($7));}
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