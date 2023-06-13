class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int cur, int color, vector<int>& colors) {
        colors[cur] = color;
        for(auto u : graph[cur]) {
            if(colors[u] == 0) {
                if(!dfs(graph, u, 3 - color, colors))
                    return false;
            }else if(colors[u] == color) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), 0);
        for(int i = 0; i < graph.size(); ++i)
            if(colors[i] == 0 && dfs(graph, i, 1, colors) == false)
                return false;
        return true;
    }
};