/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *toremove =  new ListNode;
        ListNode *y = toremove;
        toremove->next = head;

        ListNode *iter = head;
        int it = 0;
        if(head->next == nullptr && n==1)
            head = nullptr;
        else{
            while(iter!=nullptr){
            iter = iter->next;
            if(it<n)
                ++it;
            else toremove = toremove->next;
        }
        ListNode* x = toremove->next;

        if(n==1)
            toremove->next = nullptr;
        else if(toremove->next == head) head = head->next;
        else toremove->next = toremove->next->next;
        delete x;
        }
        
        delete y;
        return head;
    }
};
// @lc code=end

