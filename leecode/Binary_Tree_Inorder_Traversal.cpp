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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> vec;
        if (root == NULL) {
            return vec;
        }
        vector<int> lv = inorderTraversal(root->left);
        vector<int> rv = inorderTraversal(root->right);
        vec.insert(vec.end(), lv.begin(), lv.end());
        vec.push_back(root->val);
        vec.insert(vec.end(), rv.begin(), rv.end());
        return vec;
    }
};

