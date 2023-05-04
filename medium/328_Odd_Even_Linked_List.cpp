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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* even_head = nullptr;
        ListNode* even_node = nullptr;
        ListNode* node = head;
        ListNode* prev = nullptr;
        while(node != nullptr && node->next != nullptr) {
            if(even_head == nullptr){
                even_head = node->next;
                even_node = even_head;
            }else{
                even_node->next = node->next;
                even_node = even_node->next;
            }
            node->next = node->next->next;
            prev = node;
            node = node->next;
        }
        if(node != nullptr)
            prev = node;
        if(even_node != nullptr)
            even_node->next = nullptr;
        prev->next = even_head;
        return head;
    }
};