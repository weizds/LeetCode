class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count_map;
        for(auto num : nums)
            ++count_map[num];
        std::vector<std::vector<int>> tmp(nums.size() + 1);
        for(auto a : count_map)
            tmp[a.second].push_back(a.first);
        vector<int> res;
        for(auto it = tmp.rbegin(); it != tmp.rend(); ++it){
            if(!(*it).empty()){
                for(auto a : *it){
                    res.push_back(a);
                    if(res.size() >= k) break;
                }
            }
            if(res.size() >= k) break;
        }
        return res;
    }
};