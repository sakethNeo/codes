#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
const int N=1e5+10;
vector<int> g[N];
int p[N];

void dfs(int vertex,int par=-1){
    p[vertex]=par;
    for(int i:g[vertex]){
        if(i==par) continue;
        dfs(i,vertex);
    }
}

vector<int> path(int vertex){
    vector<int> ans;
    while(vertex!=-1){
        ans.push_back(vertex);
        vertex=p[vertex];
    }
    reverse(all(ans));
    return ans;
}

int main(){
    int e;
    cin>>e;
    for(int i=0;i<e-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }    
    dfs(1);
    int x,y;
    cin>>x>>y;
    vector<int> path_x=path(x);
    vector<int> path_y=path(y);
    int mn_ln=min(path_x.size(),path_y.size());
    int lca=-1;
    for(int i=0;i<mn_ln;i++){
        if(path_x[i]==path_x[y]) lca=path_x[i];
        else break;
    }
    cout<<lca<<endl;
    return 0;
}
/*
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
*/