class TrieNode;
class TrieNode{
public:
    TrieNode(){;}

    TrieNode* children[26]{};
    TrieNode* add(char ch){
        children[ch - 'a'] = new TrieNode;
        return children[ch - 'a'];
    }
    TrieNode* find(char ch){
        return children[ch - 'a'];
    }
    bool end{false};
};

class WordDictionary {
public:
    WordDictionary() {
        _root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode *node = _root;
        for(auto ch : word){
            if(node->find(ch) == nullptr)
                node = node->add(ch);
            else
                node = node->find(ch);
        }
        node->end = true;
    }

    bool search_dfs(TrieNode *node, string::iterator current, string::iterator end){
        if(node == nullptr)
            return false;
        if(current == end)
            return node->end;
        if(*current == '.') {
            for(int i = 0; i < 26; ++i)
                if(node->children[i] && search_dfs(node->children[i], current + 1, end))
                    return true;
            return false;
        }else{
            return search_dfs(node->find(*current), current + 1, end);
        }
    }
    bool search(string word) {
        return search_dfs(_root, word.begin(), word.end());
    }
private:
    TrieNode *_root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */