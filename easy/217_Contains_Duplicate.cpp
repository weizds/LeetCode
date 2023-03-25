class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::vector<int> tmp(nums.begin(), nums.end());
        std::sort(tmp.begin(), tmp.end());
        for(int i = 0; i < tmp.size() - 1; ++i)
            if(tmp[i] == tmp[i+1])
                return true;
        return false;
    }
};