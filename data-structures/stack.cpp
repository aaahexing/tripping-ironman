#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// Stack

struct Node {
	int v;
	Node *prev;
};

class Stack {
	Node *top;
public:
	Stack() {
		top = new Node();
		top->v = 0;
		top->prev = NULL;
	}

	~Stack() {
		Node *pre = top;
		for (Node *cur = pre->prev; cur != NULL; cur = pre->prev) {
			delete pre;
			pre = cur;
		}
		delete pre;
		top = NULL;
	}

	inline bool empty() const {
		return top->prev == NULL;
	}

	inline void push(int x) {
		Node *cur = new Node();
		cur->v = x;
		cur->prev = top->prev;
		top->prev = cur;
	}

	inline void pop() {
		// top->prev should be valid
		Node *pre = top->prev->prev;
		delete top->prev;
		top->prev = pre;
	}
};

int main() {
	return 0;
}
