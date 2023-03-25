class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        short rows[9] = {0};
        short cols[9] = {0};
        short squares[3][3] = {0};
        for(int col = 0; col < 9; ++col){
            for(int row = 0; row < 9; ++row){
                if(board[col][row] != '.'){
                    auto val = board[col][row] - '1';
                    if(((rows[row] >> val) & 1) || 
                       ((cols[col] >> val) & 1) || 
                       ((squares[col/3][row/3] >> val) & 1))
                        return false;
                    rows[row] |= 1 << val;
                    cols[col] |= 1 << val;
                    squares[col/3][row/3] |= 1 << val;;
                }
            }
        }
        return true;
    }
};