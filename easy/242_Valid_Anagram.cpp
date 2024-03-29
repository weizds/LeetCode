class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        std::vector<int> dict(26, 0);
        for(auto ch : s)
            ++dict[ch - 'a'];
        for(auto ch : t) {
            --dict[ch - 'a'];
            if(dict[ch - 'a'] < 0)
                return false;
        }
        return true;
    }
};