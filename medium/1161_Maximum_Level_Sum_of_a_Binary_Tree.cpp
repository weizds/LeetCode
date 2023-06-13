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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int max_sum = root->val;
        int max_level = 1;
        int level = 1;
        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            while(size-- > 0) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
            if(sum > max_sum) {
                max_sum = sum;
                max_level = level;
            }
            ++level;
        }
        return max_level;
    }
};