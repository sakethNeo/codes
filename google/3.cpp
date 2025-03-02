#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e8;
const long long MOD = 1e9 + 7;

long long mod_pow(long long b, long long e, long long m) {
    long long r = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            r = (r * b) % m;
        }
        b = (b * b) % m;
        e /= 2;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long max_v = LLONG_MIN;
    long long res = 0;

    for (int i = 1; i <= n; ++i) {
        long long pow_v = mod_pow(INF, n - 1, MOD);
        long long val = (arr[i - 1] - arr[i]);
        long long cur_v = (val * pow_v);
        if (cur_v > max_v) {
            max_v = cur_v;
            res = cur_v;
        }
    }

    cout << res % MOD << endl;
    return 0;
}


Amwsomness factor