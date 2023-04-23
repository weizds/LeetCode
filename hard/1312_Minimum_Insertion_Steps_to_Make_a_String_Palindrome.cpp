class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string s_reverse{s};
        reverse(s_reverse.begin(), s_reverse.end());
        vector<int> dp(n + 1, 0);
        vector<int> dp_prev(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(s[i - 1] == s_reverse[j - 1]) {
                    dp[j] = dp_prev[j - 1] + 1;
                }else{
                    dp[j] = max(dp_prev[j], dp[j - 1]);
                }
            }
            dp_prev = dp;
        }
        return n - dp[n];
    }
};