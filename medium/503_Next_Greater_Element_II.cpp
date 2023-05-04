class Solution {
public:
    void scan(vector<int>& nums, stack<int>& st, vector<int>& res) {
        int n = nums.size();
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if(!st.empty())
                res[i] = nums[st.top()];
            st.push(i);
        }
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(), -1);
        scan(nums, st, res);
        scan(nums, st, res);
        return res;
    }
};