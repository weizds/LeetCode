class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> count(26, {INT_MAX, INT_MIN});
        for(int i = 0; i < s.size(); ++i) {
            count[s[i] - 'a'].first = min(count[s[i] - 'a'].first, i);
            count[s[i] - 'a'].second = max(count[s[i] - 'a'].second, i);
        }
        int res = 0;
        for(int i = 0; i < count.size(); ++i) {
            int freq[26]{0};
            if(count[i].first == INT_MAX)
                continue;
            for(int j = count[i].first + 1; j < count[i].second; ++j) {
                if(freq[s[j] - 'a'] == 0)
                    ++res;
                ++freq[s[j] - 'a'];
            }
        }
        return res;
    }
};