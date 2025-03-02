#include <bits/stdc++.h>
using namespace std;


class SegmentTreeMax {
    vector<int> a;
    vector<vector<int>> t;
private:
    SegmentTreeMax(vector<int>& inp) : a(inp) {
        int n = a.size();
        t.resize(n << 2);
        build(0, 0, n - 1, 0);
    }
    void build(int v, int tl, int tr) {
        if (tl == tr) t[v] = vector<int>(1, a[v]);
        else {
            int tm = (tl + tr) / 2;
            build(2 * v, tl, tm);
            build(2 * v + 1, tm + 1, tr);
            merge(t[2 * v].begin(), t[2 * v].end(), t[2 * v + 1].begin(), t[2 * v + 1].end(),
                back_inserter(t[v]));
        }
    }
    int get(int v, int val, int tl, int tr, int l, int r) {
        if (l > r) return -1e9;
        if (l == tl && r == tr) {
            auto lb = lower_bound(t[v].begin(), t[v].end(), val);
            return (lb != t[v].end()) ? *lb : -1e9;
        }
        int tm = (tl + tr) / 2;
        return min(get(2 * v, tl, tm, l, min(tm, r)),
            get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
    }
public:
    int get(int l, int r) {
        return get(0, 0, n - 1, l, r);
    }
}

// to use update use multiset instead of vector 
/*
void update(int v, int tl, int tr, int pos, int new_val) {
    t[v].erase(t[v].find(a[pos]));
    t[v].insert(new_val);
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
    } else {
        a[pos] = new_val;
    }
}
*/

signed main() {

    return 0;
}