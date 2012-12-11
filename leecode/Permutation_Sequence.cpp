#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		int fac[10], v[10];
		string ret(n, '0');
		fac[0] = 1;
		for (int i = 1; i <= 9; ++i) {
			fac[i] = i * fac[i - 1];
		}
		if (k > fac[n]) {
			return "";
		}
		memset(v, 0, sizeof(v));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!v[j]) {
					ret[i] = j + 1 + '0';
					if (k <= fac[n - 1 - i]) {
						v[j] = 1;
						break;
					} else {
						k -= fac[n - 1 - i];
					}
				}
			}
		}
		return ret;
	}
};

int main() {
	int n, k;
	Solution s;
	while (cin >> n >> k) {
		cout << s.getPermutation(n, k) << endl;
	}
	return 0;
}
