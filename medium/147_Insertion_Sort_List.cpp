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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* unsorted_head = head->next;
        ListNode* sorted_head = head;
        sorted_head->next = nullptr;
        while(unsorted_head != nullptr) {
            ListNode* next = unsorted_head->next;
            ListNode* prev = nullptr;
            ListNode* node = sorted_head;
            while(node != nullptr && unsorted_head->val > node->val){
                prev = node;
                node = node->next;
            }
            if(prev == nullptr){
                unsorted_head->next = sorted_head;
                sorted_head = unsorted_head;
            }else{
                prev->next = unsorted_head;
                unsorted_head->next = node;
            }
            unsorted_head = next;
        }
        return sorted_head;
    }
};