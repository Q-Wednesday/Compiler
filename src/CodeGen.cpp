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

static Value *ToBoolean(CodeGenContext &context, Value *termValue)
{
    if (termValue->getType()->getTypeID() == Type::IntegerTyID)
    {
        termValue = context.builder.CreateIntCast(termValue, Type::getInt32Ty(context.llvmContext), true);
        return context.builder.CreateICmpNE(termValue, ConstantInt::get(Type::getInt32Ty(context.llvmContext), 0, true));
    }
    else if (termValue->getType()->getTypeID() == Type::DoubleTyID)
    {
        return context.builder.CreateFCmpONE(termValue, ConstantFP::get(context.llvmContext, APFloat(0.0)));
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
    cout << 1 << endl;
    auto TargetTriple = sys::getDefaultTargetTriple();
    //选择目标
    std::string Error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);
    if (!Target)
    {
        errs() << Error;
        return 1;
    }

    cout << 2 << endl;
    //目标机器
    auto CPU = "generic";
    auto Features = "";

    TargetOptions opt;
    auto RM = Optional<Reloc::Model>();
    auto TargetMachine = Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    cout << 3 << endl;

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
    cout << 4 << endl;
    legacy::PassManager pass;
    auto FileType = CGFT_ObjectFile;

    if (TargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType))
    {
        errs() << "TargetMachine can't emit a file of this type";
        return 1;
    }
    cout << 5 << endl;
    pass.run(*theModule);
    cout << 6 << endl;
    dest.flush();
    cout << "-----Code Generation Succeed-----" << endl;
    return 0;
}
// 根据标识符获取基本类型方法，暂用
Type *CodeGenContext::getTypeOf(const IdentifierNode &node)
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
    if (typestr == "string")
    {
        return Type::getInt8PtrTy(llvmContext);
    }
    if(typestr=="char"){
        return Type::getInt8Ty(llvmContext);
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
shared_ptr<IdentifierNode> CodeGenContext::getSymbolType(string name) const
{
    for (auto it = blockStack.rbegin(); it != blockStack.rend(); ++it)
    {
        if ((*it)->types.count(name))
        {
            return (*it)->types[name];
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
        auto arrayPtr = context.builder.CreateLoad(value, "arrayPtr");
        if(arrayPtr->getType()->isArrayTy()){
            cout << "Ident is  array";
            vector<Value*> indices;
            indices.push_back(ConstantInt::get(Type::getInt32Ty(context.llvmContext), 0, false));
            auto ptr = context.builder.CreateInBoundsGEP(value, indices, "arrayPtr");
            return ptr;
        }
        
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
    auto Ttype = context.getTypeOf(*this->type);
    Value *initial = nullptr;
    Value *instance = nullptr;

    if (this->ident->isArray)
    {
        if (this->ident->array_size <= 0)
            return LogErrorV("declared an array with nonpositive size");
        this->type->isArray = true;
        this->type->array_size = this->ident->array_size;
        Value *V_array_size = IntegerNode(this->ident->array_size).codeGen(context);
        auto arrayType = ArrayType::get(Ttype, this->ident->array_size);
        instance = context.builder.CreateAlloca(arrayType, V_array_size, "arraytmp");
    }
    else
        instance = context.builder.CreateAlloca(Ttype);

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
    cout << "Gen Func dec" << endl;
    vector<Type *> argsType; //存放所有形参类型

    for (auto &arg : *variables)
    { 
        if(arg->type==nullptr){
                cout << "no null" << endl;
        }
        if(arg->type->isArray){
           
            argsType.push_back(PointerType::get(context.getTypeOf(*arg->type), 0));
            
        }else{
            argsType.push_back(context.getTypeOf(*arg->type));
        }
        
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
            

            Value *argAlloc;
            if((*func_arg)->type->isArray)
                argAlloc = context.builder.CreateAlloca(PointerType::get(context.getTypeOf(*(*func_arg)->type), 0));
            else
                argAlloc = (*func_arg)->codeGen(context);
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
            LogErrorV("No Return Value");
        }
        context.popBlock();
    }

    cout << "Gen Func dec end" << endl;
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
    case T_RSHIFT:
        return isFloat ? LogErrorV("invalid operands to >>") : context.builder.CreateAShr(lhsValue, rhsValue, "ashrtemp"); //TODO 支持无符号数
    case T_LSHIFT:
        return isFloat ? LogErrorV("invalid operands to <<") : context.builder.CreateShl(lhsValue, rhsValue, "ashltemp");
    case T_CGE:
        return isFloat ? context.builder.CreateFCmpOGE(lhsValue, rhsValue, "geftemp") : context.builder.CreateICmpSGE(lhsValue, rhsValue, "getemp"); //TODO 支持无符号数
    case T_CGT:
        return isFloat ? context.builder.CreateFCmpOGT(lhsValue, rhsValue, "gtftemp") : context.builder.CreateICmpSGT(lhsValue, rhsValue, "gttemp");
    case T_CLE:
        return isFloat ? context.builder.CreateFCmpOLE(lhsValue, rhsValue, "leftemp") : context.builder.CreateICmpSLE(lhsValue, rhsValue, "letemp");
    case T_CLT:
        return isFloat ? context.builder.CreateFCmpOLT(lhsValue, rhsValue, "ltftemp") : context.builder.CreateICmpSLT(lhsValue, rhsValue, "lttemp");
    case T_CNEQUAL:
        return isFloat ? context.builder.CreateFCmpONE(lhsValue, rhsValue, "neftemp") : context.builder.CreateICmpNE(lhsValue, rhsValue, "netemp");
    case T_CEQUAL:
        return isFloat ? context.builder.CreateFCmpOEQ(lhsValue, rhsValue, "eqftemp") : context.builder.CreateICmpEQ(lhsValue, rhsValue, "eqtemp");
    case T_BITAND:
        return isFloat ? LogErrorV("invalid operands to &") : context.builder.CreateAnd(lhsValue, rhsValue, "andtemp");
    case T_BITXOR:
        return isFloat ? LogErrorV("invalid operands to ^") : context.builder.CreateXor(lhsValue, rhsValue, "xortemp");
    case T_BITOR:
        return isFloat ? LogErrorV("invalid operands to |") : context.builder.CreateOr(lhsValue, rhsValue, "oetemp");
    case T_LOGICALAND:
        return isFloat ? LogErrorV("invalid operands to &&") : context.builder.CreateLogicalAnd(lhsValue, rhsValue, "logicalandtemp");
    case T_LOGICALOR:
        return isFloat ? LogErrorV("invalid operands to ||") : context.builder.CreateLogicalOr(lhsValue, rhsValue, "logicalortemp");
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

Value *ForNode::codeGen(CodeGenContext &context)
{
    Function *calledFunc = context.builder.GetInsertBlock()->getParent();

    BasicBlock *block = BasicBlock::Create(context.llvmContext, "For", calledFunc);
    BasicBlock *count = BasicBlock::Create(context.llvmContext, "Forcount");
    if (this->initval)
    {
        this->initval->codeGen(context);
    }

    Value *termValue = this->termval->codeGen(context);
    if (!termValue)
    {
        return nullptr;
    }
    termValue = ToBoolean(context, termValue);

    context.builder.CreateCondBr(termValue, block, count);
    context.builder.SetInsertPoint(block);
    context.pushBlock(block);
    this->block->codeGen(context);
    context.popBlock();

    if (this->increval)
    {
        this->increval->codeGen(context);
    }

    termValue = this->termval->codeGen(context);
    termValue = ToBoolean(context, termValue);
    context.builder.CreateCondBr(termValue, block, count);

    calledFunc->getBasicBlockList().push_back(count);
    context.builder.SetInsertPoint(count);

    return nullptr;
}

Value *IfNode::codeGen(CodeGenContext &context)
{
    //cout << "IfNode gen start" << endl;

    Value *CondV = cond->codeGen(context);
    if (!CondV)
        return nullptr;

    CondV = ToBoolean(context, CondV);

    Function *calledFunc = context.builder.GetInsertBlock()->getParent();

    BasicBlock *then_bb = BasicBlock::Create(context.llvmContext, "then", calledFunc);
    BasicBlock *else_bb = BasicBlock::Create(context.llvmContext, "else");
    BasicBlock *merge_bb = BasicBlock::Create(context.llvmContext, "ifcont");

    if(unmatched_block){
        context.builder.CreateCondBr(CondV, then_bb, else_bb);
    }else{
        context.builder.CreateCondBr(CondV, then_bb, merge_bb);
    }
    

    context.builder.SetInsertPoint(then_bb);

    context.pushBlock(then_bb);

    Value *ThenV = matched_block->codeGen(context);
    if (!ThenV)
        return nullptr;

    context.popBlock();

    
    then_bb = context.builder.GetInsertBlock();

    if(then_bb->getTerminator()==nullptr){
        context.builder.CreateBr(merge_bb);
    }

    if(unmatched_block){
        calledFunc->getBasicBlockList().push_back(else_bb);
        context.builder.SetInsertPoint(else_bb);
        context.pushBlock(else_bb);
        Value *ElseV = unmatched_block->codeGen(context);
        if (!ElseV)
            return nullptr;

        context.popBlock();
        context.builder.CreateBr(merge_bb);
    }
    calledFunc->getBasicBlockList().push_back(merge_bb);
    context.builder.SetInsertPoint(merge_bb);
    //cout << "IfNode gen end" << endl;
    return nullptr;
}

Value *ArrayElem::codeGen(CodeGenContext &context)
{
    cout << "Gen ArrayElem" << endl;
    cout << "array elem: array name " << array->name<<endl;
    //<< " index:" << dynamic_pointer_cast<IntegerNode>(index_expr)->value << endl;
    auto array_ptr = context.getIdent(this->array->name);
    auto array_type = context.getSymbolType(this->array->name);
    assert(array_type->isArray);
    auto V_array_size = IntegerNode(array_type->array_size).codeGen(context);
    auto value = index_expr->codeGen(context);
    ArrayRef<Value *> indices;
    if(context.isFuncArg(array->name)){
        cout << "array is func arg" << endl;
        array_ptr=context.builder.CreateLoad(array_ptr, "actualArrayPtr");
        indices= value ;
    }
    else if (array_ptr->getType()->isPointerTy())
    {
        cout << "not func arg" << endl;
        indices = {ConstantInt ::get(Type::getInt64Ty(context.llvmContext), 0), value};
    }else{
        return LogErrorV("The variable is not array");
    }
    auto ptr = context.builder.CreateInBoundsGEP(array_ptr, indices, "arrayelem");
    
    auto v=context.builder.CreateAlignedLoad(ptr, MaybeAlign(4));
    cout << "Gen ArrayElem end" << endl;
    return v;
}


Value* ArrayAssignment::codeGen(CodeGenContext& context){
    cout << "Gen Array Assignment" << endl;
    auto ptr = context.getIdent(arrayElem->array->name);

    if(ptr==nullptr){
        return LogErrorV("Unknown Array");
    }

    auto arrayPtr = context.builder.CreateLoad(ptr, "arrayPtr");

    if( !arrayPtr->getType()->isArrayTy() && !arrayPtr->getType()->isPointerTy() ){
        return LogErrorV("The variable is not array");
    }

    auto index = arrayElem->index_expr->codeGen(context);
    ArrayRef<Value *> gep;
    if(context.isFuncArg(arrayElem->array->name)){
        cout << "is func arg" << endl;
        gep = index;
    }else{
        gep={ConstantInt::get(Type::getInt64Ty(context.llvmContext), 0), index};
    }
   

    auto ptr2elem=context.builder.CreateInBoundsGEP(ptr, gep, "elementPtr");
    cout << "Array Assignment End" << endl;
    return context.builder.CreateAlignedStore(expr->codeGen(context), ptr2elem, MaybeAlign(4));

}

Value* ArrayInitialzation::codeGen(CodeGenContext& context){
    auto arrayPtr = decl->codeGen(context);
    auto arraySize = decl->ident->array_size;

    for (int index = 0; index < exprVec->size();++index){
        cout << "index: " << index << endl;
        auto indexValue = make_shared<IntegerNode>(index);
        auto arrayElem = make_shared<ArrayElem>(decl->ident, indexValue);
        ArrayAssignment assignment(arrayElem, exprVec->at(index));
        assignment.codeGen(context);
    }
    return nullptr;
}