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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkNode(TreeNode* root, ListNode* head) {
        if(head == nullptr)
            return true;
        if(root == nullptr)
            return false;
        if(root->val == head->val)
            return checkNode(root->left, head->next) || checkNode(root->right, head->next);
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == nullptr)
            return false;
        return checkNode(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};