class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> dp(m + 1, 0);
        vector<int> dp_prev(m + 1, 0);
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) {
                if(i == 0 || j == 0)
                    dp[j] = i + j;
                else if(word1[i - 1] == word2[j - 1])
                    dp[j] = dp_prev[j - 1];
                else
                    dp[j] = min(dp[j - 1], dp_prev[j]) + 1;
                
            }
            dp_prev = dp;
        }
        return dp[m];
    }
};