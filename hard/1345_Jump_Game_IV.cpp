class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> graph;
        int n = arr.size();
        for(int i = 0; i < n; ++i)
            graph[arr[i]].push_back(i);
        queue<int> q;
        vector<bool> visited(n, false);
        visited[0] = true;
        q.push(0);
        int res = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto v = q.front();
                q.pop();
                if(v == n - 1)
                    return res;
                auto &adj = graph[arr[v]];
                for(auto u : adj) {
                    if(!visited[u]) {
                        q.push(u);
                        visited[u] = true;
                    }
                }
                adj.clear();
                if(((v + 1) < n) && !visited[v + 1]) {
                    q.push(v + 1);
                    visited[v + 1] = true;
                }
                if(((v - 1) >= 0) && !visited[v - 1]) {
                    q.push(v - 1);
                    visited[v - 1] = true;
                }
            }
            ++res;
        }
        return res;
    }
};