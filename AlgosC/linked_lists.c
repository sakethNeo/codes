#include<stdio.h>
#include<stdlib.h>

struct node{
    int n;
    struct node* next;
};
typedef struct node ELEMENT;
typedef ELEMENT* LINK;

void scan(LINK* head_ref,int k){
    LINK temp=NULL;
    temp=(LINK)malloc(sizeof(ELEMENT));
    temp->n=k;
    temp->next=*head_ref;
    *head_ref=temp;
}

void printnode(LINK head){
    while(head){
        printf("%d ",head->n);
        head=head->next;
    }
    printf("\n");
}

void reverse(LINK* head_ref){
    LINK head=*head_ref;
    LINK temp=NULL;
    while(head){
        scan(&temp,head->n);
        head=head->next;
    }
    *head_ref=temp;
}

void delMax(LINK *head_ref){
    LINK prev=NULL;
    LINK curr=*head_ref;
    LINK max=*head_ref;
    while(curr){
        if(curr->n > max->n){
            max=curr;
        }
        curr=curr->next;
    }
    if(*head_ref==max) *head_ref=(*head_ref)->next;
    else{
        curr=*head_ref;
        while(curr!=max){
            prev=curr;
            curr=curr->next;
        }
        prev->next=max->next;
    }
}

int main(){
    LINK head=NULL;
    scan(&head,1);
    scan(&head,10);
    scan(&head,10);
    scan(&head,100);
    scan(&head,100);
    scan(&head,1000);
    return 0;
}
