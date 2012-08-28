#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct BSTNode {
	int v;
	BSTNode *lson;
	BSTNode *rson;
};

// An iterator for BST

class BSTIterator {
	BSTNode *root;
	BSTNode *cursor;
	stack<BSTNode*> S;
public:
	explicit BSTIterator(BSTNode *_r) {
		while (!S.empty()) {
			S.pop();
		}
		cursor = root = _r;
	}
	
	inline void reset() {
		while (!S.empty()) {
			S.pop();
		}
		cursor = root;
	}

	inline BSTNode* operator++ () {
		while (cursor) {
			S.push(cursor);
			cursor = cursor->lson;
		}
		if (!S.empty()) {
			BSTNode *ret = S.top();
			S.pop();
			cursor = ret->rson;
			return ret;
		}
		return NULL;
	}

	inline BSTNode* operator-- () {
		while (cursor) {
			S.push(cursor);
			cursor = cursor->rson;
		}
		if (!S.empty()) {
			BSTNode *ret = S.top();
			S.pop();
			cursor = ret->lson;
			return ret;
		}
		return NULL;
	}
};

class OperatorItem {
	int v;
public:
	explicit OperatorItem(int _v) {
		v = _v;
	}

	inline int getV() const {
		return v;
	}

	// overloaded operators
	OperatorItem operator+ (const OperatorItem &o) const {
		return OperatorItem(v + o.v);
	}

	OperatorItem operator- (const OperatorItem &o) const {
		return OperatorItem(v - o.v);
	}

	// postfix: ++x
	OperatorItem& operator++ () {
		++this->v;
		return *this;
	}

	// postfix: --x
	OperatorItem& operator-- () {
		--this->v;
		return *this;
	}

	// prefix: x++
	OperatorItem operator++ (int) {
		OperatorItem ret(*this);
		++this->v;
		return ret;
	}

	// prefix: x--
	OperatorItem operator-- (int) {
		OperatorItem ret(*this);
		--this->v;
		return ret;
	}
};

int main() {
	int n, a, b, x;
	while (scanf("%d", &n) != EOF) {
		if (n == 2) {
			scanf("%d%d", &a, &b);
			OperatorItem oa(a), ob(b);
			printf("a + b = %d\n", (oa + ob).getV());
			++oa;
			printf("++a = %d\n", oa.getV());
			--ob;
			printf("--b = %d\n", ob.getV());
			oa++;
			printf("a++ = %d\n", oa.getV());
			ob--;
			printf("b-- = %d\n", ob.getV());
		}
	}
	return 0;
}
