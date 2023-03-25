class Solution {
public:
    int bfs(const vector<vector<pair<int, int>>> &adj) {
        vector<bool> visited(adj.size(), false);
        int res = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            visited[v.first] = true;
            res += v.second;
            for(auto u : adj[v.first]) {
                if(!visited[u.first])
                    q.push(u);
            }
        }
        return res;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto con : connections) {
            adj[con[0]].push_back({con[1], 1});
            adj[con[1]].push_back({con[0], 0});
        }
        return bfs(adj);
    }
};