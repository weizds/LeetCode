class Solution {
public:
    int climbStairs(int n) {
        int dp[2]{1, 1};
        for(int i = 2; i <= n; ++i) {
            int next = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = next;
        }
        return dp[1];
    }
};