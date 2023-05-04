class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10)
            return {};
        vector<string> res;
        unordered_map<string, int> hash_map;
        const int substr_size = 10;
        for(int i = 0; i <= s.size() - substr_size; ++i) {
            if(hash_map[s.substr(i, substr_size)]++ == 1)
                res.push_back(s.substr(i, substr_size));
        }
        return res;
    }
};