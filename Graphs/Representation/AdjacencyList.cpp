#include <cstdio>
#include <vector>
#define MAX 100
using namespace std;

// Adjacency List implemented by Vector
vector<vector<int> > adjList;

int main (void) {
	int nc, ec;
	int u, v;
	int i;

	// NC is the number of the nodes of a Graph
	// EC is the number of the edges of a Graph
	// U and V are nodes which are adjacent each other

	scanf("%d", &nc);
	adjList.resize(nc + 1);

	scanf("%d", &ec);
	for (i = 0; i < ec; ++ i) {
	 // Consturct a Graph from given edge's information Using Adjacency List
	 // Format : /'U V/' meaning U and V are Adjacent
		scanf("%d %d", &u, &v);

		// If a edge is directed edge
		adjList[u].push_back(v);

		// If a edge is undirected edge
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	return 0;
}
