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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()) {
            int curr_max = INT_MIN;
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                TreeNode *node =  q.front();
                q.pop();
                curr_max = max(curr_max, node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            res.push_back(curr_max);
        }
        return res;
    }
};