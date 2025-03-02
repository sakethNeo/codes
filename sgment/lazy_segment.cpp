#include <bits/stdc++.h>
using namespace std;

class SegmentTreeLazy {
    int n;
    vector<int> a, t, lazy;
    void build(int v, int tl, int tr) {
        if (tl == tr) t[v] = a[tl];
        else {
            int tm = tl + tr >> 1;
            build(2 * v + 1, tl, tm);
            build(2 * v + 1, tm + 1, tr);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }
    void push(int v) {
        t[v * 2] += lazy[v];
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
    void update(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r)
            return;
        if (l == tl && tr == r) {
            t[v] += addend;
            lazy[v] += addend;
        }
        else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), addend);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -INF;
        if (l == tl && tr == r)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return max(query(v * 2, tl, tm, l, min(r, tm)),
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
public:
    SegmentTreeLazy(vector<int>& inp) : n(inp.size()), a(inp) {
        t.resize(4 * n);
        lazy.resize(4 * n);
        build(1, 0, n - 1);
    }
    void update(int l, int r, int addend) {
        update(1, 0, n - 1, l, r, addend);
    }
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
}

class SegmentTreeAssign {
    int n;
    vector<int> a, t;
    void build(int v, int tl, int tr) {
        if (tl == tr) t[v] = a[tl];
        else {
            int tm = tl + tr >> 1;
            build(2 * v + 1, tl, tm);
            build(2 * v + 1, tm + 1, tr);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }
    void push(int v) {
        if (marked[v]) {
            t[v * 2] = t[v * 2 + 1] = t[v];
            marked[v * 2] = marked[v * 2 + 1] = true;
            marked[v] = false;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int new_val) {
        if (l > r)
            return;
        if (l == tl && tr == r) {
            t[v] = new_val;
            marked[v] = true;
        }
        else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), new_val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
        }
    }
    int get(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            return t[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return get(v * 2, tl, tm, pos);
        else
            return get(v * 2 + 1, tm + 1, tr, pos);
    }
public:
    SegmentTreeAssign(vector<int>& inp) : n(inp.size()), a(inp) {
        t.resize(4 * n);
        build(1, 0, n - 1);
    }
    void update(int l, int r, int new_val) {
        update(1, 0, n - 1, l, r, new_val);
    }
    int get(int pos) {
        return get(1, 0, n - 1, pos);
    }
};

signed main() {



}