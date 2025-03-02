#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=1e3+10;
vector<int> g[N];
bool vis[N];

vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex){
    vis[vertex]=true;
    current_cc.push_back(vertex);
    for(auto i:g[vertex]){
        if(vis[i]) continue;
        dfs(i);
    }
}

// shit starts
    vector<vector<int>> cc; 
    vector<bool> vis(n+1,0);
    vector<int> t;
    function<void(int)> dfs=[&](int s)->void {
        vis[s]=1; t.push_back(s);
        for(auto i:g[s]){
            if(!vis[i]) dfs(i);
        }
    };
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i); cc.push_back(t);
            t.clear();
        }
    }
    fill(vis.begin(),vis.end(),0);
    function<bool(int,int)> loop=[&](int s,int p=0)->bool {
        vis[s]=1;
        for(auto i:g[s]){
            if(i!=p && vis[i]) return 1;
            else if(i==p) continue;
            else return loop(i,s);
        }
    };
    int cyc=0;
    for(auto v:cc){
        for(auto i:v){
            if(loop(i,0)) cyc++;
            break;
        }
    }
// shit ends
int main(){
    int v,e;
    cin>>v>>e;
    for(int i=1;i<=e;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for(int i=1;i<=v;i++){
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
    }
    cout<<cc.size()<<"\n";
    for(auto i:cc){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
/*
8 5
1 2
2 3
2 4
3 5
6 7
*/