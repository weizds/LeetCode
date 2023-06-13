class Solution {
public:
    bool isInside(int64_t x_c, int64_t y_c, int64_t r, int64_t x, int64_t y) {
        return (x - x_c) * (x - x_c) + (y - y_c) * (y - y_c) <= r * r;
    }
    int dfs(vector<vector<int>>& graph, int cur, vector<bool>& visited) {
        int count_visited = 1;
        visited[cur] = true;
        for(int v : graph[cur])
            if(!visited[v])
                count_visited += dfs(graph, v, visited);
        return count_visited;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; ++i) {
            int x_c = bombs[i][0];
            int y_c = bombs[i][1];
            int r = bombs[i][2];
            for(int j = 0; j < n; ++j) {
                if(i != j && isInside(x_c, y_c, r, bombs[j][0], bombs[j][1]))
                    graph[i].push_back(j);
            }
        }
        int res = 0;
        for(int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            res = max(res, dfs(graph, i, visited));
        }
        return res;
    }
};