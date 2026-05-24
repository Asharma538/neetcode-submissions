/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> v;
    bool valid(TreeNode* root, int left, int right){
        if (root==NULL) return true;
        if (root->val >= right or root->val <= left) return false;

        return valid(root->left, left, root->val) && valid(root->right, root->val, right);
    }
    
    bool isValidBST(TreeNode* root) {
        return valid(root, -1e9, 1e9);
    }
};
