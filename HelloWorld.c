#include<stdio.h>
int main(){
    printf("Hello world!\n");
    int* p;
    int value=45;
    *(p+1)=value;
    printf("%d",value);
    printf("%d\n",*(p+1));
    printf("%u\n",p);
    printf("%u\n",p+1);
    return 0;
}