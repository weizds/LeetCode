class Solution {
public:
    int palindromeSize(string s, int mask) {
        int res = 0;
        int left_bit = 0;
        int right_bit = s.size();
        while(left_bit <= right_bit) {
            if((mask & (1 << left_bit)) == 0)
                ++left_bit;
            else if((mask & (1 << right_bit)) == 0)
                --right_bit;
            else if(s[left_bit] != s[right_bit]){
                return res;
            }else{
                res += left_bit == right_bit ? 1 : 2;
                ++left_bit;
                --right_bit;
            } 
        }
        return res;
    }
    int maxProduct(string s) {
        int n = s.size();
        int mask = (1 << n) - 1;
        vector<int> dp(mask + 1, 0);
        for(int i = 1; i <= mask; ++i)
            dp[i] = palindromeSize(s, i);
        int res = 0;
        for(int mask1 = mask; mask1 >= 1; --mask1) {
            if(dp[mask1] * (n - dp[mask1]) > res) {
                for(int mask2 = mask1 ^ mask; mask2 >= 1; mask2 = (mask2 - 1) & (mask ^ mask1)) {
                    if(dp[mask1] * dp[mask2] > res) {
                        res = dp[mask1] * dp[mask2];
                    }
                }
            }
        }
        return res;
    }
};