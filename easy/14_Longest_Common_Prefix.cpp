class Solution {
public:
    string commonPrefix(const string &str1, const string &str2) {
        int i = 0;
        for(; i < str1.size() && i < str2.size(); ++i) {
            if(str1[i] != str2[i])
                break;
        }
        return str1.substr(0, i);
    }
    string longestCommonPrefix(vector<string>& strs) {
        while(strs.size() > 1) {
            int n = strs.size();
            for(int i = 0; i < n / 2; ++i){
                strs[i] = commonPrefix(strs[i], strs[n - i - 1]);
                strs.pop_back();
            }
        }
        return strs.back();
    }
};