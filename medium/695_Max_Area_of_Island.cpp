class Solution {
 public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid.back().size() || grid[i][j] == 0)
            return 0;
        int dirs[]{1, 0, -1, 0, 1};
        grid[i][j] = 0;
        int res = 1;
        for(int k = 0; k < 4; ++k) {
            res += dfs(grid, i + dirs[k], j + dirs[k + 1]);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] != 0)
                    res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};