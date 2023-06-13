class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change[5]{0};
        for(auto bill : bills) {
            if(bill == 10) {
                if(change[1] >= 1)
                    --change[1];
                else
                    return false;
            }else if(bill == 20) {
                if(change[1] >= 1 && change[2] >= 1) {
                    --change[1];
                    --change[2];
                }else if(change[1] >= 3) {
                    change[1] -= 3;
                }else{
                    return false;
                }
            }
            ++change[bill/5];
        }
        return true;
    }
};