#include<stdio.h>
void printArray(int *ptr,int n){
    for(int i=0;i<n;i++){
        printf("Value of element at %d is : %d\n",i+1,*(ptr+i));
    }
}
int main(){
    int arr[]={4,47,32,41,49,5,45,6};
    printArray(arr,8);
    return 0;
}