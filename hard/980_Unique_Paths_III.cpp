class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int empty_left) {
        if(empty_left == -1 && grid[i][j] == 2)
            return 1;
        int dirs[]{1, 0, -1, 0, 1};
        int res = 0;
        int grid_val = grid[i][j];
        grid[i][j] = -1;
        for(int k = 0; k < 4; ++k) {
            int new_i = i + dirs[k];
            int new_j = j + dirs[k + 1];
            if(new_i >= 0 && new_i < grid.size() && 
                new_j >= 0 && new_j < grid.back().size() && grid[new_i][new_j] != -1)
            res += dfs(grid, new_i, new_j, empty_left - 1);
        }
        grid[i][j] = grid_val;
        return res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int, int> start{0, 0};
        int empty{0};
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 1)
                    start = {i, j};
                else if(grid[i][j] == 0)
                    ++empty;
            }
        }
        return dfs(grid, start.first, start.second, empty);
    }
};