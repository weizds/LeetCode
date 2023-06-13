    class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mod = 1e9 + 7;
        int right = n - 1;
        int left = 0;
        int res = 0;
        vector<int> power(n);
        power[0] = 1;
        for(int i = 1; i < n; ++i)
            power[i] = power[i - 1] * 2 % mod;
        while(left <= right) {
            if(nums[left] + nums[right] <= target) {
                res += power[right - left];
                res %= mod;
                ++left;
            }else{
                --right;
            }
        }
        return res;
    }
};