class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int max_len = 1;
        vector<int> lis(n, 1);
        vector<int> count(n, 1);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] <= nums[j])
                    continue;
                if(lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                    count[i] = count[j];
                }else if(lis[i] == lis[j] + 1) {
                    count[i] += count[j];
                }
            }
            max_len = max(max_len, lis[i]);
        }
        int res = 0;
        for(int i = 0; i < n; ++i)
            if(lis[i] == max_len)
                res += count[i];
        return res;
    }
};