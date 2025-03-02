#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
const vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
const vector<char> dirChar = {'L', 'R', 'U', 'D'};
int minCostToReachDestination(int N, vector<vector<char>>& Dir, int Sx, int Sy, int Dx, int Dy) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<int>> cost(N, vector<int>(N, INT_MAX));
    pq.push({0, {Sx, Sy}});
    cost[Sx][Sy] = 0;
    
    while (!pq.empty()) {
        auto [curCost, pos] = pq.top();
        pq.pop();
        
        int x = pos.first;
        int y = pos.second;
                if (x == Dx && y == Dy) {
            return curCost;
        }
            for (int i = 0; i < 4; ++i) {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                int newCost = curCost + (Dir[x][y] == dirChar[i] ? 0 : 1);
                if (newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }
    
    return -1;
}