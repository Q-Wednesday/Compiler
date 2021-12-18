//
// Created by Q-Wednesday on 2021/12/5.
//

#ifndef SRC_ASTNODES_H
#define SRC_ASTNODES_H

#include <llvm/IR/Value.h>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;
using namespace llvm;

class StatementNode;
class VariableDeclaration;
class ExpressionNode;
using StatementVec = vector<shared_ptr<StatementNode>>;
using VariableVec = vector<shared_ptr<VariableDeclaration>>;
using ExprVec = vector<shared_ptr<ExpressionNode>>;
//TODO: 对可视化函数进行重构，简化代码

class CodeGenContext;

//所有抽象语法树节点的基类
class ASTNode
{
public:
    unsigned nodeID;
    static unsigned numOfNodes;
    ASTNode()
    {
        nodeID = ++numOfNodes;
    }
    virtual string getNodeType() const = 0;
    virtual void graphGen(ostream &out) const
    {
        out << "node" << to_string(nodeID)
            << "[label=\"" << getNodeType() << "\"]" << endl;
    }
    virtual Value *codeGen(CodeGenContext &)
    {
        return nullptr;
    }
};

//抽象语法树节点分为表达式和声明两类
//表达式是有返回值的，比如1+4;声明没有，比如int a;

class ExpressionNode : public ASTNode
{
public:
    ExpressionNode() {}
    string getNodeType() const override
    {
        return "Expression";
    }
};

class StatementNode : public ASTNode
{
public:
    StatementNode(){};
    string getNodeType() const override
    {
        return "Statement";
    }
};

class ExpressionStatement : public StatementNode
{
public:
    shared_ptr<ExpressionNode> expression;
    ExpressionStatement() {}
    ExpressionStatement(shared_ptr<ExpressionNode> expr) : expression(expr) {}
    string getNodeType() const override
    {
        return "Expression Statement";
    }
    void graphGen(ostream &out) const override
    {
        ASTNode::graphGen(out);
        expression->graphGen(out);
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(expression->nodeID) << endl;
    }

    Value *codeGen(CodeGenContext &) override;
};

class CodeBlockNode : public ExpressionNode
{
public:
    shared_ptr<StatementVec> statements = make_shared<StatementVec>();
    CodeBlockNode() {}
    string getNodeType() const override
    {
        return "Code Block";
    }

    void graphGen(ostream &out) const override
    {
        ASTNode::graphGen(out);
        for (auto state : *statements)
        {
            state->graphGen(out);
            out << "node" << to_string(nodeID)
                << "->"
                << "node" << to_string(state->nodeID) << endl;
        }
    }
    Value *codeGen(CodeGenContext &) override;
};

class IdentifierNode : public ExpressionNode
{
public:
    string name;
    bool isArray = false;
    int array_size = 0;

    IdentifierNode() {}

    IdentifierNode(const string &n) : name(n) {}

    string getNodeType() const override
    {
        return "Identifier";
    }
    Value *codeGen(CodeGenContext &context) override;
};

class ArrayElem : public ExpressionNode
{
public:
    shared_ptr<IdentifierNode> array;
    shared_ptr<ExpressionNode> index_expr;

    ArrayElem() {}

    ArrayElem(shared_ptr<IdentifierNode> array_in, shared_ptr<ExpressionNode> index_expr_in)
        : array(array_in), index_expr(index_expr_in) {}

    string getNodeType() const override
    {
        return "ArrayElem";
    }
};

class DoubleNode : public ExpressionNode
{
public:
    double value;

    DoubleNode(){};

    DoubleNode(double v) : value(v) {}

    string getNodeType() const override
    {
        return "Double";
    }

    Value *codeGen(CodeGenContext &context) override;
};

class IntegerNode : public ExpressionNode
{
public:
    int value;
    IntegerNode() {}
    IntegerNode(int v) : value(v) {}

    string getNodeType() const override
    {
        return "Integer";
    }
    Value *codeGen(CodeGenContext &context) override;
};

class LiteralNode : public ExpressionNode
{
public:
    string value;
    LiteralNode() {}
    LiteralNode(string v) : value(v.begin() + 1, v.end() - 1) {}

    string getNodeType() const override
    {
        return "Literal";
    }
    Value *codeGen(CodeGenContext &context) override;
};
//赋值语句
class AssignmentNode : public ExpressionNode
{
public:
    shared_ptr<IdentifierNode> lhs;
    shared_ptr<ExpressionNode> rhs;

    AssignmentNode() {}
    AssignmentNode(shared_ptr<IdentifierNode> l, shared_ptr<ExpressionNode> r) : lhs(l), rhs(r) {}

    string getNodeType() const override
    {
        return "Assignment";
    }

    void graphGen(ostream &out) const override
    {
        ASTNode::graphGen(out);
        lhs->graphGen(out);
        rhs->graphGen(out);
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(lhs->nodeID) << endl;
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(rhs->nodeID) << endl;
    }
    Value *codeGen(CodeGenContext &context) override;
};

//声明变量
class VariableDeclaration : public StatementNode
{
public:
    const shared_ptr<IdentifierNode> type; //采用用户定义标识符支持结构体
    shared_ptr<IdentifierNode> ident;
    shared_ptr<ExpressionNode> initValue = nullptr;

    VariableDeclaration() {}
    VariableDeclaration(const shared_ptr<IdentifierNode> type, shared_ptr<IdentifierNode> name,
                        shared_ptr<ExpressionNode> value = nullptr) : type(type), ident(name), initValue(value) {}

    string getNodeType() const override
    {
        return "Variable Declaration";
    }

    void graphGen(ostream &out) const override
    {
        ASTNode::graphGen(out);
        type->graphGen(out);
        ident->graphGen(out);
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(type->nodeID) << endl;
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(ident->nodeID) << endl;
    }

    Value *codeGen(CodeGenContext &) override;
};

//声明函数，函数就是由一系列语句组成的
class FunctionDeclaration : public StatementNode
{
public:
    shared_ptr<IdentifierNode> type;
    shared_ptr<IdentifierNode> funcName;
    shared_ptr<VariableVec> variables;
    shared_ptr<CodeBlockNode> body;
    bool isExtern;
    FunctionDeclaration() {}
    FunctionDeclaration(shared_ptr<IdentifierNode> type, shared_ptr<IdentifierNode> name,
                        shared_ptr<VariableVec> variables, shared_ptr<CodeBlockNode> body,
                        bool isExtern = false) : type(type), funcName(name), variables(variables), body(body), isExtern(isExtern) {}

    string getNodeType() const override
    {
        return "Function declaration";
    }

    void graphGen(ostream &out) const override
    {
        ASTNode::graphGen(out);
        type->graphGen(out);
        funcName->graphGen(out);
        if (body)
        {
            body->graphGen(out);
            out << "node" << to_string(nodeID)
                << "->"
                << "node" << to_string(body->nodeID) << endl;
        }

        //TODO: 暂时没有对变量进行处理
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(type->nodeID) << endl;
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(funcName->nodeID) << endl;
    }

    Value *codeGen(CodeGenContext &) override;
};

// return语句
class ReturnNode : public StatementNode
{
public:
    shared_ptr<ExpressionNode> expression;
    ReturnNode() {}
    ReturnNode(shared_ptr<ExpressionNode> expr) : expression(expr) {}

    string getNodeType() const override
    {
        return "Return";
    }
    Value *codeGen(CodeGenContext &) override;
};

// 二元运算
class BinaryOperationNode : public ExpressionNode
{
public:
    shared_ptr<ExpressionNode> lhs;
    shared_ptr<ExpressionNode> rhs;
    int op;

    BinaryOperationNode() {}
    BinaryOperationNode(shared_ptr<ExpressionNode> lhs, int op, shared_ptr<ExpressionNode> rhs) : lhs(lhs), op(op), rhs(rhs) {}

    string getNodeType() const override
    {
        return "Binary Op";
    }

