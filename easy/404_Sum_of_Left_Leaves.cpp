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
    int helper(TreeNode* root, bool is_left) {
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr)
            return is_left ? root->val : 0;
        return helper(root->left, true) + helper(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};