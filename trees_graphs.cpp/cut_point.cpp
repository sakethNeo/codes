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

void IS_CUTPOINT(int v) {
    
}

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int u : g[v]) {
        if (u == p) continue;
        if (vis[u]) {
            low[v] = min(low[v], tin[u]);
        }
        else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] >= tin[v] && p != -1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cutpoints() {
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
    find_cutpoints();

    return 0;
}
