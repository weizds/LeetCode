class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start,
        vector<int> &curr_combination, int curr_sum, vector<vector<int>> &res) {
        if(curr_sum > target) {
            return;
        }
        if(curr_sum == target) {
            res.push_back(curr_combination);
            return;
        }
        for(int i = start; i < candidates.size(); ++i) {          
            if(i > start && candidates[i] == candidates[i - 1])
                continue;
            curr_combination.push_back(candidates[i]);
            backtrack(candidates, target, i + 1, curr_combination, curr_sum + candidates[i], res);
            curr_combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr_combination;
        backtrack(candidates, target, 0, curr_combination, 0, res);
        return res;
    }
};