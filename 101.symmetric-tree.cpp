/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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

    //fisrt AC 2020.03.25 Time#100% Memory#100% 
    //recursively
    /*
    bool isSymmetric(TreeNode* head1, TreeNode* head2){
        if(head1 && head2 && head1->val == head2->val)
            return isSymmetric(head1->left,head2->right) && isSymmetric(head1->right,head2->left);
        else if(!head1 && !head2)
            return true;
        return false;
    }

    bool isSymmetric(TreeNode* root){
        if(root) return isSymmetric(root->left, root->right);
        return true;
    }
    */

    //fisrt AC 2020.03.25 Time#100% Memory#100% 
    //iteratively
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1,q2;
        if(root) {q1.push(root->left); q2.push(root->right);}
        bool tag = true;
        while(!q1.empty() && !q2.empty()){
            TreeNode *left = q1.front(), *right = q2.front();
            q1.pop(); q2.pop();
            if(left && right && left->val == right->val){
                q1.push(left->left);
                q1.push(left->right);
                q2.push(right->right);
                q2.push(right->left);
            }
            else if(!left && !right)
                continue;
            else {
                tag = false;
                break;
            }
        }
        return tag;
    }

};
// @lc code=end

