class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [](const string &s1, const string &s2){
            return s1.size() < s2.size();
        });
        int res = 1;
        for(auto word : words) {
            dp[word] = 1;
            for(int i = 0 ; i < word.size(); ++i) {
                string predecessor{word};
                predecessor.erase(i, 1);
                if(dp.count(predecessor)){
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                    res = max(res, dp[word]);
                }
            }
        }
        return res;
    }
};