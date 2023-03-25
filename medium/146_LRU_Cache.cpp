class LRUCache {
public:
    LRUCache(int capacity) :capacity(capacity) {
        
    }
    
    int get(int key) {
        if(_map.find(key) != _map.end()){
            pair<int, int> _pair = *_map[key];
            _list.erase(_map[key]);
            _list.push_front(_pair);
            _map[key] = _list.begin();
            return _list.front().second;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(_map.find(key) != _map.end()){
            _list.erase(_map[key]);
            _list.push_front({key, value});
            _map[key] = _list.begin();
        }else{
            if(_list.size() >= capacity){
                int lru_key = _list.back().first;
                _list.pop_back();
                _map.erase(lru_key);
            }
            _list.push_front({key, value});
            _map[key] = _list.begin();
        }
    }
    private:
    list<pair<int, int> > _list;
    unordered_map<int, list<pair<int, int> >::iterator> _map;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */