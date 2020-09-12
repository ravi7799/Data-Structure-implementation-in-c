#include<stdio.h>

int main(){
    
    int n,i,j,k;
    while(1){
        
        printf("Height: ");
        scanf("%d",&n);
        if(n<=8 && n>=1){
            break;
        }
    }
    if(n<=8 && n>=1){
        for(i=1;i<=n;i++){

            for(k=1 ;k<=n-i;k++){
                printf(" ");
            }
            for(j=1;j<=i;j++){
                printf("#");
            }
            printf("\n");
        }
    }
    return 0;
}