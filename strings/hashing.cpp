#include <iostream>
#include <vector>

using namespace std;

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

    string s = "example";
    vector<long long> prefixHash = computePrefixHash(s);
    vector<long long> p_pow(s.size());
    p_pow[0] = 1;
    for (int i = 1; i < s.size(); i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }

    return 0;
}
