#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> A(26);
    for (int i = 0; i < 26; ++i) {
        cin >> A[i];
    }
    int K;
    cin >> K;
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
    dp[0][0] = 1;  
    for (int k = 1; k <= K; ++k) {
        for (int i = 0; i < N; ++i) {
            if (dp[k-1][i] == 0) continue; 
            vector<int> count(26, 0);
            for (int j = i; j < N; ++j) {
                int idx = S[j] - 'a';
                count[idx]++;
                if (count[idx] > A[idx]) break;
                dp[k][j + 1] = (dp[k][j + 1] + dp[k - 1][i]) % MOD;
            }
        }
    }
    cout << dp[K][N] << endl;
    return 0;
}