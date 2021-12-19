#include <stdio.h>

int main()
{
    char buf[4096];

    int i = 0;
    int lens = 0;
    int halflens = 0;
    int temp = 0;
    scanf("%s", buf);
    
    while (buf[i] != 0)
    {
        i=i+1;
    }

    lens = i;
    halflens = lens/2;
    // printf("%d",halflens);
    // printf("%d",lens);
    
    i=0;
    while(i<halflens)
    {
        temp = lens-1-i;
        if (buf[i]== buf[temp])
        {
            temp=0;
        }
        else
        {
            printf("%s","不是回文数");
            return 0;
        }
        i=i+1;
    }
    printf("%s","是回文数");
    return 0;
}