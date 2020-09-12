#include<stdio.h>
#include<stdlib.h>

typedef struct Heap{
    int size;
    int* arr;
} heap;

heap* createHeap(heap* maxHeap,int size){
    maxHeap=(heap *)malloc(sizeof(heap));
    maxHeap->arr=(int*)malloc(sizeof(int)*size);
    maxHeap->size=0;
    printf("Heap is Successfully initialized\n");
    return maxHeap;
}

heap* swimUp(heap* maxh,int n){
    int x=n;
    int parent= (n-1)/2;
    if( maxh->arr[n] > maxh->arr[parent]){
        int temp=maxh->arr[n];
        maxh->arr[n]=maxh->arr[parent];
        maxh->arr[parent]=temp;
        n=parent;
    }
    if(x != n){
        maxh = swimUp(maxh,n);
    }
    return maxh;
}

heap* insert(heap* maxh,int data){
    if(maxh->size==0){
        maxh->arr[0]=data;
        maxh->size +=1;
    }else{
        maxh->arr[maxh->size]=data;
        maxh->size+=1;
        maxh= swimUp(maxh,maxh->size -1);
    }
    return maxh;
}

void traverseHeap(heap* maxh){
    for(int i=0;i<maxh->size;i++){
        printf("%d , ",maxh->arr[i]);
    }
    printf("\n");
}

heap* heapify(heap* maxheap,int n){
    int left=2*n+1;
    int right=2*n+2;
    int largest=n;

    if(  left < maxheap->size  &&  maxheap->arr[largest] < maxheap->arr[left] ){
        largest=left;
    }
    if( right < maxheap->size &&  maxheap->arr[largest] <maxheap->arr[right]){
        largest=right;
    }
    if(largest != n){
        int temp=maxheap->arr[largest];
        maxheap->arr[largest]=maxheap->arr[n];
        maxheap->arr[n]=temp;
        maxheap=heapify(maxheap,largest);
    }
}

int delete(heap** maxheap){
    heap* x=*(maxheap);
    int temp=x->arr[0];
    x->arr[0]=x->arr[x->size -1];
    x->arr[x->size -1]=temp;
    x->size -=1;
    x=heapify(x,0);
    return temp;
}

int main(){
    heap *maxheap;
    int n,val;
    printf("Hello!! .. Please Enter the size of number of Element you want in your Max Heap. \n");
    scanf("%d",&n);
    maxheap=createHeap(maxheap,n);
    printf("Enter the Numbers you want to add\n");

    for(int i=0;i<n;i++){
        printf("Enter the number\n");
        scanf("%d",&val);
        maxheap=insert(maxheap,val);
    }
    traverseHeap(maxheap);
    for(int i=0;i<6;i++){
        printf("deleted Item is: %d \n", delete(&maxheap) );
    }
    traverseHeap(maxheap);
    for(int i=0;i<4;i++){
        printf("deleted Item is: %d \n", delete(&maxheap) );
    }
    traverseHeap(maxheap);
    return 0;
}