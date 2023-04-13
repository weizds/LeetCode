class Solution {
public:
    
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> mp;
        long long res = 0;
        for(const auto &rect : rectangles) {
            ++mp[(double)rect.front() / rect.back()];
        }
        auto nChoose2{[](long long n) {
            return n * (n - 1) / 2;
        }};
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            if(it->second > 1)
                res += nChoose2(it->second);
        }
        return res;
    }
};