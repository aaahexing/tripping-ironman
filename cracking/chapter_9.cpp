#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

// 9.1: in-place merge, assume one of the arrays has enough buffer
void merge(int n, int a[], int m, int b[]) {
	int i = n - 1;
	int j = m - 1;
	int index = n + m - 1;
	while (i >= 0 && j >= 0) {
		if (a[i] > b[j]) {
			a[index--] = a[i];
			--i;
		} else {
			a[index--] = b[j];
			--j;
		}
	}
	while (j >= 0) {
		a[index--] = b[j];
		--j;
	}
}

// 9.2
inline bool cmp(const string &a, const string &b) {
	string aa = a, bb = b;
	sort(aa.begin(), aa.end());
	sort(bb.begin(), bb.end());
	return aa < bb;
}

// [ ]
int search(int l, int r, int a[], int x) {
	while (l <= r) {
		int m = (l + r) >> 1;
		if (a[m] < x) {
			l = m + 1;
		} else if (a[m] > x) {
			r = m - 1;
		} else {
			return m;
		}
	}
	return -1;
}

// 9.3
int search2(int n, int a[], int x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (a[m] == x) {
			return m;
		} else if (a[l] <= a[m]) {
			if (x > a[m]) {
				l = m + 1;
			} else {
				if (x >= a[l]) {
					r = m - 1;
				} else {
					l = m + 1;
				}
			}
		} else {
			if (x < a[m]) {
				r = m - 1;
			} else {
				if (x <= a[r]) {
					l = m + 1;
				} else {
					r = m - 1;
				}
			}
		}
	}
	return -1;
}

// 9.5: binary-search modified, make sure there's at least one valid string at the end
int search_str(int n, string s[], string x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		for (; r >= l && s[r] == ""; --r);
		if (r < l) {
			return -1;
		}
		int m = (l + r) >> 1;
		for (; s[m] == ""; ++m);	// will ALWAYS find one because s[r] != ""
		if (x < s[m]) {
			r = m - 1;
		} else if (x > s[m]) {
			l = m + 1;
		} else {
			return m;
		}
	}
	return -1;
}

int main() {
	int n, m;
	int a[MAXN], b[MAXN];
	while (scanf("%d", &n) != EOF) {
		if (n == 1) {
			scanf("%d", &n);
			for (int i = 0; i < n; ++i) {
				scanf("%d", &a[i]);
			}
			scanf("%d", &m);
			for (int j = 0; j < m; ++j) {
				scanf("%d", &b[j]);
			}
			merge(n, a, m, b);
			for (int i = 0; i < n + m; ++i) {
				printf("%d ", a[i]);
			}
			puts("");
		}
	}
	return 0;
}

