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
        int res = 0;
        queue<pair<TreeNode*, uint64_t>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int size = q.size();
            uint64_t cur_min = q.front().second;
            uint64_t left = -1;
            uint64_t right = 0;
            for(int i = 0; i < size; ++i) {
                uint64_t cur = q.front().second - cur_min;
                TreeNode* node = q.front().first;
                q.pop();
                if(left == -1)
                    left = cur;
                right = cur;
                if(node->left)
                    q.push({node->left, cur * 2 + 1});
                if(node->right)
                    q.push({node->right, cur * 2 + 2});
            }
            res = max((uint64_t)res, right - left + 1);
        }
        return res;
    }
};