#include <bits/stdc++.h>
using namespace std;

class TreeDecomposition {
private:
    struct Node {
        std::vector<int> children;
        int parent;
        int chainHead;
        int depth;
        int subtreeSize;
        int chainPosition;
        int traversalIn;
        int traversalOut;

        Node() : parent(-1), chainHead(0), depth(0),
            subtreeSize(0), chainPosition(0),
            traversalIn(0), traversalOut(0) { }
    };

    int nodeCount;
    int timeStamp;
    std::vector<Node> nodes;
    std::vector<int> linearizedTree;

    void calculateSubtreeSizes(int vertex) {
        nodes[vertex].subtreeSize = 1;

        // Sort children by subtree size in descending order
        auto& children = nodes[vertex].children;
        for (int child : children) {
            nodes[child].parent = vertex;
            nodes[child].depth = nodes[vertex].depth + 1;
            calculateSubtreeSizes(child);
            nodes[vertex].subtreeSize += nodes[child].subtreeSize;
        }

        if (!children.empty()) {
            std::sort(children.begin(), children.end(),
                [&](int a, int b) {
                return nodes[a].subtreeSize > nodes[b].subtreeSize;
            });
        }
    }

    void buildChains(int vertex) {
        linearizedTree[timeStamp] = vertex;
        nodes[vertex].traversalIn = timeStamp++;

        for (int child : nodes[vertex].children) {
            nodes[child].chainHead = (child == nodes[vertex].children[0])
                ? nodes[vertex].chainHead
                : child;
            buildChains(child);
        }
        nodes[vertex].traversalOut = timeStamp;
    }

public:
    TreeDecomposition() : nodeCount(0), timeStamp(0) { }

    explicit TreeDecomposition(int n) {
        initialize(n);
    }

    void initialize(int n) {
        nodeCount = n;
        timeStamp = 0;
        nodes.resize(n);
        linearizedTree.resize(n);
    }

    void connectNodes(int from, int to) {
        nodes[from].children.push_back(to);
        nodes[to].children.push_back(from);
    }

    void constructDecomposition(int root = 0) {
        // Clean parent-child relationships
        for (int i = 0; i < nodeCount; ++i) {
            if (!nodes[i].children.empty()) {
                nodes[i].children.erase(
                    std::remove_if(nodes[i].children.begin(), nodes[i].children.end(),
                        [&](int x) { return x == nodes[i].parent; }),
                    nodes[i].children.end()
                );
            }
        }

        nodes[root].chainHead = root;
        calculateSubtreeSizes(root);
        buildChains(root);
    }

    int findLowestCommonAncestor(int u, int v) const {
        while (nodes[u].chainHead != nodes[v].chainHead) {
            if (nodes[nodes[u].chainHead].depth < nodes[nodes[v].chainHead].depth) {
                std::swap(u, v);
            }
            u = nodes[nodes[u].chainHead].parent;
        }
        return nodes[u].depth < nodes[v].depth ? u : v;
    }

    int calculateDistance(int u, int v) const {
        int lca = findLowestCommonAncestor(u, v);
        return nodes[u].depth + nodes[v].depth - 2 * nodes[lca].depth;
    }

    int traverseUpward(int vertex, int steps) const {
        if (nodes[vertex].depth < steps) return -1;

        int targetDepth = nodes[vertex].depth - steps;
        while (nodes[nodes[vertex].chainHead].depth > targetDepth) {
            vertex = nodes[nodes[vertex].chainHead].parent;
        }

        return linearizedTree[nodes[vertex].traversalIn -
            nodes[vertex].depth + targetDepth];
    }

    bool checkAncestry(int ancestor, int descendant) const {
        return nodes[ancestor].traversalIn <= nodes[descendant].traversalIn &&
            nodes[descendant].traversalIn < nodes[ancestor].traversalOut;
    }

    int findParentInRotatedTree(int newRoot, int vertex) const {
        if (newRoot == vertex) return vertex;

        if (!checkAncestry(newRoot, vertex)) {
            return nodes[vertex].parent;
        }

        for (int child : nodes[newRoot].children) {
            if (checkAncestry(child, vertex)) {
                return child;
            }
        }
        return nodes[newRoot].children.back();
    }

    int getSubtreeSize(int newRoot, int vertex) const {
        if (newRoot == vertex) return nodeCount;

        if (!checkAncestry(vertex, newRoot)) {
            return nodes[vertex].subtreeSize;
        }

        int directParent = findParentInRotatedTree(newRoot, vertex);
        return nodeCount - nodes[directParent].subtreeSize;
    }

    int findThreeWayLCA(int a, int b, int c) const {
        return findLowestCommonAncestor(a, b) ^
            findLowestCommonAncestor(b, c) ^
            findLowestCommonAncestor(c, a);
    }
};

signed main(){

    return 0;
}

/*
struct HLD {
    int n;
    vector<int> siz, top, dep, parent, in, out, seq;
    vector<vector<int>> adj;
    int cur;

    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(find(adj[u].begin(), adj[u].end(), parent[u]));
        }

        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }

    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }

        int d = dep[u] - k;

        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }

        return seq[in[u] - dep[u] + d];
    }

    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }

    int rootedParent(int u, int v) {
        swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }

    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }

    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};
*/