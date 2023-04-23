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
    int dfs(TreeNode* root, bool &balanced) {
        if(root == nullptr)
            return 0;
        int left_depth = dfs(root->left, balanced);
        int right_depth = dfs(root->right, balanced);
        balanced &= abs(left_depth - right_depth) <= 1;
        return max(left_depth, right_depth) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
};