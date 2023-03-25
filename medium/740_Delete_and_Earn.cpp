class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_nums = *max_element(nums.begin(), nums.end());
        vector<int> sum(max_nums + 1, 0);
        for(auto num : nums)
            sum[num] += num;
        int dp[2];
        dp[0] = 0;
        dp[1] = sum[1];
        int res = sum[1];
        for(int i = 2; i <= max_nums; ++i) {
            res = max(dp[1], dp[0] + sum[i]);
            dp[0] = dp[1];
            dp[1] = res;
        }
        return res;
    }
};