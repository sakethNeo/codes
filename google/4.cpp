#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007
#define ALPHABET_SIZE 26

using namespace std;

int solve(int N, int M, vector<pair<char, char>> &Pairs) {
    bool forbidden[ALPHABET_SIZE][ALPHABET_SIZE];
    memset(forbidden, false, sizeof(forbidden));

    for (int i = 0; i < M; ++i) {
        int u = Pairs[i].first - 'a';
        int v = Pairs[i].second - 'a';
        forbidden[u][v] = true;
        forbidden[v][u] = true;
    }

    for (int k = 0; k < ALPHABET_SIZE; ++k) {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            for (int j = 0; j < ALPHABET_SIZE; ++j) {
                if(i == j)
                    continue;
                    
                forbidden[i][j] = forbidden[i][j] || (forbidden[i][k] && forbidden[k][j]);
            }
        }
    }

    vector<vector<int>> dp(N + 1, vector<int>(ALPHABET_SIZE, 0));

    for (int c = 0; c < ALPHABET_SIZE; ++c) {
        dp[1][c] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        for (int c = 0; c < ALPHABET_SIZE; ++c) {
            for (int p = 0; p < ALPHABET_SIZE; ++p) {
                if (!forbidden[p][c]) {
                    dp[i][c] = (dp[i][c] + dp[i - 1][p]) % MOD;
                }
            }
        }
    }

    int result = 0;
    for (int c = 0; c < ALPHABET_SIZE; ++c) {
        result = (result + dp[N][c]) % MOD;
    }

    return result;
}