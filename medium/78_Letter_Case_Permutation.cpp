class Solution {
public:
    void helper(string &s, int start, vector<string> &res) {
        if(start == s.size()) {
            res.push_back(s);
            return;
        }
        for(int i = start; i < s.size(); ++i) {
            if(isalpha(s[i])){
                s[i] = toupper(s[i]);
                helper(s, start + 1, res);
                s[i] = tolower(s[i]);
                helper(s, start + 1, res);
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        helper(s, 0, res);
        return res;
    }
};