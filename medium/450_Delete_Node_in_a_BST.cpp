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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }else{
            if(root->left == nullptr && root->right == nullptr)
                return nullptr;
            if(root->left == nullptr || root->right == nullptr)
                return root->left ? root->left : root->right;
            TreeNode* tmp = root->left;
            while(tmp->right != nullptr)
                tmp = tmp->right;
            tmp->right = root->right;
            return root->left;
        }
        return root;
    }
};