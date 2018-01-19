int find_set (int u) {
	if (u == parent[u]) {
		return u;
	} return parent[u] = find_set(parent[u]);
}

void union_set (int a, int b) {
	int p, q;

	p = find_set(a);
	q = find_set(b);

	if (p != q) {
		parent[p] = q;
	}
}