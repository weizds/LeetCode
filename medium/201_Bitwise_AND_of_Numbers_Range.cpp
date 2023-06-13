class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0 || right == 0)
            return 0;
        int count = 0;
        for(; left != right; ++count) {
            left >>= 1;
            right >>= 1;
        }
        return left << count;
    }
};