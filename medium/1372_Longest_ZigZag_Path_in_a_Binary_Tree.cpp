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
    void dfs(TreeNode* root, int left, int right, int &res) {
        if(root == nullptr)
            return;
        res = max(res, max(left, right));
        dfs(root->left, right + 1, 0, res);
        dfs(root->right, 0, left + 1, res);
    }
    int longestZigZag(TreeNode* root) {
        int res = 0;
        dfs(root, 0, 0, res);
        return res;
    }
};