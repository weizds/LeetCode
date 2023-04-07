class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algorithm
        int count = 0;
        int major = 0;
        for(auto num : nums) {
            if(count == 0)
                major = num;
            if(num == major)
                ++count;
            else
                --count;
        }
        return major;
    }
};