class Solution {
public:
    void dfs(unordered_map<int, int> &count, vector<vector<int>>& res, vector<int>& tmp, int n) {
        if(tmp.size() == n){
            res.push_back(tmp);
            return;
        }
        for(auto it = count.begin(); it != count.end(); ++it){
            if(it->second > 0) {
                --it->second;
                tmp.push_back(it->first);
                dfs(count, res, tmp, n);
                tmp.pop_back();
                ++it->second;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> count;
        for(auto num : nums)
            ++count[num];
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(count, res, tmp, nums.size());
        return res;
    }
};