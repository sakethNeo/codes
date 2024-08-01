#include <bits/stdc++.h>
using namespace std;

const int mxn=2e5;
int m,n;
vector<int> g[mxn];
int in[mxn], low[mxn];
int timer;
int cut_points;
bool vis[mxn];

void dfs(int s,int p=-1){
    vis[s]=true;
    in[s]=low[s]=timer++;
    int children=0;
    for(int u:g[s]){
        if(u==p) continue;
        if(vis[u])
            low[s]=min(low[s],in[u]);
        else{
            dfs(u,s);
            low[s]=min(low[s],low[u]);
            if(low[u]>=in[s] && p!=-1)
                cut_points++;
            ++children;
        }
    }
    if(children>1 && p==-1) cut_points++;
}

signed main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    cout<<cut_points<<endl;
}
