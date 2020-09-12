#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


void display(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* add(struct Node *head,int val){
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    p->data=val;
    p->next=NULL;
    struct Node* temp;
    printf("Addition started\n");
    
    if(head==NULL){
        printf("1st element added\n");
        head=p;
        printf("True\n");
    }else if(head->next==NULL){
        head->next=p;
    }else{
        temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=p;
    }

    printf("Addition Successfull :-D\n");
    return head
    ;
}

int len(struct Node *head){
    if(head==NULL){
        return 0;
    }else if(head->next==NULL){
        return 1;
    }else{
        int count=1;
        struct Node* temp=head;
        while(temp->next != NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
}

struct Node* delete(struct Node *head,int pos){
    if(pos>len(head)-1){
        printf("Invalid Position\n");
        return head;
    }

    if(head==NULL){
        printf("Nothing To Delete");
    }else if(head->next==NULL && pos==0){
        printf("Deleted item is :%d\n", head->data);
        free(head);
        head=NULL;
    }else{
        struct Node* temp=head;
        int count=0;
        while(count<pos){
            temp=temp->next;
            count++;
        }
        struct Node* tempo=temp->next;
        printf("Deleted Item is : %d\n",tempo->data);
        temp->next=temp->next->next;
        temp->next->next=NULL;
        free(tempo);
    }
    return head;
}

