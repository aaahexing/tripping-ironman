#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class BitSet {
	// unsigned is better, because we can ignore any problems relevant to
	//	the sign-bit.
	int *s;
public:
	BitSet(int n) {
		s = new int[n >> 5];
	}

	~BitSet() {
		delete [] s;
	}

	inline void set(int i) {
		s[i >> 5] |= (1 << (i & 0x1f));
	}

	inline bool get(int i) {
		return (s[i >> 5] & (1 << (i & 0x1f))) != 0;
	}
};

const int MAXN = 1024;

// 12.4
void checkDuplicates(int n, int a[]) {
	BitSet bitset(32000);
	for (int i = 0; i < n; ++i) {
		int num = a[i] - 1;	// solve the offset-by-1 issue
		if (bitset.get(num)) {
			printf("%d\n", num + 1);
		}
		bitset.set(num);
	}
}

int main() {
	int n;
	int a[MAXN];
	while (scanf("%d", &n) != EOF) {
		if (n == 4) {
			scanf("%d", &n);
			for (int i = 0; i < n; ++i) {
				scanf("%d", &a[i]);
			}
			checkDuplicates(n, a);
		}
	}
	return 0;
}
