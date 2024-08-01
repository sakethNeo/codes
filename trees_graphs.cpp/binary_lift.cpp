// https://cses.fi/problemset/task/1687/

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1e9+7;
const int inf=1e18;

const int mxN=2e5+1;
int n,q;
int anc[mxN][19], d[mxN];
vector<int> g[mxN];

void dfs(int u=0, int p=-1){
    anc[u][0]=p;
    for(int i=1;i<19;i++)
        anc[u][i]=~anc[u][i-1]? anc[anc[u][i-1]][i-1]:-1;
    for(auto v:g[u]){
        if(v==p) continue;
        d[v]=d[u]+1;
        dfs(v,u);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        g[--x].push_back(i);
    }
    dfs();
    while(q--){
        int x,k;
        cin>>x>>k;
        --x;
        if(d[x]<k)
            cout<<"-1\n";
        else{
            for(int i=18;i>=0;i--) if(k>>i&1)
                x=anc[x][i];
            cout<<x+1<<"\n";
        }
    }
 
    return 0;
}