/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool tag1 = false,tag2 = false;
        return find(root,p,q,tag1,tag2);
    }

    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q,bool &tag1,bool &tag2){

        if(!root) return nullptr;
        bool tag = false;
        if(!tag1&&!tag2) tag = true;
        TreeNode* res;
        res = find(root->left,p,q,tag1,tag2);
        if(res) return res;
        res = find(root->right,p,q,tag1,tag2);
        if(res) return res;
        if(root==p) tag1=true;
        if(root==q) tag2=true;
        if(tag&&tag1&&tag2)
            return root;
        else return nullptr;
    }
};
// @lc code=end

