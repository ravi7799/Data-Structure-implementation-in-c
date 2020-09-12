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

struct Node* addFirst(node* head,int val){
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    p->data=val;
    p->next=NULL;

    if(head==NULL){
        head=p;
    }else{
        p->next=head;
        head=p;
    }
    return head;
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

    if(pos==0){
        free(head);
        head=NULL;
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


int getLast(node* head){

    if(head==NULL){
        return 0;
    }else if(head->next==NULL){
        return head->data;
    }else{
        struct Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
    }


}
int getFirst(node* head){

    if(head==NULL){
        return 0;
    }else{
        return head->data;
    }
}


node* removeFirst(node* head){
    if(head->next==NULL){
        free(head);
        head=NULL;
    }else{
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        free(temp);
    }
    return head;
}

node* reverse(node* head){
    int len1=len(head);
    node* temp=head;
    node* head2=NULL;
    while(temp !=NULL){
        head2=addFirst(head2,temp->data);
        temp=temp->next;
    }
    return head2;
}

node* removeLast(node* head){
    if(head==NULL){
        printf("Nothing to delete\n");
    }else if(head->next==NULL){
        free(head);
        head=NULL;
    }else{
        struct Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
        return head;
}



node* addLinkedList(node* l1, node* l2){
    l1=reverse(l1);
    l2=reverse(l2);
    int len1=len(l1);
    int len2=len(l2);
    if(len1<len2){
        for(int i=0;i<len2-len1;i++){
            l1=add(l1,0);
        }
    }else{
        for(int i=0;i<len1-len2;i++){
            l2=add(l2,0);
        }
    }


    printf("reverse 1 =\n");
    display(l1);
    printf("reverse 1 =\n");
    display(l2);

    node* add1=NULL;
    int sum=0,carry=0,count;
    if(len1>len2){
        count=len1;
    }else{
        count=len2;
    }

    while(count!=0){
        sum=getFirst(l1)+ getFirst(l2)+carry;
        printf("sum = %d and Carry =%d\n",sum,carry);
        l1=removeFirst(l1);
        l2=removeFirst(l2);
        if(sum/10 > 0){
            add1=add(add1,sum%10);
            carry=sum/10;
            sum=0;
        }else{
            add1=add(add1,sum);
            carry=0;
        }
        count--;
    }
    if(carry !=0){
        add1=add(add1,carry);
    }
    return add1;
}

int main(){
    node* ll1,*ll2,*ans;
    int num1,num2,sum;
    ll1=createLinkedList(ll1);
    ll2=createLinkedList(ll2);
    ans=createLinkedList(ans);

    printf("Enter the First number:\n");
    scanf("%d",&num1);
    printf("Enter the Second number:\n");
    scanf("%d",&num2);
    if(num1<num2){
        int temp=num1;
        num1=num2;
        num2=temp;
    }
    while(num1!=0){
        ll1=addFirst(ll1,num1%10);
        num1/=10;
    }
    
    while(num2!=0){
        ll2=addFirst(ll2,num2%10);
        num2/=10;
    }
    display(ll1);
    printf("\n");
    display(ll2);

    ans=addLinkedList(ll1,ll2);
    printf("\n");
    display(reverse(ans));
    return 0;
}