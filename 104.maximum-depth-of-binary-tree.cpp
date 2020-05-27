/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    void maxDepth(TreeNode* root,int &res,int dep){
        if(root == NULL) return;
        res = max(res,dep);
        maxDepth(root->left,res,dep+1);
        maxDepth(root->right,res,dep+1);
    }

    int maxDepth(TreeNode* root) {
        int res = 0;
        maxDepth(root,res,1);
        return res;
    }
};
// @lc code=end

