#include <bits/stdc++.h>

template<typename FlowType>
class NetworkFlow {
private:
    struct FlowEdge {
        int dest;
        FlowType capacity;
        FlowEdge(int d, FlowType c) : dest(d), capacity(c) { }
    };

    int vertices;
    std::vector<FlowEdge> edges;
    std::vector<std::vector<int>> adjacency;
    std::vector<int> distance;
    std::vector<int> edgePointer;

    bool buildLevelGraph(int source, int sink) {
        distance.assign(vertices, -1);
        std::queue<int> bfsQueue;

        distance[source] = 0;
        bfsQueue.push(source);

        while (!bfsQueue.empty()) {
            int current = bfsQueue.front();
            bfsQueue.pop();

            for (int edgeIdx : adjacency[current]) {
                auto [nextVertex, remainingFlow] = edges[edgeIdx];
                if (remainingFlow > 0 && distance[nextVertex] == -1) {
                    distance[nextVertex] = distance[current] + 1;
                    if (nextVertex == sink) return true;
                    bfsQueue.push(nextVertex);
                }
            }
        }
        return false;
    }

    FlowType pushFlow(int vertex, int sink, FlowType currentFlow) {
        if (vertex == sink) return currentFlow;

        FlowType remainingFlow = currentFlow;
        for (int& i = edgePointer[vertex]; i < (int)adjacency[vertex].size(); ++i) {
            int edgeIdx = adjacency[vertex][i];
            auto [nextVertex, capacity] = edges[edgeIdx];

            if (capacity > 0 && distance[nextVertex] == distance[vertex] + 1) {
                FlowType bottleneck = pushFlow(nextVertex, sink, std::min(remainingFlow, capacity));
                edges[edgeIdx].capacity -= bottleneck;
                edges[edgeIdx ^ 1].capacity += bottleneck;
                remainingFlow -= bottleneck;

                if (remainingFlow == 0) return currentFlow;
            }
        }
        return currentFlow - remainingFlow;
    }

public:
    NetworkFlow() : vertices(0) { }
    explicit NetworkFlow(int n) {
        initialize(n);
    }

    void initialize(int n) {
        vertices = n;
        edges.clear();
        adjacency.assign(n, { });
        edgePointer.resize(n);
        distance.resize(n);
    }

    void addConnection(int from, int to, FlowType capacity) {
        adjacency[from].push_back(edges.size());
        edges.emplace_back(to, capacity);
        adjacency[to].push_back(edges.size());
        edges.emplace_back(from, 0);
    }

    FlowType maximumFlow(int source, int sink) {
        FlowType totalFlow = 0;
        while (buildLevelGraph(source, sink)) {
            edgePointer.assign(vertices, 0);
            totalFlow += pushFlow(source, sink, std::numeric_limits<FlowType>::max());
        }
        return totalFlow;
    }

    std::vector<bool> getMinCut() {
        std::vector<bool> reachable(vertices);
        for (int i = 0; i < vertices; ++i) {
            reachable[i] = (distance[i] != -1);
        }
        return reachable;
    }

    struct FlowInfo {
        int origin;
        int destination;
        FlowType maxCapacity;
        FlowType currentFlow;
    };

    std::vector<FlowInfo> getFlowDetails() {
        std::vector<FlowInfo> result;
        for (int i = 0; i < (int)edges.size(); i += 2) {
            FlowInfo info;
            info.origin = edges[i + 1].dest;
            info.destination = edges[i].dest;
            info.maxCapacity = edges[i].capacity + edges[i ^ 1].capacity;
            info.currentFlow = edges[i ^ 1].capacity;
            result.push_back(info);
        }
        return result;
    }
};

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    MaxFlow<int> g(n + 62);
    int s = n + 60, t = s + 1;
    
    for (int i = 0; i < n; i++) {
        g.addEdge(s, i, 1);
        for (int j = 0; j < 60; j++) {
            if (a[i] >> j & 1) {
                g.addEdge(i, n + j, int(1E9));
            }
        }
    }
    for (int j = 0; j < 60; j++) {
        g.addEdge(n + j, t, 1);
    }
    
    int ans = n - g.flow(s, t);
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

/*
template<class T>
struct MaxFlow {
    struct _Edge {
        int to;
        T cap;
        _Edge(int to, T cap) : to(to), cap(cap) {}
    };
    int n;
    std::vector<_Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    MaxFlow() {}
    MaxFlow(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (int i : g[u]) {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }
    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T flow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }
    std::vector<bool> minCut() {
        std::vector<bool> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = (h[i] != -1);
        }
        return c;
    }
    struct Edge {
        int from;
        int to;
        T cap;
        T flow;
    };
    std::vector<Edge> edges() {
        std::vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2) {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};
*/

