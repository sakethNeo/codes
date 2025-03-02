#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int par[N];
int size[N];

void make(int v){
    par[v]=v;
    size[v]=1;
}

int find(int v){
    if(par[v]==v) return v;
    //path compression
    return par[v]=find(par[v]);
}

void Union(int i,int j){
    i = find(i);
    j = find(j);
    if(i==j) return;
    if(size[i]>size[j]) swap(i,j);
    par[i]=j;
    size[j]+=size[i];
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }
    sort(edges.begin(),edges.end());
    for(int i=1;i<=v;i++) make(i);
    int cost=0;
    for(auto &edge:edges){
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        cout<<u<<" "<<v<<endl;
        cost+=wt;
    }
    cout<<cost<<endl;
    return 0;
} 
/*
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
*/