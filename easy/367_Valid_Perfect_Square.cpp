class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1)
            return 1;
        int low = 2;
        int high = num / 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(mid == num / mid && num % mid == 0)
                return true;
            else if(mid < num / mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};