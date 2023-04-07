class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        int last = 0;
        while(num != 0) {
            last = num >> 1;
            num = num & (num - 1);
            ++count;
        }
        while(last != 0) {
            last = last >> 1;
            ++count;
        }
        return count;
    }
};