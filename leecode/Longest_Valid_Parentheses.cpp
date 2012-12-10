#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> S;
		int ans = 0, last_len = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') {
				S.push(0);
			} else {
				if (S.empty()) {
					// invalid
					last_len = 0;
				} else {
					// valid
					int cur = S.top() + 2;
					S.pop();
					ans = max(ans, cur);
					if (S.empty()) {
						last_len += cur;
						ans = max(ans, last_len);
					} else {
						int nxt = S.top() + cur;
						S.pop();
						S.push(nxt);
					}
				}
			}
			if (!S.empty()) {
				ans = max(ans, S.top());
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	cout << s.longestValidParentheses("()(()") << endl;
	cout << s.longestValidParentheses("()()") << endl;
	cout << s.longestValidParentheses("()(())") << endl;
	cout << s.longestValidParentheses("(()()") << endl;
	cout << s.longestValidParentheses("(()()(())((") << endl;
	return 0;
}
