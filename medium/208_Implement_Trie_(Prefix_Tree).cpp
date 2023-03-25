struct TrieNode;

struct TrieNode {
    TrieNode() {
        for(int i = 0; i < 26; ++i)
            next[i] = nullptr;
        end = false;
    }
    TrieNode *next[26];
    bool end;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(auto ch : word) {
            if(node->next[ch - 'a'] == nullptr)
                node->next[ch - 'a'] = new TrieNode();
            node = node->next[ch - 'a'];
        }
        node->end = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for(auto ch : word) {
            if(node->next[ch - 'a'] == nullptr)
                return false;
            node = node->next[ch - 'a'];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(auto ch : prefix) {
            if(node->next[ch - 'a'] == nullptr)
                return false;
            node = node->next[ch - 'a'];
        }
        return true;
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */