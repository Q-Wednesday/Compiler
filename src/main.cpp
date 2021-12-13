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
    CodeGenContext codeGenContext;
    codeGenContext.generateCode(*programBlock);
    codeGenContext.generateObject("test.o");
    return 0;
}