#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

// 1.1: floor of the square root
// 	always write binary-search with closed interval []
int sroot_floor(int n) {
	int l = 1, r = n;
	while (r - l + 1 > 1) {
		int m = (l + r + 1) >> 1;
		if (m > n / m) {
			r = m - 1;
		} else {
			l = m;
		}
	}
	return l;
}

int sroot_ceiling(int n) {
	int l = 1, r = n;
	while (r - l + 1 > 1) {
		int m = (l + r) >> 1;
		if (m < n / m) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	return r;
}

// 1.2: first occurrence of k
int findFirst(int n, int a[], int x) {
	int l = 0, r = n - 1;
	while (r - l + 1 > 1) {
		int m = (l + r) >> 1;
		if (a[m] < x) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	return (a[r] == x ? r : -1);
}

// 1.3: first element larger than x
int findFirstLarger(int n, int a[], int x) {
	int l = 0, r = n - 1;
	while (r - l + 1 > 1) {
		int m = (l + r) >> 1;
		if (a[m] <= x) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	return (a[r] > x ? r : -1);
}

// 1.5: find the first occurence of x in an array with unknown length
int getLength(int a[], int x) {
	for (int k = 0; ; ++k) {
		try {
			int v = a[(1 << k) - 1];
			if (v > x) {
				return (1 << k);
			}
		} catch (...) {
			return (1 << k);
		};
	}
	return -1;	// This won't happen, though
}
int searchUnbound(int a[], int x) {
	int n = getLength(a, x);
	int l = n >> 1, r = n - 1;
	while (r - l + 1 > 1) {
		int m = (l + r) >> 1;
		try {
			if (a[m] < x) {
				l = m + 1;
			} else {
				r = m;
			}
		} catch (...) {
			r = m - 1;
		}
	}
	return (a[r] == x ? r : -1);
}

// 1.13
int calCapacity(int n, int a[]) {
	int mini = a[0], ret = 0;
	for (int i = 1; i < n; ++i) {
		if (ret < a[i] - mini) {
			ret = a[i] - mini;
		}
		mini = min(mini, a[i]);
	}
	return ret;
}

// 1.15: find frequent items, occurs more than 1/k among n items
int calFrequent(int n, int k, int a[]) {
	map<int, int> M;
	for (int i = 0; i < n; ++i) {
		if (M.find(a[i]) != M.end()) {
			++M[a[i]];
		} else {
			// need to insert
			M[a[i]] = 1;
			for (map<int, int> :: iterator it = M.begin(); it != M.end();) {
				--it->second;
				if (it->second == 0) {
					M.erase(it++);
				} else {
					++it;
				}
			}
		}
	}
	return (M.empty() ? -1 : M.begin()->first);
}

int main() {
	int n, m, x;
	int a[MAXN];
	while (scanf("%d", &n) != EOF) {
		if (n == 1) {
			scanf("%d", &n);
			printf("square_root: floor = %d, ceiling = %d\n", sroot_floor(n), sroot_ceiling(n));
		} else if (n == 2) {
			scanf("%d%d", &n, &m);
			for (int i = 0; i < n; ++i) {
				scanf("%d", &a[i]);
			}
			for (int i = 0; i < m; ++i) {
				scanf("%d", &x);
				printf("findFirst : %d\n", findFirst(n, a, x));
			}
		} else if (n == 3) {
			scanf("%d%d", &n, &m);
			for (int i = 0; i < n; ++i) {
				scanf("%d", &a[i]);
			}
			for (int i = 0; i < m; ++i) {
				scanf("%d", &x);
				printf("first larger : %d\n", findFirstLarger(n, a, x));
			}
		}
	}
	return 0;
}
