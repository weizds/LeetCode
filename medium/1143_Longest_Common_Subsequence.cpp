class Solution {
public:
    int longestCommonSubsequence(const string& text1, const string& text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(m + 1, 0);
        vector<int> dp_prev(m + 1, 0);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[j] = dp_prev[j - 1] + 1;
                }else{
                    dp[j] = max(dp[j - 1], dp_prev[j]);
                }
            }
            dp_prev = dp;
        }
        return dp[m];
    }
};