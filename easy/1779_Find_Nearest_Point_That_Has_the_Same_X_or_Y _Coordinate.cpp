class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1;
        int min_dist = INT_MAX;
        for(int i = 0; i < points.size(); ++i) {
            if(points[i].front() == x) {
                if(abs(y - points[i].back()) < min_dist && res < i) {
                    min_dist = abs(y - points[i].back());
                    res = i;
                }
            }
            if(points[i].back() == y) {
                if(abs(x - points[i].front()) < min_dist && res < i) {
                    min_dist = abs(x - points[i].front());
                    res = i;
                }
            }
        }
        return res;
    }
};