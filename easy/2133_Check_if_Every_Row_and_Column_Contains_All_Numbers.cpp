class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> rows(n, 0);
        vector<int> cols(n, 0);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(rows[matrix[i][j] - 1] != i
                   || cols[matrix[j][i] - 1] != i)
                    return false;
                ++rows[matrix[i][j] - 1];
                ++cols[matrix[j][i] - 1];
            }
        }
        return true;
    }
};