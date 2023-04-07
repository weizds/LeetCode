class Solution {
public:
    // Return length of last word in input string using reverse iteration and counting.
    int lengthOfLastWord(string s) {
        int count = 0;
        for(auto it = s.rbegin(); it != s.rend(); ++it){
            if(*it == ' '){
                if(count == 0)
                    continue;
                else 
                    break;
            }
            ++count;
        }
        return count;
    }
};