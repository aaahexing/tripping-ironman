#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	string multiply(string a, string b) {
		int m = a.length();
		int n = b.length();
		vector<int> c(m + n, 0);
		// Do the multiplication
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				c[i + j + 1] += (a[i] - '0') * (b[j] - '0');
			}
		}
		// Solve the carry
		for (int i = m + n - 1; i >= 0; --i) {
			if (c[i] >= 10) {
				c[i - 1] += c[i] / 10;
				c[i] %= 10;
			}
		}
		// Remove the leading zeros
		int zi = 0;
		for (; c[zi] == 0 && zi < m + n - 1; ++zi);
		string ans = "";
		for (; zi < m + n; ++zi) {
			ans += c[zi] + '0';
		}
		return ans;
	}
};

int main() {
	Solution s;
	string a, b;
	while (cin >> a >> b) {
		cout << s.multiply(a, b) << endl;
	}
	return 0;
}
