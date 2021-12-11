#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Support/raw_ostream.h>
#include "CodeGen.h"
#include "ASTNodes.h"
using namespace llvm;
//错误日志
std::unique_ptr<ExpressionNode> LogError(const char *str) {
    fprintf(stderr, "LogError: %s\n", str);
    return nullptr;
}

Value *LogErrorV(string str){
    return LogErrorV(str.c_str());
}

Value *LogErrorV(const char *str) {
    LogError(str);
    return nullptr;
}
// 根据标识符获取基本类型方法，暂用
Type* CodeGenContext::getTypeOf(IdentifierNode& node){
    string typestr = node.name;
    if(typestr=="int"){
        return Type::getInt32Ty(llvmContext);
    }
    if(typestr=="double"){
        return Type::getDoubleTy(llvmContext);
    }
    if(typestr=="void"){
        return Type::getVoidTy(llvmContext);
    }
    //TODO:支持其他加入的类型以及结构体

    return nullptr;
}

//CodeGenContext的方法
Value* CodeGenContext::getIdent(string name) const {
    for (auto it = blockStack.rbegin(); it != blockStack.rend();++it){
        if((*it)->locals.count(name)){
            return (*it)->locals[name];
        }
    }
    return nullptr;
}

//开始实现各个抽象语法树节点的代码生成
Value* DoubleNode::codeGen(CodeGenContext &context){
    return ConstantFP::get(Type::getDoubleTy(context.llvmContext), this->value);
}


Value* IntegerNode::codeGen(CodeGenContext& context){
    return ConstantInt::get(Type::getInt32Ty(context.llvmContext), this->value, true);//true表示有符号
}

Value* LiteralNode::codeGen(CodeGenContext& context){
    return context.builder.CreateGlobalString(this->value, "string");//创建字符串常量
}

Value* IdentifierNode::codeGen(CodeGenContext &context){
    //先找变量
    auto value = context.getIdent(this->name);
    if( !value){
        return LogErrorV("Unknow variable name " + this->name);
    }

    if(value->getType()->isPointerTy()){
        //TODO:用于支持数组
    }
    return context.builder.CreateLoad(value, false, "");//布尔值表示是不是可变的

}

Value* AssignmentNode::codeGen(CodeGenContext &context){
    Value *dest = context.getIdent(this->lhs->name);
    //TODO: 支持类型检查和类型转化

    if(!dest){
        return LogErrorV("Undeclared variable");
    }

    Value *expr = this->rhs->codeGen(context);

    //TODO:支持类型转换
    context.builder.CreateStore(expr, dest);
    return dest;
}


Value* VariableDeclaration::codeGen(CodeGenContext& context){
    //先获得类型
    auto type = context.getTypeOf(*this->type);
    Value *initial = nullptr;
    Value *instance = nullptr;
    //TODO:支持数组

    instance = context.builder.CreateAlloca(type);
    context.setSymbolType(this->ident->name, this->type);
    context.setSymbolValue(this->ident->name, instance);

    if(this->initValue){
        AssignmentNode assignment(this->ident, this->initValue);
        assignment.codeGen(context);
    }
    return instance;
}

Value* ExpressionStatement::codeGen(CodeGenContext& context){
    return expression->codeGen(context);
}

Value* CodeBlockNode::codeGen(CodeGenContext& context){
    Value *back = nullptr;
    for(auto statement:*statements){
        back = statement->codeGen(context);
    }
    return back;
}

Value* FunctionDeclaration::codeGen(CodeGenContext& context){
    vector<Type *> argsType;//存放所有形参类型

    //TODO:对参数为数组的情况作出调整
    for(auto& arg: *variables){
        argsType.push_back(context.getTypeOf(*arg->type));
    }

    auto returnType = context.getTypeOf(*this->type);
    //获取函数类型
    auto functionTy = FunctionType::get(returnType, argsType, false);
    auto function = Function::Create(functionTy, GlobalValue::ExternalLinkage, 
                    funcName->name.c_str(), context.theModule.get());
    if(!isExtern){
        //创建函数
        BasicBlock *basicBlock = BasicBlock::Create(context.llvmContext, "entry", function, nullptr);

        context.builder.SetInsertPoint(basicBlock);
        context.pushBlock(basicBlock);

        //把函数的形参加入到当前参数中
        auto func_arg = variables->begin();//语法树中的表示
        for(auto& ir_arg:function->args()){//IR中的表示
            auto argName = (*func_arg)->ident->name;
            ir_arg.setName(argName);
            //TODO:添加对数组的支持
            auto argAlloc = (*func_arg)->codeGen(context);
            context.builder.CreateStore(&ir_arg, argAlloc, false);
            context.setSymbolValue(argName, argAlloc);
            context.setSymbolType(argName, (*func_arg)->type);
            context.setFuncArg(argName, true);
            ++func_arg;//迭代器往后移动
        }

        body->codeGen(context);
        Value *rv;
        if((rv=context.getReturnValueNow())){
            context.builder.CreateRet(rv);
        }else{
            return LogErrorV("No Return Value");
        }
        context.popBlock();
    }

    return function;
}

Value* ReturnNode::codeGen(CodeGenContext & context){
    Value *returnValue = expression->codeGen(context);
    context.setReturnValue(returnValue);
    return returnValue;
}

Value* BinaryOperationNode::codeGen(CodeGenContext & context){
    auto lhsValue = lhs->codeGen(context);
    auto rhsValue = rhs->codeGen(context);

    bool isFloat = false;
    if(lhsValue->getType()->getTypeID()==Type::DoubleTyID || rhsValue->getType()->getTypeID()==Type::DoubleTyID){
        isFloat = true;
        //TODO:添加类型提升
    }
    

    switch (op)
    {
    case T_PLUS:
        return isFloat ? context.builder.CreateFAdd(lhsValue, rhsValue, "addftemp") : context.builder.CreateAdd(lhsValue, rhsValue, "addtemp");

    case T_MINUS:
        return isFloat ? context.builder.CreateFSub(lhsValue, rhsValue, "subftemp") : context.builder.CreateSub(lhsValue, rhsValue, "subtemp");
    case T_MULT:
        return isFloat ? context.builder.CreateFMul(lhsValue, rhsValue, "mulftemp") : context.builder.CreateMul(lhsValue, rhsValue, "multemp");
    case T_DIV:
        return isFloat ? context.builder.CreateFDiv(lhsValue, rhsValue, "divftemp") : context.builder.CreateSDiv(lhsValue, rhsValue, "divtemp");
    default:
        return LogErrorV("Unknown binary operator");
    }


}