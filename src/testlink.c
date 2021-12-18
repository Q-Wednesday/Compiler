#include <stdio.h>
int testFunc(int);

int main()
{
    int n = 3;
    if (n == 3)
        n = 2;
    else
        n = 1;
    printf("%d\n", testFunc(n));
    return 0;
}