#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAX_N = 300005;
 
int bridgec;
vector<int> adj [MAX_N];
int in [MAX_N];
int low [MAX_N];
int timer;
 
void dfs (int vertex, int parent) {
  timer++;
  in[vertex] = timer;
  low[vertex] = timer;
 
  for (int nxt : adj[vertex]) {
    if (in[nxt] == 0) { // not visited
      dfs(nxt, vertex);
      low[vertex] = min(low[vertex], low[nxt]);
      if (low[nxt] > in[vertex]) {
        bridgec++;
      }
    } else if (nxt != parent) {
      low[vertex] = min(low[vertex], in[nxt]);
    }
  }
}
 
int main () {
  /* problem statement: given a connected graph. calculate the number of bridges. */
  ios::sync_with_stdio(false);
 
  int vertexc, edgec;
  cin >> vertexc >> edgec;
 
  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;
 
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
 
  dfs(1, 0);
 
  cout << bridgec << endl;
}

/*
4 4
1 2
2 3
3 4
4 2
*/