#include<stdio.h>
#include<stdlib.h>

typedef struct ArrayStack{
    int capacity;
    int *stack;
    int top;
} arrstack;


void createstack(arrstack* arrs,int capacity){
    arrs->capacity=capacity;
    arrs->stack=(int*)malloc(capacity * sizeof(int));
    arrs->top=-1;
    printf("Array is Created\n");
}

void push(arrstack* stk, int element){
    if(stk->top==stk->capacity){
        printf("Stack is Full");
    }else{
        stk->top ++;
        *(stk->stack + stk->top)=element;
    }
}

int pop(struct ArrayStack* stk){
    if(stk->top == -1){
        printf("Underflow");
    }else{
        int temp= *(stk->stack + (stk->top));
        stk->top--;
        return temp;
    }
}

void display(struct ArrayStack* stk){
    if(stk->top == -1){
        printf("Underflow");
    }else{
        int i=stk->top;
        while(i >=0){
            printf("%d ",*(stk->stack +i));
            i--;
        }
        printf("\n");
    }
}
int main(){
    arrstack stack;
    
    int choice=0,element;
    createstack(&stack,8);

    while(choice !=4 ){
        printf("Press 1 to push element to stack\n");
        printf("Press 2 to pop from stack\n");
        printf("Press 3 to display\n");
        printf("Press 4 to exit\n");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to push\n");
                scanf("%d",&element);
                push(&stack,element);
                break;
            case 2:
                printf("popped Element is : %d\n",pop(&stack));
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}