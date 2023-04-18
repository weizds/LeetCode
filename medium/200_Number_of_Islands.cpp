class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid.back().size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        int dirs[]{1, 0, -1, 0, 1};
        for(int k = 0; k < 4; ++k)
            dfs(grid, i + dirs[k], j + dirs[k + 1]);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid.back().size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};