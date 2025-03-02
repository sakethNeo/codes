#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j){
    // conditions
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}

int main(){

    return 0;
}