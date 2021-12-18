#include <stdio.h>

char buf[4096];
char ops_stack[4096];
char vector[4096]; //0 - num
int assistant_vector[4096];
int RPN_stack[4096];
int RPN_stack_size = 0;
int ops_stack_size = 0;
int vector_size = 0;

int cmp_priority(char top, char cur)
{
    if ((top == '+' || top == '-') && (cur == '+' || cur == '-'))
    {
        return 1;
    }
    if ((top == '*' || top == '/') && (cur == '+' || cur == '-' || top == '*' || top == '/'))
    {
        return 1;
    }
    if (cur == ')')
    {
        return 1;
    }
    return 0;
}

void RPN_vector_push_back(char ops, int num)
{
    assistant_vector[vector_size] = num;
    vector[vector_size] = ops;
    vector_size = vector_size + 1;
    return;
}

void ops_push_back(char ops)
{
    ops_stack[ops_stack_size] = ops;
    ops_stack_size = ops_stack_size + 1;
    return;
}

char ops_pop()
{
    ops_stack_size = ops_stack_size - 1;
    return ops_stack[ops_stack_size];
}

char ops_top()
{
    return ops_stack[ops_stack_size - 1];
}
void RPN_push_back(int ops)
{
    RPN_stack[RPN_stack_size] = ops;
    RPN_stack_size = RPN_stack_size + 1;
    return;
}

int RPN_pop()
{
    RPN_stack_size = RPN_stack_size - 1;
    return RPN_stack[RPN_stack_size];
}

int RPN_top()
{
    return RPN_stack[RPN_stack_size - 1];
}

int main()
{

    int i = 0;
    scanf("%s", buf);

    //infix_to_suffix();
    while (buf[i] != 0)
    {
        int temp = 0;
        int num_flag = 0;
        while (buf[i] >= '0' && buf[i] <= '9')
        {
            num_flag = 1;
            temp = temp * 10 + buf[i] - '0';
            i = i + 1;
        }
        if (num_flag)
        {
            RPN_vector_push_back(0, temp);
        }
        else
        {
            if (buf[i] == '(' || ops_stack_size == 0)
            {
                ops_push_back(buf[i]);
            }
            else
            {
                if (cmp_priority(ops_top(), buf[i]))
                {
                    if (buf[i] == ')')
                    {
                        while (ops_stack_size && ops_top() != '(')
                        {
                            RPN_vector_push_back(ops_pop(), 0);
                        }
                        ops_pop();
                    }
                    else
                    {
                        while (ops_stack_size && cmp_priority(ops_top(), buf[i]))
                        {
                            RPN_vector_push_back(ops_pop(), 0);
                        }
                        ops_push_back(buf[i]);
                    }
                }
                else
                {
                    ops_push_back(buf[i]);
                }
            }
            i = i + 1;
        }
    }
    while (ops_stack_size)
    {
        RPN_vector_push_back(ops_pop(), 0);
    }

    //calcsuffix
    for (i = 0; i < vector_size; i = i + 1)
    {
        if (vector[i])
        {
            int numr = RPN_pop();
            int numl = RPN_pop();
            if (vector[i] == '+')
            {
                numl = numl + numr;
            }
            else
            {
                if (vector[i] == '-')
                {
                    numl = numl - numr;
                }
                else
                {
                    if (vector[i] == '*')
                    {
                        numl = numl * numr;
                    }
                    else
                    {
                        if (vector[i] == '/')
                        {
                            numl = numl / numr;
                        }
                    }
                }
            }
            RPN_push_back(numl);
        }
        else
        {
            RPN_push_back(assistant_vector[i]);
        }
    }
    printf("%d", RPN_pop());

    return 0;
}