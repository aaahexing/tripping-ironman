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
    int m_root_i;
public:
    TreeNode *build(const vector<int> &preorder, const vector<int> &inorder, int l, int r) {
        if (r - l <= 0) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[m_root_i++]);
        for (int i = l; i < r; ++i) {
            if (inorder[i] == root->val) {
                root->left = build(preorder, inorder, l, i);
                root->right = build(preorder, inorder, i + 1, r);
            }
        }
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        m_root_i = 0;
        return build(preorder, inorder, 0, (int)inorder.size());
    }
};
