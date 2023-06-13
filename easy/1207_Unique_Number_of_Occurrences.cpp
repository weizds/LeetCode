class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for(auto num : arr)
            ++count[num];
        unordered_set<int> unique;
        for(auto it = count.begin(); it != count.end(); ++it) {
            if(unique.find(it->second) != unique.end())
                return false;
            unique.insert(it->second);
        }
        return true;
    }
};