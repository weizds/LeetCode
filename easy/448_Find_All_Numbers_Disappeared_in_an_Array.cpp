class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]);
            nums[index - 1] = -abs(nums[index - 1]);
        }
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] > 0)
                res.push_back(i + 1);
        return res;
    }

    // vector<int> findDisappearedNumbers(vector<int>& nums) {
    //     for(int i = 0; i < nums.size(); ++i) {
    //         while(nums[i] != nums[nums[i] - 1]){
    //             swap(nums[i], nums[nums[i] - 1]);
    //         }
    //     }
    //     vector<int> res;
    //     for(int i = 0; i < nums.size(); ++i)
    //         if(i + 1 != nums[i])
    //             res.push_back(i + 1);
    //     return res;
    // }
};