class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bot = matrix.size() - 1;
        while(top <= bot){
            int mid = top + (bot - top) / 2;
            if(matrix[mid].back() < target){
                top = mid + 1;
            }else if(matrix[mid].front() > target){
                bot = mid - 1;
            }else{
                int low = 0;
                int high = matrix[0].size() - 1;
                while(low <= high){
                    int mid2 = low + (high - low) / 2;
                    if(matrix[mid][mid2] < target){
                        low = mid2 + 1;
                    }else if(matrix[mid][mid2] > target){
                        high = mid2 - 1;
                    }else{
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};