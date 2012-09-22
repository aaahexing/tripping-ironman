#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
	static const char *symbols;
	static const int values[];
	string digitToRoman(int digit, int i) {
		string ret = "";
		if (digit <= 3) {
			for (int j = 0; j < digit; ++j) {
				ret += symbols[i + 1];
			}
		} else if (digit == 9) {
			ret += symbols[i + 1];
			ret += symbols[i - 1];
		} else if (digit == 4) {
			ret += symbols[i + 1];
			ret += symbols[i];
		} else {
			ret += symbols[i];
			for (int j = 0; j < digit - 5; ++j) {
				ret += symbols[i + 1];
			}
		}
		return ret;
	}
	string intToRoman(int num) {
		string ret = "";
		if (num >= 1000) {
			for (int i = 0; i < num / 1000; ++i) {
				ret += symbols[0];
			}
			num %= 1000;
		}
		for (int i = 1; i <= 5; i += 2) {
			if (num >= values[i + 1]) {
				ret += digitToRoman(num / values[i + 1], i);
				num %= values[i + 1];
			}
		}
		return ret;
	}
};

const char* Solution::symbols = "MDCLXVI";
const int Solution::values[] = { 1000, 500, 100, 50, 10, 5, 1 };

int main() {
	int num;
	Solution s;
	while (cin >> num) {
		cout << s.intToRoman(num) << endl;
	}
	return 0;
}
