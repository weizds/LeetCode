class Solution {
public:
    // XXIV
    int romanToInt(string s) {
        unordered_map<char, int> values{{'M', 1000}, {'D', 500}, {'C', 100},
                                   {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int res = 0;
        for(int i = 0; i < s.size() - 1; ++i) {
            if(values[s[i]] >= values[s[i + 1]])
                res += values[s[i]];
            else
                res -= values[s[i]];
        }
        res += values[s.back()];
        return res;
    }
};