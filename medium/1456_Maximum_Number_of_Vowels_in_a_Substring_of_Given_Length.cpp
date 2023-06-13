class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0;
        auto isVowel{[](char ch){
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        }};
        int vowel_count = 0;
        int res = 0;
        for(int r = 0; r < s.size(); ++r) {
            if(isVowel(s[r]))
                ++vowel_count;
            if(r >= k) {
                if(isVowel(s[l]))
                    --vowel_count;
                ++l;
            }
            res = max(res, vowel_count);
        }
        return res;
    }
};