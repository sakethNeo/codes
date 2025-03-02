#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *left,*right;
};

struct queue{
    int front,rear,size;
    struct node** arr;
};

struct node* newNode(int k){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->key=k;
    newNode->left=newNode->right=NULL;
    return newNode;
}

struct queue* newQueue(int size){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front=q->rear=-1;
    q->size=size;
    q->arr=(struct node**)malloc(size*sizeof(struct node*));
    for(int i=0;i<size;i++){
        q->arr[i]=NULL;
    }
    return q;
}

int isEmpty(struct queue* q){
    return q->front==-1;
}

int isFull(struct queue* q){
    return q->rear==q->size-1;
}

int hasSingleElement(struct queue* q){
    return q->front==q->rear;
}

struct node* getFront(struct queue* q){
    return q->arr[q->front];
}

void enqueue(struct queue* q,struct node* root){
    if(isFull(q)) return;
    q->arr[++q->rear]=root;
    if(isEmpty(q)) ++q->front;
}

struct node* dequeue(struct queue* q){
    if(isEmpty(q)) return NULL;
    struct node* temp=q->arr[q->front];
    if(hasSingleElement(q)) q->front=q->rear=-1;
    else ++q->front;
    return temp;
}

void insert(struct node** head,struct queue* q,int k){
    struct node* temp=newNode(k);
    if(!*head) *head=temp;
    else{
        struct node* fr=getFront(q);
        while(fr->key==-1){
            dequeue(q);
            fr=getFront(q);
        }
        if(!fr->left) fr->left=temp;
        else if(!fr->right) fr->right=temp;
        if(fr->left!=NULL && fr->right!=NULL){
            if(fr->left->key==-1) fr->left=NULL;
            if(fr->right->key==-1) fr->right=NULL;
            dequeue(q);
        }
    }
    enqueue(q,temp);
}

void levelOrder(struct node* root){
    struct queue* q=newQueue(100);
    if(!root) return;
    enqueue(q,root);
    while(!isEmpty(q)){
        struct node* temp=dequeue(q);
        printf("%d ",temp->key);
        if(temp->left) enqueue(q,temp->left);
        if(temp->right) enqueue(q,temp->right);
    }
    printf("\n");
}

int main() {
    int a[]={7, 4, 9, -1, 6, -1, -1, 5};
    int n=sizeof(a)/sizeof(a[0]);
    struct node* root=NULL;
    struct queue* q=newQueue(100);
    for(int i=0;i<n;i++){
        insert(&root,q,a[i]);
    }
    levelOrder(root);
    return 0;
}

