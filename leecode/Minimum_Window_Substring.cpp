#include <cstdio>
#include <cstring>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		int cT[256], cS[256];
		memset(cT, 0, sizeof(cT));
		memset(cS, 0, sizeof(cS));
		for (int i = 0; i < T.length(); ++i) {
			++cT[T[i]];
		}
		int s = -1;
		pair<int, int> opt = make_pair(0x3f3f3f3f, -1);
		for (int i = 0; i < S.length(); ++i) {
			// Accumulate current character
			++cS[S[i]];
			while ((s < 0 || cS[S[s]] > cT[S[s]]) && s <= i) {
				--cS[S[s]];
				++s;
			}
			bool contain = true;
			for (int k = 0; k < 256; ++k) {
				if (cS[k] < cT[k]) {
					contain = false;
					break;
				}
			}
			if (contain) {
				if (i - s + 1 < opt.first) {
					opt = make_pair(i - s + 1, s);
				}
			}
		}
		if (opt.first >= 0x3f3f3f3f) {
			return "";
		} else {
			return S.substr(opt.second, opt.first);
		}
	}
};

int main() {
	Solution s;
	cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
	return 0;
}
