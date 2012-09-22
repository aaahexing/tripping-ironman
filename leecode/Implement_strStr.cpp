#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
	vector<int> next;
	void genNext(char *p) {
		int m = strlen(p);
		next = vector<int>(m + 1, 0);
		int k = 0;
		for (int i = 2; i <= m; ++i) {
			while (k > 0 && p[i - 1] != p[k + 1 - 1]) {
				k = next[k];
			}
			if (p[i - 1] == p[k + 1 - 1]) {
				++k;
			}
			next[i] = k;
		}
	}
	char *strStr(char *haystack, char *needle) {
		if (*haystack == '\0') {
			return *needle == '\0' ? haystack : NULL;
		}
		if (*needle == '\0') {
			return haystack;
		}
		genNext(needle);
		int n = strlen(haystack);
		int m = strlen(needle);
		int k = 0;
		for (int i = 1; i <= n; ++i) {
			while (k > 0 && haystack[i - 1] != needle[k + 1 - 1]) {
				k = next[k];
			}
			if (haystack[i - 1] == needle[k + 1 - 1]) {
				++k;
			}
			if (k == m) {
				return haystack + i - m;
			}
		}
		return NULL;
	}
};

int main() {
	Solution s;
	printf("match %s\n", s.strStr("mississippi", "issip"));
	return 0;
}
