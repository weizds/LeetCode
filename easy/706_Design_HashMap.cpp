class MyHashMap {
public:
    MyHashMap() {
        data.resize(size);
    }
    void put(int key, int value) {
        size_t h = hash<int>{}(key);
        vector<pair<int, int>> &vec = data[h % size];
        bool found = false;
        for(auto it = vec.begin(); it != vec.end(); ++it) {
            if(it->first == key) {
                it->second = value;
                found = true;
                break;
            }
        }
        if(!found)
            vec.push_back({key, value});
    }
    
    int get(int key) {
        size_t h = hash<int>{}(key);
        vector<pair<int, int>> &vec = data[h % size];
        for(auto it = vec.begin(); it != vec.end(); ++it) {
            if(it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        size_t h = hash<int>{}(key);
        vector<pair<int, int>> &vec = data[h % size];
        for(auto it = vec.begin(); it != vec.end(); ++it) {
            if(it->first == key) {
                swap(*it, vec.back());
                vec.pop_back();
                break;
            }
        }
    }
private:
    size_t size{1024};
    vector<vector<pair<int, int>>> data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */