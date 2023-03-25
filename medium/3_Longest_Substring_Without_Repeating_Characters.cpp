class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> letters;
        
        int i = 0;
        int j = 0;
        
        int result = 0;
        
        while (j < s.size()) {
            if (letters.find(s[j]) == letters.end()) {
                letters.insert(s[j]);
                result = max(result, (int)letters.size());
                j++;
            } else {
                letters.erase(s[i]);
                i++;
            }
        }
        
        return result;
    }
};