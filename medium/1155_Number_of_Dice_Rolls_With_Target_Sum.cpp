class Solution {
public:
    int mod = 1e9 + 7;
    int dp[31][1001];
    int recur(int n, int k, int t){
        if(n == 0 && t == 0)
            return 1;
        if(n == 0 || t <= 0)
            return 0;
        if(dp[n][t] != -1) 
            return dp[n][t];
        int res = 0;
        for(int j = 1; j <= k; j++){
            res = (res + (recur(n - 1, k, t - j))) % mod;
        }
        return dp[n][t] = res;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return recur(n, k, target);
    }
};