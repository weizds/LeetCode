class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot_index = left + rand() % (right - left + 1);
        int pivot = nums[pivot_index];
        swap(nums[pivot_index], nums[right]);
        int index = left;
        for(int i = left; i < right; ++i) {
            if(nums[i] <= pivot) {
                swap(nums[index], nums[i]);
                ++index;
            }
        }
        swap(nums[index], nums[right]);
        return index;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        k = nums.size() - k;
        while(left < right) {
            int pivot = partition(nums, left, right);
            if(pivot == k)
                return nums[k];
            else if(pivot > k){
                right = pivot - 1;
            }else{
                left = pivot + 1;
            }
        }
        return nums[left];
    }
};