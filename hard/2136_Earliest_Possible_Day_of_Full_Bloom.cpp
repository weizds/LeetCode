class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> plant_grow(plantTime.size());
        for(int i = 0; i < plantTime.size(); ++i)
            plant_grow[i] = {growTime[i], plantTime[i]};
        sort(plant_grow.begin(), plant_grow.end());
        int res = 0;
        for (auto[grow, plant] : plant_grow) {
            res = max(res, grow) + plant;
        }
        return res;
    }
};