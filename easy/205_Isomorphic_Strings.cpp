class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> map_s;
        unordered_map<char, int> map_t;
        for(int i = 0; i < s.size(); ++i){
            if(map_s.find(s[i]) == map_s.end())
                map_s[s[i]] = i;
            if(map_t.find(t[i]) == map_t.end())
                map_t[t[i]] = i;
            if(map_s[s[i]] != map_t[t[i]])
                return false;
        }
        return true;
    }
};