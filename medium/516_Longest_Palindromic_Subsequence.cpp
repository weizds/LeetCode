class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n);
        vector<int> dp_prev(n);
        for(int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for(int j = i + 1; j < n; ++j) {
                if(s[i] == s[j])
                    dp[j] = 2 + dp_prev[j - 1];
                else
                    dp[j] = max(dp[j - 1], dp_prev[j]);
            }
            dp_prev = dp;
        }
        return dp[n - 1];
    }
};