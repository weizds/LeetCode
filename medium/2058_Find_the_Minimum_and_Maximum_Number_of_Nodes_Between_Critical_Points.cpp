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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int dist_min = INT_MAX;
        int dist_max = -1;
        int index = 1;
        int first_critical = -1;
        int prev_critical = -1;
        if(head == nullptr)
            return {-1, -1};
        ListNode *node = head;
        while(node != nullptr && node->next != nullptr && node->next->next != nullptr) {
            if(node->val > node->next->val && node->next->val < node->next->next->val){
                if(prev_critical > 0)
                    dist_min = min(dist_min, index - prev_critical);
                prev_critical = index;
                if(first_critical < 0)
                    first_critical = index;
                else
                    dist_max = max(dist_max, index - first_critical);
            }else if(node->val < node->next->val && node->next->val > node->next->next->val){
                if(prev_critical > 0)
                    dist_min = min(dist_min, index - prev_critical);
                prev_critical = index;
                if(first_critical < 0)
                    first_critical = index;
                else
                    dist_max = max(dist_max, index - first_critical);
            }
            node = node->next;
            ++index;
        }
        if(dist_min == INT_MAX)
            dist_min = -1;
        return {dist_min, dist_max};
    }
};