class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat.front().size();
        if(n * m != r * c)
            return mat;
        vector<vector<int>> res(r, vector<int>(c));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int flat_index = i * m + j;
                res[flat_index / c][flat_index % c] = mat[i][j];
            }
        }
        return res;
    }
};