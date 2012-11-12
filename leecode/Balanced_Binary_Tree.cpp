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
    bool gao(TreeNode *root, int &height) {
        if (root == NULL) {
            height = 0;
            return true;
        }
        bool ret = true;
        int lh = 0, rh = 0;
        if (!gao(root->left, lh)) {
            ret = false;
        }
        if (!gao(root->right, rh)) {
            ret = false;
        }
        if (abs(lh - rh) > 1) {
            ret = false;
        }
        height = 1 + max(lh, rh);
        return ret;
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int h = 0;
        return gao(root, h);
    }
};

