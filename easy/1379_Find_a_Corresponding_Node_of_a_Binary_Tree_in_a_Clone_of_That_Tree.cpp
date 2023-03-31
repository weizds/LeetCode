/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* find(TreeNode*root, TreeNode* target) {
    if(root == nullptr)
        return nullptr;
    if(root->val == target->val){
            return root;
    }
    TreeNode* res = find(root->left, target);
    if(res != nullptr)
        return res;
    else return find(root->right, target);
}

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return find(cloned, target);
    }
};