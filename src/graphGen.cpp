#include "ASTNodes.h"
#include "grammar.hpp"
#include <fstream>
unsigned ASTNode::numOfNodes = 0;
extern CodeBlockNode* programBlock;
int main(){

    #ifdef YYDEBUG
      yydebug = 1;
    #endif
    yyparse();
    ofstream fout("AST.dot");
    fout << "#@startdot\ndigraph AST{" << endl;
    programBlock->graphGen(fout);
    fout << "}\n#@enddot";
    fout.close();
    return 0;
}