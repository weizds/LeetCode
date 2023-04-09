class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); ++i)
            mp[arr[i]] = i;
        for(int i = 0; i < arr.size(); ++i) {
            auto found = mp.find(arr[i] * 2);
            if(found != mp.end() && found->second != i)
                return true;
        }
        return false;
    }
};