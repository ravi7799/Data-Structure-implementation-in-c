#include<stdio.h>
#include<stdlib.h>

typedef struct myArray{
    int init_size;
    int len;
    int *array;
} myarr;


void createArray(myarr* arr,int in_size){
    arr->init_size=in_size;
    arr->len=0;
    arr->array= (int*)malloc(arr->init_size * sizeof(int));
}

void add(myarr* arr,int val){
    if( arr->len +1 > arr->init_size){
        printf("Array is filled\n\n");
    }else{
        if(arr->len==0){
            *(arr->array)=val;
            arr->len+=1;
        }else{
            *(arr->array+arr->len)=val;
            arr->len= arr->len+1;
        }
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


void setshift(myarr* arr,int val,int pos){
    if( pos > arr->init_size){
        printf("Invalid index (out of bound index..)\n\n");
    }
    if(arr->len +1 > arr->init_size){
        printf("Array is filled,can't add more element\n\n");
    }else{
        if(arr->len ==0){
            *(arr->array)=val;
            arr->len=1;
        }else{
            if(pos==0){
                for(int i=arr->len;i>=pos;i--){
                    *(arr->array +i)=*(arr->array+i-1);
                }
                *(arr->array)=val;
                arr->len= arr->len+1;
            }else{
                for(int i=arr->len;i>=pos;i--){
                    *(arr->array +i)=*(arr->array+i-1);
                }
                *(arr->array+pos)=val;
                arr->len= arr->len+1;
            }
        }
    }

}

void set(myarr* arr,int val,int pos){
    if( pos > arr->len){
        printf("Invalid index (out of bound index..)\n\n");
    }else{
        if(arr->len ==0){
            *(arr->array)=val;
        }else{
            if(pos==0){
                *(arr->array)=val;
            }else{
                *(arr->array+pos)=val;

            }
        }
    }

}


int delete(myarr* arr, int pos){
    if(arr->len==0){
        printf("Nothing to delete(array is empty)");
        return -1;
    }else if(pos > arr->len){
        printf("Index out of bound");
        return __INT32_MAX__;
    }else{
        int temp=*(arr->array + pos);
        for(int i=pos;i<arr->len-1;i++){
            *(arr->array +i)=*(arr->array+i+1);
        }
        *(arr->array + arr->len -1)=-9999;
        arr->len= arr->len-1;
        return temp;
    }
}

int len(myarr* arr){
    return arr->len;
}



int main(){
    myarr arr;
    int n,choice=0,value,pos;
    printf("Enter the initial size of Array");
    scanf("%d",&n);

    // Creating a Array
    createArray(&arr, n);
    while(choice !=7){
        printf("\n\nPress 1 to add a element to Array\n");
        printf("Press 2 to add a element in particular position (with shifting)\n");
        printf("Press 3 to add a element in particular position (without shifting)\n");
        printf("Press 4 to display\n");
        printf("Press 5 to know the length of array\n");
        printf("Press 6 to delete a element from particular position\n");
        printf("Press 7 to exit\n\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:printf("Enter the value you want to add to your array:\n");
                    scanf("%d",&value);
                    add(&arr,value);
                    break;
            case 2:printf("Enter the value you want to add to your array:\n");
                    scanf("%d",&value);
                    printf("Enter its position:\n");
                    scanf("%d",&pos);
                    setshift(&arr,value,pos);
                    break;
            case 3:printf("Enter the value you want to add to your array:\n");
                    scanf("%d",&value);
                    printf("Enter its position:\n");
                    scanf("%d",&pos);
                    set(&arr,value,pos);
                    break;
            case 4:
                    printf("Content in the array is :\n");
                    for(int i=0;i<arr.len;i++){
                        printf("%d ",*(arr.array+i));
                    }
                    printf("\n");
                    break;
            case 5:
                    printf("\nLength of your Array is = %d \n",len(&arr));
                    break;
            case 6:
                    printf("\nEnter the position from where you want to delete the element");
                    scanf("%d",&pos);
                    printf("\nDeleted element is : %d",delete(&arr,pos));
                    printf("\n");
                    break;
            case 7:exit(0);
        }
    }
    return 0;
}