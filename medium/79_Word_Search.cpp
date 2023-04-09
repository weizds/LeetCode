class Solution {
public:
    bool dfs(vector<vector<char>>& board, 
    int i, int j, const string &word, int cur) {
        int n = board.size();
        int m = board.back().size();
        if((i < 0) || (i >= n) || (j < 0) || (j >= m) || board[i][j] != word[cur])
            return false;
        if(cur + 1 == word.size())
            return true;

        vector<int> dir{1, 0, -1, 0, 1};
        board[i][j] = '#';
        for(int k = 0; k < 4; ++k) {
            if(dfs(board, i + dir[k], j + dir[k + 1], word, cur + 1))
                return true;
        }
        board[i][j] = word[cur];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board.back().size();
        // Word is larger than the board
        if(word.size() > n * m)
            return false;
        unordered_map<char, int> dict_word;
        for(auto ch : word)
            ++dict_word[ch];
        unordered_map<char, int> dict_board;
        for(const auto &line : board)
            for(auto ch : line)
                 ++dict_board[ch];
        // Check if all letters of the word are present on the board
        for(auto ch : word)
            if(dict_board[ch] < dict_word[ch])
                return false;
        // Reverse the word if the frequency of the first letter in the word is greater than that of the last
        if(dict_board[word.front()] > dict_board[word.back()])
            reverse(word.begin(), word.end());
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};