class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back() + 1, 0);
        auto day_it = days.begin();
        for(int i = 1; i < dp.size(); ++i) {
            if(i == *day_it) {
                dp[i] = min({ dp[i - 1] + costs[0], 
                                dp[max(0, i - 7)] + costs[1], 
                                dp[max(0, i - 30)] + costs[2]});
                if(day_it != days.end() - 1)
                    ++day_it;
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp.back();
    }
};