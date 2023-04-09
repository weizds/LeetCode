class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        auto it = lower_bound(nums.begin(), nums.end(), 0);
        auto negative_it{it - 1};
        while(negative_it != (nums.begin() - 1) || it != nums.end()) {
            if(negative_it == (nums.begin() - 1)) {
                res.push_back((*it) * (*it));
                ++it;
                continue;
            }
            if(it == nums.end()) {
                res.push_back((*negative_it) * (*negative_it));
                --negative_it;
                continue;
            }
            if(abs(*negative_it) < *it) {
                res.push_back((*negative_it) * (*negative_it));
                --negative_it;
            }else{
                res.push_back((*it) * (*it));
                ++it;
            }
        }
        return res;
    }
};