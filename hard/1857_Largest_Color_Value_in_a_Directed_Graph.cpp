class Solution {
public:
    int dfs(const vector<vector<int>> &adj, int v, vector<char> &visited, 
        const string &colors, vector<vector<int>> &count) {
        if(visited[v] == 1)
            return INT_MAX;
        if(visited[v] == 2)
            return count[v][colors[v] - 'a'];
        visited[v] = 1;
        for(auto u : adj[v]) {
            if(dfs(adj, u, visited, colors, count) == INT_MAX)
                return INT_MAX;
            for(int i = 0; i < 26; ++i)
                count[v][i] = max(count[v][i], count[u][i]);
        }
        ++count[v][colors[v] - 'a'];
        visited[v] = 2;
        return count[v][colors[v] - 'a'];
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        for(const auto &e : edges)
            adj[e.front()].push_back(e.back());
        vector<vector<int>> count(n, vector<int>(26, 0));
        vector<char> visited(n, 0);
        int res = 0;
        for(int i = 0; i < n; ++i) {
            res = max(res, dfs(adj, i, visited, colors, count));
        }
        if(res == INT_MAX)
            return -1;
        return res;
    }
};