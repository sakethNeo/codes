#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
const int inf = 1e18;

int n;
int s[3001], c[3001];
int dp[3001][4];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> c[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i][j] = inf;
        }
    }

    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int k = 1; k <= 3; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (s[j] < s[i]) {
                    dp[i][k] = min(dp[i][k], dp[j][k-1] + c[i]);
                }
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp[i][3]);
    }

    if (ans < inf) cout << ans << "\n";
    else cout << "-1\n";

    return 0;
}
