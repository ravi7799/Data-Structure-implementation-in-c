#include<stdio.h>
#include<stdlib.h>


int partition(int arr[],int low,int high,int n){
    int pivot=arr[high],temp;
    int i=low-1;
    for(int p=low;p<high;p++){
        if(arr[p] < pivot){
            i++;
            temp=arr[i];
            arr[i]=arr[p];
            arr[p]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;

    return i+1;

    // while(low<high){

    //     while( low<n && arr[low]<=arr[pivot]){
    //         low++;
    //     }
    //     while( high>=0 && arr[high]>arr[pivot]){
    //         high--;
    //     }
    //     if(low<high){
    //         temp=arr[low];
    //         arr[low]=arr[high];
    //         arr[high]=temp;
    //     }
    // }

    // temp=arr[pivot];
    // arr[pivot]=arr[high];
    // arr[high]=temp;

    // return high;
}

void quicksort(int arr[],int l,int h,int n){
    if(l<h){
        int p=partition(arr,l,h,n);
        quicksort(arr,l,p-1,n);
        quicksort(arr,p+1,h,n);
    }
}


int main(){
    int n;
    printf("Enter the size of Array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("The Number in your array is :\n");
    for(int i=0;i<n;i++){
        arr[i]=rand()%200;
        printf("%d ",arr[i]);
    }

    quicksort(arr,0,n-1,n);

    printf("\nFinal Array is: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}