    void graphGen(ostream &out) const override
    {
        ASTNode::graphGen(out);
        lhs->graphGen(out);
        rhs->graphGen(out);
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(lhs->nodeID) << endl;
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(rhs->nodeID) << endl;
    }
    Value *codeGen(CodeGenContext &) override;
};

//函数调用
class CallFunctionNode : public ExpressionNode
{
public:
    shared_ptr<IdentifierNode> funcName;
    shared_ptr<ExprVec> argv = make_shared<ExprVec>();

    CallFunctionNode() {}
    CallFunctionNode(shared_ptr<IdentifierNode> funcName, shared_ptr<ExprVec> argv) : funcName(funcName), argv(argv) {}
    //CallFunctionNode(shared_ptr<IdentifierNode> func) : func(func) {}

    string getNodeType() const override
    {
        return "Call Function";
    }

    void graphGen(ostream &out) const override
    {
        //TODO: 如果能确定函数id可以添加一条调用边指向函数声明处。不过这好像是CFG的需求
        ASTNode::graphGen(out);
        funcName->graphGen(out);
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(funcName->nodeID) << endl;
    }
    Value *codeGen(CodeGenContext &) override;
};
// for 语句 for(initval;termval;increval)
class ForNode : public StatementNode
{
public:
    shared_ptr<CodeBlockNode> block;
    shared_ptr<ExpressionNode> initval, termval, increval;

    ForNode(shared_ptr<CodeBlockNode> bin, shared_ptr<ExpressionNode> initin = nullptr, shared_ptr<ExpressionNode> termin = nullptr, shared_ptr<ExpressionNode> increin = nullptr)
        : block(bin), initval(initin), termval(termin), increval(increin)
    {

        if (initval == nullptr) //一直跑下去
        {
            initval = make_shared<IntegerNode>(1);
        }

        if (termval == nullptr) //一直跑下去
        {
            termval = make_shared<IntegerNode>(1);
        }

        if (increval == nullptr) //一直跑下去
        {
            increval = make_shared<IntegerNode>(1);
        }
    }

    string getNodeType() const override
    {
        return "ForNode";
    }

    void graphGen(ostream &out) const override
    {
        ASTNode::graphGen(out);
        if (initval != nullptr)
        {
            initval->graphGen(out);
            out << "node" << to_string(nodeID)
                << "->"
                << "node" << to_string(initval->nodeID) << endl;
        }
        if (termval != nullptr)
        {
            termval->graphGen(out);
            out << "node" << to_string(nodeID)
                << "->"
                << "node" << to_string(termval->nodeID) << endl;
        }
        if (increval != nullptr)
        {
            increval->graphGen(out);
            out << "node" << to_string(nodeID)
                << "->"
                << "node" << to_string(increval->nodeID) << endl;
        }
        block->graphGen(out);
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(block->nodeID) << endl;
    }
    Value *codeGen(CodeGenContext &) override;
};
// if 语句 if(cond) block
class IfNode : public StatementNode
{
public:
    shared_ptr<CodeBlockNode> matched_block, unmatched_block;
    shared_ptr<ExpressionNode> cond;

    IfNode(shared_ptr<ExpressionNode> cond_in, shared_ptr<CodeBlockNode> matched_block_in, shared_ptr<CodeBlockNode> unmatched_block_in = nullptr)
        : matched_block(matched_block_in), unmatched_block(unmatched_block_in), cond(cond_in) {}

    string getNodeType() const override
    {
        return "IfNode";
    }

    void graphGen(ostream &out) const override
    {
        ASTNode::graphGen(out);
        cond->graphGen(out);
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(cond->nodeID) << endl;
        matched_block->graphGen(out);
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(matched_block->nodeID) << endl;
        if (unmatched_block != nullptr)
        {
            unmatched_block->graphGen(out);
            out << "node" << to_string(nodeID)
                << "->"
                << "node" << to_string(unmatched_block->nodeID) << endl;
        }
    }
    Value *codeGen(CodeGenContext &) override;
};

#endif //SRC_ASTNODES_H
