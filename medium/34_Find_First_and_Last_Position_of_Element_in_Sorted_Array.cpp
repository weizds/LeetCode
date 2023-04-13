class Solution {
public:
    int left_binary_search(const vector<int> &vec, int target) {
        int l = 0;
        int r = vec.size() - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(vec[m] < target)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }

    int right_binary_search(const vector<int> &vec, int target) {
        int l = 0;
        int r = vec.size() - 1;
        while(l < r) {
            int m = (l + r + 1) / 2;
            if(vec[m] > target)
                r = m - 1;
            else
                l = m;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        int first = left_binary_search(nums, target);
        if(nums[first] != target)
            return {-1, -1};
        int second = right_binary_search(nums, target);
        return {first, second};
    }
};