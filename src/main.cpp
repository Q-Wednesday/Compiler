#include "ASTNodes.h"
#include "grammar.hpp"
#include "CodeGen.h"
#include <fstream>
#include <string>
unsigned ASTNode::numOfNodes = 0;
extern int yyparse();
extern void yyrestart(FILE *);
extern CodeBlockNode* programBlock;
int main(int argc,char* argv[]){
  string filename = "out.o";
  FILE *f;
  for (int i = 0; i < argc;++i){
    if(strcmp(argv[i],"-o")==0){
      if(i+1<argc){
        filename = string(argv[i + 1]);
      }
    }
    if(strcmp(argv[i],"-i")==0){
      if(i+1<argc){
        f = fopen(argv[i + 1], "r");
        yyrestart(f);
      }
    }
  }

    yyparse();
    ofstream fout(filename+".dot");
    fout << "#@startdot\ndigraph AST{" << endl;
    programBlock->graphGen(fout);
    fout << "}\n#@enddot";
    fout.close();
    CodeGenContext codeGenContext;
    codeGenContext.generateCode(*programBlock);
    codeGenContext.generateObject(filename);
    return 0;
}