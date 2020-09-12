#include<stdio.h>
#include<stdlib.h>

typedef  struct Node{
    int data ;
    struct Node* next;
} node;

node* createLinkedList(node* head){
    head=NULL;
    return head;
}

void display(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* add(struct Node *head,int val){
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    p->data=val;
    p->next=NULL;
    struct Node* temp;
    
    if(head==NULL){
        head=p;
    }else if(head->next==NULL){
        head->next=p;
    }else{
        temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=p;
    }

    return head;
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

node* reverse(node* head){

    if(head ==NULL || head->next==NULL){
        return head;
    }
    
    node* p=head;
    node* q=head->next;
    node* r=head->next->next;
    
    while(q != NULL){
        q->next=p;
        p=q;
        q=r;
        if(r==NULL){
            q=r;
        }else{
            r=r->next;
        }
        
    }

    head->next=NULL;
    head=p;
    return head;
}

int main(){
    int n,item;
    node* head;
    head=createLinkedList(head);
    printf("Number of Elements you want to add to your list\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the number to add in Linked List\n");
        scanf("%d",&item);
        head=add(head,item);
    }
    display(head);
    printf("\n");
    head=reverse(head);
    display(head);
    return 0;
}