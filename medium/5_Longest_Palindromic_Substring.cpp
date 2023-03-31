class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int len = 0;
        int n = s.size();
        auto check{[&](int l, int r){
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > len){
                    start = l;
                    len = r - l + 1;
                }
                --l;
                ++r;
            }
        }};
        for(int i = 0; i < n; ++i) {
            check(i, i);
            if(i + 1 < n)
                check(i, i + 1);
        }
        return s.substr(start, len);
    }
};