class Solution {
public:
    int dfs(vector<string>& words, vector<int>& score, 
        int current_word, vector<int>& letters_count) {
        if(current_word >= words.size())
            return 0;
        int next_score = dfs(words, score, current_word + 1, letters_count);
        int word_score = 0;
        bool found = true;
        vector<int> letters_count_copy(letters_count.begin(), letters_count.end());
        for(int i = 0; i < words[current_word].size(); ++i) {
            char ch = words[current_word][i];
            word_score += score[ch - 'a'];
            --letters_count_copy[ch - 'a'];
            if(letters_count_copy[ch - 'a'] < 0) {
                found = false;
                break;
            }
        }
        if(!found)
            return next_score;
        return max(next_score, word_score + dfs(words, score, current_word + 1, letters_count_copy));
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letters_count(26, 0);
        for(auto ch : letters)
            ++letters_count[ch - 'a'];
        return dfs(words, score, 0, letters_count);
    }
};