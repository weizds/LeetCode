class Solution {
public:
    bool compare(const string &s1, const string s2, const vector<int> &order_map) {
        int i = 0;
        int min_len = min(s1.size(), s2.size());
        for(; i < min_len; ++i) {
            if(s1[i] != s2[i])
                return order_map[s1[i] - 'a'] <= order_map[s2[i] - 'a'];
        }
        return s1.size() <= s2.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> order_map(26);
        for(int i = 0; i < order.size(); ++i)
            order_map[order[i] - 'a'] = i;
        for(int i = 0; i < words.size() - 1; ++i) {
            if(!compare(words[i], words[i + 1], order_map))
                return false;
        }
        return true;
    }
};