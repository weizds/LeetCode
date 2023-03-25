class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        uint64_t current_val = k;
        for(auto it = num.rbegin(); it != num.rend(); ++it) {
            current_val += *it;
            res.push_back(current_val % 10);
            current_val /= 10;
        }
        while(current_val > 0) {
            res.push_back(current_val % 10);
            current_val /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};