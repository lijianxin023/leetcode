/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//fisrt AC 2020.03.31 Time#73.05% Memory#30%
    /*
    ListNode* sortList(ListNode* head) {
        int n = 0;
        ListNode* Node = head;
        while(Node) {++n; Node = Node->next;}
        ListNode* prehead = new ListNode(0);
        prehead -> next = head;
        for(int i = 1;i<n ;i*=2){
            ListNode *fnode = prehead, *snode = prehead->next;
            while(fnode){
                for(int j = 0;snode && j < i ;++j) snode = snode->next;
                if(snode == NULL) break;
                int fnum = 0, snum = 0;
                while(fnum < i && snum < i && snode){
                    if(fnode->next->val <= snode ->val){
                        fnode = fnode -> next;
                        ++fnum;
                    }
                    else {
                        ListNode *temp = fnode->next;
                        fnode -> next = snode;
                        snode = snode -> next;
                        fnode -> next -> next = temp;
                        fnode = fnode -> next;
                        ++snum;
                    }
                }
                for(int j = fnum ;j < i ;++j) 
                    fnode = fnode ->next;
                fnode->next = snode;
                for(int j = snum;fnode && j < i ;++j) 
                    fnode = fnode ->next;
                if(fnode) snode = fnode->next;
            }
        }
        return prehead->next;
    }
    */

    ListNode* sortList(ListNode* head) {     
        
        bool done = (!head);
        for(int step = 1;!done;step*=2){

            ListNode 
            *fnode, 
            *snode,
             *remaining;
            fnode = prehead, snode = prehead->next;
            
        }
        return prehead->next;
    }
};
// @lc code=end

