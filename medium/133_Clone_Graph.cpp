/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
    
class Solution {
public:
    void dfs(Node* root, Node* new_root, unordered_map<Node*, Node*> &mp) {
        if(root == nullptr)
            return;
        for(auto node : root->neighbors) {
            Node* new_node = nullptr;
            if(mp.find(node) != mp.end()){
                new_node = mp[node];
            }else{
                new_node = new Node(node->val);
                mp[node] = new_node;
                dfs(node, new_node, mp);
            }
            new_root->neighbors.push_back(new_node);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;
        unordered_map<Node*, Node*> mp;
        Node* new_root = new Node(node->val);
        mp[node] = new_root;
        dfs(node, new_root, mp);
        return new_root;
    }
};