#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int64_t inf = 1e18;
// constexpr int mod = 998244353;
constexpr int mod = 1e9 + 7;

inline int add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

inline int sub(int& a, int b) {
    a -= b;
    if (a < 0) a += mod;
    return a;
}

inline int mul(int a, int b) {
    return (a * b) % mod;
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

// assume -mod <= x < 2*mod
int norm(int x) {
    if (x < 0) {
        x += mod;
    }
    if (x >= mod) {
        x -= mod;
    }
    return x;
}
template<class T>
T power(T a, long long b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x % mod)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(mod - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, mod - 2);
    }
    Z& operator*=(const Z& rhs) {
        x = 1LL * x * rhs.x % mod;
        return *this;
    }
    Z& operator+=(const Z& rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z& operator-=(const Z& rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z& operator/=(const Z& rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z& lhs, const Z& rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z& lhs, const Z& rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z& lhs, const Z& rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z& lhs, const Z& rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend istream& operator>>(istream& is, Z& a) {
        long long v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Z& a) {
        return os << a.val();
    }
};
// credits: jiangly

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}