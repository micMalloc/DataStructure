#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 10;

int init_segment_tree (int, int, int);
int get_solution (int, int, int, int, int);
void update_segment_tree (int, int, int, int, int);

int data[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
vector<int> segment_tree;

int main () {
	int n;
	int h, tree_size;

	scanf("%d", &n);

	h = (int)ceil(log(n) / log(2));
	tree_size = (1 << (h + 1));

	segment_tree.resize(tree_size);
	segment_tree[0] = 0;
	
	init_segment_tree(1, 0, n - 1);

	return 0;
}
/* Get Sum of Given Range */
int init_segment_tree (int loca, int start, int end) {
	int mid;

	if (start < end) {
		mid = (start + end) / 2;
		segment_tree[loca] += init_segment_tree(2 * loca, start, mid);
		segment_tree[loca] += init_segment_tree((2 * loca) + 1, mid + 1, end);
	} else {
		segment_tree[loca] = data[start];
	} return segment_tree[loca];
}

int get_solution (int curr, int start, int end, int left, int right) {
	int mid;
	int ans = 0;

	if (start > right || end < left) {
		return 0;
	}
	if (left <= start || end <= right) {
		return segment_tree[curr];
	}

	mid = (start + end) / 2;
	ans += get_solution(2 * curr, start, mid, left, right);
	ans += get_solution((2 * curr) + 1, mid + 1, end, left, right);

	return ans;
}

void update_segment_tree (int node, int start, int end, int idx, int dif) {
	int mid;

	if (idx < start || idx > end) return;

	segment_tree[node] += dif;
	if (start != end) {
		mid = (start + end) / 2;
		update_segment_tree(node * 2, start, mid, idx, dif);
		update_segment_tree(node * 2 + 1, mid + 1, end, idx, dif);
	}
}