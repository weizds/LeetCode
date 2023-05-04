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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node_a = headA;
        ListNode *node_b = headB;
        while(node_a != node_b) {
            if(node_a == nullptr)
                node_a = headB;
            else
                node_a = node_a->next;
            if(node_b == nullptr)
                node_b = headA;
            else
                node_b = node_b->next;
        }
        return node_a;
    }
};