#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

struct TreeNode {
	int v;
	TreeNode *lson;
	TreeNode *rson;
	TreeNode *parent;
};

// 4.1
bool isBalanced(TreeNode *root, int depth, int &mini, int &maxi) {
	if (root) {
		if (!isBalanced(root->lson, depth + 1, mini, maxi))
			return false;
		if (!isBalanced(root->rson, depth + 1, mini, maxi))
			return false;
		if (root->lson == NULL && root->rson == NULL) {
			// leaf
			mini = min(mini, depth);
			maxi = max(maxi, depth);
		}
	}
	return maxi - mini <= 1;
}

// 4.3: create a bst with minimal height with a sorted array
TreeNode* create(int l, int r, int a[]) {
	if (r - l == 0) {
		return NULL;
	}
	int m = (l + r) >> 1;
	TreeNode *cur = new TreeNode();
	cur->v = a[m];
	cur->lson = create(l, m, a);
	cur->rson = create(m, r, a);
	return cur;
}

// 4.5: find ancestor
TreeNode* findMin(TreeNode *r) {
	if (r == NULL) {
		return NULL;
	} else {
		return (r->lson ? findMin(r->lson) : r);
	}
}

TreeNode* findSuccessor(TreeNode *r) {
	while (r != NULL) {
		if (r->rson) {
			return findMin(r->rson);
		}
		if (r == r->parent->lson) {
			return r;
		} else {
			r = r->parent;
		}
	}
	return NULL;
}

TreeNode* findSuccessorOpt(TreeNode *r) {
	if (r != NULL) {
		if (r->rson) {
			return findMin(r->rson);
		} else {
			if (r == r->parent->lson) {
				return r;
			} else {
				return findSuccessorOpt(r->parent);
			}
		}
	}
	return NULL;
}

// 4.6: LCA
TreeNode* findLCA(TreeNode *r, TreeNode *a, TreeNode *b) {
	
}

// 4.8

int depth;
TreeNode* path[MAXN];
void tr(TreeNode *r, int sum, int tar) {
	if (sum == tar) {
		// print
	}
	if (r != NULL) {
		// not use r
		tr(r->lson, 0, tar);
		tr(r->rson, 0, tar);
		// use r
		path[depth++] = r;
		tr(r->lson, sum + r->v, tar);
		tr(r->rson, sum + r->v, tar);
		--depth;
	}
}

// for debugging
void show(TreeNode *r) {
	if (r) {
		show(r->lson);
		printf("%d\n", r->v);
		show(r->rson);
	}
}

int main() {
	int n, v, a[MAXN];
	return 0;
}
