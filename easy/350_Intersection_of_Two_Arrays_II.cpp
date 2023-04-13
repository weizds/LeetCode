class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        unordered_map<int, int> mp;
        for(auto num : nums1)
            ++mp[num];
        vector<int> res;
        for(auto num : nums2) {
            if(mp.find(num) != mp.end() && mp[num] > 0) {
                res.push_back(num);
                --mp[num];
            }
        }
        return res;
    }
    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     sort(nums1.begin(), nums1.end());
    //     sort(nums2.begin(), nums2.end());
    //     vector<int> res;
    //     int i = 0;
    //     int j = 0;
    //     while(i < nums1.size() && j < nums2.size()) {
    //         if(nums1[i] < nums2[j]) {
    //             ++i;
    //         }else if(nums1[i] > nums2[j]) {
    //             ++j;
    //         }else {
    //             res.push_back(nums1[i]);
    //             ++i;
    //             ++j;
    //         }
    //     }
    //     return res;
    // }
};
