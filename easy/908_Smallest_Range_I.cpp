class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        auto [nums_min, nums_max] = minmax_element(nums.begin(), nums.end());
        int score = *nums_max - *nums_min;
        if(score <= k * 2)
            return 0;
        else
            return score - k * 2;
    }
};