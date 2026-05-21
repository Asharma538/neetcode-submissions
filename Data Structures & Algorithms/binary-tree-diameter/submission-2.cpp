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
    int mx = 0;
    TreeNode *oroot = NULL;
    int diameterOfBinaryTree(TreeNode* root) {
        if (oroot == NULL) oroot = root;

        if (root == NULL) return -1;

        int left = diameterOfBinaryTree(root->left) + 1;
        int right = diameterOfBinaryTree(root->right) + 1;
        mx = max(left + right, mx);

        // cout<<root->val<<' '<<tmp<<'\n';
        if (oroot == root) return mx;
        return max(left, right);
    }
};













