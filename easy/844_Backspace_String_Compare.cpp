class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        for(; i >= 0 || j >= 0;){
            int bscount = 0;
            while(i >= 0){
                if(s[i] == '#'){
                    bscount++; 
                    i--;    
                }else if(bscount > 0){
                    bscount--;
                    i--;
                }else{
                    break;
                }
            }
            bscount = 0;
            while(j >= 0){
                if(t[j] == '#'){
                    bscount++; 
                    j--;    
                }else if(bscount){
                    bscount--;
                    j--;
                }else{
                    break;
                }
            }
            std::cout << i << j << std::endl;
            if(i < 0 && j < 0)
                return true;
            else if(i < 0)
                return false;
            else if(j < 0)
                return false;
            if(s[i] != t[j]){
                return false;
            }else{
                i--;
                j--;
            }
        }
        if(i < 0 && j < 0)
            return true;
        else if(i < 0)
            return false;
        else if(j < 0)
            return false;
        return true;
    }
};