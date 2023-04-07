class Solution {
public:
    // find at what position most bricks ends
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        for(const auto &line : wall) {
            int sum = line[0];
            for(int i = 1; i < line.size(); ++i){
                ++mp[sum];
                sum += line[i];
            }
        }
        int res = 0;
        for(auto p : mp){
            res = max(res, p.second);
        }
        return wall.size() - res;
    }
};