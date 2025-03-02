function findCentralHub(graph, n) {
    const adjList = Array.from({ length: n }, () => []);

    for (const [u, v] of graph) {
        adjList[u].push(v);
        adjList[v].push(u);
    }

    const centrality = Array(n).fill(0);

    function bfs(start) {
        const distances = Array(n).fill(Infinity);
        const numShortestPaths = Array(n).fill(0);
        const predecessors = Array.from({ length: n }, () => []);
        const stack = [];
        const queue = [start];

        distances[start] = 0;
        numShortestPaths[start] = 1;

        while (queue.length > 0) {
            const node = queue.shift();
            stack.push(node);

            for (const neighbor of adjList[node]) {
                if (distances[neighbor] === Infinity) {
                    distances[neighbor] = distances[node] + 1;
                    queue.push(neighbor);
                }
                if (distances[neighbor] === distances[node] + 1) {
                    numShortestPaths[neighbor] += numShortestPaths[node];
                    predecessors[neighbor].push(node);
                }
            }
        }

        const dependency = Array(n).fill(0);

        while (stack.length > 0) {
            const node = stack.pop();
            for (const pred of predecessors[node]) {
                dependency[pred] += (numShortestPaths[pred] / numShortestPaths[node]) * (1 + dependency[node]);
            }
            if (node !== start) {
                centrality[node] += dependency[node];
            }
        }
    }

    for (let i = 0; i < n; i++) {
        bfs(i);
    }

    let maxCentrality = -Infinity;
    let nodeWithMaxCentrality = -1;

    for (let i = 0; i < n; i++) {
        if (centrality[i] > maxCentrality || (centrality[i] === maxCentrality && i < nodeWithMaxCentrality)) {
            maxCentrality = centrality[i];
            nodeWithMaxCentrality = i;
        }
    }

    return nodeWithMaxCentrality;
}