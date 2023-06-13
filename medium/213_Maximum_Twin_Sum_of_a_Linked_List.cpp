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
    ListNode* splitList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        if(head == nullptr)
            return 0;
        auto middle = splitList(head);
        middle = reverseList(middle);
        int res = head->val + middle->val;
        while(middle != nullptr) {
            res = max(res, head->val + middle->val);
            head = head->next;
            middle = middle->next;
        }
        return res;
    }
};