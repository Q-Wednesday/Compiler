//
// Created by 14032 on 2021/12/5.
//

#ifndef SRC_ASTNODES_H
#define SRC_ASTNODES_H
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class StatementNode;
class VariableDeclaration;
class ExpressionNode;
using StatementVec = vector<shared_ptr<StatementNode>>;
using VariableVec = vector<shared_ptr<VariableDeclaration>>;
using ExprVec = vector<shared_ptr<ExpressionNode>>;
//TODO: 对可视化函数进行重构，简化代码

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
};

class IdentifierNode : public ExpressionNode
{
public:
    string name;

    IdentifierNode() {}

    IdentifierNode(const string &n) : name(n) {}

    string getNodeType() const override
    {
        return "Identifier";
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
};

class LiteralNode : public ExpressionNode
{
public:
    string value;
    LiteralNode() {}
    LiteralNode(string v) : value(v) {}

    string getNodeType() const override
    {
        return "Literal";
    }
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
};

//声明变量
class VariableDeclaration : public StatementNode
{
public:
    const shared_ptr<IdentifierNode> type; //采用用户定义标识符支持结构体
    shared_ptr<IdentifierNode> name;
    shared_ptr<ExpressionNode> initValue = nullptr;

    VariableDeclaration() {}
    VariableDeclaration(const shared_ptr<IdentifierNode> type, shared_ptr<IdentifierNode> name,
                        shared_ptr<ExpressionNode> value = nullptr) : type(type), name(name), initValue(value) {}

    string getNodeType() const override
    {
        return "Variable Declaration";
    }

    void graphGen(ostream &out) const override
    {
        ASTNode::graphGen(out);
        type->graphGen(out);
        name->graphGen(out);
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(type->nodeID) << endl;
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(name->nodeID) << endl;
    }
};

//声明函数，函数就是由一系列语句组成的
class FunctionDeclaration : public StatementNode
{
public:
    shared_ptr<IdentifierNode> type;
    shared_ptr<IdentifierNode> name;
    shared_ptr<VariableVec> variables;
    shared_ptr<CodeBlockNode> body;

    FunctionDeclaration() {}
    FunctionDeclaration(shared_ptr<IdentifierNode> type, shared_ptr<IdentifierNode> name,
                        shared_ptr<VariableVec> variables, shared_ptr<CodeBlockNode> body) : type(type), name(name), variables(variables), body(body) {}

    string getNodeType() const override
    {
        return "Function declaration";
    }

    void graphGen(ostream &out) const override
    {
        ASTNode::graphGen(out);
        type->graphGen(out);
        name->graphGen(out);
        body->graphGen(out);
        //TODO: 暂时没有对变量进行处理
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(type->nodeID) << endl;
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(name->nodeID) << endl;
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(body->nodeID) << endl;
    }
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
};

//函数调用
class CallFunctionNode : public ExpressionNode
{
public:
    shared_ptr<IdentifierNode> func;
    shared_ptr<ExprVec> argv = make_shared<ExprVec>();

    CallFunctionNode() {}
    CallFunctionNode(shared_ptr<IdentifierNode> func, shared_ptr<ExprVec> argv) : func(func), argv(argv) {}
    //CallFunctionNode(shared_ptr<IdentifierNode> func) : func(func) {}

    string getNodeType() const override
    {
        return "Call Function";
    }

    void graphGen(ostream &out) const override
    {
        //TODO: 如果能确定函数id可以添加一条调用边指向函数声明处。不过这好像是CFG的需求
        ASTNode::graphGen(out);
        func->graphGen(out);
        out << "node" << to_string(nodeID)
            << "->"
            << "node" << to_string(func->nodeID) << endl;
    }
};
#endif //SRC_ASTNODES_H
