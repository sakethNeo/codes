#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* left;
    struct node* right;
    int height;
};

int max(int a,int b){
    return (a>b)? a:b;
}

int getHeight(struct node* root){
    if(!root) return -1;
    return root->height;
}

void inorderIterative(struct node* root){
    if(root==NULL) return;
    struct node* current=root;
    struct node* stack[100];
    int top=-1;
    while(1){
        while(current!=NULL){
            stack[++top]=current;
            current=current->left;
        }
        if(top==-1) break;
        current=stack[top--];
        printf("%d[%d] ",current->key,getHeight(current));
        current=current->right;
    }
}

void inorder(struct node* root){
    if(!root) return;
    inorder(root->left);
    printf("%d[%d] ",root->key,getHeight(root));
    inorder(root->right);
}

struct node* newNode(int k){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->key=k;
    new->height=0;
    new->left=new->right=NULL;
    return new;
}

struct node* leftRotate(struct node* par){
    struct node* chd=par->right;
    par->right=chd->left;
    par->height=1+max(getHeight(par->left),getHeight(par->right));
    chd->left=par;
    chd->height=1+max(getHeight(chd->left),getHeight(chd->right));
    par=chd;
    return par;
}

struct node* rightRotate(struct node* par){
    struct node* chd=par->left;
    par->left=chd->right;
    par->height=1+max(getHeight(par->left),getHeight(par->right));
    chd->right=par;
    chd->height=1+max(getHeight(chd->left),getHeight(chd->right));
    par=chd;
    return par;
}

struct node* retrace(struct node* root){
    if(!root) return NULL;
    if(getHeight(root->left)-getHeight(root->right)>1){
        if(getHeight(root->left->left)<getHeight(root->left->right)){
            root->left=leftRotate(root->left);
        }
        root=rightRotate(root);
    }
    else if(getHeight(root->right)-getHeight(root->left)>1){
        if(getHeight(root->right->left)>getHeight(root->right->right)){
            root->right=rightRotate(root->right);
        }
        root=leftRotate(root);
    }
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    return root;
}

struct node* insert(struct node* root,int k){
    if(!root){
        return retrace(newNode(k));
    }
    if(k>root->key){
        root->right=insert(root->right,k);
    }
    else if(k<root->key){
        root->left=insert(root->left,k);
    }
    root=retrace(root);
    return root;
}

int main(){
    struct node* root=NULL;
    int n=9;
    int a[]={2,18,42,43,51,54,74,93,99};
    for(int i=0;i<n;i++){
        root=insert(root,a[i]);
        // inorderIterative(root);
        inorder(root);
        printf("\n");
    }
    return 0;
}

