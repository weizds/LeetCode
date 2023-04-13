class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Compare all 0..n-1 symbols of each string, where n = min length of all strings
        auto min_str = min_element(strs.begin(), strs.end(), [](const string &s1, const string &s2){
            return s1.size() < s2.size();
        });
        int max_char = min_str->size();
        for(int last_char = 0; last_char < max_char; ++last_char) {
            char cur_char = strs[0][last_char];
            for(int i = 1; i < strs.size(); ++i) {
                if(strs[i][last_char] != cur_char)
                    return strs[0].substr(0, last_char);
            }
        }
        return *min_str;
    }
    // string commonPrefix(const string &str1, const string &str2) {
    //     int i = 0;
    //     for(; i < str1.size() && i < str2.size(); ++i) {
    //         if(str1[i] != str2[i])
    //             break;
    //     }
    //     return str1.substr(0, i);
    // }
    // string longestCommonPrefix(vector<string>& strs) {
    //     while(strs.size() > 1) {
    //         int n = strs.size();
    //         for(int i = 0; i < n / 2; ++i){
    //             strs[i] = commonPrefix(strs[i], strs[n - i - 1]);
    //             strs.pop_back();
    //         }
    //     }
    //     return strs.back();
    // }
};