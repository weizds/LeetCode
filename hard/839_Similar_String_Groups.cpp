class Solution {
public:
    bool isSimilar(const string& str1, const string& str2) {
        int count = 0;
        for(int i = 0; i < str1.size() && i < str2.size(); ++i)
            if(str1[i] != str2[i])
                ++count;
        return count == 0 || count == 2;
    }
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int current) {
        visited[current] = true;
        for(auto u : adj[current])
            if(!visited[u])
                dfs(adj, visited, u);
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(isSimilar(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(strs.size(), false);
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                dfs(adj, visited, i);
                ++res;
            }
        }
        return res;
    }
};