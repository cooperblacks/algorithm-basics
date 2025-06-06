// Topological Sort
// Type: DAG, DFS-based
// Time: O(V + E)
// Space: O(V)

function topologicalSort(graph) {
    const visited = new Set();
    const stack = [];

    function dfs(node) {
        visited.add(node);
        for (const neighbor of graph[node] || []) {
            if (!visited.has(neighbor)) dfs(neighbor);
        }
        stack.push(node);
    }

    for (const node in graph) {
        if (!visited.has(node)) dfs(node);
    }

    return stack.reverse();
}
