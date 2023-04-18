class Solution {
public:
    int countBits(int num) {
        int res = 0;
        for(; num > 0; ++res)
            num &= num - 1;
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> buckets(16);
        sort(arr.begin(), arr.end());
        for(auto num : arr){
            buckets[countBits(num)].push_back(num);
        }
        int i = 0;
        for(const auto &bucket : buckets) {
            for(auto num : bucket)
                arr[i++] = num;
        }
        return arr;
    }
    // vector<int> sortByBits(vector<int>& arr) {
    //     sort(arr.begin(), arr.end(), [](int a, int b){
    //         int count_a = __builtin_popcount(a);
    //         int count_b = __builtin_popcount(b);
    //         if(count_a == count_b)
    //             return a < b;
    //         return count_a < count_b;
    //     });
    //     return arr;
    // }
};