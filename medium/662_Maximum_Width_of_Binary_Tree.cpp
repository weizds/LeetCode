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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long res = 0;
        while(!q.empty()) {
            int size = q.size();
            long long start = q.front().second;
            res = max(res, q.back().second - start + 1);
            for(int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                if(cur.first->left != nullptr)
                    q.push({cur.first->left, (cur.second - start) * 2});
                if(cur.first->right != nullptr)
                    q.push({cur.first->right, (cur.second - start) * 2 + 1});
            }
        }
        return res;
    }
};