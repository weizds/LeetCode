class Solution {
public:
    // To find the maximum subarray sum in a circular array, 
    // we can use the double Kadane's algorithm to find both the maximum and minimum subarray sums.
    // If the maximum subarray sum is found in the circular portion of the array, 
    // we need to compute the actual maximum subarray sum by subtracting the minimum subarray sum 
    // from the total sum of the array.
    // There is an edge case to consider when all elements in the array are negative. 
    // In this case, the maximum subarray sum is simply the maximum element in the array.
    int maxSubarraySumCircular(vector<int>& nums) {
        int cur_min = nums[0];
        int global_min = nums[0];
        int cur_max = nums[0];
        int global_max = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            cur_min = min(cur_min + nums[i], nums[i]);
            global_min = min(global_min, cur_min);
            cur_max = max(cur_max + nums[i], nums[i]);
            global_max = max(global_max, cur_max);
        }
        if(global_max < 0)
            return global_max;
        int total = accumulate(nums.begin(), nums.end(), 0);
        return max(total - global_min, global_max);
    }
};