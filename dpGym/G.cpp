#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
const int inf = 1e18;

vector<vector<int>> dp(101, vector<int>(2001, -inf));
int u, v;
int t, d;

int cal(int i, int val)
{
    if (i == 0)
        return dp[i][val] = (val == u) ? val : -inf;
    int ans = -inf;
    for (int j = -d; j <= d; j++)
    {
        if (val > -j)
            ans = max(ans, val + cal(i - 1, val + j));
    }
    return dp[i][val] = ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> u >> v;
    cin >> t >> d;

    dp[0][u] = u;
    for (int i = 1; i < t; i++)
    {
        for (int j = 0; j < 2001; j++)
        {
            for (int k = -d; k <= d; k++)
            {
                if (j + k > 0)
                    dp[i][j] = max(dp[i][j], j + dp[i - 1][j + k]);
            }
        }
    }

    cout << dp[t - 1][v] << "\n";

    return 0;
}
