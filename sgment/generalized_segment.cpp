#include <bits/stdc++.h>
using namespace std;

constexpr int64_t inf = 1e18;
#define int int64_t
// constexpr int mod = 998244353;
constexpr int mod = 1e9 + 7;


template<typename node>
class SegmentTree {
    int n;
    vector<int> a;
    vector<node> t;
    node query(int v, int l, int r, int tl, int tr) {
        if (l > tr || r < tl) return node();
        if (l <= tl && r >= tr) {
            return t[v];
        }
        int tm = (tl + tr) >> 1;
        return query(v + v, l, r, tl, tm) + query(v + v + 1, l, r, tm + 1, tr);
    }
    void update(int v, int x, int tl, int tr) {
        if (tl == tr) t[v] = node(x);
        else {
            int tm = (tl + tr) >> 1;
            if (x <= tm) update(v + v, x, tl, tm);
            else update(v + v + 1, x, tm + 1, tr);
            t[v] = t[v + v] + t[v + v + 1];
        }
    }
public:
    SegmentTree(vector<int>& inp) : a(inp) {
        n = inp.size();
        t.resize(4 * n);
        build(1, 0, n - 1);
    }
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = node(a[tl]);
        }
        else {
            int tm = (tl + tr) >> 1;
            build(v + v, tl, tm);
            build(v + v + 1, tm + 1, tr);
            t[v] = t[v + v] + t[v + v + 1];
        }
    }
    node query(int l, int r) {
        return query(1, l, r, 0, n - 1);
    }
    void update(int i, int x) {
        update(i, x, 0, n - 1);
    }
};

struct node {
    node() {

    }
    node(int x) {

    }
    node operator+(const node& other) {

    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}