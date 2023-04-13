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
    void mergeLists(ListNode* list1, ListNode* list2) {
        while(list1 != nullptr && list2 != nullptr) {
            ListNode* list1_next = list1->next;
            ListNode* list2_next = list2->next;
            list1->next = list2;
            if(list1_next == nullptr)
                break;
            list2->next = list1_next;
            list1 = list1_next;
            list2 = list2_next;
        }
    }
    void reorderList(ListNode* head) {
        if(head->next == nullptr)
            return;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slow_prev = nullptr;
        while(slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        slow_prev->next = nullptr;
        slow = reverseList(slow);
        mergeLists(head, slow);
    }
};