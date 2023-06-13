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
    void helper(TreeNode* root, int sum, vector<int>& current_path, vector<vector<int>>& res) {
        if(root == nullptr)
            return;
        current_path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && sum == root->val)
            res.push_back(current_path);
        helper(root->left, sum - root->val, current_path, res);
        helper(root->right, sum - root->val, current_path, res);
        current_path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        helper(root, targetSum, path, paths);
        return paths;
    }
};