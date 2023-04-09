class Solution {
public:
    int dfs(vector<vector<int>> &adj, vector<int> &dp, int start) {
        if(dp[start] != -1)
            return dp[start];
        int res = 0;
        for(auto v : adj[start]) {
            res = max(res, dfs(adj, dp, v));
        }
        dp[start] = res + 1;
        return res + 1;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<vector<int>> adj(n);
        stack<int> st;
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                int j = st.top();
                st.pop();
                if(i - j <= d)
                    adj[i].push_back(j);
            }
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                int j = st.top();
                st.pop();
                if(j - i <= d)
                    adj[i].push_back(j);
            }
            st.push(i);
        }
        int res = 1;
        vector<int> dp(n, -1);
        for(int i = 0; i < n; ++i) {
            res = max(res, dfs(adj, dp, i));
        }
        return res;
    }
};