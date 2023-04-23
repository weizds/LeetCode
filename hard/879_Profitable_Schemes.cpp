class Solution {
public:
    int helper(int cur, int count, int profit, int n, int minProfit, vector<int>& group, vector<int>& profits) {
        if(cur == group.size())
            return profit >= minProfit;
        if(memo[cur][count][profit] != -1)
            return memo[cur][count][profit];
        int res = helper(cur + 1, count, profit, n, minProfit, group, profits);
        if(count + group[cur] <= n)
            res += helper(cur + 1, count + group[cur], min(minProfit, profit + profits[cur]),
                n, minProfit, group, profits);
        return memo[cur][count][profit] = res % mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profits) {
        memset(memo, -1, sizeof(memo));
        return helper(0, 0, 0, n, minProfit, group, profits);
    }
private:
    int mod = 1e9 + 7;
    int memo[101][101][101];
};