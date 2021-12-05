//
// Created by 14032 on 2021/12/5.
//

#ifndef SRC_ASTNODES_H
#define SRC_ASTNODES_H
#include <iostream>

using namespace std;

//所有抽象语法树节点的基类
class ASTNode{
public:
    ASTNode(){}
    virtual string getNodeType() const =0;

};

//抽象语法树节点分为表达式和声明两类
//表达式是有返回值的，比如1+4;声明没有，比如int a;

class ExpressionNode:public ASTNode{
    public:
    ExpressionNode(){}
    string getNodeType() const override{
        return "Expression";
    }
};

class StatementNode:public ASTNode{
    public:
    StatementNode(){};
    string getNodeType() const override{
        return "Statement";
    }
};

class IdentifierNode:public ExpressionNode{
    public:
        string name;

        IdentifierNode(){}

        IdentifierNode(const string& n):name(n){}

        string getNodeType()const override{
            return "Identifier";
        }
};

class DoubleNode:public ExpressionNode{
public:
    double value;

    DoubleNode() {};

    DoubleNode(double v):value(v){}

    string getNodeType()const override{
        return "Double";
    }
};

class IntegerNode:public ExpressionNode{
    public:
        int value;
        IntegerNode() {};
        IntegerNode(int v):value(v){}

        string getNodeType()const override{
            return "Integer";
        }
}


#endif //SRC_ASTNODES_H
