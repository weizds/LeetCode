class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.back().size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    ++fresh;
            }
        }
        if(fresh == 0)
            return 0;
        int minutes = 0;
        int dirs[]{1, 0, -1, 0 , 1};
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                if(grid[cur.first][cur.second] == 2) {
                    for(int k = 0; k < 4; ++k) {
                        int new_i = cur.first + dirs[k];
                        int new_j = cur.second + dirs[k + 1];
                        if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m)
                            continue;
                        if(grid[new_i][new_j] == 1) {
                            grid[new_i][new_j] = 2;
                            q.push({new_i, new_j});
                            --fresh;
                        }
                    }
                }
            }
            ++minutes;
        }
        if(fresh == 0)
            return minutes - 1;
        return -1;
    }
};