class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size())
            return false;
        vector<int> dict(26, 0);
        for(auto ch : magazine)
            ++dict[ch - 'a'];
        for(auto ch : ransomNote) {
            --dict[ch - 'a'];
            if(dict[ch - 'a'] < 0)
                return false;
        }
        return true;
    }
};