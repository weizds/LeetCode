class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> dict(26, 0);
        for(auto ch : s)
            ++dict[ch - 'a'];
        int res = t.size();
        for(auto ch : t) {
            if(dict[ch - 'a'] > 0) {
                --dict[ch - 'a'];
                --res;
            }
        }
        return res;
    }
};