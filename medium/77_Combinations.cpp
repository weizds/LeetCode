class Solution {
public:
    void helper(int start, int n, int k, vector<int> &current_vec, vector<vector<int>> &res) {
        if(current_vec.size() == k) {
            res.push_back(current_vec);
            return;
        }
        for(int i = start; i <= n; ++i) {
            current_vec.push_back(i);
            helper(i + 1, n, k, current_vec, res);
            current_vec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(1, n, k, tmp, res);
        return res;
    }
};