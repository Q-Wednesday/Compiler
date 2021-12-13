#include "ASTNodes.h"
#include "grammar.hpp"
#include "CodeGen.h"
#include <fstream>
unsigned ASTNode::numOfNodes = 0;
extern int yyparse();
extern CodeBlockNode* programBlock;
int main(){

    #ifdef YYDEBUG
      yydebug = 0;
    #endif
    yyparse();
    ofstream fout("AST.dot");
    fout << "#@startdot\ndigraph AST{" << endl;
    programBlock->graphGen(fout);
    fout << "}\n#@enddot";
    fout.close();
    CodeGenContext codeGenContext;
    codeGenContext.generateCode(*programBlock);
    codeGenContext.generateObject("test.o");
    return 0;
}