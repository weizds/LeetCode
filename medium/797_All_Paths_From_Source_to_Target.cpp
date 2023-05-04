class Solution {
public:
    void dfs(vector<vector<int>>& graph, int v, vector<int>& path, vector<vector<int>>& res) {
        if(v + 1 == graph.size()) {
            res.push_back(path);
            return;
        }
        for(auto u : graph[v]) {
            path.push_back(u);
            dfs(graph, u, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path{0};
        dfs(graph, 0, path, res);
        return res;
    }
};