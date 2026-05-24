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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int lp, int rp, int li, int ri){
        for(int i = li; i<=ri; i++){
            if (inorder[i] == preorder[lp]){
                TreeNode* root = new TreeNode(preorder[lp]);

                root->left = build(preorder,inorder, lp+1, lp+1 + ((i-1)-li) ,li,i-1);
                root->right = build(preorder,inorder, rp - (ri - (i+1)), rp ,i+1,ri);

                return root;
            }
        }
        return NULL;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0) return NULL;

        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};



