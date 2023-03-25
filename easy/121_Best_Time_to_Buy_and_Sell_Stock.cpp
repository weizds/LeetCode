class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int res = 0;
        for(int r = 1; r < prices.size(); ++r){
            if(prices[r] < prices[l])
                l = r;
            res = max(res, prices[r] - prices[l]);
        }
        return res;
    }
};