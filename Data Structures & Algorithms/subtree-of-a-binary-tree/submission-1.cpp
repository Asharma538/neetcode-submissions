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
    bool isSame(TreeNode* r, TreeNode* sr){
        if (r == NULL and sr == NULL) return 1;
        if (r == NULL or sr == NULL) return 0;
        if (r->val != sr->val) return 0;

        return isSame(r->left, sr->left) & isSame(r->right , sr->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL and subRoot == NULL) return 1;
        if (root == NULL or subRoot == NULL) return 0;

        if (root->val == subRoot->val and isSame(root, subRoot)) return 1;

        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }

};
