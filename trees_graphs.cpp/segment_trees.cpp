#include<bits/stdc++.h>
using namespace std;


class SegmentTreeSum {
private:
    vector<int> a, tree;
    int n;

    void build(int i, int tl, int tr) {
        if (tl == tr) tree[i] = a[tl];
        else {
            int mid = tl + (tr - tl) / 2;
            build(2 * i, tl, mid);
            build(2 * i + 1, mid + 1, tr);
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    int query(int i, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return 0;
        if (l <= tl && r >= tr) return tree[i];
        int mid = tl + (tr - tl) / 2;
        return (query(2 * i, tl, mid, l, r) + query(2 * i + 1, mid + 1, tr, l, r));
    }
    void update(int i, int tl, int tr, int idx, int val) {
        if (tl == tr) {
            a[i] = val;
            tree[i] = val;
        }
        else {
            int mid = tl + (tr - tl) / 2;
            if (idx <= mid) update(2 * i, tl, mid, idx, val);
            else update(2 * i + 1, mid + 1, tr, idx, val);
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
public:
    SegmentTreeSum(vector<int>& nums) {
        a = nums;
        n = nums.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
};

class SegmentTreeMax {
private:
    int n;
    vector<int> a, t;
    void build(int i, int tl, int tr) {
        if (tl == tr) t[i] = a[tl];
        else {
            int mid = tl + (tr - tl) / 2;
            build(2 * i, tl, mid);
            build(2 * i + 1, mid + 1, tr);
            t[i] = max(t[2 * i], t[2 * i + 1]);
        }
    }
    int query(int i, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return INT_MIN;
        if (l <= tl && r >= tr) return t[i];
        int mid = tl + (tr - tl) / 2;
        return max(query(2 * i, tl, mid, l, r), query(2 * i + 1, mid + 1, tr, l, r));
    }
    void update(int i, int tl, int tr, int idx, int val) {
        if (idx<tl || idx>tr) return;
        if (tl == tr) a[i] = val, t[i] = val;
        else {
            int mid = tl + (tr - tl) / 2;
            if (idx <= mid) update(2 * i, tl, mid, idx, val);
            else update(2 * i + 1, mid + 1, tr, idx, val);
            t[i] = max(t[2 * i], t[2 * i + 1]);
        }
    }
public:
    SegmentTreeMax(vector<int>& inp) : n(inp.size()), a(inp), t(4 * n, 0) {
        build(1, 0, n - 1);
    }
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
    void update(int i, int val) {
        update(1, 0, n - 1, i, val);
    }
};

class SegmentTreeMin {
private:
    int n;
    vector<int> a, t;
    void build(int i, int tl, int tr) {
        if (tl == tr) t[i] = a[tl];
        else {
            int mid = tl + (tr - tl) / 2;
            build(2 * i, tl, mid);
            build(2 * i + 1, mid + 1, tr);
            t[i] = min(t[2 * i], t[2 * i + 1]);
        }
    }
    int query(int i, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return INT_MIN;
        if (l <= tl && r >= tr) return t[i];
        int mid = tl + (tr - tl) / 2;
        return min(query(2 * i, tl, mid, l, r), query(2 * i + 1, mid + 1, tr, l, r));
    }
    void update(int i, int tl, int tr, int idx, int val) {
        if (idx<tl || idx>tr) return;
        if (tl == tr) a[i] = val, t[i] = val;
        else {
            int mid = tl + (tr - tl) / 2;
            if (idx <= mid) update(2 * i, tl, mid, idx, val);
            else update(2 * i + 1, mid + 1, tr, idx, val);
            t[i] = min(t[2 * i], t[2 * i + 1]);
        }
    }
public:
    SegmentTreeMax(vector<int>& inp) : n(inp.size()), a(inp), t(4 * n, 0) {
        build(1, 0, n - 1);
    }
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
    void update(int i, int val) {
        update(1, 0, n - 1, i, val);
    }
};

int main() {
    vector<int> input = {1, 3, 5, 7, 9, 11};
    SegmentTreeSum tl(input);

    cout << "Sum of elements in range [1, 3]: " << tl.query(1, 3) << endl;

    tl.update(2, 10);

    cout << "Sum of elements in range [1, 3] after update: " << tl.query(1, 3) << endl;

    return 0;
}