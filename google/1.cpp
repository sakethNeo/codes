#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> points;
pair<int, int> start;
vector<int> dp;

int manhattanDistance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int mask) {
    if (mask == (1 << N) - 1) return 0; 
    if (dp[mask] != -1) return dp[mask]; 

    int res = INT_MAX;
    for (int i = 0; i < N; ++i) {
        if (!(mask & (1 << i))) { 
            int cost = 2 * manhattanDistance(start, points[i]);
            res = min(res, cost + solve(mask | (1 << i))); 
            for (int j = i + 1; j < N; ++j) {
                if (!(mask & (1 << j))) { 
                    cost = manhattanDistance(start, points[i]) +
                           manhattanDistance(points[i], points[j]) +
                           manhattanDistance(points[j], start);
                    res = min(res, cost + solve(mask | (1 << i) | (1 << j)));
                }
            }
        }
    }
    return dp[mask] = res;
}

int main() {
    cin >> N;
    points.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i]. first >> points[i].second;
    }
    cin >> start.first >> start.second;
    dp.resize(1 << N, -1); 
    cout << solve(0) << endl; 
    return 0;
}