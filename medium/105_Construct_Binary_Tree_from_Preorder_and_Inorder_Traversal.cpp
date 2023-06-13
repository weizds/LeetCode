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
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorder_map, int& index, int left, int right) {
        if (left > right)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[index]);
        int mid = inorder_map[preorder[index]];
        index++;
        root->left = build(preorder, inorder_map, index, left, mid - 1);
        root->right = build(preorder, inorder_map, index, mid + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        unordered_map<int, int> inorder_map;
        for(int i = 0; i < inorder.size(); ++i)
            inorder_map[inorder[i]] = i;
        return build(preorder, inorder_map, index, 0, inorder.size() - 1);
    }
};