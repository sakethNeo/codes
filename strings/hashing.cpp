#include <bits/stdc++.h>
using namespace std;


class RollingHash {
private:
    string s;
    int base, mod, n;
    vector<int> pf, sf, pw;
public:
    RollingHash(const string& _s, int _base = 911, int _mod = 1e9 + 7) :
        s(_s), base(_base), mod(_mod) {
        n = s.size();
        pw.resize(n, 1);
        pf.resize(n, s[0]);
        sf.resize(n, s[n - 1]);
        for (int i = 1; i < n; i++) {
            pw[i] = (1LL * pw[i - 1] * base) % mod;
            pf[i] = (pf[i - 1] + 1LL * s[i] * pw[i]) % mod;
        }
        for (int i = n - 2; i >= 0; i--) {
            sf[i] = (sf[i + 1] + 1LL * s[i] * pw[n - i - 1]) % mod;
        }
    }
    int get(int l, int r) {
        if (l == 0) return pf[r];
        int hash = (pf[r] - pf[l - 1] + mod) % mod;
        hash = (1LL * hash * pw[n - l]) % mod;
        return hash;
    }
    int rget(int l, int r) {
        if (r == n - 1) return sf[l];
        int hash = (sf[l] - sf[r + 1] + mod) % mod;
        hash = (1LL * hash * pw[r + 1]) % mod;
        return hash;
    }
};


const int p = 31;  
const int m = 1e9 + 7;

vector<long long> computePrefixHash(const string &s) {
    int n = s.size();
    vector<long long> prefixHash(n);
    vector<long long> p_pow(n);

    p_pow[0] = 1;
    prefixHash[0] = s[0] - 'a' + 1;

    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
        prefixHash[i] = (prefixHash[i - 1] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }

    return prefixHash;
}
 
long long getSubstringHash(const vector<long long> &prefixHash, int l, int r, const vector<long long> &p_pow) {
    long long hashValue = prefixHash[r];
    if (l > 0) {
        hashValue = (hashValue - prefixHash[l - 1] + m) % m;
    }
    hashValue = (hashValue * p_pow[p_pow.size() - 1 - l]) % m;
    return hashValue;
}

signed main(){

    string s = "abcddcba";
    RollingHash rh(s);
    cout << rh.get(0, 3) << " " << rh.rget(4, 7);

    return 0;
}
