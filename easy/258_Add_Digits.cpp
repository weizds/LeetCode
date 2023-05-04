class Solution {
public:
    int addDigits(int num) {
        // digital root
        if(num == 0)
            return 0;
        return 1 + (num - 1) % 9;
    }
};