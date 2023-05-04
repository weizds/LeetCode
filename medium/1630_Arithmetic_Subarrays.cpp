class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res(l.size());
        for(int i = 0; i < l.size(); ++i) {
            int len = r[i] - l[i];
            // subarray of 1 number
            if(len < 1){
                res[i] = true;
                continue;
            }
            auto min_max = minmax_element(nums.begin() + l[i], nums.begin() + r[i] + 1);
            // all numbers are equal
            if(*min_max.second == *min_max.first) {
                res[i] = true;
                continue;
            }
            // diff is not an integer
            if((*min_max.second - *min_max.first) % len != 0) {
                res[i] = false;
                continue;
            }
            int diff = (*min_max.second - *min_max.first) / len;
            int min_num = *min_max.first;
            vector<bool> seen(len + 1, false);
            int j = l[i];
            for(; j <= r[i]; ++j) {
                // number is either not divisible by "diff" or has already been seen.
                if(((nums[j] - min_num) % diff != 0) || seen[(nums[j] - min_num) / diff])
                    break;
                seen[(nums[j] - min_num) / diff] = true;
            }
            res[i] = (j == r[i] + 1);
        }
        return res;
    }
};