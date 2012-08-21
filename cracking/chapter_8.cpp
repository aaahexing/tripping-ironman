#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

// 8.3: all subset
int s[MAXN], sn;
void subset(int a[], int n, int i) {
	if (i == n) {
		printf("subset : ");
		for (int j = 0; j < sn; ++j) {
			printf("%d ", s[j]);
		}
		puts("");
		return;
	}
	// not use i
	subset(a, n, i + 1);
	// use i
	s[sn++] = a[i];
	subset(a, n, i + 1);
	sn--;
}

// 8.4: permutations of a string
int v[MAXN];
void perm(int n, int i) {
	if (i == n) {
		printf("perm : ");
		for (int j = 0; j < n; ++j) {
			printf("%d ", s[j]);
		}
		puts("");
		return;
	}
	for (int j = 0; j < n; ++j) {
		if (!v[j]) {
			s[i] = j;
			v[j] = 1;
			perm(n, i + 1);
			v[j] = 0;
		}
	}
}

inline string insertCharAt(string s, int i, char c) {
	if (i == (int)s.length()) {
		return s + c;
	} else {
		return s.substr(0, i) + c + s.substr(i);
	}
}
vector<string> permString(string str) {
	vector<string> ret;
	if (str.length() <= 1) {
		ret.push_back(str);
	} else {
		char c = str[0];
		const string rem = str.substr(1);
		vector<string> small = permString(rem);
		for (int ri = 0; ri < (int)small.size(); ++ri) {
			for (int i = 0; i <= (int)rem.length(); ++i) {
				ret.push_back(insertCharAt(small[ri], i, c));
			}
		}
	}
	return ret;
}

int main() {
	int n;
	string s;
	int a[MAXN];
	while (cin >> n) {
		if (n == 3) {
			scanf("%d", &n);
			for (int i = 0; i < n; ++i) {
				scanf("%d", &a[i]);
			}
			sn = 0;
			subset(a, n, 0);
		} else if (n == 4) {
			scanf("%d", &n);
			memset(v, 0, sizeof(v));
			perm(n, 0);
		} else if (n == 44) {
			cin >> s;
			vector<string> perm = permString(s);
			for (int i = 0; i < (int)perm.size(); ++i)
				cout << perm[i] << endl;
			cout << endl;
		}
	}
	return 0;
}
