class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count_negative = 0;
        for(auto num : nums) {
            if(num == 0)
                return 0;
            if(num < 0)
                ++count_negative;
        }
        return count_negative % 2 ? -1 : 1;
    }
};