class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> dp(m + 1);
        vector<int> dp_prev(m + 1);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp_prev[j - 1] + 1;
                }else{
                    dp[j] = max(dp[j - 1], dp_prev[j]);
                }
            }
            dp_prev = dp;
        }
        return dp[m];
    }
};