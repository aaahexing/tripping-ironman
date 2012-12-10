#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> next;
public:
    void genNext(char *p) {
        const int pn = strlen(p);
        next = vector<int>(pn + 1);
        int k = 0;
        next[1] = 0;
        for (int i = 2; i <= pn; ++i) {
            while (k > 0 && p[i - 1] != p[k + 1 - 1]) {
                k = next[k];
            }
            if (p[i - 1] == p[k + 1 - 1]) {
                ++k;
            }
            next[i] = k;
        }
    }
    char *match(char *s, char *p) {
        genNext(p);
        int k = 0;
        const int n = strlen(s);
        const int pn = strlen(p);
        for (int i = 1; i <= n; ++i) {
            while (k > 0 && s[i - 1] != p[k + 1 - 1]) {
                k = next[k];
            }
            if (s[i - 1] == p[k + 1 - 1]) {
                ++k;
            }
            if (k == pn) {
                return s + i - k;
            }
        }
        return NULL;
    }
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (haystack == NULL) {
            return needle == NULL ? haystack : NULL;
        }
        if (*haystack == '\0') {
            return (needle == NULL || *needle == '\0') ? haystack : NULL;
        }
        if (needle == NULL || *needle == '\0') {
            return haystack;
        }
        return match(haystack, needle);
    }
};

int main() {
	Solution s;
	puts(s.strStr("aaa", "aa"));
	return 0;
}

