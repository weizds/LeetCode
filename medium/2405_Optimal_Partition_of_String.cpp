class Solution {
public:
    // if next symbol already in substring, drop substring and start new
    // for 26 alphabet
    int partitionString(string s) {
        vector<int> seen(26, -1);
        int start = 0;
        int res = 1;
        for(int i = 0; i < s.size(); ++i) {
            if(seen[s[i] - 'a'] >= start) {
                start = i;
                ++res;
            }
            seen[s[i] - 'a'] = i;
        }
        return res;
    }
    // for n alphabet
    // int partitionString(string s) {
    //     unordered_set<char> hash_set;
    //     int j = 0;
    //     hash_set.insert(s[0]);
    //     int res = 1;
    //     for(int i = 1; i < s.size(); ++i) {
    //         if(hash_set.find(s[i]) != hash_set.end()) {
    //             hash_set.clear();
    //             j = i;
    //             ++res;
    //         }
    //         hash_set.insert(s[i]);
    //     }
    //     return res;
    // }
};