class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.back().size();
        vector<int> res(m, 0);
        for(int col = 0; col < m; ++col) {
            int current_col = col;
            for(int row = 0; row < n; ++row) {
                int next_col = current_col + grid[row][current_col];
                if(next_col < 0 || next_col >= m || grid[row][current_col] != grid[row][next_col]) {
                    res[col] = -1;
                    break;
                }
                res[col] = next_col;
                current_col = next_col;
            }
        }
        return res;
    }   
    // vector<int> findBall(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid.back().size();
    //     vector<vector<int>> dp(n + 1, vector<int>(m, 0));
    //     for(int j = 0; j < m; ++j)
    //         dp[n][j] = j;
    //     for(int i = n - 1; i >= 0; --i) {
    //         for(int j = 0; j < m; ++j) {
    //             int next_j = j + grid[i][j];
    //             if(next_j < 0 || next_j >= m || grid[i][j] != grid[i][next_j])
    //                 dp[i][j] = -1;
    //             else
    //                 dp[i][j] = dp[i + 1][next_j];
    //         }
    //     }
    //     return dp.front();
    // }
};