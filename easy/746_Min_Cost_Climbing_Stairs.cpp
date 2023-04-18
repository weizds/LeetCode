class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(2);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; ++i) {
            int next = min(dp[0], dp[1]) + cost[i];
            dp[0] = dp[1];
            dp[1] = next;
        }
        return min(dp[0], dp[1]);
    }
};