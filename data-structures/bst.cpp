#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct TreeNode {
	int v;
	TreeNode *lson;
	TreeNode *rson;
};

class BinarySearchTree {
	TreeNode *root;
public:
	BinarySearchTree() {
		root = NULL;
	}

	~BinarySearchTree() {
		if (root) {
			queue<TreeNode*> Q;
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

	TreeNode* findMin(TreeNode *r) {
		if (r == NULL) {
			return NULL;
		} else {
			return (r->lson == NULL ? r : findMin(r->lson));
		}
	}

	TreeNode* findMax(TreeNode *r) {
		if (r == NULL) {
			return NULL;
		} else {
			return (r->rson == NULL ? r : findMax(r->rson));
		}
	}

	TreeNode* find(TreeNode *r, int x) {
		if (r == NULL) {
			return NULL;
		}
		if (x < r->v) {
			return find(r->lson, x);
		} else if (x > r->v) {
			return find(r->rson, x);
		} else {
			return r;
		}
	}

	TreeNode* insert(TreeNode *r, int x) {
		if (r == NULL) {
			r = new TreeNode();
			r->v = x;
			r->lson = r->rson = NULL;
		} else {
			if (x < r->v) {
				r->lson = insert(r->lson, x);
			} else if (x > r->v) {
				r->rson = insert(r->rson, x);
			} else {
				// duplicated key found
			}
		}
		return r;
	}

	TreeNode* remove(TreeNode *r, int x) {
		if (r == NULL) {
			// element not found
		} else {
			if (x < r->v) {
				r->lson = remove(r->lson, x);
			} else if (x > r->v) {
				r->rson = remove(r->rson, x);
			} else {
				// found the element to be removed
				if (r->lson && r->rson) {
					TreeNode *tar = findMin(r->rson);
					r->v = tar->v;
					r->rson = remove(r->rson, tar->v);
				} else {
					TreeNode *tar = r;
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

	void show(TreeNode *r, int depth) {
		if (r != NULL) {
			for (int i = 0; i < depth; ++i)
				putchar(' ');
			printf("%d\n", r->v);
			show(r->lson, depth + 1);
			show(r->rson, depth + 1);
		}
	}

	// some interfaces
	TreeNode* findMin() {
		return findMin(root);
	}

	TreeNode* findMax() {
		return findMax(root);
	}

	TreeNode* find(int x) {
		return find(root, x);
	}

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
		BinarySearchTree bst;
		for (int i = 0; i < n; ++i) {
			scanf("%s", cmd);
			if (!strcmp(cmd, "find")) {
				scanf("%d", &v);
				TreeNode *ptr = bst.find(v);
				if (!ptr) {
					puts("null");
				} else {
					printf("%x : %d\n", (unsigned)ptr, ptr->v);				
				}
			} else if (!strcmp(cmd, "findMin")) {
				TreeNode *mini = bst.findMin();
				if (!mini) {
					puts("null");
				} else {
					printf("%x : %d\n", (unsigned)mini, mini->v);
				}
			} else if (!strcmp(cmd, "findMax")) {
				TreeNode *maxi = bst.findMax();
				if (!maxi) {
					puts("null");
				} else {
					printf("%x : %d\n", (unsigned)maxi, maxi->v);			
				}
			} else if (!strcmp(cmd, "insert")) {
				scanf("%d", &v);
				bst.insert(v);
			} else if (!strcmp(cmd, "remove")) {
				scanf("%d", &v);
				bst.remove(v);
			} else if (!strcmp(cmd, "show")) {
				bst.show();
			}
		}
	}
	return 0;
}
