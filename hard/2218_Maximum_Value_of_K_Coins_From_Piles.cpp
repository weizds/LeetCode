class Solution {
public:
    int helper(vector<vector<int>>& piles, int i, int coins, vector<vector<int>> &dp) {
        if(i == 0)
            return 0;
        if(dp[i][coins] != -1)
            return dp[i][coins];
        int sum = 0;
        int max_coins = min((int)piles[i - 1].size(), coins);
        dp[i][coins] = helper(piles, i - 1, coins, dp);
        for(int cur_coins = 1; cur_coins <= max_coins; ++cur_coins) {
            sum += piles[i - 1][cur_coins - 1];
            dp[i][coins] = max(dp[i][coins], helper(piles, i - 1, coins - cur_coins, dp) + sum);
        }
        return dp[i][coins];
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return helper(piles, n, k, dp);
    }
};