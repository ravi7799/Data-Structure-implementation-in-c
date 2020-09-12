#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int num;
    srand(time(0));
    num=rand()%100 +1;                 //it will produce number between 1 to 100
    printf("Random number generated is : %d",num);
    return 0;    
}