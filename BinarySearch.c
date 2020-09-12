#include<stdio.h>

void bubblesort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j+1]<arr[j]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int bsearch(int arr[],int low,int high,int elem){
    int mid=(low+high)/2;

    if(arr[mid]==elem){
        return mid;
    }
    if(arr[mid]>elem){
        bsearch(arr,low,mid,elem);
    }
    if(arr[mid]<elem){
        bsearch(arr,mid,high,elem);
    }

}

int main(){
    int arr[]={543,5,3,324,2,4,6,54,67,567,34,5,235,45,1,7,567,999};
    int element=235,i;

    int n=sizeof(arr)/sizeof(int);

    bubblesort(arr,n);
    int result= bsearch(arr,0,n-1,element);
  
    printf("NEW SORTED ARRAY IS\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    if(result==-1){
        printf("Element not  found\n");
    }else{
        printf("Element found at position : %d\n",result);
    }

    return 0;
}