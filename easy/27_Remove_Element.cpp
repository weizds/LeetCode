class Solution {
public:
    // Removes all instances of a value from a vector efficiently using in-place replacement.
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int j = n - 1;
        for(int i = n - 1; i >= 0; --i) {
            if(nums[i] == val) {
                nums[i] = nums[j];
                --j;
            }
        }
        return j + 1;
    }
};