class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int max_so_far = -1;
        int n2 = nums2.size();
        unordered_map<int, int> max_map;
        stack<int> st;
        for(int i = 0; i < n2; ++i) {
            while(!st.empty() && nums2[i] > st.top()){
                max_map[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty()){
            max_map[st.top()] = -1;
            st.pop();
        }
        int n1 = nums1.size();
        vector<int> res;
        for(int i = 0; i < n1; ++i)
            res.push_back(max_map[nums1[i]]);
        return res;
    }
};