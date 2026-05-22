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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<pair<TreeNode*,int>> q;
        set<int> s;

        q.push({root,0});
        while(q.size()){
            TreeNode* x = q.front().first;
            int d = q.front().second;

            q.pop();
            if (x==NULL) continue;
            if (s.find(d) == s.end()){
                s.insert(d);
                ans.push_back(x->val);
            }

            if (x->right != NULL) q.push({x->right, d+1});
            if (x->left != NULL) q.push({x->left, d+1});
        }
        return ans;
    }
};
