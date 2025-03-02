#include <bits/stdc++.h>
using namespace std;


class SegmentTreeMax {
    vector<int> a, t;
private:
    SegmentTreeMax(vector<int>& inp) : a(inp) {
        int n = a.size();
        t.resize(n << 2);
        build(0, 0, n - 1, 0);
    }
    void build(int v, int tl, int tr) {
        if (tl == tr) t[v] = a[v];
        else {
            int tm = (tl + tr) / 2;
            build(2 * v, tl, tm);
            build(2 * v + 1, tm + 1, tr);
            t[v] = max(t[2 * v], t[2 * v + 1]);
        }
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) return -1e9;
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return max(get(2 * v, tl, tm, l, min(tm, r)),
            get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
    }
    void update(int v, int i, int val, int tl, int tr) {
        if (tl == tr) t[v] = val;
        else {
            int tm = (tl + tr) / 2;
            if (i <= tm) update(2 * v, i, val, tl, tm);
            else update(2 * v + 1, i, val, tm + 1, tr);
            t[v] = max(t[2 * v], t[2 * v + 1]);
        }
    }
    int get_first(int v, int val, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return -1;
        if (t[v] <= val) return -1;
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int res = get_first(2 * v, val, tl, tm, l, r);
        if (res != -1) return res;
        return get_first(2 * v + 1, val, tm + 1, tr, l, r);
    }
public:
    int get(int l, int r) {
        return get(0, 0, n - 1, l, r);
    }
    void update(int i, int val) {
        update(0, i, val, 0, n - 1);
    }
    int get_first(int l, int r, int val) {
        return get_first(0, val, 0, n - 1, l, r);
    }
}


signed main() {

    return 0;
}