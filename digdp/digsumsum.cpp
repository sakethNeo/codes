#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[20][2][200]; 

int dpDigitSum(string &s, int n, bool t, int sum) {
    if (n == 0) return sum;
    if (dp[n][t][sum] != -1) return dp[n][t][sum];
    
    int ub = t ? s[s.size() - n] - '0' : 9;
    int ans = 0;
    for (int i = 0; i <= ub; i++)
        ans += dpDigitSum(s, n - 1, t && (i == ub), sum + i);

    return dp[n][t][sum] = ans;
}

int findingDigitSum(string &s) {
    memset(dp, -1, sizeof(dp)); 
    return dpDigitSum(s, s.size(), true, 0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    a--;
    string l = to_string(a), r = to_string(b);
    cout << findingDigitSum(r) - findingDigitSum(l);

    return 0;
}
