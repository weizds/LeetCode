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
    TreeNode* build(vector<int>& postorder, unordered_map<int, int>& inorder_map, int& index, int i, int j) {
        if (i > j)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[index]);
        int split = inorder_map[postorder[index]];
        --index;
        root->right = build(postorder, inorder_map, index, split + 1, j);
        root->left = build(postorder, inorder_map, index, i, split - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        unordered_map<int, int> inorder_map;
        for(int i = 0; i < inorder.size(); ++i)
            inorder_map[inorder[i]] = i;
        return build(postorder, inorder_map, index, 0, inorder.size() - 1);
    }
};