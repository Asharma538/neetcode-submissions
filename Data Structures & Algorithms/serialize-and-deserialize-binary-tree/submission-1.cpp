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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        queue<TreeNode*> q;
        string s = "";

        q.push(root);
        while(q.size()){
            TreeNode* x = q.front();
            q.pop();

            if (x == NULL){
                s += "NULL|";
                continue;
            }
            q.push(x->left);
            q.push(x->right);
            s += to_string(x->val);
            s += '|';

        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size()==0) return NULL;

        queue<TreeNode*> q;
        queue<TreeNode*> q1;
        int ch = 0;
        while(ch < data.size()){
            string tmp;
            while(ch<data.size() and data[ch]!='|'){
                tmp += data[ch];
                ch++;
            }
            if (tmp=="NULL") q.push(NULL),q1.push(NULL);
            else if (tmp!="") q.push(new TreeNode(stoi(tmp))), q1.push(new TreeNode(stoi(tmp)));
        
            ch++;
        }

        while(q1.size()){
            if (q1.front() == NULL) cout<<"NULL ";
            else cout<<q1.front()->val<<' ';
            q1.pop();
        }
        
        bool leg = 0; // left is 0 , right is 1
        TreeNode* root = q.front();
        TreeNode* prev = root;
        q.pop();

        queue<TreeNode*> cq;
        cq.push(root);
        while(q.size()){
            TreeNode* prev = cq.front();
            TreeNode* curr = q.front();
            q.pop();
            if (leg){
                prev->right = curr;
                cq.pop();
            } else {
                prev->left = curr;
            }
            if (curr!=NULL) cq.push(curr);
            leg = !leg;
        }
        return root;
    }
};
