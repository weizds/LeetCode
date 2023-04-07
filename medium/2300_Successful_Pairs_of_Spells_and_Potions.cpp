class Solution {
public:
    int left_binary_search(const vector<int> &vec, long long spell, long long success) {
        int l = 0;
        int r = vec.size();
        while(l < r) {
            int m = (l + r) / 2;
            if(vec[m] * spell < success)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for(auto spell : spells) {
            int count = potions.size() - left_binary_search(potions, spell, success);
            res.push_back(count);
        }
        return res;
    }
};