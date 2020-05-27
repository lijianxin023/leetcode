/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

    //fisrt AC 2020.03.25 Time#33.45% Memory#42.86% 
    /*
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,\
    int low1, int low2, int high1, int high2){
        if(low1==high1)
                return NULL;
        int headval = preorder[low1];
        int len_left = 0;

        TreeNode* res = new TreeNode(headval);
        
        while(low2+len_left < high2 && inorder[low2+len_left]!=headval)
            ++len_left;
        res->left = buildTree(preorder,inorder,low1+1,low2,low1+len_left,low2+len_left-1);
        res->right = buildTree(preorder,inorder,low1+len_left+1,low2+len_left+1,high1,high2);
        return res;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,inorder,0,0,preorder.size()-1,inorder.size()-1);
    }
    

    //fisrt AC 2020.03.25 Time#89.76% Memory#57.14% 
    /*
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        stack<TreeNode*> s;
        int i = 0, j = 0;
        const int n = preorder.size();
        if(n==0) return NULL;
        TreeNode* head = new TreeNode(preorder[i++]); s.push(head);
        
        while(i<n && j<n){
            TreeNode* head = s.top();
            TreeNode* newhead = new TreeNode(preorder[i++]);
            if(inorder[j] != head->val)
                head->left = newhead; 
            else{
                while(!s.empty()&& inorder[j] == s.top()->val){
                    ++j;
                    head = s.top();
                    s.pop();
                }
                head->right = newhead;
            }
            s.push(newhead);
        }
        return head; 
    }
    */
};
// @lc code=end

