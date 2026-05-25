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
    int mx = -1e9;
    int dfs(TreeNode* root){
        if (root==NULL) return -1e9;

        int l = dfs(root->left);
        int r = dfs(root->right);
        mx = max(mx , l+r+root->val);
        mx = max(mx , l+root->val);
        mx = max(mx , r+root->val);
        mx = max(mx, root->val);
        mx = max(mx , l);
        mx = max(mx , r);

        return max(root->val, max(l+root->val , r+root->val));
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mx;
    }
};
