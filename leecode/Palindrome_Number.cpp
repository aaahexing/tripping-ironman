#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int rx = 0;
		for (int mx = x; mx > 0; mx /= 10) {
			rx = rx * 10 + (mx % 10);
		}
		return rx == x;
	}
};

int main() {
	int x;
	Solution s;
	while (cin >> x) {
		cout << s.isPalindrome(x) << endl;	
	}
	return 0;
}
