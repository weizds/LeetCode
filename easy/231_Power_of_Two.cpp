class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 & __builtin_popcount(n) == 1;
    }
    // bool isPowerOfTwo(int n) {
    //     if(n == 0 || n == 0x80000000)
    //         return false;
    //     return (n & (n - 1)) == 0;
    // }
};