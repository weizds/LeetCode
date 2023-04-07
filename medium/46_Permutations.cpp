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
};