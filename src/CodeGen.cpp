#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Support/raw_ostream.h>

#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/ADT/Optional.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Host.h>

#include "CodeGen.h"
#include "ASTNodes.h"
using namespace llvm;
//错误日志
std::unique_ptr<ExpressionNode> LogError(const char *str)
{
    fprintf(stderr, "LogError: %s\n", str);
    return nullptr;
}

Value *LogErrorV(string str)
{
    return LogErrorV(str.c_str());
}

Value *LogErrorV(const char *str)
{
    LogError(str);
    return nullptr;
}

static Value* ToBoolean(CodeGenContext& context, Value* termValue)
{
    if( termValue->getType()->getTypeID()==Type::IntegerTyID )
    {
        termValue = context.builder.CreateIntCast(termValue,Type::getInt1Ty(context.llvmContext),true);
        return context.builder.CreateICmpNE(termValue,ConstantInt::get(Type::getInt1Ty(context.llvmContext),0,true));
    }
    else if( termValue->getType()->getTypeID()==Type::DoubleTyID )
    {
        return context.builder.CreateFCmpONE(termValue,ConstantFP::get(context.llvmContext,APFloat(0.0)));
    }
    else
    {
        return termValue;
    }
}

//从语法树根节点生成代码主逻辑
void CodeGenContext::generateCode(CodeBlockNode &root)
{
    cout << "-----Start Generate Code-----" << endl;
    vector<Type *> sysArgs;
    FunctionType *mainFuncType = FunctionType::get(Type::getVoidTy(this->llvmContext), makeArrayRef(sysArgs), false);
    Function *mainFunc = Function::Create(mainFuncType, GlobalValue::ExternalLinkage, "main");
    BasicBlock *block = BasicBlock::Create(this->llvmContext, "entry");

    pushBlock(block);
    Value *retValue = root.codeGen(*this);
    popBlock();
    codeGenerated = true;
    cout << "-----Generation Succeed-----" << endl;
    return;
}

//生成.o输出，注意必须先调用generateCode才可以
int CodeGenContext::generateObject(const string &filename)
{
    if (!codeGenerated)
    {
        cout << "Code Not Generated!" << endl;
    }
    cout << "-----Start Generate Object-----" << endl;
    //初始化所有的目标
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto TargetTriple = sys::getDefaultTargetTriple();
    //选择目标
    std::string Error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);
    if (!Target)
    {
        errs() << Error;
        return 1;
    }

    //目标机器
    auto CPU = "generic";
    auto Features = "";

    TargetOptions opt;
    auto RM = Optional<Reloc::Model>();
    auto TargetMachine = Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    //配置模块
    theModule->setDataLayout(TargetMachine->createDataLayout());
    theModule->setTargetTriple(TargetTriple);

    std::error_code EC;
    raw_fd_ostream dest(filename, EC, sys::fs::OF_None);

    if (EC)
    {
        errs() << "Could not open file: " << EC.message();
        return 1;
    }

    legacy::PassManager pass;
    auto FileType = CGFT_ObjectFile;

    if (TargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType))
    {
        errs() << "TargetMachine can't emit a file of this type";
        return 1;
    }

    pass.run(*theModule);
    dest.flush();
    cout << "-----Code Generation Succeed-----" << endl;
    return 0;
}
// 根据标识符获取基本类型方法，暂用
Type *CodeGenContext::getTypeOf(IdentifierNode &node)
{
    string typestr = node.name;
    if (typestr == "int")
    {
        return Type::getInt32Ty(llvmContext);
    }
    if (typestr == "double")
    {
        return Type::getDoubleTy(llvmContext);
    }
    if (typestr == "void")
    {
        return Type::getVoidTy(llvmContext);
    }
    if(typestr=="string"){
        return Type::getInt8PtrTy(llvmContext);
    }
    //TODO:支持其他加入的类型以及结构体

    return nullptr;
}

//CodeGenContext的方法
Value *CodeGenContext::getIdent(string name) const
{
    for (auto it = blockStack.rbegin(); it != blockStack.rend(); ++it)
    {
        if ((*it)->locals.count(name))
        {
            return (*it)->locals[name];
        }
    }
    return nullptr;
}

//开始实现各个抽象语法树节点的代码生成
Value *DoubleNode::codeGen(CodeGenContext &context)
{
    return ConstantFP::get(Type::getDoubleTy(context.llvmContext), this->value);
}

Value *IntegerNode::codeGen(CodeGenContext &context)
{
    return ConstantInt::get(Type::getInt32Ty(context.llvmContext), this->value, true); //true表示有符号
}

Value *LiteralNode::codeGen(CodeGenContext &context)
{
    return context.builder.CreateGlobalString(this->value, "string"); //创建字符串常量
}

Value *IdentifierNode::codeGen(CodeGenContext &context)
{
    //先找变量
    auto value = context.getIdent(this->name);
    if (!value)
    {
        return LogErrorV("Unknow variable name " + this->name);
    }

    if (value->getType()->isPointerTy())
    {
        //TODO:用于支持数组
    }
    return context.builder.CreateLoad(value, false, ""); //布尔值表示是不是可变的
}

