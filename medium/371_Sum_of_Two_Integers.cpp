class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry = 0;
        while(b){
            carry = (unsigned)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        
        return a;
    }
};