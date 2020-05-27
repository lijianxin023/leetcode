/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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

//first AC 2020.04.08 #Time 61.24% #Memory 100%
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2 = 0;
        ListNode *x = headA;
        while(x){
            ++n1;
            x = x->next;
        }
        x = headB;
        while(x){
            ++n2;
            x = x->next;
        }
        while (n1!=n2)
        {
            if(n1>n2){
                headA = headA->next;
                --n1;
            }
            else{
                headB = headB->next;
                --n2;
            }
        }
        while(headA && headB){
            if(headA == headB)
                return headA;
            else{
                headA = headA->next;
                headB = headB->next;
            }
        }
        return nullptr;
    }
};
// @lc code=end

