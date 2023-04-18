class Solution {
public:
    void helper(vector<int>& nums, vector<bool>& used, vector<vector<int>>& res, vector<int>& tmp) {
        if(tmp.size() == nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!used[i]) {
                used[i] = true;
                tmp.push_back(nums[i]);
                helper(nums, used, res, tmp);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        helper(nums, used, res, tmp);
        return res;
    }
    // void helper(vector<int>& nums, int start, vector<vector<int>>& res) {
    //     if(start == nums.size()){
    //         res.push_back(nums);
    //         return;
    //     }
    //     for(int i = start; i < nums.size(); ++i){
    //         swap(nums[i], nums[start]);
    //         helper(nums, start + 1, res);
    //         swap(nums[i], nums[start]);
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     helper(nums, 0, res);
    //     return res;
    // }
};