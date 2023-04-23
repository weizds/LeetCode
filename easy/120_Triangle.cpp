class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i = 0; i < n - 1; ++i) {
            int m = triangle[i + 1].size();
            triangle[i + 1][0] += triangle[i][0];
            triangle[i + 1][m - 1] += triangle[i][m - 2];
            for(int j = 1; j < m - 1; ++j) {
                triangle[i + 1][j] += min(triangle[i][j], triangle[i][j - 1]);
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};