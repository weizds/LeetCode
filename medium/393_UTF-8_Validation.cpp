class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for(int i = 0; i < data.size(); ++i) {
            if(count > 0) {
                if((0xC0 & data[i]) != 0x80)
                    return false;
                --count;
                continue;
            }
            if((0xF8 & data[i]) == 0xF0)
                count = 3;
            else if((0xF0 & data[i]) == 0xE0)
                count = 2;
            else if((0xE0 & data[i]) == 0xC0)
                count = 1;
            else if((0x80 & data[i]) != 0)
                return false;
        }
        return count == 0;
    }
};