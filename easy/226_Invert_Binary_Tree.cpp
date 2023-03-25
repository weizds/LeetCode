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
    void dfsInvert(TreeNode* root) {
        if(root == nullptr)
            return;
        dfsInvert(root->left);
        dfsInvert(root->right);
        swap(root->left, root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfsInvert(root);
        return root;
    }
};