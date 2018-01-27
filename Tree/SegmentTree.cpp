#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 10;

int makeSegmentTree (int, int, int);
int get_solution (int, int, int, int);

int data[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
vector<int> segTree;

int main () {
	int n;

	scanf("%d", &n);
	segTree.resize(4 * n);
	segTree[0] = 0;
	
	makeSegmentTree(1, 0, n - 1);

	return 0;
}
/* Get Sum of Given Range */
int makeSegmentTree (int loca, int start, int end) {
	int mid;

	if (start < end) {
		mid = (start + end) / 2;
		segTree[loca] += makeSegmentTree(2 * loca, start, mid);
		segTree[loca] += makeSegmentTree((2 * loca) + 1, mid + 1, end);
	} else {
		segTree[loca] = data[start];
	} return segTree[loca];
}

int get_solution (int curr, int start, int end, int left, int right) {
	int mid;
	int ans = 0;

	if (start > right || end < left) {
		return 0;
	}
	if (left <= start || end <= right) {
		return data[curr];
	}

	mid = (start + end) / 2;
	ans += get_solution(2 * curr, start, mid, left, right);
	ans += get_solution((2 * curr) + 1, mid + 1, end, left, right);

	return ans;
}