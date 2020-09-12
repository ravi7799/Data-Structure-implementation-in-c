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

btree* add(btree* root){
    int val;
    printf("Enter the Value");
    scanf("%d",&val);
    btree* ptr=newNode(val);

    if(val==-1){
        return NULL;
    }else{
        root=ptr;

        printf("Enter Left child of it:");
        root->left=add(root->left);

        printf("Enter the right child of it:");
        root->right=add(root->right);

        return root;
    }
}

int main(){
    btree* root;
    int value;
    root=createBinaryTree(root);
    root=add(root);
    printf("EHlloo bro\n");
    inorder(root);
    return 0;
}