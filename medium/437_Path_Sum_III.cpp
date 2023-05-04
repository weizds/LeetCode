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
    void dfs(TreeNode* root, int target, long long sum) {
        if(root == nullptr)
            return;
        sum += root->val;
        res += cache[sum - target];
        ++cache[sum];
        dfs(root->left, target, sum);
        dfs(root->right, target, sum);
        --cache[sum];
    }
    int pathSum(TreeNode* root, int targetSum) {
        cache[0] = 1;
        dfs(root, targetSum, 0);
        return res;
    }
private:
    unordered_map<long long, long long> cache;
    int res{0};
};