#include<bits/stdc++.h>
using namespace std;

const int N=1e3;
vector<int> g[N];
int height[N],depth[N];

void dfs(int vertex,int par=0){
    for(auto i:g[vertex]){
        if(i==par) continue;
        depth[i]=depth[vertex]+1;
        dfs(i,vertex);
        height[vertex]=max(height[vertex],height[i]+1);
    }
}
// path shit
vector<vector<int>> path;
vector<int> t;
function<void(int,int,vector<int>&)> dfs = [&](int s, int p, vector<int> &t)->void {
    t.push_back(s);
    bool isLeaf = true;
    for (auto u : g[s]) {
        if (u == p) continue;
        isLeaf = false;
        dfs(u, s, t);
    }
    if (isLeaf)
        path.push_back(t);
    t.pop_back();
};

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
    for(int i=1;i<=e;i++){
        cout<<i<<". "<<"height="<<height[i]<<" "<<"depth="<<depth[i]<<"\n";
    }
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