#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string digit(int d, int u) {
        const string units = "IVXLCDM";
        string ret = "";
        if (d < 4) {
            for (int i = 0; i < d; ++i) {
                ret += units[u];
            }
        } else if (d == 4) {
            ret += units[u];
            ret += units[u + 1];
        } else if (d == 5) {
            ret += units[u + 1];
        } else if (d >= 6 && d <= 8){
            ret += units[u + 1];
            for (int i = 0; i < d - 5; ++i) {
                ret += units[u];
            }
        } else if (d == 9) {
			ret += units[u];
			ret += units[u + 2];
		} else {
			ret += units[u + 2];
		}
        return ret;
    }
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string ret = "";
        int f = 1000;
        for (int u = 6; u >= 0; u -= 2) {
            if (num >= f) {
                ret += digit(num / f, u);
                num -= num / f * f;
            }
            f /= 10;
        }
        return ret;
    }
};

int main() {
	Solution s;
	cout << s.intToRoman(1) << endl;
	cout << s.intToRoman(2012) << endl;
	return 0;
}

