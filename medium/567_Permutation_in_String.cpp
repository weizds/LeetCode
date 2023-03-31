class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> hashmap;
        if(s1.size() > s2.size())
            return false;
        for(auto ch : s1)
            ++hashmap[ch];
        int count = hashmap.size();
        int l = 0;
        for(int r = 0; r < s2.size(); ++r) {
            --hashmap[s2[r]];
            if(hashmap[s2[r]] == -1)
                ++count;
            if(hashmap[s2[r]] == 0)
                --count;
            if(r >= s1.size()) {
                ++hashmap[s2[l]];
                if(hashmap[s2[l]] == 0)
                    --count;
                if(hashmap[s2[l]] == 1)
                    ++count;
                ++l;
            }
            if(count == 0)
                return true;
        }
        return false;
    }
};