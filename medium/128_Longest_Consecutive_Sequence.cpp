class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int max_seq = 0;
        for(auto num : s){
            if(!s.count(num - 1)){
                int seq = 1;
                while(s.count(num + seq))
                    ++seq;
                max_seq = max(max_seq, seq);
            }
        }

        return max_seq;
    }
};