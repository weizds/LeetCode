class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zero_count = 0;
        int n = arr.size();
        for(int i = 0; i < n; ++i)
            if(arr[i] == 0)
                ++zero_count;
        for(int i = n - 1; i >= 0; --i) {
            if(arr[i] == 0){
                --zero_count;
                if(i + zero_count + 1 < n)
                    arr[i + zero_count + 1] = 0;
            }
            if(i + zero_count < n)
                arr[i + zero_count] = arr[i];
        }
    }
    // void duplicateZeros(vector<int>& arr) {
    //     int zero_count = 0;
    //     int len = arr.size() - 1;
    //     for(int i = 0; i <= len - zero_count; ++i) {
    //         if(arr[i] == 0) {
    //             if(i == len - zero_count) {
    //                 arr[len] = 0;
    //                 --len;
    //                 break;
    //             }
    //             ++zero_count;
    //         }
    //     }
    //     for(int i = len - zero_count; i >= 0; --i) {
    //         if(arr[i] == 0){
    //             arr[i + zero_count] = 0;
    //             --zero_count;
    //             arr[i + zero_count] = 0;
    //         }else{
    //             arr[i + zero_count] = arr[i];
    //         }
    //     }
    // }
};