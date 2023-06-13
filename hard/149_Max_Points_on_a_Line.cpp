class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 1;
        int res = 2;
        for(int i = 0; i < n; ++i) {
            unordered_map<double, int> count;
            for(int j = 0; j < n; ++j)
                if(i != j)
                    ++count[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])];
            for(auto a : count)
                res = max(res, a.second + 1);
        }
        return res;
    }
};