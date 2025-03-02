using ll = long long;

class SegTree {
    vector<ll> tree;
    vector<ll> A;
    ll n;

public:
    SegTree(const vector<int>& arr) {
        n = arr.size();
        A = vector<ll>(arr.begin(), arr.end());
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    void build(ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = A[start];
        } else {
            ll mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void upd(ll idx, ll val, ll node, ll start, ll end) {
        if (start == end) {
            A[idx] = val;
            tree[node] = val;
        } else {
            ll mid = (start + end) / 2;
            if (idx <= mid) {
                upd(idx, val, 2 * node + 1, start, mid);
            } else {
                upd(idx, val, 2 * node + 2, mid + 1, end);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    ll qry(ll L, ll R, ll node, ll start, ll end) {
        if (R < start || end < L) {
            return 0;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        ll mid = (start + end) / 2;
        ll left = qry(L, R, 2 * node + 1, start, mid);
        ll right = qry(L, R, 2 * node + 2, mid + 1, end);
        return left + right;
    }

    void upd(ll idx, ll val) {
        upd(idx, val, 0, 0, n - 1);
    }

    ll qry(ll L, ll R) {
        return qry(L, R, 0, 0, n - 1);
    }
};

vector<ll> solve(int N, int l, vector<int> A, vector<vector<int>> query) {
    SegTree segTree(A);
    vector<ll> results;

    for (const auto& q : query) {
        if (q[0] == 1) {
            int idx = q[1];
            int val = q[2];
            segTree.upd(idx - 1, val);
        } else if (q[0] == 2) {
            int L = q[1];
            int R = q[2];
            ll sum = 0;
            for (int i = L - 1; i < R; ++i) {
                for (int j = i; j < R; ++j) {
                    sum += segTree.qry(i, j);
                }
            }
            results.push_back(sum);
        }
    }

    return results;
}