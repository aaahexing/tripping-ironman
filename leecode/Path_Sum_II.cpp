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
    void gao(TreeNode *root, int sum, int cur, vector<int> &v, vector< vector<int> > &ret) {
        cur += root->val;
        v.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            // leaf
            if (cur == sum) {
                ret.push_back(v);
            }
        } else {
            if (root->left) {
                gao(root->left, sum, cur, v, ret);
            }
            if (root->right) {
                gao(root->right, sum, cur, v, ret);
            }
        }
        v.pop_back();
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        vector< vector<int> > ret;
        if (root != NULL) {
            gao(root, sum, 0, v, ret);
        }
        return ret;
    }
};

