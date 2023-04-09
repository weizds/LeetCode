class Solution {
public:
    // DP with monotoic deque to maintain max in window of size k
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for(int i = 1; i < n; ++i) {
            dp[i] = dp[dq.front()] + nums[i];
            while(!dq.empty() && dp[dq.back()] <= dp[i])
                dq.pop_back();
            dq.push_back(i);
            if(i - dq.front() >=k)
                dq.pop_front();
        }
        return dp[n - 1];
    }
};