class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.size();
        string res;
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] == '#') {
                int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0') - 1;
                res.push_back('a' + num);
                i -= 2;
            }else{
                res.push_back(s[i] - '1' + 'a');
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};