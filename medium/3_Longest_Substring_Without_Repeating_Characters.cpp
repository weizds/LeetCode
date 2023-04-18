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
    // int lengthOfLongestSubstring(string s) {
    //     vector<bool> seen(128, false);
    //     int l = 0;
    //     int res = 0;
    //     for(int r = 0; r < s.size(); ++r) {
    //         while(seen[s[r]])
    //             seen[s[l++]] = false;
    //         seen[s[r]] = true;
    //         res = max(res, r - l + 1);
    //     }
    //     return res;
    // }
};