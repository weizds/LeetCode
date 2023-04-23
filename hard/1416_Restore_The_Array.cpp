class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int mod = 1e9 + 7;
        if(s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 0; i <= n; ++i) {
            if(s[i] == '0')
                continue;
            long long num = 0;
            for(int j = i + 1; j <= n; ++j) {
                num *= 10;
                num += s[j - 1] - '0';
                while(s[j] == '0' && num <= k) {
                    ++j;
                    num *= 10;
                    num += s[j - 1] - '0';
                }
                if(num > k)
                    break;
                dp[j] = (dp[j] + dp[i]) % mod;
            }
        }
        return dp[n];
    }
};