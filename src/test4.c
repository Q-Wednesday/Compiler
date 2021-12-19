#include <stdio.h>

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

int main()
{
    char buf[4096];
    char ops_stack[4096];
    char vector[4096]; //0 - num
    int assistant_vector[4096];
    int RPN_stack[4096];
    int RPN_stack_size = 0;
    int ops_stack_size = 0;
    int vector_size = 0;

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
            assistant_vector[vector_size] = temp;
            vector[vector_size] = 0;
            vector_size = vector_size + 1;
        }
        else
        {
            if (buf[i] == '(' || ops_stack_size == 0)
            {
                ops_stack[ops_stack_size] = buf[i];
                ops_stack_size = ops_stack_size + 1;
            }
            else
            {
                if (cmp_priority(ops_stack[ops_stack_size - 1], buf[i]))
                {
                    if (buf[i] == ')')
                    {
                        while (ops_stack_size && ops_stack[ops_stack_size - 1] != '(')
                        {
                            ops_stack_size = ops_stack_size - 1;
                            vector[vector_size] = ops_stack[ops_stack_size];
                            vector_size = vector_size + 1;
                        }
                        ops_stack_size = ops_stack_size - 1;
                    }
                    else
                    {
                        while (ops_stack_size && cmp_priority(ops_stack[ops_stack_size - 1], buf[i]))
                        {
                            ops_stack_size = ops_stack_size - 1;
                            vector[vector_size] = ops_stack[ops_stack_size];
                            vector_size = vector_size + 1;
                        }
                        ops_stack[ops_stack_size] = buf[i];
                        ops_stack_size = ops_stack_size + 1;
                    }
                }
                else
                {
                    ops_stack[ops_stack_size] = buf[i];
                    ops_stack_size = ops_stack_size + 1;
                }
            }
            i = i + 1;
        }
    }
    while (ops_stack_size)
    {
        ops_stack_size = ops_stack_size - 1;
        vector[vector_size] = ops_stack[ops_stack_size];
        vector_size = vector_size + 1;
    }

    //calcsuffix
    for (i = 0; i < vector_size; i = i + 1)
    {
        if (vector[i])
        {
            RPN_stack_size = RPN_stack_size - 1;
            int numr = RPN_stack[RPN_stack_size];
            RPN_stack_size = RPN_stack_size - 1;
            int numl = RPN_stack[RPN_stack_size];
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
            RPN_stack[RPN_stack_size] = numl;
            RPN_stack_size = RPN_stack_size + 1;
        }
        else
        {
            RPN_stack[RPN_stack_size] = assistant_vector[i];
            RPN_stack_size = RPN_stack_size + 1;
        }
    }
    RPN_stack_size = RPN_stack_size - 1;
    printf("%d", RPN_stack[RPN_stack_size]);
    return 0;
}