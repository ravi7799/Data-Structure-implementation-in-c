#include<stdio.h>
#include<time.h>


int lsearch(int arr[],int n,int elem){

    for(int i=0;i<n;i++){
        if(arr[i]==elem){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]={543,5,3,324,2,4,6,54,67,567,34,5,235,45,1,7,567,999};
    int element=1;
    
    int n=sizeof(arr)/sizeof(int);
    printf("%d\n",n);

    int start=clock();
    int result= lsearch(arr,n,element);
    double time1=(clock()-start)/CLOCKS_PER_SEC;
    printf("Time taken is : %f\n",time1);
    
    if(result==-1){
        printf("Element not  found\n");
    }else{
        printf("Element found at position : %d\n",result);
    }

    return 0;
}