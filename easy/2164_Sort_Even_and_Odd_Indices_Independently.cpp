class Solution {
public:
    // Since the input elements are constrained to be between 1 and 100 inclusive, 
    // it's advantageous to use count sort separately for even and odd indices.
    vector<int> sortEvenOdd(vector<int>& nums) {
        int count[101]{0};
        int n = nums.size();
        for(int i = 0; i < n; i+=2)
            ++count[nums[i]];
        for(int i = 0, j = 0; i <= 100; ++i) {
            while(count[i] > 0) {
                --count[i];
                nums[j] = i;
                j += 2;
            }
        }
        for(int i = 1; i < n; i+=2)
            ++count[nums[i]];
        for(int i = 100, j = 1; i > 0; --i) {
            while(count[i] > 0) {
                --count[i];
                nums[j] = i;
                j += 2;
            }
        }
        return nums;
    }
};