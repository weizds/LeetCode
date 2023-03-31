class Solution {
public:
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