#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 10
int size=0;
int H[CAPACITY+1];

int Root(){
    return 1;
}
int Parent(int i){
    return i/2;
}
int LeftChild(int i){
    return (i*2);
}
int RightChild(int i){
    return 2*i+1;
}
int HasParent(int i){
    return (i!=Root());
}
int IsNode(int i){
    return i<=size;
}

void swap(int *a,int *b){
    int temp=*a; *a=*b; *b=temp;
}
int getMin(){
    if(size==0) return -1;
    return H[Root()];
}
void ShiftUp(int n){
    while(HasParent(n)&&(H[Parent(n)]>H[n])){
        swap(&H[Parent(n)],&H[n]);
        n=Parent(n);
    }
}
void push(int newNum){
    if(CAPACITY==size) return;
    H[++size]=newNum;
    ShiftUp(size);
}
void ShiftDown(int n){
    while(IsNode(LeftChild(n))){
        int chd=LeftChild(n);
        if(IsNode(RightChild(n))&&(H[RightChild(n)]<H[LeftChild(n)])) chd=RightChild(n);
        if(H[n]>H[chd]) swap(&H[n],&H[chd]);
        else break;
        n=chd;
    }
}
void pop(){
    if(!size) return;
    H[Root()]=H[size];
    size--;
    ShiftDown(Root());
}


// build heap (or) heapify
void buildHeap(int a[],int n){
    for(int i=0;i<n;i++){
        H[i+1]=a[i];
    }
    size=n;
    for(int i=size/2;i>=1;i--) ShiftDown(i);
}
void printHeap(){
    for(int i=1;i<=size;i++){
        printf("%d ",H[i]);
    }
    printf("\n");
}

// try heapsort without using extra space

int main() {
    int a[]={10,5,20,7,6,13,8,19,11,1};
    int n=sizeof(a)/sizeof(a[0]);
    buildHeap(a,n);
    printHeap();
    return 0;
}
