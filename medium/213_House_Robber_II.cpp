class Solution {
public:
    int rob1(vector<int>::iterator from, vector<int>::iterator to) {
        int dp[2]{0};
        for(auto it = from; it != to; ++it) {
            int next = max(dp[0] + *it, dp[1]);
            dp[0] = dp[1];
            dp[1] = next;
        }
        return dp[1];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums.front();
        return max(rob1(nums.begin(), nums.end() - 1), 
            rob1(nums.begin() + 1, nums.end()));
    }
};