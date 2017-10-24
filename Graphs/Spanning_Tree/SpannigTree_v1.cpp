
/* Implementation of Spanning Tree using DFS */
void spanningTree (int start) {
	depthFirstSeach(start);
}

/* Depth-First-Traversal by using Adjacency List */
void depthFirstSeach (int current, int prev) {
	int next;

	visited[current] = 1;
	for (int i = 0; i < adjList[current].size(); ++ i) {
		next = adjList[current][i];
		if (visited[next] != 1) {
		// Visit the next adjacent node recursively
			depthFirstSeach(next, current);
		} else if (prev != next) {
		// Remove a edge that lead to Cycle
			adjList[current].erase(adjList[current].begin + i);
		}
	}
}