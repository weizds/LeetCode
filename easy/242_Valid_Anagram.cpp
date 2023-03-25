class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> dict(26, 0);
        for(auto ch : s)
            ++dict[ch - 'a'];
        for(auto ch : t)
            --dict[ch - 'a'];
        for(auto count : dict)
            if(count != 0)
                return false;
        return true;
    }
};