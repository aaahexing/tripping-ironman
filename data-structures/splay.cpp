#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct SplayTreeNode {
	int v;
	SplayTreeNode *lson;
	SplayTreeNode *rson;
};

class SplayTree {
	SplayTreeNode *root;
public:
	SplayTree() {
		root = NULL;
	}
	
	~SplayTree() {
		if (root) {
			queue<SplayTreeNode*> Q;
			Q.push(root);
			while (!Q.empty()) {
				root = Q.front(); Q.pop();
				if (root->lson) {
					Q.push(root->lson);
				}
				if (root->rson) {
					Q.push(root->rson);
				}
				delete root;
			}
			root = NULL;
		}
	}

	// x is the right child of p
	inline SplayTreeNode* rotateL(SplayTreeNode *r) {
		SplayTreeNode *rR = r->rson;
		r->rson = rR->lson;
		rR->lson = r;
		return rR;
	}

	// x is the left child of p
	inline SplayTreeNode* rotateR(SplayTreeNode *r) {
		SplayTreeNode *rL = r->lson;
		r->lson = rL->rson;
		rL->rson = r;
		return rL;
	}

	// splay the node with [x] into the position 'r'
	SplayTreeNode* splay(SplayTreeNode *r, int x) {
		while (x != r->v) {
			if (x < r->v) {
				if (x < r->lson->v) {
					// zig-zig, R + R
					r->lson = rotateR(r->lson);
					r = rotateR(r);
				} else if (x > r->lson->v) {
					// zig-zag, L + R
					r->lson = rotateL(r->lson);
					r = rotateR(r);
				} else {
					// zig, R
					r = rotateR(r);
				}
			} else {
				if (x > r->rson->v) {
					// zig-zig, L + L
					r->rson = rotateL(r->rson);
					r = rotateL(r);
				} else if (x < r->rson->v) {
					// zig-zag, R + L
					r->rson = rotateR(r->rson);
					r = rotateR(r);
				} else {
					// zig, L
					r = rotateL(r);
				}
			}
		}
		return r;
	}

	SplayTreeNode* findMin(SplayTreeNode *r) {
		if (r == NULL) {
			return NULL;
		} else {
			return r->lson ? findMin(r->lson) : r;
		}
	}

	SplayTreeNode* findMax(SplayTreeNode *r) {
		if (r == NULL) {
			return NULL;
		} else {
			return r->rson ? findMax(r->rson) : r;
		}
	}

	SplayTreeNode* find(SplayTreeNode *r, int x) {
		SplayTreeNode *ret = NULL;
		if (r == NULL) {
			// not found, do nothing
		} else {
			if (x < r->v) {
				ret = find(r->lson, x);
			} else if (x > r->v) {
				ret = find(r->rson, x);
			} else {
				ret = r;
			}
		}
		return ret;
	}

	SplayTreeNode* insert(SplayTreeNode *r, int x) {
		if (r == NULL) {
			r = new SplayTreeNode();
			r->v = x;
			r->lson = r->rson = NULL;
		} else {
			if (x < r->v) {
				r->lson = insert(r->lson, x);
			} else if (x > r->v) {
				r->rson = insert(r->rson, x);
			} else {
				// x has been in the tree, do nothing.
			}
		}
		return r;
	}

	SplayTreeNode* remove(SplayTreeNode *r, int x) {
		if (r == NULL) {
			// no x, do nothing
		} else {
			if (x < r->v) {
				r->lson = remove(r->lson, x);
			} else if (x > r->v) {
				r->rson = remove(r->rson, x);
			} else {
				if (r->lson && r->rson) {
					SplayTreeNode *tar = findMin(r->rson);
					r->v = tar->v;
					r->rson = remove(r->rson, tar->v);
				} else {
					SplayTreeNode *tar = r;
					if (r->lson == NULL) {
						r = r->rson;
					} else {
						r = r->lson;
					}
					delete tar;
				}
			}
		}
		return r;
	}

	SplayTreeNode* findFather(SplayTreeNode *f, SplayTreeNode *r, int x) {
		if (r == NULL) {
			// no x, do nothing
			return NULL;
		} else {
			if (x < r->v) {
				return findFather(r, r->lson, x);
			} else if (x > r->v) {
				return findFather(r, r->rson, x);
			} else {
				return f;
			}
		}
	}

	void show(SplayTreeNode *root, int depth) {
		if (root) {
			show(root->lson, depth + 1);
			for (int i = 0; i < depth; ++i)
				putchar(' ');
			printf("%d\n", root->v);
			show(root->rson, depth + 1);
		}
	}

	// some interfaces
	SplayTreeNode* find(int x) {
		if (find(root, x) == NULL) {
			return NULL;
		} else {
			root = splay(root, x);
			return root;
		}
	}
	void insert(int x) {
		root = insert(root, x);
		// Splay the node contains 'x' to the root
		root = splay(root, x);
	}
	void remove(int x) {
		SplayTreeNode *father = findFather(NULL, root, x);
		if (father == NULL) {
			root = remove(root, x);
		} else {
			int fx = father->v;
			root = remove(root, x);
			root = splay(root, fx);
		}
	}
	void splayToRoot(int x) {
		root = splay(root, x);
	}
	void show() {
		show(root, 0);
	}
};

int main() {
	int n, v;
	char cmd[32];
	while (scanf("%d", &n) != EOF) {
		SplayTree splay;
		for (int op = 0; op < n; ++op) {
			scanf("%s", cmd);
			if (!strcmp(cmd, "show")) {
				splay.show();
			} else if (!strcmp(cmd, "insert")) {
				scanf("%d", &v);
				splay.insert(v);
			} else if (!strcmp(cmd, "find")) {
				scanf("%d", &v);
				SplayTreeNode *ret = splay.find(v);
				printf("Find %d : %x\n", v, (unsigned)ret);
			} else if (!strcmp(cmd, "remove")) {
				scanf("%d", &v);
				splay.remove(v);
			}
		}
	}
	return 0;
}
