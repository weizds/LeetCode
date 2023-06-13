class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end() - 1, 0);
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[n];
    }
};