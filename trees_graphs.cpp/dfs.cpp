#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    //cout<<vertex<<"\n";
    vis[vertex]=true;
    for (auto i : g[vertex]){
        //cout<<"par = "<<vertex<<" ,child = "<<i<<"\n";
        if(!vis[i]) dfs(i);
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    return 0;
}

/*
example : 
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/