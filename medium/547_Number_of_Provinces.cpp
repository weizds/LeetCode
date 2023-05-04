class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int current, vector<bool>& visited) {
        visited[current] = true;
        for(int i = 0; i < isConnected.size(); ++i)
            if(isConnected[current][i] == 1 && !visited[i])
                dfs(isConnected, i, visited);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                ++res;
                dfs(isConnected, i, visited);
            }
        }
        return res;
    }
};