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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inOrderPush(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        inOrderPush(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    stack<TreeNode*> st;
    void inOrderPush(TreeNode* root) {
        while(root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */