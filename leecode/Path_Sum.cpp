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
    bool gao(TreeNode *root, int sum, int cur) {
        cur += root->val;
        if (root->left == NULL && root->right == NULL) {
            // leaf
            return cur == sum;
        } else {
            if (root->left && gao(root->left, sum, cur)) {
                return true;
            }
            if (root->right && gao(root->right, sum, cur)) {
                return true;
            }
            return false;
        }
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return false;
        } else {
            return gao(root, sum, 0);
        }
    }
};

