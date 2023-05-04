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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* node = head;
        while(node != nullptr) {
            ListNode* tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        int carry = 0;
        ListNode dummy;
        ListNode* node = &dummy;
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
            node->next = new ListNode(carry % 10);
        return reverseList(dummy.next);
    }
};