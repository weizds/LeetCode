class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix.back().size();
        int low_row = 0;
        int high_row = n - 1;
        while(low_row < high_row) {
            int mid_row = (high_row + low_row) / 2;
            if(matrix[mid_row][0] == target)
                return true;
            if(matrix[mid_row][0] < target && target <= matrix[mid_row][m - 1]) {
                low_row = mid_row;
                break;
            }
            if(matrix[mid_row][0] > target) {
                high_row = mid_row - 1;
            }else{
                low_row = mid_row + 1;
            }
        }
        int low_col = 0;
        int high_col = m - 1;
        while(low_col <= high_col) {
            int mid = (high_col + low_col) / 2;
            if(matrix[low_row][mid] == target)
                return true;
            else if(matrix[low_row][mid] < target)
                low_col = mid + 1;
            else
                high_col = mid - 1;
        }
        return false;
    }
};