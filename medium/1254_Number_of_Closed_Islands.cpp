class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 1) {
            return 0;
        }
        grid[i][j] = 1;
        return 1 + dfs(grid, i - 1, j, n, m) + dfs(grid, i + 1, j, n, m)
            + dfs(grid, i, j - 1, n, m) + dfs(grid, i, j + 1, n, m);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.back().size();
        // first remove islands on the edge
        for(int i = 0; i < n; ++i){
            dfs(grid, i, 0, n, m);
            dfs(grid, i, m - 1, n, m);
        }
        for(int j = 0; j < m; ++j){
            dfs(grid, 0, j, n, m);
            dfs(grid, n - 1, j, n, m);
        }
        int res = 0;
        // now count the rest
        for(int i = 1; i < n - 1; ++i) {
            for(int j = 1; j < m - 1; ++j) {
                if(dfs(grid, i, j, n, m) > 0)
                    ++res;
            }
        }
        return res;
    }
};