/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t == nullptr) res.push_back(0);
            else{
                int value = t->val+1001;
                int n1 = value/128;
                int n2 = value%128;
                res.push_back(n1);
                res.push_back(n2);
                q.push(t->left);
                q.push(t->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        queue<TreeNode*> q;
        if(data[0]==0) return nullptr;
        else root = new TreeNode(data[0]*128+data[1]-1001);
        q.push(root);
        int c, i = 2;

        while(i<data.size()){
            TreeNode* temp = q.front();
            q.pop();
            c = data[i++];
            if(c==0) temp->left = nullptr;
            else {
                temp->left = new TreeNode(c*128+data[i++]-1001);
                q.push(temp->left);
            }

            c = data[i++];
            if(c==0) temp->right = nullptr;
            else {
                temp->right = new TreeNode(c*128+data[i++]-1001);
                q.push(temp->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

