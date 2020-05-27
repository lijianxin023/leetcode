/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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

//fisrt AC 2020.03.26 Time#13.67% Memory#26.32%
//use unordered_set
    /*
    bool hasCycle(ListNode *head) {
        bool tag = false;
        while(head){
            if(s.count(head)){
                tag = true;
                break;
            }
            s.insert(head);
            head = head->next;
        }
        return tag;
    }
    */
//second AC 2020.03.26 Time#99.85% Memory#100%
/*
    bool hasCycle(ListNode *head) {
        bool tag = false;
        ListNode *node = head;
        while(node){
            if(node->next == head){
                tag = true;
                break;
            }
            ListNode *temp = node;
            node = node->next;
            temp->next = head;
        }
        return tag;
    }
    */
//third AC 2020.03.26 Time#70.11% Memory#100%
    bool hasCycle(ListNode *head) {
        ListNode *walker = head, *runner = head;
        while(runner && runner->next){
            runner = runner->next->next;
            walker = walker->next;
            if(walker == runner)
                return true;
        }
        return false;
    }


};
// @lc code=end

