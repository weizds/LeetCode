class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int dict[26]{0};
        // unordered_map<char, int> hashmap;
        if(s1.size() > s2.size())
            return false;
        for(auto ch : s1)
            ++dict[ch - 'a'];
            // ++hashmap[ch];
        int count = s1.size();
        int l = 0;
        vector<int> res;
        for(int r = 0; r < s2.size(); ++r) {
            // --hashmap[s[r]];
            // if(hashmap[s[r]] >= 0)
            --dict[s2[r] - 'a'];
            if(dict[s2[r] - 'a'] >= 0)
                --count;
            if(r >= s1.size()) {
                // ++hashmap[s[l]];
                // if(hashmap[s[l]] > 0)
                ++dict[s2[l] - 'a'];
                if(dict[s2[l] - 'a'] > 0)
                    ++count;
                ++l;
            }
            if(count == 0)
                return true;
        }
        return false;
    }
};