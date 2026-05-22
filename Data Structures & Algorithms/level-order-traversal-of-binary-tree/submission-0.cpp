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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        while(q.size()){
            TreeNode* x = q.front().first;
            int d = q.front().second;
            if (ans.size() == d){
                ans.push_back({x->val});
            } else {
                ans[d].push_back(x->val);
            }

            q.pop();

            if (x->left != NULL) q.push({x->left, d+1});
            if (x->right != NULL) q.push({x->right, d+1});

        }
        return ans;
    }
};
