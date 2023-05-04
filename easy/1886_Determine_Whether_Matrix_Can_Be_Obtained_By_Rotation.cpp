class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int k = 0; k < 4; ++k) {
            if(mat == target)
                return true;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
                reverse(mat[i].begin(), mat[i].end());
            }
        }
        return false;
    }
};