class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza.back().size();
        vector<vector<int>> apples(n + 1, vector<int>(m + 1, 0));
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(n, vector<int>(m, 0)));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                apples[i][j] = (pizza[i][j] == 'A') + apples[i][j + 1] +
                               apples[i + 1][j] - apples[i + 1][j + 1];
                dp[0][i][j] = apples[i][j] > 0;
            }
        }
        int max = 1e9 + 7;
        for(int remain = 1; remain < k; ++remain) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    for(int next_i = i + 1; next_i < n; ++next_i){
                        if(apples[i][j] - apples[next_i][j] > 0)
                            dp[remain][i][j] += dp[remain - 1][next_i][j];
                            dp[remain][i][j] %= max;
                    }
                    for(int next_j = j + 1; next_j < m; ++next_j){
                        if(apples[i][j] - apples[i][next_j] > 0)
                            dp[remain][i][j] += dp[remain - 1][i][next_j];
                            dp[remain][i][j] %= max;
                    }
                }
            }
        }
        return dp[k-1][0][0];
    }
};