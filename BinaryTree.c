#include<stdio.h>
#include<stdlib.h>

typedef struct BinaryTree{
    int data;
    struct BinaryTree* left;
    struct BinaryTree* right;
} btree;

btree* createBinaryTree(btree *root){
    root=NULL;
    return root;
}


void inorder(btree* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}


btree* newNode(int data ){
    btree *ptr=(btree*)malloc(sizeof(btree));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

btree* add(btree* root,int data){
    btree *ptr=newNode(data);

    if(root==NULL){
        printf("First Node\n");
        root=ptr;
    }else{
        btree* par=root;
        printf("Other Node\n");

        while(par !=NULL){
            if(par->data > data){
                if(par->left == NULL){
                    par->left=ptr;
                    break;
                }
                par=par->left;
            }
            if(par->data <= data){
                if(par->right == NULL){
                    par->right=ptr;
                    break;
                }
                par=par->right; 
            }
        }
    }
    return root;
}

int main(){
    btree* root;
    int value;
    root=createBinaryTree(root);
    for(int i=0;i<10;i++){
        printf("Enter the Number:\n");
        scanf("%d",&value);
        root=add(root,value);
    }

    printf("EHlloo bro\n");
    inorder(root);
    return 0;
}