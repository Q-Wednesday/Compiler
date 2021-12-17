#include <stdio.h>
#define BUFSIZ 4096

int main()
{
    char buf[BUFSIZ];
    scanf("%s", buf);
    infix_to_suffix(buf);
    return 0;
}