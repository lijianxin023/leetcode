/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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

    //fisrt AC 2020.03.26 Time#55.25% Memory#100% 
    //backtrack
    int maxPathSum(TreeNode* root,int &maxsum) {
        int leftsum = 0, rightsum = 0;
        if(root->left) leftsum = max(maxPathSum(root->left,maxsum),0);
        if(root->right) rightsum = max(maxPathSum(root->right,maxsum),0);
        maxsum = max(leftsum+rightsum+root->val,maxsum);
        return max(leftsum,rightsum)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        maxPathSum(root,maxsum);
        return maxsum;
    }
};
// @lc code=end

