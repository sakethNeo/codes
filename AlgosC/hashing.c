#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int mod=10;
const int ss=5;

typedef struct node HashNode{
    char key[5];
    int val;
}HashNode;

typedef struct node HashTable{
    int size;
    HashNode* arr;
}HashTable;

int hash(HashTable ht,char key[]){
    int x=1;
    int ans=0;
    for(int i=0;i<ss;i++,x=(x*31)%ht.size){
        ans=(ans+(key[i]-'a'+1)*x)%ht.size;
    }
    return ans;
}

HashTable initialize(int size){
    HashTable newN;
    newN.size=size;
    newN.arr=(HashNode*)malloc(size*sizeof(HashNode));
    for(int i=0;i<size;i++){
        for(int j=0;j<ss;j++) newN.arr[i].key[j]='\0';
        newN.arr[i].val=0;
    }
    return newN;
}

int search(HashTable ht,char key[]){
    int i=hash(ht,key);
    int prev=i;
    do{
        if(strlen(ht.arr[i].key)==0) return -1;
        if(strcmp(ht.arr[i].key,key)==0) return ht.arr[i].val;
        i=(i+1)%ht.size;
    }while(i!=prev);
    return -1;
}

int increaseValue(HashTable *head,char key[]){
    HashTable ht=*head;
    int i=hash(ht,key);
    int prev=i;
    do{
        if(strlen(ht.arr[i].key)==0) return -1;
        if(strcmp(ht.arr[i].key,key)==0){
            ht.arr[i].val++;
            *head=ht;
            return i;
        }
        i=(i+1)%ht.size;
    }while(i!=prev);
    return -1;
}

int insert(HashTable *head,char key[],int val){
    HashTable ht=*head;
    int i=hash(ht,key);
    int prev=i;
    do{
        if(strlen(ht.arr[i].key)==0){
            strcpy(ht.arr[i].key,key);
            ht.arr[i].val=val;
            *head=ht;
            return i;
        }
        i=(i+1)%ht.size;
    }while(i!=prev);
    return -1;
}

int delete(HashTable *head,char key[]){
    HashTable ht=*head;
    int i=hash(ht,key);
    int prev=i;
    do{
        if(strlen(ht.arr[i].key)==0) return -1;
        if(strcmp(ht.arr[i].key,key)==0){
            for(int j=0;j<ss;j++) ht.arr[i].key[j]='\0';
            ht.arr[i].val=0;
            *head=ht;
            return i;
        }
        i=(i+1)%ht.size;
    }while(i!=prev);
    return -1;
}

void print(HashTable ht){
    for(int i=0;i<ht.size();i++){
        printf("(%s,%d) ",ht.arr[i].key,ht.arr[i].val);
    }
}

void deleteHashTable(HashTable *ht){
    free(ht->arr);
    ht->size=0;
}

int main(){
    
    return 0;
}
