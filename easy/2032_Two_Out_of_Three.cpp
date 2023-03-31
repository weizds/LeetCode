class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> res;
        unordered_map<int, int> mp;
        // 3 5 6 7
        for(auto num : nums1)
            mp[num] = 1;
        for(auto num : nums2) {
            mp[num] |= 2;
        }
        for(auto num : nums3) {
            mp[num] |= 4;
        }
        for(auto it = mp.begin(); it != mp.end(); ++it)
            if(it->second > 4 || it->second == 3)
                res.push_back(it->first);
        return res;
    }
    /* OR
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> res;
        vector<int> mp(101, 0);
        for(auto num : nums1)
            mp[num] = 1;
        for(auto num : nums2)
            mp[num] |= 2;
        for(auto num : nums3)
            mp[num] |= 4;
        for(int i = 1; i < 101; ++i)
            if(mp[i] == 3 || mp[i] > 4)
                res.push_back(i);
        return res;
    }*/
};