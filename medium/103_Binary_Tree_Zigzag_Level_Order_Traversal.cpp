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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bool left_to_right = false;
        queue<TreeNode*> q;
        if(root == nullptr)
            return res;
        q.push(root);
        while(!q.empty()) {
            res.push_back({});
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                res.back().push_back(node->val);
                q.pop();
            }
        }
        for(int i = 0; i < res.size(); ++i)
            if(i % 2 == 1)
                reverse(res[i].begin(), res[i].end());

        return res;
    }
};