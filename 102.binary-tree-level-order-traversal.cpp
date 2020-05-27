/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            vector<int> tempres;
            int num = q.size();
            for(int i = 0;i < num; ++i){
                TreeNode* head = q.front();
                q.pop();
                tempres.push_back(head->val);
                if(head->left) q.push(head->left); 
                if(head->right) q.push(head->right); 
            }
            res.push_back(tempres);
        }
        return res;
    }
};
// @lc code=end

