class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for(auto ch : s)
            ++count[ch];
        int res = 0;
        for(auto it = count.begin(); it != count.end(); ++it) {
            res += it->second  - it->second % 2;
            if(res % 2 == 0 && it->second % 2 == 1)
                ++res;
        }
        return res;
    }
};