#include <cstdio>
#define MAX 100

int adjacencyMatrix[MAX][MAX];

int main (void) {
	int n;
	int u, v;
	int i;

	// N is the number of the edges of a Graph
	// U and V are nodes which are adjacent each other

	scanf("%d", &n);
	for (i = 0; i < n; ++ i) {
	 // Consturct a Graph from given edge's information Using Adjacency Matrix
	 // Format : /'U V/' meaning U and V are Adjacent
		scanf("%d %d", &u, &v);

	 // 1 is meaning that the two nodes are adjacent
		// If a edge is directed edge
		adjacencyMatrix[u][v] = 1;

		// If a edge is undirected edge
		adjacencyMatrix[u][v] = 1;
		adjacencyMatrix[v][u] = 1;
	}

	return 0;
}
