class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res={{1}};
        for(int i = 1; i < numRows; ++i) {
            int n = i + 1;
            vector<int> current(n);
            current[0] = 1;
            current[n - 1] = 1;
            for(int j = 1; j < n - 1; ++j)
                current[j] = res.back()[j - 1] + res.back()[j];
            res.push_back(current);
        }
        return res;
    }
};