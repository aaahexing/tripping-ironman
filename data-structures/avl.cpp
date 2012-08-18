#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct AVLTreeNode {
	int v;
	int height;
	AVLTreeNode *lson;
	AVLTreeNode *rson;
};

// The decision how we will rebalance the tree is only decided
//	by the DEEPEST sub-tree no matter whether we are doing
//	'insertion' or 'deletion'.

class AVLTree {
	AVLTreeNode *root;
public:
	AVLTree() {
		root = NULL;
	}

	~AVLTree() {
		if (root) {
			queue<AVLTreeNode*> Q;
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

	inline int getHeight(AVLTreeNode *r) {
		return r == NULL ? -1 : r->height;
	}

	inline void updateHeight(AVLTreeNode *r) {
		r->height = max(getHeight(r->lson), getHeight(r->rson)) + 1;
	}

	//	r	       L
	//     / \	      / \
	//    L   R    ->    A+  r
	//   / \	        / \
	//  A+  B	       B   R
	inline AVLTreeNode* singleRotateL(AVLTreeNode *r) {
		AVLTreeNode *rL = r->lson;
		r->lson = rL->rson;
		rL->rson = r;
		updateHeight(r);
		updateHeight(rL);
		return rL;
	}

	//	r	       R
	//     / \	      / \
	//    L   R    ->    r   B+
	//       / \	    / \
	//      A   B+     L   A
	inline AVLTreeNode* singleRotateR(AVLTreeNode *r) {
		AVLTreeNode *rR = r->rson;
		r->rson = rR->lson;
		rR->lson = r;
		updateHeight(r);
		updateHeight(rR);
		return rR;
	}

	//	r                  LR+
	//     / \                /   \
	//    L   R              L     r
	//   / \         ->     / \   / \
	//  LL LR+             LL  A B   R
	//     / \
	//    A   B
	inline AVLTreeNode* doubleRotateLR(AVLTreeNode *r) {
		r->lson = singleRotateR(r->lson);
		return singleRotateL(r);
	}

	//	r                 RL+
	//     / \               /   \
	//    L   R             r     R
	//       / \     ->    / \   / \
	//      RL+ RR        L   A B   RR
	//     / \
	//    A   B
	inline AVLTreeNode* doubleRotateRL(AVLTreeNode *r) {
		r->rson = singleRotateL(r->rson);
		return singleRotateR(r);
	}

	AVLTreeNode* insert(AVLTreeNode *r, int x) {
		if (r == NULL) {
			r = new AVLTreeNode();
			r->v = x;
			r->height = 0;
			r->lson = r->rson = NULL;
		} else {
			if (x < r->v) {
				r->lson = insert(r->lson, x);
				if (getHeight(r->lson) - getHeight(r->rson) >= 2) {
					if (x < r->lson->v) {
						// LL insertion
						r = singleRotateL(r);
					} else {
						// LR insertion
						r = doubleRotateLR(r);
					}			
				}
			} else if (x > r->v) {
				r->rson = insert(r->rson, x);
				if (getHeight(r->rson) - getHeight(r->lson) >= 2) {
					if (x > r->rson->v) {
						// RR insertion
						r = singleRotateR(r);				
					} else {
						// RL insertion
						r = doubleRotateRL(r);
					}				
				}
			} else {
				// There has been one x in the tree, do nothing
			}
		}
		updateHeight(r);
		return r;
	}

	AVLTreeNode* findMin(AVLTreeNode *r) {
		if (r == NULL) {
			return NULL;
		} else {
			return r->lson == NULL ? r : findMin(r->lson);
		}
	}

	AVLTreeNode* findMax(AVLTreeNode *r) {
		if (r == NULL) {
			return NULL;
		} else {
			return r->rson == NULL ? r : findMax(r->rson);
		}
	}

	AVLTreeNode* find(AVLTreeNode *r, int x) {
		if (r == NULL) {
			return NULL;
		} else {
			if (x < r->v) {
				return find(r->lson, x);
			} else if (x > r->v) {
				return find(r->rson, x);
			} else {
				return r;
			}
		}
	}

	AVLTreeNode* remove(AVLTreeNode *r, int x) {
		if (r == NULL) {
			// No such element found, do nothing
		} else {
			if (x < r->v) {
				r->lson = remove(r->lson, x);
			} else if (x > r->v) {
				r->rson = remove(r->rson, x);
			} else {
				// Element is here, remove it!
				if (r->lson && r->rson) {
					AVLTreeNode* tar = findMin(r->rson);
					r->v = tar->v;
					r->rson = remove(r->rson, tar->v);
				} else {
					AVLTreeNode* tar = r;
					if (r->lson == NULL) {
						r = r->rson;
					} else {
						r = r->lson;
					}
					delete tar;
				}
			}
			if (r != NULL) {
				updateHeight(r);			
				// Rebalance it
				if (getHeight(r->lson) - getHeight(r->rson) >= 2) {
					// r->lson must be valid
					if (getHeight(r->lson->lson) > getHeight(r->lson->rson)) {
						r = singleRotateL(r);
					} else {
						r = doubleRotateLR(r);
					}
				} else if (getHeight(r->rson) - getHeight(r->lson) >= 2) {
					// r->rson must be valid
					if (getHeight(r->rson->rson) > getHeight(r->rson->lson)) {
						r = singleRotateR(r);
					} else {
						r = doubleRotateRL(r);
					}
				}
			}
		}
		return r;
	}

	void show(AVLTreeNode *r, int depth) {
		if (r) {
			show(r->lson, depth + 1);
			for (int i = 0; i < depth; ++i)
				putchar(' ');
			printf("%d (%d)\n", r->v, getHeight(r));
			show(r->rson, depth + 1);
		}
	}

	// some interfaces
	void insert(int x) {
		root = insert(root, x);
	}
	void remove(int x) {
		root = remove(root, x);
	}
	void show() {
		show(root, 0);
	}
};

int main() {
	int n, v;
	char cmd[32];
	while (scanf("%d", &n) != EOF) {
		AVLTree avl;
		for (int o = 0; o < n; ++o) {
			scanf("%s", cmd);
			if (!strcmp(cmd, "show")) {
				avl.show();
			} else if (!strcmp(cmd, "insert")) {
				scanf("%d", &v);
				avl.insert(v);
			} else if (!strcmp(cmd, "remove")) {
				scanf("%d", &v);
				avl.remove(v);
			}
		}
	}
	return 0;
}
