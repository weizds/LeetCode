/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        Node* node = head;
        while(node != nullptr) {
            Node* new_node = new Node(node->val);
            new_node->next = node->next;
            node->next = new_node;
            node = new_node->next;
        }
        node = head;
        while(node != nullptr) {
            Node* new_node = node->next;
            if(node->random != nullptr) 
                new_node->random = node->random->next;
            node = node->next->next;
        }
        node = head;
        Node* new_head = head->next;
        Node* new_node = new_head;
        while(node != nullptr) {
            node->next = new_node->next;
            node = node->next;
            if(node != nullptr) {
                new_node->next = node->next;
                new_node = new_node->next;
            }
        }
        return new_head;
    }
};