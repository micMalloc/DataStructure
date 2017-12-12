#include <cstdio>
#include <vector>
using namespace std;

void make_BIT ();
void update_BIT (int, int);
int get_sum (int);

vector<int> data;
vector<int> bit;
int n;

int main (int argc, char** argv) {
	
	scanf("%d", &n);
	data.resize(n + 1);
	bit.resize(n + 1);

	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &bit[i]);
	} make_BIT();

	return 0;
}

void make_BIT () {
	for (int i = 1; i <= n; ++ i) {
		update_BIT(i, data[i]);
	}
}

void update_BIT (int idx, int value) {
	while (idx <= n) {
		bit[idx] += value;
		idx += (idx & (-idx));
	}
}

int get_sum (int idx) {
	int sum = 0;

	while (idx > 0) {
		sum += bit[idx];
		idx -= (idx & (-idx));
	} return sum;
}