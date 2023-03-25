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
    int listCount(ListNode *node){
        int count = 0;
        while(node->next){
            count++;
            node = node->next;
        }
        return count;
    }

    void listAdd(ListNode* dst, ListNode* src){
        while(dst && src){
            dst->val += src->val;
            dst = dst->next;
            src = src->next;
        }
    }
    
    void listTidyUp(ListNode *node){
        if(node->next){
            listTidyUp(node->next);
            if(node->next->val >= 10){
                node->next->val -= 10;    
                node->val++;
            }
        }
    }
  
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_size = listCount(l1);
        int l2_size = listCount(l2);
        ListNode* tmp = NULL;
        if(l1_size >= l2_size){
            tmp = l1;
            for(int i = 0; i < l1_size - l2_size; i++, tmp = tmp->next);
            listAdd(tmp, l2);
            listTidyUp(l1);
            if(l1->val >= 10){
                l1->val -= 10;
                l1 = new ListNode(1, l1);
            }
            return l1;
        }else{
            tmp = l2;
            for(int i = 0; i < l2_size - l1_size; i++, tmp = tmp->next);
            listAdd(tmp, l1);
            listTidyUp(l2);
            if(l2->val >= 10){
                l2->val -= 10;
                l2 = new ListNode(1, l2);
            }
            return l2;
        }
    }
};