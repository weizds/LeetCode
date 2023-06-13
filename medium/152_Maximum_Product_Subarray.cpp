class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums.front();
        int cur_min = res;
        int cur_max = res;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < 0)
                swap(cur_min, cur_max);
            cur_max = max(nums[i], nums[i] * cur_max);
            cur_min = min(nums[i], nums[i] * cur_min);
            res = max(res, cur_max);
        }
        return res;
    }
};