class Solution {
public:
    string simplifyPath(string path) {
        vector<string> split;
        istringstream iss(path);
        string word;
        while(getline(iss, word, '/')) {
            if(word == "." || word.empty())
                continue;
            if(word == "..") {
                if(!split.empty())
                    split.pop_back();
            }else {
                split.push_back(word);
            }
        }
        string res{"/"};
        for(auto it = split.begin(); it != split.end(); ++it) {
            res.append(*it);
            if(it != (split.end() - 1))
                res.append(1, '/');
        }
        return res;
    }
};