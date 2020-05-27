/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;

        if(l1 == nullptr)
            head = l2;
        else if(l2 == nullptr)
            head = l1;
        else if(l1->val<=l2->val)
            head = l1;
        else head = l2;

        while(l1 && l2){
            if(l1->val > l2->val)
                swap(l1,l2);
            while(l1->next !=nullptr && l1->next->val <=l2->val)
                l1=l1->next;

            ListNode* temp1 = l1->next;
            ListNode* temp2 = l2->next;
            l1->next = l2;

            if(temp1==nullptr)
                break;
            else if(temp2==nullptr ||  temp1->val <= temp2->val)
                l2->next = temp1;
            l1 = temp1;
            l2 = temp2; 
        }

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int s = lists.size();
        int len = s;
        while(s>1){
            int temp = s;
            s = (s+1)/2;
            for(int i = 0;i<s;++i)
                if(i+s<temp)
                    lists[i] = mergeTwoLists(lists[i],lists[i+s]);
        }
        if(s == 0)
            return nullptr;
        return lists[0];
    }
};
// @lc code=end

