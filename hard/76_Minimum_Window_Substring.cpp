class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())
            return "";
        unordered_map<char, int> hash_map;
        int res = INT_MAX;
        int res_start = 0;
        int l = 0;
        for(auto ch : t)
            hash_map[ch]++;
        int t_count = hash_map.size();
        for(int r = 0; r < s.size(); ++r){
            --hash_map[s[r]];
            if(hash_map[s[r]] == 0)
                --t_count;
            while(t_count == 0){
                if(r - l + 1 < res){
                    res = r - l + 1;
                    res_start = l;
                }
                ++hash_map[s[l]];
                if(hash_map[s[l]] > 0)
                    ++t_count;
                ++l;
            }
        }
        if(res == INT_MAX)
            return "";
        else
            return s.substr(res_start, res);
    }
};