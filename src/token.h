#ifndef TOKEN_H
#define TOKEN_H
//T_T表示类型token,T_C表示比较运算符token,T_L/T_R是左括号或者右括号
enum Token
{
    T_TINT = 256,
    T_TDOUBLE,
    T_TFLOAT,
    T_TCHAR,
    T_TBOOL,
    T_TVOID,
    T_EXTERN,
    T_RETURN,
    T_IDENTIFIER,
    T_INTEGER,
    T_DOUBLE,
    T_LITERAL,
    T_ASSIGN,
    T_CEQUAL,
    T_CNEQUAL,
    T_CLT,
    T_CLE,
    T_CGT,
    T_CGE,
    T_LPAREN,
    T_RPAREN,
    T_LBRACE,
    T_RBRACE,
    T_LBRACKET,
    T_RBRACKET,
    T_DOT,
    T_COMMA,
    T_PLUS,
    T_MINUS,
    T_MULT,
    T_DIV,
    T_SEMICOLON
};

#endif