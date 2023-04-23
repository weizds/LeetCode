class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
    // int hammingWeight(uint32_t n) {
    //     int res = 0;
    //     for(;n > 0;++res){
    //         n &= n - 1;
    //     }
    //     return res;
    // }
};