
/*
- From a node, visit one adjacent node recursively,
  until there is no new adjacent node
- Then, Backtrack, and visit the next adjacent node recursively
- Finish when every adjacent node of the initial node has been recursively traversed
*/

/* Depth-First-Traversal by using Adjacency List implemented by Vector */
void depthFirstSeach (int currentVertex) {
	int v = currentVertex;
	int next;

	visited[v] = 1;
	for (int i = 0; i < adjList[v].size(); ++ i) {
		next = adjList[v][i];
		if (visited[next] != 1) {
		// Visit the next adjacent node recursively
			depthFirstSeach(next);
		}
	}
}

/* Depth-First-Traversal by using Adjacency Matrix implemented by 2D-Array */
void depthFirstSeach (int currentVertex) {
	int v = currentVertex;
	int next;

	// nc is a global variable meaning the number of nodes of a graph

	visited[v] = 1;
	for (int i = 0; i < nc; ++ i) {
		next = adjMatrix[v][i];
		if (visited[next] != 1) {
		// Visit the next adjacent node recursively
			depthFirstSeach(next);
		}
	}
}