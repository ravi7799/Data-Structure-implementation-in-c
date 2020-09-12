#include<stdio.h>
#include<stdlib.h>

typedef struct myArray{
    int init_size;
    int len;
    int *array;
} myarr;

void set(myarr* arr,int val,int pos){
    if(pos==0){
        arr->array= (int*)malloc(arr->init_size * sizeof(int));
        *(arr->array)=val;
    }
    else if( pos > arr->init_size && arr->len +1 > arr->init_size){
        printf("Array is filled");
    }else{
        *(arr->array+pos)=val;
        arr->len= arr->len+1;
    }
}

int get(myarr* arr,int ind){
    if(ind > arr->len){
        return -2700;
    }else{
        return *(arr->array + ind);
    }
    return 0;
}


int main(){
    myarr arr[5];
    int size,value;
    int n;
    printf("Enter the number of Array you want\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the size of  %d array\n",i+1);
        scanf("%d", &arr[i].init_size );
        printf("length of array is %d\n",arr[i].init_size);
        for(int j=0;j<=arr[i].init_size-1;j++){
            printf("Enter value of %d array at postion  %d \n",i+1,j+1);
            scanf("%d",&value);
            set(&arr[i],value,j);
        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<arr[j].init_size;i++)
            printf("%d ",get(&arr[j],i));
        printf("\n");
    }
    
    return 0;  
}