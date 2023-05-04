class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty())
            return {};
        unordered_map<string, vector<string>> hash_map;
        for(auto s : strs) {
            string tmp(s);
            sort(tmp.begin(), tmp.end());
            hash_map[tmp].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it = hash_map.begin(); it != hash_map.end(); ++it)
            res.push_back(it->second);
        return res;
    }
};