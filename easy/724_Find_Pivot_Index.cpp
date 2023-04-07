class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref_sum(n + 2, 0);
        for(int i = 1; i <= n; ++i)
            pref_sum[i] = pref_sum[i - 1] + nums[i - 1];
        pref_sum[n + 1] = pref_sum[n];
        for(int i = 1; i <= n; ++i) {
            if(pref_sum[i - 1] == pref_sum[n + 1] - pref_sum[i])
                return i - 1;
        }
        return -1;
    }
    // int pivotIndex(vector<int>& nums) {
    //     int n = nums.size();
    //     int total = accumulate(nums.begin(), nums.end(), 0);
    //     int sum = 0;
    //     for(int i = 0; i < n; ++i) {
    //         if(sum == total - nums[i] - sum)
    //             return i;
    //         sum += nums[i];
    //     }
    //     return -1;
    // }
};