#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define V vector<int>
#define pb push_back
V g[N];
int sum[N];

void dfs(int v,int p=-1){
    sum[v]=v;
    for(auto i:g[v]){
        if(i==p) continue;
        dfs(i,v);
        sum[v]+=sum[i];
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
    int del=-1;
    dfs(1);
    int ans=0;
    for(int i=2;i<=e;i++){
        int part1=sum[i];
        int part2=sum[1]-sum[i];
        ans=max(ans,part1*part2);
        del=i;
    }
    cout<<del<<endl;
    return 0;
}