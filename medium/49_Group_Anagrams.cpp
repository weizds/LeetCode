class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        for(auto word : strs){
            vector<int> dict(26);
            for(auto ch : word){
                ++dict[ch - 'a'];
            }
            string tmp_str;
            for(int i = 0; i < dict.size(); i++){
                if(dict[i] > 0){
                    tmp_str.append(1, static_cast<char>(i + 'a'))
                        .append(to_string(dict[i])).append(1, ',');
                }
            }
            map[tmp_str].push_back(word);
        }
        for(auto a : map)
            res.push_back(a.second);
        return res;
    }
};