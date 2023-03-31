class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        auto it_zero = lower_bound(satisfaction.begin(), satisfaction.end(), 0);
        if(it_zero == satisfaction.end())
            return 0;
        int res = 0;
        int count = 1;
        for(auto it = it_zero; it != satisfaction.end(); ++it) {
            res += count * (*it);
            ++count;
        }
        int sum = accumulate(it_zero, satisfaction.end(), 0);
        if(it_zero != satisfaction.begin()) {
            auto it = it_zero - 1;
            while(it != (satisfaction.begin() - 1) && sum + *it > 0) {
                sum += *it;
                res += sum;
                --it;
            }
        }
        return res;
    }
};