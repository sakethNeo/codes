#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int inf=1e18;
#define all(v) v.begin(),v.end()
vector<pair<int,int>> g[N];
int n,e;

auto dij(int s){
    vector<int> d(n+1,inf);
    d[s]=0;
    priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> pq;
    pq.push({0,s});
    while(!pq.empty()){ 
        int w,v;
        tie(w,v)=pq.top();
        pq.pop();
        if(w>d[v]) continue;
        for(auto p:g[v]){
            int nv=p.first,nw=p.second;
            if(d[nv]>d[v]+nw){
                d[nv]=d[v]+nw;
                pq.push({d[nv],nv});
            }
        }
    }
    return d;
}

signed main(){

    cin>>n>>e;
    for(int i=0;i<e;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        g[v1].push_back({v2,wt});
    }
    auto dis=dij(1);
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";

    return 0;
}
/*
6 9
1 2 1
1 3 5
2 3 2
3 5 2
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2
*/