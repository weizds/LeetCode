class Solution {
public:
    bool isAnagram(const vector<int>& vec){
        for(auto val : vec)
            if(val != 0)
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size())
            return res;
        vector<int> dict(26, 0);
        int n = p.size();
        for(int i = 0; i < n; ++i){
            ++dict[p[i] - 'a'];
            --dict[s[i] - 'a'];
        }
        if(isAnagram(dict))
            res.push_back(0);
        int m = s.size();
        for(int i = n; i < m; ++i){
            --dict[s[i] - 'a'];
            ++dict[s[i - n] - 'a'];
            if(isAnagram(dict))
                res.push_back(i - n + 1);
        }
        return res;
    }
};