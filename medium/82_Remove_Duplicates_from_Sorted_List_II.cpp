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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;
        ListNode* prev = nullptr;
        while(node != nullptr) {
            bool found = false;
            while(node->next != nullptr && node->val == node->next->val) {
                node->next = node->next->next;
                found = true;
            }
            if(found) {
                if(prev == nullptr){
                    head = node->next;
                }else{
                    prev->next = node->next;
                }
            }else{
                prev = node;
            }
            node = node->next;
        }
        return head;
    }
};