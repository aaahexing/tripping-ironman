#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

// 10.4
inline int mult(int a, int b) {
	int ret = 0;
	for (int i = 0; i < b; ++i) {
		ret += a;
	}
	return ret;
}
inline int subtract(int a, int b) {
	int ret = max(a, b) - min(a, b);
	return a > b ? ret : -ret;
}
inline int divide(int a, int b) {
	int ret = 0;
	while (a >= b) {
		a = subtract(a, b);
		++ret;
	}
	return ret;
}
inline int divideOpt(int a, int b) {
	int ret = 0;
	while (a >= b) {
		int c = 0;
		while ((b << c) <= (a >> 1)) {
			++c;
		}
		ret += (1 << c);
		a -= (b << c);
	}
	return ret;
}

// 10.7
const int p[] = { 3, 5, 7 };

int findKth(int k) {
	int n[3] = { 0 };
	vector<int> number;
	number.push_back(1);
	for (int i = 0; i < k; ++i) {
		int m = 0;
		for (int j = 1; j < 3; ++j) {
			if (p[m] * number[n[m]] > p[j] * number[n[j]]) {
				m = j;
			}
		}
		number.push_back(p[m] * number[n[m]]);
		// This is important
		for (int j = 0; j < 3; ++j) {
			if (p[j] * number[n[j]] == number.back()) {
				++n[j];
			}
		}
	}
	return number.back();
}

int main() {
	int n, a, b;
	while (scanf("%d", &n) != EOF) {
		if (n == 4) {
			scanf("%d%d", &a, &b);
			printf("mult\t: %d\n", mult(a, b));
			printf("subtract: %d\n", subtract(a, b));
			printf("divide\t: %d\t%d\n", divide(a, b), divideOpt(a, b));
		} else if (n == 7) {
			scanf("%d", &n);
			printf("kth = %d\n", findKth(n));
		}
	}
	return 0;
}
