class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int dict[26]{0};
        // unordered_map<char, int> hashmap;
        if(p.size() > s.size())
            return {};
        for(auto ch : p)
            ++dict[ch - 'a'];
            // ++hashmap[ch];
        int count = p.size();
        int l = 0;
        vector<int> res;
        for(int r = 0; r < s.size(); ++r) {
            // --hashmap[s[r]];
            // if(hashmap[s[r]] >= 0)
            --dict[s[r] - 'a'];
            if(dict[s[r] - 'a'] >= 0)
                --count;
            if(r >= p.size()) {
                // ++hashmap[s[l]];
                // if(hashmap[s[l]] > 0)
                ++dict[s[l] - 'a'];
                if(dict[s[l] - 'a'] > 0)
                    ++count;
                ++l;
            }
            if(count == 0)
                res.push_back(l);
        }
        return res;
    }
};