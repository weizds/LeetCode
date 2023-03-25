class Solution {
public:
    int characterReplacement(string s, int k) {
        int map[26] = {0};
        int max_freq = 0;
        int res = 0;
        for(int l = 0, r = 0; r < s.size(); ++r){
            ++map[s[r] - 'A'];
            max_freq = max(max_freq, map[s[r] - 'A']);
            if(r - l + 1 - max_freq > k){
                --map[s[l] - 'A'];
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};