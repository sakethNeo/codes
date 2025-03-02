#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 101;
int dp[MAX_N][MAX_N];
bool seen[1000];

int mex(vector<int>& values) {
    memset(seen, 0, sizeof(seen));
    for (int x : values) seen[x] = true;
    for (int i = 0; i < 1000; i++) {
        if (!seen[i]) return i;
    }
    return 999;
}

int grundy(int i, int j) {
    // Base cases
    if (i == 0 || j == 0 || i == j) return 999;
    // if losing just write 0 there instead of 999

    // If already calculated
    if (dp[i][j] != -1) return dp[i][j];

    vector<int> values;

    // Get Grundy numbers of all positions that can reach (i,j)

    // Vertical moves: positions that can reach (i,j) from above
    for (int k = 0; k < i; k++) {
        values.push_back(grundy(k, j));
    }

    // Horizontal moves: positions that can reach (i,j) from left
    for (int k = 0; k < j; k++) {
        values.push_back(grundy(i, k));
    }

    // Diagonal moves
    int mini = min(i, j);
    for (int k = 1; k <= mini; k++) {
        values.push_back(grundy(i - k, j - k));
    }

    // Calculate and store mex value
    return dp[i][j] = mex(values);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialize dp array
    memset(dp, -1, sizeof(dp));

    // Read input
    int n, xor_sum = 0;
    cin >> n;

    while (n--) {
        int row, col;
        cin >> row >> col;
        xor_sum ^= grundy(row, col);
    }

    cout << (xor_sum == 0 ? "N" : "Y") << endl;

    return 0;
}