#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int rdm(){
    return (rand()%(26)+97);
}

int main(){
    int r;
    do{
        printf("%c\n",rdm());
        Sleep(20);
    }while(rdm()!='i');
    do{
        printf("i %c\n",rdm());
        Sleep(20);
    }while(rdm()!='l');
    do{
        printf("i l%c\n",rdm());
        Sleep(20);
    }while(rdm()!='o');
    do{
        printf("i lo%c\n",rdm());
        Sleep(20);
    }while(rdm()!='v');
    do{
        printf("i lov%c\n",rdm());
        Sleep(20);
    }while(rdm()!='e');
    do{
        printf("i love %c\n",rdm());
        Sleep(20);
    }while(rdm()!='y');
    do{
        printf("i love y%c\n",rdm());
        Sleep(20);
    }while(rdm()!='o');
    do{
        printf("i love yo%c\n",rdm());
        Sleep(20);
    }while(rdm()!='u');
    printf("i love you");
}