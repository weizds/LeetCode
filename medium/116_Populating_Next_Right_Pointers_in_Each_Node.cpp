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
    // O(1) space
    Node* connect(Node* root) {
        Node *level_start = root;
        while(level_start != nullptr) {
            Node* node = level_start;
            while(node != nullptr) {
                if(node->left != nullptr)
                    node->left->next = node->right;
                if(node->right != nullptr && node->next != nullptr)
                    node->right->next = node->next->left;
                node = node->next;
            }
            level_start = level_start->left;
        }
        return root;
    }
    // O(N) space
    // Node* connect(Node* root) {
    //     if(root == nullptr)
    //         return nullptr;
    //     queue<Node*> q;
    //     q.push(root);
    //     while(!q.empty()) {
    //         int size = q.size();
    //         for(int i = 0; i < size; ++i) {
    //             auto cur = q.front();
    //             q.pop();
    //             if(cur->left != nullptr)
    //                 q.push(cur->left);
    //             if(cur->right != nullptr)
    //                 q.push(cur->right);
    //             if(i < size - 1)
    //                 cur->next = q.front();
    //         }
    //     }
    //     return root;
    // } 
};