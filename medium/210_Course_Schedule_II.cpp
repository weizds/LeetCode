class Solution {
public:
    bool dfs(int v, vector<vector<int>>& adj, vector<int>& visited, vector<int>& res) {
        if(visited[v] == 1)
            return false;
        if(visited[v] == 2)
            return true;
        visited[v] = 1;
        for(auto u : adj[v]) {
            if(!dfs(u, adj, visited, res))
                return false;
        }
        visited[v] = 2;
        res.push_back(v);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> adj(numCourses);
        for(auto edge : prerequisites) {
            adj[edge.back()].push_back(edge.front());
        }
        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; ++i) {
            if(visited[i] == 0)
                if(!dfs(i, adj, visited, res))
                    return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
};