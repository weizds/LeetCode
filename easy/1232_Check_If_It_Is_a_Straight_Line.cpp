class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx = (coordinates[0][0] - coordinates[1][0]);
        int dy = (coordinates[0][1] - coordinates[1][1]);
        for(int i = 2; i < coordinates.size(); ++i) {
            if(dx * (coordinates[i][1] - coordinates[i-1][1]) != (coordinates[i][0] - coordinates[i-1][0]) * dy)
                return false;
        }
        return true;
    }
};