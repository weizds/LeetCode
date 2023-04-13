class Solution {
public:
    // in place
    string removeStars(string s) {
        int write_ptr = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '*') {
                --write_ptr;
            }else{
                s[write_ptr] = s[i];
                ++write_ptr;
            }
        }
        s.resize(write_ptr);
        return s;
    }
    // new string
    // string removeStars(string s) {
    //     string res;
    //     for(int i = 0; i < s.size(); ++i) {
    //         if(s[i] == '*') {
    //             res.pop_back();
    //         }else{
    //             res.push_back(s[i]);
    //         }
    //     }
    //     return res;
    // }
};