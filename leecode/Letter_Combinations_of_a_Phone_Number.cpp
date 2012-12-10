#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, string> M;
        M[0] = " ";
        M[1] = "";
        M[2] = "abc";
        M[3] = "def";
        M[4] = "ghi";
        M[5] = "jkl";
        M[6] = "mno";
        M[7] = "pqrs";
        M[8] = "tuv";
        M[9] = "wxyz";
        vector<string> buf[2];
        buf[0].push_back("");
        for (int i = 0; i < digits.length(); ++i) {
            int pre = i & 1;
            int cur = 1 - pre;
            const string s = M[digits[i] - '0'];
            buf[cur].clear();
            for (int j = 0; j < buf[pre].size(); ++j) {
                for (int k = 0; k < s.length(); ++k) {
                    buf[cur].push_back(buf[pre][j] + s[k]);
                }
            }
        }
        int pre = (int)digits.length() & 1;
        sort(buf[pre].begin(), buf[pre].end());
        return buf[pre];
    }
};

int main() {
	Solution s;
	return 0;
}
