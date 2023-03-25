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
//   -----------------------------             -------------------
//   |                           v             |                 v
//   1 < 2 < 3           4 < 5 < 6             7 > 8 > 9         10 > 11
//           |            |                             ^
//         HEAD           -------------------------------
class Solution {
public:
    void inline reverseGroup(ListNode* head, ListNode* tail, int k){
        int node_count = 0;
        ListNode* prev = nullptr;
        ListNode* node = head;
        while(node_count < k){
            ListNode *tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
            ++node_count;
        }
        head->next = node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;
        if(k <= 1)
            return head;
        ListNode* group_head = head;
        ListNode* group_tail = head;
        ListNode* dangl = nullptr;
        ListNode* new_head = nullptr;
        int node_count = 0;
        while(group_tail){
            if(node_count == k - 1){
                node_count = 0;
                reverseGroup(group_head, group_tail, k);
                if(dangl)
                    dangl->next = group_tail;
                else
                    new_head = group_tail;
                dangl = group_head;
                group_head = group_head->next;
                group_tail = group_head;
            }else{
                group_tail = group_tail->next;
                ++node_count;
            }
        }
        return new_head;
    }

};