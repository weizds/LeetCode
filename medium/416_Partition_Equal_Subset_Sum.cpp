class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1)
            return false;
        sum /= 2;
        int n = nums.size();
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = sum; j >= 0; --j) {
                if(j - nums[i - 1] >= 0)
                    dp[j] = dp[j - nums[i - 1]] || dp[j];
            }
        }
        return dp[sum];
    }
};