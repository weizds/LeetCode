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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;
        ListNode *head;
        if(list1->val < list2->val){
            head = list1;
            list1 = list1->next;
        }else{
            head = list2;
            list2 = list2->next;
        }
        ListNode *node = head;
        while(list1 && list2){
            if(list1->val < list2->val){
                node->next = list1;
                list1 = list1->next;
            }else{
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        if(list1)
            node->next = list1;
        if(list2)
            node->next = list2;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        queue<ListNode*> q;
        for(auto list : lists)
            q.push(list);
        while(q.size() > 1) {
            ListNode *l1 = q.front();
            q.pop();
            ListNode *l2 = q.front();
            q.pop();
            ListNode *l3 = mergeTwoLists(l1, l2);
            q.push(l3);
        }
        return q.front();
    }
};