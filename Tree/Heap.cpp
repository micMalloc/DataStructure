#include <cstdio>
#include <vector>
using namespace std;

void insertHeap (int);
int deleteHeap ();
void swap (int*, int*);

vector<int> heap;

int main (void) {
	int key;

	// I don't use First space of vector
	// Second Space is the root
	heap.push_back(9999);

	while (true) {
		scanf("%d", &key);
		if (key < 0) break;
		insertHeap(key);
	}
	
	for (int i = 0; i < 8; ++ i) {
		printf("%d ", deleteHeap());
	} printf("\n");

	return 0;
}

void insertHeap (int key) {
	int i = heap.size();

	heap.push_back(key);
	while (i != 1 && (heap[i] < heap[i / 2])) {
		swap(&heap[i], &heap[i / 2]);
		i /= 2;
	}
}

int deleteHeap () {
	int result = heap[1];
	int count = heap.size() - 1;
	int parent, child;

	swap(&heap[1], &heap[count]);
	heap.pop_back();
	count = heap.size() - 1;

	parent = 1; child = 2;
	while (child <= count) {
		if (child < count && heap[child] > heap[child + 1]) {
			child = child + 1;
		}

		if (heap[parent] <= heap[child]) break;

		swap(&heap[parent], &heap[child]);

		parent = child;
		child *= 2;
	}
	return result;
}

void swap (int* a, int *b) {
	int tmp = *a;

	*a = *b;
	*b = tmp;
}