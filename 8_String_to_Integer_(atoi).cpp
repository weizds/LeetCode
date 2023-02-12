class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int sign = 1;
        if(str.empty())
            return 0;
        string number;
        int ws_count = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ' ')
                ws_count++;
            else 
                break;
        }
        str = str.substr(ws_count);
        if(str[0] == '-'){
            sign = -1;
            str.erase(0, 1);
        }else if(str[0] == '+'){
            str.erase(0, 1);
        }
        int dig_count = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] >= '0' && str[i] <= '9')
                dig_count++;
            else
                break;
        }
        str = str.substr(0, dig_count);

        if(!str.empty()){
            for(int i = 0; i < str.size(); i++){
                int digit = str[i] - '0';
                res += digit;
                if(i != str.size() - 1)
                    res *= 10;
                if(res * sign > INT_MAX)
                    return INT_MAX;
                if(res * sign < INT_MIN)
                    return INT_MIN;
            }
        }
        return res * sign;
    }
};