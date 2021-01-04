/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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

    int kSearch(TreeNode* root,int& k){
        if(!root)
            return -1;
        int res =  kSearch(root->left,k);
        if(k==0) return res;
        else if(--k==0)
            return root->val;
        else return kSearch(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int res = kSearch(root,k);
        return res;
    }
};
// @lc code=end

