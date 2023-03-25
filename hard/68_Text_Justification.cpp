class Solution {
public:
    string make_string(const vector<string> &words, int start_word, int end_word, int width, int max_width) {
        string res;
        if(start_word == end_word) {
            res.append(words[start_word]);
            res.append(max_width - words[start_word].size(), ' ');
            return res;
        }
        int word_count = end_word - start_word + 1;
        int spaces = max_width - (width - word_count);
        int slot_width = spaces / (word_count - 1); 
        int wide_slot_count = spaces % (word_count - 1);
        for(int i = start_word; i < end_word; ++i) {
            res.append(words[i]);
            if(wide_slot_count > 0){
                res.append(slot_width + 1, ' ');
                --wide_slot_count;
            }else{
                res.append(slot_width, ' ');
            }
        }
        res.append(words[end_word]);
        return res;
    }
    vector<string> fullJustify(vector<string>& words, int max_width) {
        vector<string> res;
        int start_word = 0;
        int width = 0;
        int n = words.size();
        for(int i = 0; i < n; ++i) {
            if(width + words[i].size() > max_width) {
                res.push_back(make_string(words, start_word, i - 1, width, max_width));
                start_word = i;
                width = words[i].size() + 1;
            }else{
                width += words[i].size() + 1;
            }
        }
        string last;
        for(int i = start_word; i < n - 1; ++i) {
            last.append(words[i]);
            last.append(1, ' ');
        }
        last.append(words[n - 1]);
        last.append(max_width - last.size(), ' ');
        res.push_back(last);
        return res;
    }
};