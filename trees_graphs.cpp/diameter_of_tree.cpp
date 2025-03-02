#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=1e5+10;
vector<int> g[N];
int depth[N];

void dfs(int vertex,int par=-1){
    for(auto i:g[vertex]){
        if(i==par) continue;
        depth[i]=depth[vertex]+1;
        dfs(i,vertex);
    }
}

int main(){
    int e;
    cin>>e;
    for(int i=0;i<e-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    dfs(1);
    int max_d=-1;
    int max_n;
    for(int i=1;i<=e;i++){
        if(max_d<depth[i]){
            max_d=depth[i];
            max_n=i;
        }
        depth[i]=0; // reset depth values
    }
    dfs(max_n);
    int diameter=-1;
    for(int i=1;i<=e;i++){
        if(diameter<depth[i]){
            diameter=depth[i];
        }
    }
    cout<<diameter<<endl;
    return 0;
}
/*
13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
4 11
*/