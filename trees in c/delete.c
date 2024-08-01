#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* left;
    struct node* right;
};

void inorder(struct node* root){
    if(!root) return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

struct node* insert(struct node* root,int k){
    if(!root){
        root=(struct node*)malloc(sizeof(struct node));
        root->key=k;
        root->left=root->right=NULL;
        return root;
    }
    if(k==root->key) return root;
    if(k<root->key)
        root->left = insert(root->left,k);
    else
        root->right = insert(root->right,k);
    return root;
}

struct node* findMin(struct node* root){
    if(!root) return NULL;
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

struct node* delete(struct node* root,int k){
    if(!root) return NULL;
    if(root->key>k){
        root->left=delete(root->left,k);
    }
    else if(root->key<k){
        root->right=delete(root->right,k);
    }
    else{
        if(root->right==NULL && root->left==NULL){
            free(root);
            return NULL;
        }
        else if(root->right==NULL){
            struct node* temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL){
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        struct node* temp=findMin(root->right);
        root->key=temp->key;
        root->right = delete(root->right,temp->key);  
    } 
    return root;
}

int main(){
    struct node* root = NULL;
    
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    root = delete(root, 30);
    printf("Inorder traversal after deleting 20: ");
    inorder(root);
    printf("\n");

    return 0;
}