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
    int goodNodes(TreeNode* root, int m = -1e9) {
        if (root == NULL) return 0;
        if (root->val >= m) 
            return 1 
                    + goodNodes(root->left, max(m, root->val)) 
                    + goodNodes(root->right, max(m, root->val));
        return goodNodes(root->left, max(m, root->val)) 
               + goodNodes(root->right, max(m, root->val));
        
    }
};
