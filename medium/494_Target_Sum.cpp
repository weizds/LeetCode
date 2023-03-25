#include <numeric>

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        int subtotal = nums[0];
        std::vector<int> dp(total * 2 + 1, 0);
        std::vector<int> tmp(total * 2 + 1, 0);
        dp[nums[0] + total] = 1;
        dp[-nums[0] + total] += 1;
        for(int i = 1; i < nums.size(); i++){
            subtotal += nums[i];
            for(int sum = -subtotal; sum <= subtotal; sum++){
                if(dp[sum + total] > 0){
                    tmp[sum + total + nums[i]] += dp[sum + total];
                    tmp[sum + total - nums[i]] += dp[sum + total];
                }
            }
            dp = tmp;
            std::fill(tmp.begin(), tmp.end(), 0);
        }

        return std::abs(target) > total ? 0 : dp[target + total];
    }
};