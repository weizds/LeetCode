class Solution {
public:
    int tribonacci(int n) {
        array<int, 3> nums{0, 1, 1};
        if(n < nums.size())
            return nums[n];
        int current_index = 0;
        for(int i = 3; i <= n; ++i){
            nums[i % 3] = nums[0] + nums[1] + nums[2];
        }
        return nums[n % 3];
    }
};