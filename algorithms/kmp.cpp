#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int cas, sn, pn, next[10010];
char s[1000010], p[10010];

void genNext() {
	memset(next, 0, sizeof(int) * (pn + 1));
	int k = 0;
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

int countMatch() {
	int k = 0, ret = 0;
	for (int i = 1; i <= sn; ++i) {
		while (k > 0 && s[i - 1] != p[k + 1 - 1]) {
			k = next[k];
		}
		if (s[i - 1] == p[k + 1 - 1]) {
			++k;
		}
		if (k == pn) {
			++ret;
			k = next[k];
		}
	}
	return ret;
}

int main() {
	scanf("%d", &cas);
	for (int ca = 1; ca <= cas; ++ca) {
		scanf("%s%s", p, s);
		pn = strlen(p);
		sn = strlen(s);
		genNext();
		printf("%d\n", countMatch());
	}
	return 0;
}

