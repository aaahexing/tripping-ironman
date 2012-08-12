#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

void popUp(int n, int a[], int i) {
	if (i > 1 && a[i / 2] < a[i]) {
		swap(a[i / 2], a[i]);
		popUp(n, a, i / 2);
	}
}

// Increase a[i]'s value
void increaseValue(int n, int a[], int i, int v) {
	a[i] += v;
	popUp(n, a, i);
}

// Max-heap
void pushDown(int n, int a[], int i) {
	int m = i;
	if (i * 2 <= n && a[i * 2] > a[m])
		m = i * 2;
	if (i * 2 + 1 <= n && a[i * 2 + 1] > a[m])
		m = i * 2 + 1;
	if (m != i) {
		swap(a[i], a[m]);
		pushDown(n, a, m);
	}
}

void makeHeap(int n, int a[]) {
	for (int i = (n + 1) / 2; i >= 1; --i)
		pushDown(n, a, i);
}

void heapSort(int n, int a[]) {
	makeHeap(n, a);
	for (int i = n; i >= 1; --i) {
		swap(a[1], a[i]);
		pushDown(--n, a, 1);
	}
}

int main() {
	int n, a[MAXN];
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		heapSort(n, a);
		for (int i = 1; i <= n; ++i)
			printf("%d ", a[i]);
		puts("");
	}
	return 0;
}
