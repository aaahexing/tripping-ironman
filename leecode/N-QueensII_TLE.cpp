#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	inline bool check(int n, const int* mask, int i, int j) {
		// Check the row
		for (int jj = 0; jj < n; ++jj) {
			if (mask[i] & (1 << jj)) {
				return false;
			}
		}
		// Check the column
		for (int ii = 0; ii < n; ++ii) {
			if (mask[ii] & (1 << j)) {
				return false;
			}
		}
		// Check the diagonal#1
		int i_sub_j = i - j;
		for (int jj = -n; jj <= n; ++jj) {
			int ii = jj + i_sub_j;
			if (ii >= 0 && ii < n && jj >= 0 && jj < n && (mask[ii] & (1 << jj))) {
				return false;
			}
		}
		// Check the diagonal#2
		int i_add_j = i + j;
		for (int jj = -n; jj <= n; ++jj) {
			int ii = i_add_j - jj;
			if (ii >= 0 && ii < n && jj >= 0 && jj < n && (mask[ii] & (1 << jj))) {
				return false;
			}
		}
		return true;
	}
	void gao(int n, int i, int j, int *mask, int &ret) {
		if (j >= n) {
			j = 0;
			++i;
		}
		if (i >= n) {
			// Count the number of queens
			int cc = 0;			
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (mask[i] & (1 << j)) {
						++cc;
					}
				}
			}
			if (cc == n) {
				++ret;
			}
			return;
		}
		// Try to put a queen at (i, j)
		if (mask[i] == 0 && check(n, mask, i, j)) {
			mask[i] |= (1 << j);
			gao(n, i, j + 1, mask, ret);
		}
		mask[i] &= ~(1 << j);
		gao(n, i, j + 1, mask, ret);
	}
	int totalNQueens(int n) {
		int ret = 0;
		vector<int> m(n, 0);
		gao(n, 0, 0, &m[0], ret);
		return ret;
	}
};

int main() {
	int n;
	Solution s;
	while (cin >> n) {
		int res = s.totalNQueens(n);
		cout << "Result for " << n << " : " << res << endl;
	}
	return 0;
}
