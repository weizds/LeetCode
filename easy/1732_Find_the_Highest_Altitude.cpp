class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int height = 0;
        for(auto g : gain) {
            height += g;
            res = max(res, height);
        }
        return res;
    }
};