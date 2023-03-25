/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = l1->val + l2->val;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* head = new ListNode(carry % 10);
        carry /= 10;
        ListNode* node = head;
        while(l1 != nullptr || l2 != nullptr) {
            if(l1 != nullptr) {
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                carry += l2->val;
                l2 = l2->next;
            }
            node->next = new ListNode(carry % 10);
            node = node->next;
            carry /= 10;
        }
        if(carry > 0)
            node->next = new ListNode(carry);
        carry /= 10;
        return head;
    }
};