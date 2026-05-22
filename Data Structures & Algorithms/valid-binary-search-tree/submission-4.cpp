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
    void inorder(TreeNode* root){
        if (root==NULL) return;

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root, int mx=-1e9, int mn=1e9) {
        v.clear();
        inorder(root);

        for(int i = 1 ; i < v.size() ; i++){
            if (v[i-1] >= v[i]) return false;
        }
        return true;
    }
};