Value *AssignmentNode::codeGen(CodeGenContext &context)
{
    Value *dest = context.getIdent(this->lhs->name);
    //TODO: 支持类型检查和类型转化

    if (!dest)
    {
        return LogErrorV("Undeclared variable");
    }

    Value *expr = this->rhs->codeGen(context);

    //TODO:支持类型转换
    context.builder.CreateStore(expr, dest);
    return dest;
}

Value *VariableDeclaration::codeGen(CodeGenContext &context)
{
    //先获得类型
    auto type = context.getTypeOf(*this->type);
    Value *initial = nullptr;
    Value *instance = nullptr;
    //TODO:支持数组

    instance = context.builder.CreateAlloca(type);
    context.setSymbolType(this->ident->name, this->type);
    context.setSymbolValue(this->ident->name, instance);

    if (this->initValue)
    {
        AssignmentNode assignment(this->ident, this->initValue);
        assignment.codeGen(context);
    }
    return instance;
}

Value *ExpressionStatement::codeGen(CodeGenContext &context)
{
    return expression->codeGen(context);
}

Value *CodeBlockNode::codeGen(CodeGenContext &context)
{
    Value *back = nullptr;
    for (auto statement : *statements)
    {
        back = statement->codeGen(context);
    }
    return back;
}

Value *FunctionDeclaration::codeGen(CodeGenContext &context)
{
    vector<Type *> argsType; //存放所有形参类型

    //TODO:对参数为数组的情况作出调整
    for (auto &arg : *variables)
    {
        argsType.push_back(context.getTypeOf(*arg->type));
    }

    auto returnType = context.getTypeOf(*this->type);
    //获取函数类型
    auto functionTy = FunctionType::get(returnType, argsType, false);
    auto function = Function::Create(functionTy, GlobalValue::ExternalLinkage,
                                     funcName->name.c_str(), context.theModule.get());
    if (!isExtern)
    {
        //创建函数
        BasicBlock *basicBlock = BasicBlock::Create(context.llvmContext, "entry", function, nullptr);

        context.builder.SetInsertPoint(basicBlock);
        context.pushBlock(basicBlock);

        //把函数的形参加入到当前参数中
        auto func_arg = variables->begin(); //语法树中的表示
        for (auto &ir_arg : function->args())
        { //IR中的表示
            auto argName = (*func_arg)->ident->name;
            ir_arg.setName(argName);
            //TODO:添加对数组的支持
            auto argAlloc = (*func_arg)->codeGen(context);
            context.builder.CreateStore(&ir_arg, argAlloc, false);
            context.setSymbolValue(argName, argAlloc);
            context.setSymbolType(argName, (*func_arg)->type);
            context.setFuncArg(argName, true);
            ++func_arg; //迭代器往后移动
        }

        body->codeGen(context);
        Value *rv;
        if ((rv = context.getReturnValueNow()))
        {
            context.builder.CreateRet(rv);
        }
        else
        {
            return LogErrorV("No Return Value");
        }
        context.popBlock();
    }

    return function;
}

Value *ReturnNode::codeGen(CodeGenContext &context)
{
    Value *returnValue = expression->codeGen(context);
    context.setReturnValue(returnValue);
    return returnValue;
}

Value *BinaryOperationNode::codeGen(CodeGenContext &context)
{
    auto lhsValue = lhs->codeGen(context);
    auto rhsValue = rhs->codeGen(context);

    bool isFloat = false;
    if (lhsValue->getType()->getTypeID() == Type::DoubleTyID || rhsValue->getType()->getTypeID() == Type::DoubleTyID)
    {
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

Value *CallFunctionNode::codeGen(CodeGenContext &context)
{
    Function *calledFunc = context.theModule->getFunction(funcName->name);
    if (!calledFunc)
    {
        LogErrorV("Function name not found");
    }
    if (calledFunc->arg_size() != argv->size())
    {
        LogErrorV("Function arguments size not match");
    }
    vector<Value *> arguments;
    for (auto arg : (*argv))
    {
        arguments.push_back(arg->codeGen(context));
        if (!arguments.back())
        {
            return nullptr;
        }
    }
    return context.builder.CreateCall(calledFunc, arguments, "calltemp");
}

value *ForNode::codeGen(CodeGenContext &context)
{
    Function *calledFunc = context.builder.GetInsertBlock()->getParent();
    
    BasicBlock *block = BasicBlock::Create(context.llvmContext,"For",calledFunc);
    BasicBlock *count = BasicBlock::Create(context.llvmContext,"Forcount");
    if (this->initval){
        this->initval->codeGen(context);
    }
        
    value* termValue = this->termval->codeGen(context)
    if (!termValue)
        {
            return nullptr
        }
    termValue = ToBoolean(context,termValue);

    context.builder.CreateCondBr(termValue,block,count);
    context.builder.SetInsretPoint(block);
    context.pushBlock(block);
    this->block->codeGen(context);
    context.popBlock();

    if(this->increval){
        this->increval->codeGen(context);
    }

    termValue = this->termval->codeGen(context);
    termValue = ToBoolean(context,termValue);
    context.builder.CreateCondBr(termValue,block,count);

    calledFunc->getBasicBlockList().push_back(count);
    context.builder.SetInsertPoint(count);

    return nullptr;
}