class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        for(auto word : words)
            ++count[word];
        int res = 0;
        int central = 0;
        for(auto &word : count) {
            string reversed{word.first[1], word.first[0]};
            if(word.first == reversed) {
                if(word.second % 2 == 0) {
                    res += word.second;
                }else{
                    res += word.second - 1;
                    central = 1;
                }
            }else if(word.first[0] < word.first[1] && count.find(reversed) != count.end()){
                res += 2 * min(word.second, count[reversed]);
            }
        }
        return (res + central) * 2;
    }
};