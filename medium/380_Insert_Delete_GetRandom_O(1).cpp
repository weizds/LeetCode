class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto it = mp.find(val);
        if(it != mp.end())
            return false;
        mp[val] = data.size();
        data.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto it = mp.find(val);
        if(it == mp.end())
            return false;
        mp[data.back()] = it->second;
        swap(data[it->second], data.back());
        data.pop_back();
        mp.erase(it);
        return true;
    }
    
    int getRandom() {
        int index = rand() % data.size();
        return data[index];
    }
private:
    unordered_map<int, int> mp;
    vector<int> data;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */