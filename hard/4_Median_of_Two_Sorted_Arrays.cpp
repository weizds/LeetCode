class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)
            return findMedianSortedArrays(nums2, nums1);
        int total = n + m;
        int l = 0;
        int r = n;
        while(l <= r) {
            int med1 = (l + r) / 2;
            int med2 = (total + 1) / 2 - med1;
            int nums1_l = (med1 > 0) ? nums1[med1 - 1] : INT_MIN;
            int nums1_r = (med1 < n) ? nums1[med1] : INT_MAX;
            int nums2_l = (med2 > 0) ? nums2[med2 - 1] : INT_MIN;
            int nums2_r = (med2 < m) ? nums2[med2] : INT_MAX;
            if(nums1_l <= nums2_r && nums2_l <= nums1_r) {
                if(total % 2 == 0){
                    return (max(nums1_l, nums2_l) + min(nums1_r, nums2_r)) / 2.;
                }else{
                    return max(nums1_l, nums2_l);
                }
            }else if(nums1_l > nums2_r) {
                r = med1 - 1;
            }else{
                l = med1 + 1;
            }
        }
        return 0;
    }
};