class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res = 0;
        for(int i = 0; i < s.size();) {
            int count_0 = 0;
            int count_1 = 0;
            while(i < s.size() && s[i] == '0') {
                ++count_0;
                ++i;
            }
            while(i < s.size() && s[i] == '1') {
                ++count_1;
                ++i;
            }
            res = max(res, 2 * min(count_0, count_1));
        }
        return res;
    }
};