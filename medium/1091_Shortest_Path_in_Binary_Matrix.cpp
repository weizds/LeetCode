class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, n*n + 1));
        dist[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        pair<int, int> dirs[]{{1, 0}, {1, 1}, {1, -1}, {0, 1},
                              {-1, 0}, {-1, 1}, {-1, -1}, {0, -1}};
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for(int k = 0; k < 8; ++k) {
                int new_i = i + dirs[k].first;
                int new_j = j + dirs[k].second;
                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && 
                    grid[new_i][new_j] == 0 && dist[new_i][new_j] > dist[i][j] + 1) {
                    dist[new_i][new_j] = dist[i][j] + 1;
                    q.push({new_i, new_j});
                }
            }
        }
        if(dist[n - 1][n - 1] == (n*n + 1))
            return -1;
        return dist[n - 1][n - 1];
    }
};