#ifndef __CODEGEN_H__
#define __CODEGEN_H__
//代码生成部分的头文件
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <map>
#include <string>
#include <memory>
#include "ASTNodes.h"
#include "grammar.hpp"

using namespace std;
using namespace llvm;

//用于存放生成过程中的代码块，该代码块表示一个作用域
class CodeGenBlock{
    public:
        BasicBlock *block;// BasicBlock是llvm中的类，表示一个代码块
        Value *returnValue;//
        map<string, Value*> locals; //属于这个作用域的变量
        map<string, shared_ptr<IdentifierNode>> types;//
        map<string, bool> isFuncArg; //一个名字是不是函数的参数
};

//该类用于存放生成代码的上下文相关的信息，
class CodeGenContext{
    private:
        bool codeGenerated = false;
        vector<CodeGenBlock *> blockStack;//代码块，用于实现作用域
    public:
        LLVMContext llvmContext;//llvm的上下文
        IRBuilder<> builder;
        unique_ptr<Module> theModule;
        map<string, Value *> globalVars;//全局变量

        CodeGenContext():builder(llvmContext){
            theModule = unique_ptr<Module>(new Module("main", this->llvmContext));
        }

        Value *getIdent(string name) const;
        Type *getTypeOf(IdentifierNode &node);

        void setSymbolValue(string name,Value* value){
            blockStack.back()->locals[name] = value;
        }
        void setSymbolType(string name,shared_ptr<IdentifierNode> type){
            blockStack.back()->types[name] = type;
        }
        void setFuncArg(string name,bool flag){
            blockStack.back()->isFuncArg[name] = flag;
        }
        void pushBlock(BasicBlock* block){
            CodeGenBlock *codeGenBlock = new CodeGenBlock();
            codeGenBlock->block = block;
            codeGenBlock->returnValue = nullptr;
            blockStack.push_back(codeGenBlock);
        }

        void popBlock(){
            auto block = blockStack.back();
            blockStack.pop_back();
            delete block;
        }

        Value* getReturnValueNow(){
            return blockStack.back()->returnValue;
        }

        void setReturnValue(Value* value){
            blockStack.back()->returnValue = value;
        }

        void generateCode(CodeBlockNode &);
        int generateObject(const string& filename);
};

#endif