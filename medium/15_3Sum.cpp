class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i] > 0)
                break;
            if(i == 0 || nums[i] != nums[i - 1]){
                int left = i + 1;
                int right = nums.size() - 1;
                while(left < right){
                    int sum = nums[left] + nums[right];
                    if(sum + nums[i] == 0){
                        res.push_back({nums[i], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1])
                            ++left;
                        while(left < right && nums[right] == nums[right - 1])
                            --right;
                        ++left;
                        --right;
                    }else if(sum + nums[i] > 0){
                        --right;
                    }else{
                        ++left;
                    }
                }
            }
        }
        return res;
    }
};