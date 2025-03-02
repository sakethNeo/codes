#include <bits/stdc++.h>
using namespace std;

constexpr long long inf = 1e18;
#define int int64_t
// constexpr int mod = 998244353;
constexpr int mod = 1e9 + 7;


int n, m;
vector<vector<int>> g;

vector<bool> vis;
vector<int> tin, low;
int timer;

void IS_BRIDGE(int v, int u) {

}

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for (int u : g[v]) {
        if (u == p) continue;
        if (vis[u]) {
            low[v] = min(low[v], tin[u]);
            // back edge between v and u
        }
        else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > tin[v])
                IS_BRIDGE(v, u);
                // if the child's and all of it's decendants has in_time > in_time of v then it's a bridge
        }
    }
}

void find_bridges() {
    timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs(i);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    find_bridges();

    return 0;
}


/*
12 16
1 3
1 5
1 6
1 9
3 5
3 7
3 8
3 6
9 11
9 12
5 7
6 2
11 12
2 8
2 4
4 10
*/