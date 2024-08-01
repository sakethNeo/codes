#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void merge(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int b[n1],c[n2];
    for(int i=0;i<n1;i++) b[i]=a[l+i];
    for(int i=0;i<n2;i++) c[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(b[i]<c[j]) a[k++]=b[i++];
        else a[k++]=c[j++];
    }
    while(i<n1) a[k++]=b[i++];
    while(j<n2) a[k++]=c[j++];
}

void mergesort(int a[],int l,int r){
    if(l>=r) return;
    int m=(l+r)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,m,r);
}

int partition(int a[],int l,int r){
    int i=l-1;
    for(int j=l;j<r;j++) if(a[j]<a[r]) swap(&a[j],&a[++i]);
    swap(&a[r],&a[++i]);
    return i;
}

void quicksort(int a[],int l,int r){
    if(l>=r) return;
    int p=partition(a,l,r);
    quicksort(a,l,p-1);
    quicksort(a,p+1,r);
}

int main(){  
    int a[]={4,5,2,5,26,7};
    int n=sizeof(a)/sizeof(a[0]);
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    exit(0);
}