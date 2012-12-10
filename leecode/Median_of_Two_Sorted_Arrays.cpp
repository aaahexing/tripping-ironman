#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findKth(int A[], int m, int B[], int n, int K) {
		int lo = max(0, K - n);
		int hi = min(m, K);
		// printf("%dth : lo = %d, hi = %d\n", K, lo, hi);
		while (lo < hi) {
			int mi = (lo + hi) >> 1;
			// 'ca' elements from A and 'cb' elements from B.
			int ca = mi, cb = K - mi;
			if (ca < m && cb > 0 && A[ca] < B[cb - 1]) {
				lo = mi + 1;
			} else if (ca > 0 && cb < n && A[ca - 1] > B[cb]) {
				hi = mi;
			} else {
				lo = mi;
				break;
			}
		}
		// printf("lo = %d\n", lo);
		if (lo == 0) {
			return B[K - 1];
		} else if (lo == K) {
			return A[K - 1];
		} else {
			return max(A[lo - 1], B[K - lo - 1]);
		}
	}
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		/*
		printf("\nnew case : \n");
		for (int i = 0; i < m; ++i) {
			printf("%d ", A[i]);
		}
		puts("");
		for (int j = 0; j < n; ++j) {
			printf("%d ", B[j]);
		}
		puts("");
		*/
		int tot = n + m;
		if (tot & 1) {
			return findKth(A, m, B, n, tot / 2 + 1);
		} else {
			return 0.5 * (findKth(A, m, B, n, tot / 2) + findKth(A, m, B, n, tot / 2 + 1));
		}
	}
};

int main() {
	Solution s;
	int a0[] = {};
	int b0[] = {1};
	cout << s.findMedianSortedArrays(a0, 0, b0, 1) << endl;
	int a1[] = {};
	int b1[] = {2, 3};
	cout << s.findMedianSortedArrays(a1, 0, b1, 2) << endl;
	int a2[] = {1};
	int b2[] = {1};
	cout << s.findMedianSortedArrays(a2, 1, b2, 1) << endl;
	int a3[] = {1, 2};
	int b3[] = {1, 2};
	cout << s.findMedianSortedArrays(a3, 2, b3, 2) << endl;
	int a4[] = {1};
	int b4[] = {2};
	cout << s.findMedianSortedArrays(a4, 1, b4, 1) << endl;
	return 0;
}
