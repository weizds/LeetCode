class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[2]{0};
        for(int i = 0; i < nums.size(); ++i) {
            int next = max(dp[0] + nums[i], dp[1]);
            dp[0] = dp[1];
            dp[1] = next;
        }
        return dp[1];
    }
};