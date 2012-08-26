#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

// 20.1: orz
int add_no_arithm(int a, int b) {
	if (b == 0) {
		return a;
	}
	int sum = a ^ b;
	int carry = (a & b) << 1;
	return add_no_arithm(sum, carry);
}

// 20.2: perfectly random shuffle
void shuffleCards(int n, int cards[]) {
	for (int i = 0; i < n; ++i) {
		cards[i] = i + 1;
	}
	for (int i = 0; i < n; ++i) {
		int ii = (rand() % (n - i)) + i;
		swap(cards[i], cards[ii]);
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", cards[i]);
	}
	puts("");
}

// 20.3: randomly pick m integers from an array of size n
void pickM(int n, int a[], int m) {
	int *v = new int[m];
	for (int i = 0; i < m; ++i) {
		int ii = (rand() % (n - i)) + i;
		v[i] = a[ii];
		a[ii] = a[i];
	}
	for (int i = 0; i < m; ++i) {
		printf("%d ", v[i]);
	}
	puts("");
	delete [] v;
}

// 20.4: count the number of 2s between 0 and n
int countVstupid(int n, int v) {
	int ret = 0;
	char str[128];
	for (int i = 0; i <= n; ++i) {
		sprintf(str, "%d", i);
		for (int j = 0; str[j]; ++j) {
			ret += (str[j] == '0' + v);
		}
	}
	return ret;
}
int countV(int n, int v) {
	if (n == 0) {
		return 0;
	}
	int p = 1;
	for (; p < n / 10; p *= 10);
	int f = n / p;
	int rem = n % p;
	int ret = 0;
	// count 'v's occur in the first position
	if (f > v) {
		ret += p;
	} else if (f == v) {
		ret += rem + 1;
	}
	ret += f * countV(p - 1, v) + countV(rem, v);
	return ret;
}
// @todo: has bugs
int count0s(int n) {
	int ret = 0, p = 1;
	for (; p <= n; p *= 10) {
		ret += (n / (p * 10)) * p;
		if ((n / p) % 10 == 0) {
			ret -= (p - 1) - (n % p);
		}
	}
	return ret + 1;
}

// 20.9: maintain the median
//		use two heaps
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;
void initHeap() {
	while (!max_heap.empty()) {
		max_heap.pop();
	}
	while (!min_heap.empty()) {
		min_heap.pop();
	}
}
// max_heap.size() >= min_heap.size()
void insertHeap(int x) {
	if (max_heap.empty() || x < max_heap.top()) {
		max_heap.push(x);
	} else {
		min_heap.push(x);
	}
	if (max_heap.size() > min_heap.size() + 1) {
		min_heap.push(max_heap.top());
		max_heap.pop();
	} else if (min_heap.size() > max_heap.size() + 1) {
		max_heap.push(min_heap.top());
		min_heap.pop();
	}
}
double getMedian() {
	if (max_heap.size() > min_heap.size()) {
		return max_heap.top();
	} else if (min_heap.size() > max_heap.size()) {
		return min_heap.top();
	} else {
		// min_size == max_size
		return (max_heap.empty() ? -1.0 : 0.5 * (max_heap.top() + min_heap.top()));
	}
}

int main() {
	int n, a, b, m;
	int cards[MAXN];
	while (scanf("%d", &n) != EOF) {
		if (n == 1) {
			scanf("%d%d", &a, &b);
			printf("a + b = %d\n", add_no_arithm(a, b));
		} else if (n == 2) {
			scanf("%d", &n);
			shuffleCards(n, cards);
		} else if (n == 3) {
			scanf("%d%d", &n, &m);
			for (int i = 0; i < n; ++i) {
				scanf("%d", &cards[i]);
			}
			pickM(n, cards, m);
		} else if (n == 4) {
			scanf("%d%d", &n, &m);
			printf("count 2s = %d (v : %d)\n", countV(n, m), countVstupid(n, m));
		} else if (n == 44) {
			scanf("%d", &n);
			printf("count 0s = %d (v : %d)\n", count0s(n), countVstupid(n, 0));
		} else if (n == 9) {
			scanf("%d", &n);
			initHeap();
			for (int i = 0; i < n; ++i) {
				scanf("%d", &m);
				insertHeap(m);
				printf("media : %.3lf\n", getMedian());
			}
		}
	}
	return 0;
}

