class MyHashSet {
public:
    MyHashSet() {
        m_data.resize(m_size);
    }
    
    void add(int key) {
        size_t h = hash<int>{}(key);
        vector<int> &vec = m_data[h % m_size];
        bool found = false;
        for(auto it = vec.begin(); it != vec.end(); ++it) {
            if(*it == key) {
                found = true;
                break;
            }
        }
        if(!found)
            vec.push_back(key);
    }
    
    void remove(int key) {
        size_t h = hash<int>{}(key);
        vector<int> &vec = m_data[h % m_size];
        for(auto it = vec.begin(); it != vec.end(); ++it) {
            if(*it == key) {
                swap(*it, vec.back());
                vec.pop_back();
                break;
            }
        }
    }
    
    bool contains(int key) {
        size_t h = hash<int>{}(key);
        vector<int> &vec = m_data[h % m_size];
        bool found = false;
        for(auto it = vec.begin(); it != vec.end(); ++it) {
            if(*it == key) {
                found = true;
                break;
            }
        }
        return found;
    }
private:
    size_t m_size{1024};
    vector<vector<int>> m_data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */