#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 10;

int makeSegmentTree (int, int, int);

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