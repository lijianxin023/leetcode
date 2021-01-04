/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */

// @lc code=start
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

    int tryrob(TreeNode* root, int& l, int& r){
        if(root==nullptr) return 0;
        
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryrob(root->left, ll, lr);
        r = tryrob(root->right, rl, rr);

        return max(root->val + ll + lr + rl + rr, l + r);
    }

    int rob(TreeNode* root) {
        if(root==nullptr) return 0;
        int l,r;
        return tryrob(root,l,r);
    }
};
// @lc code=end

