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
    int n;
    int var,l,h,m;
    int count=0;
    printf("Enter the size of Array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("The Number in your array is :\n");
    for(int i=0;i<n;i++){
        arr[i]=rand()%200;
        printf("%d ",arr[i]);
    }

    heapsort(arr,n);

    printf("Final array is :\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    while(count !=5){
        printf("\nEnter the Number to be searched\n");
        scanf("%d",&var);
        l=0;
        h=19;
        while(l<h){
            m=(l+h)/2;
            if(arr[m]==var){
                printf("Element found at %d", m);
                break;
            }
            if(arr[m]<var)
            {
                l=m+1;
            }else{
                h=m-1;
            } 
        }
        count++;
    }

    return 0;
}