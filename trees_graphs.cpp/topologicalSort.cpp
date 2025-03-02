#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &graph){
    int n=graph.size();
    vector<bool> vis(n,0);
    stack<int> st; 
    vector<int> ans; 
    vector<int> degree(n,0);
    for(auto v:graph){
        for(auto i:v) degree[i]++;
    }
    for(int i=0;i<n;i++) if(degree[i]==0){
        st.push(i); 
        ans.push_back(i);
    }
    while(!st.empty()){
        int v=st.top(); 
        st.pop();
        for(auto i:graph[v]){
            degree[i]--;
            if(degree[i]==0){
                st.push(i); 
                ans.push_back(i);
            }
        }
    }
    return ans;
}

void dfs(int src,vector<vector<int>> &graph,vector<bool> &vis,vector<int> &ans){
    vis[src]=1;
    for(auto i:graph[src]){
        if(!vis[i]) dfs(i,graph,vis,ans);
    }
    ans.push_back(src);
}
vector<int> topos(vector<vector<int>> &graph) {
    int n=graph.size();
    vector<bool> vis(n,0); 
    vector<int> ans; 
    for(int i=0;i<n;i++) if(!vis[i]) dfs(i,graph,vis,ans);
    reverse(ans.begin(),ans.end());
    return ans;
}

void solve(){
    int e,v;
    cin>>v>>e;
    vector<vector<int>> g(v);
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
    }
    vector<int> ans=topologicalSort(g);
    for(auto i:ans) cout<<i<<" ";
}

int main(){
    // write your code here
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}