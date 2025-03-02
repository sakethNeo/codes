#include <bits/stdc++.h>
using namespace std;

#define int long long
constexpr int inf = (int)2e18;
constexpr int mod = (int)1e9 + 7;


class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int m = pairs.size();
        // Eulerian Path
        unordered_map<int, stack<int>> adj;
        unordered_map<int, int> in;
        unordered_map<int, int> out;
		// reserve spaces for unordered_map may help in runtime.
		adj.reserve(m);
		in.reserve(m);
		out.reserve(m);
        for (int i = 0; i < m; i++) {
            int u = pairs[i][0], v = pairs[i][1];
            in[v]++;
            out[u]++;
            adj[u].push(v);
        }
		// find the starting node
        int start = -1;
        for (auto& p : adj) {
            int i = p.first;
            if (out[i] - in[i] == 1) start = i;
        }
        if (start == -1) {
			// Eulerian Circuit -> start at any node
			start = adj.begin()->first;
        }
        vector<vector<int>> ans;
        euler(adj, ans, start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    void euler(unordered_map<int, stack<int>>& adj, vector<vector<int>>& ans, int curr) {
        auto& stk = adj[curr];
        while (!stk.empty()) {
            int nei = stk.top();
            stk.pop();
            euler(adj, ans, nei);
			// postorder
            ans.push_back({curr, nei});
        }
    }
};
// leetcode 2097

void solve() {
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
