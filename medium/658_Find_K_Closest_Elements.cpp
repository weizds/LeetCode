class Solution {
public:
    // Let's find a k-sized subarray of arr closest to x using binary search 
    // by comparing the absolute difference between the target and 
    // the midpoint of the current and next subarray to determine the best starting index.
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - k;
        while(l < r) {
            int m = (l + r) / 2;
            if(x - arr[m] > arr[m + k] - x)
                l = m + 1;
            else
                r = m;
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};