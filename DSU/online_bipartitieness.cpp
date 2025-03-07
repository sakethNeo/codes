#include <bits/stdc++.h>
using namespace std;

constexpr long long inf = 1E18;
#define int int64_t
// constexpr int mod = 998244353;
constexpr int mod = 1E9 + 7;

vector<int> rank;
vector<pair<int, int>> parent;
vector<bool> bipartite;

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    rank[v] = 0;
    bipartite[v] = true;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

void add_edge(int a, int b) {
    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            bipartite[a] = false;
    }
    else {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = make_pair(a, x ^ y ^ 1);
        bipartite[a] &= bipartite[b];
        if (rank[a] == rank[b])
            ++rank[a];
    }
}

bool is_bipartite(int v) {
    return bipartite[find_set(v).first];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}
