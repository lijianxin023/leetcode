/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    //fisrt AC 2020.03.26 Time#10.6% Memory#100% 
    /*
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* root = new Node(0);
        Node* res = root;
        while(head){
            if(m.count(head))
                root->next = m[head];
            else {
                root->next = new Node(head->val);
                m[head] = root->next;
            }
            if(head->random){
                if(m.count(head->random))
                     root->next->random = m[head->random];
                else{
                    root->next->random = new Node(head->random->val);
                    m[head->random] = root->next->random;
                }
            }
            head = head->next;
            root = root->next;
        }
        return res->next;
    }
    */
    Node* copyRandomList(Node* head){
        if(head == NULL) return NULL;
        for(Node* l1, *l2 = head; l2 ; l2 = l2->next->next){
            l1 = new Node(l2->val);
            l1->next = l2->next;
            l2->next = l1;
        }
        Node* root = head->next;
        for(Node* l1 = head; l1 ; l1 = l1->next->next){
            if(l1->random) l1->next->random = l1->random->next;
        }
        for(Node* l1 = head ; l1 ; l1 = l1->next){
            Node* l2 = l1->next;
            l1->next = l2->next;
            if(l2->next) l2->next = l2->next->next;
        }
        return root;
    }
};
// @lc code=end

