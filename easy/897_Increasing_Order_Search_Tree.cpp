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
    void dfs(TreeNode* node, TreeNode*& res, TreeNode*& res_root) {
        if(node == nullptr)
            return;
        dfs(node->left, res, res_root);
        if(res == nullptr){
            res = new TreeNode(node->val);
            res_root = res;
        }else{
            res->right = new TreeNode(node->val);
            res = res->right;
        }
        dfs(node->right, res, res_root);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res{nullptr};
        TreeNode* res_root{nullptr};
        dfs(root, res, res_root);
        return res_root;
    }
};