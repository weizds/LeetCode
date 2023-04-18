class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        int cur = 1;
        int prev = 0;
        for(int i = 2; i <= n; ++i) {
            int tmp = cur;
            cur += prev;
            prev = tmp;
        }
        return cur;
    }
};