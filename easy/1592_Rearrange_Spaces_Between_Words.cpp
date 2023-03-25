class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = 0;
        vector<string> words;
        string cur_word;
        for(auto ch : text){
            if(ch == ' '){
                ++spaces;
                if(!cur_word.empty()){
                    words.push_back(cur_word);
                    cur_word.clear();
                }
            }else{
                cur_word.append(1, ch);
            }
        }
        if(!cur_word.empty())
            words.push_back(cur_word);
        string res;
        if(words.size() > 1){
            int space_width = spaces/(words.size() - 1);
            for(int i = 0; i < words.size() - 1; ++i) {
                res.append(words[i]);
                res.append(space_width, ' ');
            }
            res.append(words.back());
            res.append(spaces % (words.size() - 1), ' ');
        }else{
            res.append(words.back());
            res.append(spaces, ' ');
        }
        return res;
    }
};