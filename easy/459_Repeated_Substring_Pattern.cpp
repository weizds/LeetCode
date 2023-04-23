class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string tmp{s.substr(1, n - 1)};
        tmp.append(s.substr(0, n - 1));
        return tmp.find(s) != string::npos;
    }
    // bool check(const string &s, const string &t) {
    //     int m = t.size();
    //     for(int i = 0; i < s.size(); ++i) {
    //         if(s[i] != t[i % m])
    //             return false;
    //     }
    //     return true;
    // }
    // bool repeatedSubstringPattern(string s) {
    //     int n = s.size();
    //     for(int i = 1; i <= n/2; ++i) {
    //         if(n % i == 0) {
    //             if(check(s, s.substr(0, i)))
    //                 return true;
    //         }
    //     }
    //     return false;
    // }
};