/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    //fisrt AC 2020.03.25 Time#59.33% Memory#97.92% 
    //use backtrack
    /*
    bool isValidBST(TreeNode* root, int max, int min, bool tag1, bool tag2){
        if(!root) return true;
        return (!tag2 || root->val > min ) && ( !tag1 || root->val < max ) &&\
             isValidBST(root->left, root->val, min, true, tag2) && isValidBST(root->right, max, root->val, tag1, true);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MAX , INT_MIN, false, false);
    }
    */

    bool isValidBST(TreeNode* root) {
        
    }
};
// @lc code=end

