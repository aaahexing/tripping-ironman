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
	void gao(int n, int i, int j, int *mask, vector< vector<string> > &res) {
		if (j >= n) {
			j = 0;
			++i;
		}
		if (i >= n) {
			// Count the number of queens
			int cc = 0;			
			vector<string> m;
			for (int i = 0; i < n; ++i) {
				string s(n, '.');
				for (int j = 0; j < n; ++j) {
					if (mask[i] & (1 << j)) {
						++cc;
						s[j] = 'Q';
					}
				}
				m.push_back(s);
			}
			if (cc == n) {
				res.push_back(m);
			}
			return;
		}
		// Try to put a queen at (i, j)
		if (mask[i] == 0 && check(n, mask, i, j)) {
			mask[i] |= (1 << j);
			gao(n, i, j + 1, mask, res);
		}
		mask[i] &= ~(1 << j);
		gao(n, i, j + 1, mask, res);
	}
	vector< vector<string> > solveNQueens(int n) {
		vector<int> m(n, 0);
		vector< vector<string> > res;
		gao(n, 0, 0, &m[0], res);
		return res;
	}
};

int main() {
	int n;
	Solution s;
	while (cin >> n) {
		vector< vector<string> > res = s.solveNQueens(n);
		cout << "Result for " << n << ":" << endl;
		for (int i = 0; i < res.size(); ++i) {
			cout << endl;
			for (int j = 0; j < n; ++j) {
				cout << res[i][j] << endl;
			}
		}
	}
	return 0;
}
