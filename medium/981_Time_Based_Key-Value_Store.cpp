class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        _map[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        if(_map.find(key) == _map.end())
            return "";
        auto &vec = _map[key];
        int low = 0;
        int high = vec.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(vec[mid].first < timestamp){
                low = mid + 1;
            }else if(vec[mid].first > timestamp){
                high = mid - 1;
            }else{
                return vec[mid].second;
            }
        }
        if(high >= 0)
            return vec[high].second;
        return "";        
    }
private:
    unordered_map<string, vector<pair<int, string> > > _map;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */