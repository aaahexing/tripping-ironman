#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

int main() {
	int n, a[MAXN];
	while (cin >> n) {
		map<int, pair<int, int> > MP;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			// try to find
			for (int j = i + 1; j < n; ++j) {
				printf("i = %d, j = %d\n", i, j);
				if (MP.find(a[i] + a[j]) != MP.end()) {
					pair<int, int> pre = MP[a[i] + a[j]];
					printf("a[%d] + a[%d] = a[%d] + a[%d]\n", pre.first, pre.second, i, j);
				}
			}
			for (int j = 0; j < i; ++j) {
				MP[a[j] + a[i]] = make_pair(j, i);
			}
		}
	}
	return 0;
}
