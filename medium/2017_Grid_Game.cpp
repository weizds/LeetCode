class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = grid[0][0];
        long long bottom = 0;
        long long res = LONG_MAX;
        for(int i = 1; i < grid[0].size(); i++) {
            top += grid[0][i];
        }

        for(int i = 0; i < grid[0].size(); i++) {
            top -= grid[0][i];
            res = min(res,max(top,bottom));
            bottom += grid[1][i];
        }
        return res;
    }
};