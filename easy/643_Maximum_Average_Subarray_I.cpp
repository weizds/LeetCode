class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double res = -DBL_MAX;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            if(i >= k)
                sum -= nums[i - k];
            if(i + 1 >= k)
                res = max(res, sum / k);
        }
        return res;
    }
};