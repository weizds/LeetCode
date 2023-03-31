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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        ListNode* to_remove = head;
        ListNode* prev = nullptr;
        int count = 0;
        while(node != nullptr) {
            if(count >= n){
                prev = to_remove;
                to_remove = to_remove->next;
            }
            node = node->next;
            ++count;
        }
        if(prev == nullptr){
            head = head->next;
        }else{
            prev->next = to_remove->next;
        }
        return head;
    }
};