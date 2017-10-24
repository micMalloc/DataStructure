
/*
- From a node, visit adjacent nodes one at a time.
- Then visit all unvisited adjacent nodes of each of the adjacent nodes of the original node
  one at a time
- Finish when all nodes on each of the paths from the original node have been visited
*/

/* Bread-First-Traversal by using Adjacency List implemented by Vector */
void breadthFirstSearch (int start) {
	int current, next, i;

	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		current = q.front(); q.pop();
		for (i = 0; i < adjList[current][i]; ++ i) {
			next = adjList[current][i];
			if (visited[next] != 1) {
				q.push(next);
				visited[next] = 1;
			}
		}
	}
}

/* Bread-First-Traversal by using Adjacency Matrix implemented by 2D-Array */
void breadthFirstSearch (int start) {
	int current, next, i;

	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		current = q.front(); q.pop();
		for (i = 0; i < nc; ++ i) {
			next = adjMatrix[current][i];
			if (visited[next] != 1) {
				q.push(next);
				visited[next] = 1;
			}
		}
	}
}