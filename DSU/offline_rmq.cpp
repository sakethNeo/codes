#include <bits/stdc++.h>
using namespace std;

constexpr long long inf = 1E18;
#define int int64_t
// constexpr int mod = 998244353;
constexpr int mod = 1E9 + 7;


struct Query {
    int L, R, idx;
};

vector<int> answer;
vector<int> parent;
vector<vector<Query>> container;
stack<int> s;

int find_set(int v) {
    if (v != parent[v]) {
        parent[v] = find_set(parent[v]);
    }
    return v;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10;
    parent.resize(n);
    answer.resize(n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] > a[i]) {
            parent[s.top()] = i;
            s.pop();
        }
        s.push(i);
        for (Query q : container[i]) {
            // container[i] has queries with R == i
            answer[q.idx] = a[find_set(q.L)];
        }
    }

    return 0;
}
