class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> pattern_map;
        unordered_map<string, int> s_map;
        istringstream iss(s);
        int i = 0;
        for(string token; iss >> token; ++i) {
            if(i == pattern.size() || pattern_map[pattern[i]] != s_map[token])
                return false;
            pattern_map[pattern[i]] = s_map[token] = i + 1;
        }
        return i == pattern.size();
    }
};