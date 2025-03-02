#include "bits/stdc++.h"
#ifdef ONLINE_JUDGE
#define dbg(...) 007
#endif
using namespace std;

constexpr long long inf = 1e18;
#define int int64_t
// constexpr int mod = 998244353;
constexpr int mod = 1e9 + 7;

inline void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

inline int add(int&& a, int b) {
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

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

inline int add(int& a, int b) {
    a %= mod, b %= mod;
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

inline int add(int&& a, int b) {
    a %= mod, b %= mod;
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

inline int sub(int&& a, int b) {
    a %= mod, b %= mod;
    a -= b;
    if (a < 0) a += mod;
    return a;
}

inline int sub(int& a, int b) {
    a %= mod, b %= mod;
    a -= b;
    if (a < 0) a += mod;
    return a;
}

inline int mul(int&& a, int b) {
    a %= mod, b %= mod;
    return ((int64_t)a * b) % mod;
}

inline int mul(int& a, int b) {
    a %= mod, b %= mod;
    return a = ((int64_t)a * b) % mod;
}

inline int pw(int a, int b) {
    a %= mod;
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