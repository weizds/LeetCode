class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix.back().size();
        pref_sum = vector<vector<int>>(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i) {
            pref_sum[i][0] = matrix[i][0];
            for(int j = 1; j < m; ++j) {
                pref_sum[i][j] = pref_sum[i][j - 1] + matrix[i][j];
            }
        }
        for(int j = 0; j < m; ++j) {
            for(int i = 1; i < n; ++i) {
                pref_sum[i][j] += pref_sum[i -1][j];
            }
        }   
    }
    int sum(int row, int col) {
        if(row >= 0 && col >= 0)
            return pref_sum[row][col];
        return 0;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2, col2) - sum(row1 - 1, col2) - sum(row2, col1 - 1) + sum(row1 - 1, col1 - 1);
    }
private:
    vector<vector<int>> pref_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */