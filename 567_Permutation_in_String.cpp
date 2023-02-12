class Solution {
public:
    bool isPermutation(const vector<int>& vec){
        for(auto val : vec)
            if(val != 0)
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
            return false;
        vector<int> dict(26, 0);
        int n = s1.size();
        for(int i = 0; i < n; ++i){
            ++dict[s1[i] - 'a'];
            --dict[s2[i] - 'a'];
        }
        if(isPermutation(dict))
            return true;
        int m = s2.size();
        for(int i = n; i < m; ++i){
            --dict[s2[i] - 'a'];
            ++dict[s2[i - n] - 'a'];
            if(isPermutation(dict))
                return true;
        }
        return false;
    }
};