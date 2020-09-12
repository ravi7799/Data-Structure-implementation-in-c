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



int main(){
    struct Node* head=NULL;
    int choice=0,value,pos;

    while(choice<=6){
        printf("\n\nPress 1 to add a element to Linked List\n");
        printf("Press 2 to add a element in particular position \n");
        printf("Press 3 to display\n");
        printf("Press 4 to know the Size of Linked List\n");
        printf("Press 5 to delete a element from particular position\n");
        printf("Press 6 to exit\n\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:printf("Enter the value you want to add:\n");
                    scanf("%d",&value);
                    head=add(head,value);
                    break;
            case 2:printf("Enter the value you want to add to your array:\n");
                    // scanf("%d",&value);
                    // printf("Enter its position:\n");
                    // scanf("%d",&pos);
                    // setshift(&arr,value,pos);
                    break;
            case 3:
                    printf("Content in the LINKED LIST is :\n");
                    display(head);
                    break;
            case 4:
                    printf("\nLength of your Array is = %d \n",len(head));
                    break;
            case 5:
                    printf("\nEnter the position from where you want to delete the element");
                    scanf("%d",&pos);
                    head=delete(head,pos);
                    printf("\n");
                    break;
            case 6:exit(0);
        }
    }

    return 0;
}