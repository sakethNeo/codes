#include <bits/stdc++.h>
using namespace std;

constexpr long long inf = 1E18;
#define int int64_t
// constexpr int mod = 998244353;
constexpr int mod = 1E9 + 7;

struct Query {
    int l, r, c;
};
vector<int> answer, parent;
vector<Query> query;

void make_set(int i) {
    parent[i] = i;
}

int find_set(int v) {
    if (v != parent[v]) {
        parent[v] = find_set(parent[v]);
    }
    return v;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i <= L; i++) {
        make_set(i);
    }

    for (int i = m - 1; i >= 0; i--) {
        int l = query[i].l;
        int r = query[i].r;
        int c = query[i].c;
        for (int v = find_set(l); v <= r; v = find_set(v)) {
            answer[v] = c;
            parent[v] = v + 1;
        }
    }

    return 0;
}
