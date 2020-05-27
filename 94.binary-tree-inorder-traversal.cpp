/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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

//fisrt AC 2020.03.23 Time#100% Memory#100% 
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        if(root) s.push(root);
        bool tag = false;
        while(!s.empty()){
            TreeNode* head = s.top();
            s.pop();
            if(tag){
                result.push_back(head->val);
                if(head->right) tag = false;
                continue;
            }    
            if(head->right) s.push(head->right);
            if(head->left){
                s.push(head);
                s.push(head->left);
            }
            else{
                result.push_back(head->val);
                tag = head->right==NULL?true:false;
            }
        }
        return result;
    }
};
// @lc code=end

