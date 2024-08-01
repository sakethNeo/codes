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
vpi g[N];
V lev(N,INF);
bool vis[N];
int v,e;

int bfs(){
    deque<int> q;
    q.push_back(1);
    lev[1]=0;
    while(!q.empty()){
        int cur_v=q.front();
        q.pop_front();
        for(auto i:g[cur_v]){
            int i_v=i.ff;
            int wt=i.ss;
            if(lev[cur_v]+wt < lev[i_v]){
                lev[i_v]=lev[cur_v]+1;
                if(wt) q.push_back(i_v);
                else q.push_front(i_v);
            }
        }
    }
    return lev[v] == INF ? -1:lev[v];
}

int main(){
    cin>>v>>e;
    for(int i=0;i<e-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].pb({v2,0});
        g[v2].pb({v1,1});
    }
    cout<<bfs()<<endl;
    return 0;
}