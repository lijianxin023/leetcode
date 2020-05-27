/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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

//fisrt AC 2020.03.30 Time#74.08% Memory#100%
    /*
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *walker = head, *runner = head, *temp = NULL;
        while(runner && runner->next){
            runner = runner->next->next;
            walker = walker->next;
            if(walker == runner){
                temp = walker;
                break;
            }
        }
        if(temp == NULL) return NULL;
        int t_pos = 0, circle_num = 1;
        ListNode *t = temp->next;
        walker = head;
        while(walker != temp) {walker = walker->next; ++ t_pos;}
        while(t != temp) {t = t->next; ++ circle_num;}
        int res = 0;
        walker = head;
        if(t_pos < circle_num)
            for(int i = 0;i < circle_num-t_pos ;++i)
                t = t->next;
        else for(int i = 0;i < t_pos-circle_num ;++i){
            walker = walker->next;
            ++res;
        }
        while(t != walker){
            t= t->next;
            walker = walker->next;
            ++res;
        }
        return t;
    
    }
    */

    //second AC 2020.03.30 Time#97.01% Memory#100%
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *walker = head, *runner = head, *temp = NULL;
        while(runner && runner->next){
            runner = runner->next->next;
            walker = walker->next;
            if(walker == runner){
                temp = walker;
                break;
            }
        }
        if(temp == NULL) return NULL;
        walker = head;
        while(walker != temp){
            walker = walker->next;
            temp = temp->next;
        }
        return walker;
    }
};
// @lc code=end

