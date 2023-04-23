class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            if(s[i - 1] >= '1' && s[i - 1] <= '9')
                dp[i] += dp[i - 1];
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if(num >= 10 && num <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};