class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int max_so_far = -1;
        for(int i = n - 1; i >= 0; --i) {
            if(arr[i] > max_so_far) {
                swap(arr[i], max_so_far);
            }else{
                arr[i] = max_so_far;
            }
        }
        return arr;
    }
};