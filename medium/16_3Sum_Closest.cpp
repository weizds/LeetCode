class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(abs(sum - target) < abs(res - target))
                    res = sum;
                if(sum == target){
                    return sum;
                }else if(sum > target){
                    --right;
                }else{
                    ++left;
                }
            }
        }
        return res;
    }
};