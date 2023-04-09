class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())
            return -1;
        for(int i = 0; i < haystack.size() - needle.size() + 1; ++i) {
            if(haystack[i] == needle[0]){
                int j = 0;
                while(haystack[i + j] == needle[j] && j < needle.size())
                    ++j;
                if(j == needle.size())
                    return i;
            }
        }
        return -1;
    }
};