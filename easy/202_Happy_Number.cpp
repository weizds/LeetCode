class Solution {
public:
    int next(int num) {
        int sum = 0;
        while(num > 0) {
            sum += (num % 10) * (num % 10);
            num /=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int fast = next(n);
        int slow = n;
        while(fast != 1 && slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};