/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void gao(TreeNode *root, int depth, int &ans) {
        if (root->left == NULL && root->right == NULL) {
            ans = min(ans, depth + 1);
        } else {
            if (root->left) {
                gao(root->left, depth + 1, ans);
            }
            if (root->right) {
                gao(root->right, depth + 1, ans);
            }
        }
    }
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        } else {
            int ret = 1000000000;
            gao(root, 0, ret);
            return ret;
        }
    }
};

