#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxN = 3e5;
int n;
vector<vector<int>> g(N);
int sz[N];
bool dead[N];


struct edge {
    int node = -1;
    int64_t weight = 0;

    edge() {}

    edge(int _node, int64_t _weight) : node(_node), weight(_weight) {}
};

struct centroid_decomposition {
    int N;
    vector<vector<edge>> adj;
    vector<int> depth;
    vector<int> subtree_size;
    vector<int> centroid_parent;
    vector<int> subroot;
    vector<int> nodes;

    centroid_decomposition(int _N = 0) {
        init(_N);
    }

    void init(int _N) {
        N = _N;
        adj.assign(N, {});
        depth.resize(N);
        subtree_size.resize(N);
        centroid_parent.assign(N, -1);
        subroot.resize(N);
    }

    void add_edge(int u, int v, int64_t weight = 0) {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);
    }

    void erase_edge(int from, int to) {
        for (edge &e : adj[from])
            if (e.node == to) {
                swap(e, adj[from].back());
                adj[from].pop_back();
                return;
            }

        assert(false);
    }

    int dfs(int node, int parent = -1, int sub = -1, int64_t weight = 0) {
        if (parent < 0) {
            sub = node;
            nodes.clear();
        }

        depth[node] = parent < 0 ? 0 : depth[parent] + 1;
        subtree_size[node] = 1;
        subroot[node] = sub;
        nodes.push_back(node);

        for (edge &e : adj[node])
            if (e.node != parent)
                subtree_size[node] += dfs(e.node, node, parent < 0 ? e.node : sub, weight + e.weight);

        return subtree_size[node];
    }

    int centroid(int root) {
        int n = dfs(root);
        bool found;

        // Repeatedly move to the subtree that is at least half of the tree, if such a subtree exists.
        do {
            found = false;

            for (edge &e : adj[root])
                if (subtree_size[e.node] < subtree_size[root] && 2 * subtree_size[e.node] >= n) {
                    root = e.node;
                    found = true;
                    break;
                }
        } while (found);

        return root;
    }

    void solve(int root) {
        root = centroid(root);

        for (int node : nodes)
            if (node != root)
                centroid_parent[node] = root;

        // TODO: either compute the answer for the whole tree here by calling `dfs(root)`, or compute it for each
        // subtree below by calling `dfs(e.node)`.

        for (edge &e : adj[root]) {
            erase_edge(e.node, root);
            // TODO: either compute the answer for the subtree of `e.node` here, or compute it for the whole tree above.
            // If computing for the whole tree above, we can move the `erase_edge` call to the loop below instead.
        }

        // Recurse after solving root, so that edge erasures don't cause incorrect results.
        for (edge &e : adj[root])
            solve(e.node);
    }
};

void solve(int v) {
    function<void(int,int)> pdfs=[&](int v,int pr){
        sz[v]=1;
        for(int u:g[v]){
            if(u==pr || dead[u]) continue;
            pdfs(u,v);
            sz[v]+=sz[u];
        }
    };
    function<int(int,int)> fct=[&](int num,int v,int pr){
        for(int u:g[v])
            if(u!=pr && !dead[u] && 2*sz[u]>num)
                return fct(num,u,v);
        return v;
    };
    pdfs(v,-1);
    int ct=fct(sz[v],v);
    dead[v]=true;
    for(int u:g[v])
        if(!dead[u])
            solve(u);
}

int get_subtree_size(int node, int parent = -1) {
	int &res = subtree_size[node];
	res = 1;
	for (int i : adj[node]) {
		if (i == parent) { continue; }
		res += get_subtree_size(i, node);
	}
	return res;
}

int get_centroid(int node, int parent = -1) {
	for (int i : adj[node]) {
		if (i == parent) { continue; }

		if (subtree_size[i] * 2 > n) { return get_centroid(i, node); }
	}
	return node;
}

signed main() {
    
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
