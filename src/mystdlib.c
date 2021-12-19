#include<stdio.h>
int inputNum(){
    int num;
    scanf("%d", &num);
    return num;
}



void getArray(int a[],int len){
    for (int i = 0; i < len;i++){
        printf("input a[%d]:", i);
        scanf("%d", &a[i]);
    }
}

void printLine(char* str){
    printf("%s\n", str);
}
