#include <unordered_map>

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        int res = 0;
        for(auto num : nums)
            if(num < k)
                map[num]++;

        if(k % 2 == 0){
            auto found = map.find(k / 2);
            if(found != map.end()){
                res += found->second / 2;
                found->second = 0;
            }
        }
       
        for(auto it = map.begin(); it != map.end();++it){
            if(it->first <= k / 2){
                auto found = map.find(k - it->first);
                if(found != map.end()){
                    res += std::min(it->second, found->second);
                }
            }
        }
        
        return res;
    }
};
