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
    TreeNode *build(const vector<int> &inorder, const vector<int> &postorder, int l, int r) {
        if (r - l <= 0) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[m_root_i--]);
        for (int i = l; i < r; ++i) {
            if (inorder[i] == root->val) {
                root->right = build(inorder, postorder, i + 1, r);
                root->left = build(inorder, postorder, l, i);
            }
        }
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        m_root_i = (int)(postorder.size()) - 1;
        return build(inorder, postorder, 0, (int)(inorder.size()));
    }
};
