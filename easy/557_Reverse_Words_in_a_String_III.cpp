class Solution {
public:
    void reverse_string(string &s, int start, int len) {
        for(int i = 0; i < len/2; ++i)
            swap(s[i + start], s[len - i - 1 + start]);
    }
    string reverseWords(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') {
                if(count > 1)
                    reverse_string(s, i - count, count);
                count = 0;
            }else{
                ++count;
            }
        }
        if(count > 1)
            reverse_string(s, s.size() - count, count);
        return s;
    }
};