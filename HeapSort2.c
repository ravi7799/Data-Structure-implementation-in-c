#include<stdio.h>
#include<stdlib.h>

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(  left <n && arr[largest] < arr[left]){
        largest=left;
    }

    if( right <n &&  arr[largest] < arr[right]){
        largest=right;
    }

    if(largest !=i){
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heapify(arr,n,largest);
    }
}


void heapsort(int arr[],int n){

    printf("Heyy\n");
    for(int i=n/2 -1;i>=0;i--){
        heapify(arr,n,i);
    }

    int heaplen =n;
    while(heaplen>0){
        int temp=arr[0];
        arr[0]=arr[heaplen-1];
        arr[heaplen-1]=temp;
        heapify(arr,heaplen-1,0);
        heaplen--;
    }

    printf("\n");
}



int main(){
    int n,value;
    printf("Enter the size of Array:\n");
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&value);
        arr[i]=value;
    }
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}