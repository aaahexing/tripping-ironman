#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

// RRRRWWWWXX...XXBBBB
void sort(char *s) {
	int n = strlen(s);
	int bufferR = 0, bufferB = n - 1;
	for (int i = 0; i < n; ) {
		if (s[i] == 'R') {
			if (bufferR < i) {
				swap(s[i], s[bufferR]);
			} else {
				++i;
			}
			++bufferR;
		} else if (s[i] == 'B') {
			if (bufferB > i) {
				swap(s[i], s[bufferB]);
			} else {
				++i;
			}
			--bufferB;			
		} else {
			++i;
		}
		// printf(": %s; bufferR = %d, bufferB = %d\n", s, bufferR, bufferB);
	}
}

int main() {
	char s[MAXN];
	while (cin >> s) {
		sort(s);
		puts(s);
	}
	return 0;
}
