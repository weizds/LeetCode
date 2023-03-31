class Solution {
public:
    void dfs(vector<int>& edges, int current, vector<int>& visited, vector<int>& dist, int current_dist, int &res) {
        if(current == -1)
            return;
        if(visited[current] == 2)
            return;
        if(visited[current] == 0) {
            visited[current] = 1;
            dist[current] = current_dist;
            dfs(edges, edges[current], visited, dist, current_dist + 1, res);
        }else{
            res = max(res, current_dist - dist[current]);
        }
        visited[current] = 2;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        vector<int> dist(n, -1);
        int res = -1;
        for(int i = 0; i < n; ++i) {
            if(visited[i] == 0)
                dfs(edges, i, visited, dist, 0, res);
        }
        return res;
    }
};