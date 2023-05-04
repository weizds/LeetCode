/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *level_start = nullptr;
        Node* prev = nullptr;
        Node* node = root;
        while(node != nullptr) {
            while(node != nullptr) {
                if(node->left != nullptr) {
                    if(prev != nullptr) {
                        prev->next = node->left;
                    }else{
                        level_start = node->left;
                    }
                    prev = node->left;
                }
                if(node->right != nullptr) {
                    if(prev != nullptr) {
                        prev->next = node->right;
                    }else{
                        level_start = node->right;
                    }
                    prev = node->right;
                }
                node = node->next;
            }
            node = level_start;
            prev = nullptr;
            level_start = nullptr;
        }
        return root;
    }
};