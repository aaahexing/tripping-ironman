#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

class Stack {
	int s[MAXN], n;
public:
	Stack() {
		n = 0;
	}

	inline bool empty() {
		return n == 0;
	}

	inline void push(int x) {
		s[n++] = x;
	}

	inline void pop() {
		--n;
	}

	inline int top() {
		return s[n - 1];
	}
};

// 3.1: 3 stacks using a single array
class ThreeStacks {
	int n[3];
	int s[MAXN * 3];
public:
	ThreeStacks() {
		for (int i = 0; i < 3; ++i) {
			n[i] = 0;
		}
	}

	inline bool empty(int si) {
		return n[si] == 0;
	}

	inline void push(int si, int x) {
		s[si * MAXN + n[si]++] = x;
	}

	inline void pop(int si) {
		--n[si];
	}

	inline int top(int si) {
		return s[si * MAXN + n[si] - 1];
	}
};

struct StackNode {
	int v;
	int prev;
};

class ThreeStacksOpt {
	int prev[3];
	int n, s[MAXN * 3];
	StackNode pack[MAXN * 3];
public:
	ThreeStacksOpt() {
		for (int i = 0; i < 3; ++i) {
			prev[i] = -1;
		}
		// init the memory pool
		n = 0;
		for (int i = MAXN * 3 - 1; i >= 0; --i) {
			s[n++] = i;
		}
	}

	inline bool empty(int si) {
		return prev[si] == -1;
	}

	inline int getSpace() {
		return (n == 0 ? -1 : s[--n]);
	}

	inline void push(int si, int x) {
		int i = getSpace();
		if (i == -1) {
			fprintf(stderr, "There's no space available!");
			return;
		} else {
			pack[i].v = x;
			pack[i].prev = prev[si];
			prev[si] = i;
		}
	}

	inline void pop(int si) {
		s[n++] = prev[si];
		prev[si] = pack[prev[si]].prev;
	}

	inline int top(int si) {
		return pack[prev[si]].v;
	}
};

// 3.4: Towers of Hanoi

class TowersOfHanoi {
	int n;
	Stack disks[3];
public:
	TowersOfHanoi(int _n) {
		n = _n;
		for (int i = n - 1; i >= 0; --i) {
			disks[0].push(i);
		}
	}

	void move(int src, int tar) {
		int disk = disks[src].top();
		disks[tar].push(disk);
		disks[src].pop();
		printf("move disk %d from tower %d to tower %d\n", disk, src, tar);
	}

	void move(int n, int src, int tar, int buf) {
		if (n > 0) {
			move(n - 1, src, buf, tar);
			move(src, tar);
			move(n - 1, buf, tar, src);
		}
	}

	void go() {
		move(n, 0, 2, 1);
	}
};

int main() {
	char cmd[32];
	int n, si, x;
	while (scanf("%d", &n) != EOF) {
		if (n == 1) {
			scanf("%d", &n);
			ThreeStacksOpt stack3o;
			for (int i = 0; i < n; ++i) {
				scanf("%s", cmd);
				if (!strcmp(cmd, "push")) {
					scanf("%d%d", &si, &x);
					stack3o.push(si, x);
				} else if (!strcmp(cmd, "top")) {
					scanf("%d", &si);
					if (stack3o.empty(si)) {
						puts("empty");
					} else {
						printf("%d\n", stack3o.top(si));
					}
				} else if (!strcmp(cmd, "pop")) {
					scanf("%d", &si);
					if (stack3o.empty(si)) {
						puts("empty");
					} else {
						stack3o.pop(si);
					}
				}
			}
		} else if (n == 4) {
			scanf("%d", &n);
			TowersOfHanoi tower(n);
			tower.go();
		}
	}

	return 0;
}
