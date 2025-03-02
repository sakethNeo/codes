#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;
#define V vector<int>
#define pi pair<int,int>
#define vpi vector<pair<int,int>>
#define ff first
#define ss second
#define pb push_back
#define all(v) v.begin(),v.end()
V g[N];
int lev[N];
bool vis[N];

void bfs(int v){
    queue<int> q;
    q.push(v);
    vis[v]=true;
    while(!q.empty()){
        int cur_v=q.front();
        q.pop();
        for(auto i:g[cur_v]){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
                lev[i]=lev[cur_v]+1;
            }
        }
    }
}

auto bfs = [&](int s) {
    vector<int> dis(n, -1);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (auto y : g[x]) {
            if (dis[y] == -1) {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }
    return dis;
};

int main(){
    int e;
    cin>>e;
    for(int i=0;i<e-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    bfs(1);
    return 0;
}