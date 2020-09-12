#include<stdio.h>

typedef struct Stack{
    int top;
    int arr[100];
} stack;

stack* createStack(stack* st){
    st->top=-1;
    st->arr[0]=0;
    printf("Stack Made Successfully...\n");
    return st;
}

int  isEmpty(stack* st){
    if(st->top<=-1){
        return 1;
    }
    return 0;
}

int  isFull(stack* st){
    if(st->top==99){
        return 1;
    }
    return 0;
}

stack* push(stack* st,int elem){
    if(isFull(st)==1){
        printf("Stack OverFlow\n");
    }else{
        st->arr[(st->top)++]=elem;
    }
    return st;
}

stack* pop(stack* st){
    if(isEmpty(st)==1){
        printf("Stack is Empty\n");
    }else{
        printf("%d",st->arr[st->top--]);
    }
    return st;
}

void display(stack* st){
    if(isEmpty(st)){
        printf("Stack is Empty\n");
    }else{
        for(int i=st->top;i>0;i--){
            printf("%d ",st->arr[i]);
        }
        printf("\n");
    }
}


int main(){
    printf("EHyy");
    stack* st1;
    int choice,val;
    choice=0;
    printf("Kaise ho");
    st1=createStack(st1);
    printf("Ehlll");

    while(choice !=4){
        printf("1. Press 1 to push in Stack\n");
        printf("2. Press 2 to pop from Stack\n");
        printf("3. Press 3 to display the Stack\n");
        printf("4. Press 4 to Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter your value To push\n");
                scanf("%d",&val);
                st1=push(st1,val);
                break;
            case 2:
                st1=pop(st1);
                break;
            case 3:
                display(st1);
                break;
        }
    }
    return 0;
}
