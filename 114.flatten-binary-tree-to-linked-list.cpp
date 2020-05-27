/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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

    //fisrt AC 2020.03.25 Time#72.61% Memory#100% 
    //recursively
    /*
    TreeNode* flat(TreeNode* root){
        if(!root->left && !root->right)   return root;
        else if(!root->left) return flat(root->right);

        swap(root->left,root->right);
        if(!root->left) return flat(root->right);

        TreeNode* left = flat(root->left);
        TreeNode* right = flat(root->right);
        right->right = root->left;
        root->left = nullptr;     
        return left;
    }

    void flatten(TreeNode* root) {
        if(root) flat(root);
    }
    */


    //fisrt AC 2020.03.25 Time#72.61% Memory#100% 
    //iteratively use stack?
    void flatten(TreeNode* root) {
        
    }

};
// @lc code=end

