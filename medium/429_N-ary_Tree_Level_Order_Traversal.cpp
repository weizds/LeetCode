/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
            return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            while(size-- > 0) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                for(auto child : node->children)
                    q.push(child);
            }
            res.push_back(move(level));
        }
        return res;
    }
};