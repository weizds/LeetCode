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
    bool find(TreeNode* root, int target) {
        if(root == nullptr)
            return false;
        if(target < root->val)
            return find(root->left, target);
        else if(target > root->val)
            return find(root->right, target);
        return true;
    }
    bool dfs(TreeNode* root, TreeNode* node, int k) {
        if(node == nullptr)
            return false;
        if((k != node->val * 2) && find(root, k - node->val))
            return true;
        return dfs(root, node->left, k) || dfs(root, node->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root != nullptr)
            return dfs(root, root, k);
        return false;
    }
};