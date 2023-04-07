class Solution {
public:
    string toHex(int num) {
        string convert{"0123456789abcdef"};
        string res;
        for(int i = 7; i >= 0; --i){
            int part = (num >> i*4) & 0xF;
            if(part > 0 || !res.empty() || i == 0)
                res.push_back(convert[part]);
        }
        return res;
    }
};