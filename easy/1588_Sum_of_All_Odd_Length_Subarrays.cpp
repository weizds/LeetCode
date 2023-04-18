class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = 0;
        int res = 0;
        for(int i = 0; i < arr.size(); ++i) {
            n += arr.size() - 2*i;
            res += arr[i] * (n - n/2);
        }
        return res;
    }
};