#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> g[N];
bool vis[N];
int n;
bool dfs(int vertex,int par);

// bottom one not only tells if there is a loop but it returns the loop!!
vector<bool> vis(n+1,false);
vector<int> par(n+1,-1);
function<bool(int,int,vector<int>&)> dfs = [&](int v, int p, vector<int>& t)->bool {
    vis[v] = true;
    for (auto& i : g[v]) {
        int u = i.first;
        if (u == p) continue;
        if (vis[u]) {
            t.push_back(u);
            int in = v;
            while (in != u) {
                t.push_back(in);
                in = par[in];
            }
            return true;
        }
        par[u] = v;
        if (dfs(u, v, t)) return true;
    }
    return false;
};
// ends

// skibidi cycle detector
auto hasCycle = [&]() -> bool {
    vector<bool> c(n, 0);
    function<bool(int)> df = [&](int u) -> bool {
        c[u] = 1;
        for (int v : g[u]) {
            if (c[v] == 1 || (c[v] == 0 && df(v))) return true;
        }
        c[u] = 0;
        return false;
    };
    for (int i = 0; i < n; ++i) {
        if (c[i] == 0 && df(i)) return true;
    }
    return false;
};
// the end

int main(){

    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool boo=false;
    for(int i=1;i<=v;i++){
        if(vis[i]) continue;
        if(dfs(i,0)){
            boo=true;
            break;
        }
    }
    cout<<((boo)? "loop!!\n":"no loop\n");
    return 0;
}

bool dfs(int vertex,int par){
    vis[vertex]=true;
    bool isLoopExists=false;
    for(auto i:g[vertex]){
        if(vis[i] && i==par) continue;
        if(vis[i]) return true;
        isLoopExists|=dfs(i,vertex);
    }
    return isLoopExists;
}