#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int mex(vector<int>& v) {
    int n = v.size();
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (v[i] < n) vis[v[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) return i;
    }
    return n;
}

const int mod = 1e9 + 7;

inline int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

inline int sub(int a, int b) {
    a -= b;
    if (a < 0) a += mod;
    return a;
}

inline int mul(int a, int b) {
    return ((int64_t)a * b) % mod;
}

inline int pw(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int inv(int a) {
    return pw(a, mod - 2);
}

inline int dv(int a, int b) {
    return mul(a, inv(b));
}

const int N = (int)1000100;
bool factorialsdone;
vector<int> fact, invfact;

void computefactorials(int n) {
    if (factorialsdone) return;
    fact.resize(N);
    invfact.resize(N);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], i);
        invfact[i] = inv(fact[i]);
    }
    factorialsdone = 1;
}

int C(int n, int r) {
    if (r > n) return 0;
    computefactorials(n);
    return mul(fact[n], mul(invfact[n - r], invfact[r]));
}


signed main() {
    vector<int> nums = {3289, 2832, 14858, 22011};
    cout << mul(pw(nums[2], 5), pw(nums[3], 1)) << "\n";
    return 0;
}
