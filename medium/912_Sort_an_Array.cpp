class Solution {
public:
    void siftDown(vector<int> &heap, int start, int end) {
        int root = start;
        while(root*2 + 1 <= end) {
            int left = root * 2 + 1;
            int to_swap = root;
            if(heap[to_swap] < heap[left])
                to_swap = left;
            int right = left + 1;
            if(right <= end && heap[to_swap] < heap[right])
                to_swap = right;
            if(to_swap == root){
                break;
            }else{
                swap(heap[to_swap], heap[root]);
                root = to_swap;
            }            
        }
    }

    void heapify(vector<int> &heap) {
        int end = heap.size() - 1;
        for(int start = (end - 1) / 2; start >= 0; start--){
            siftDown(heap, start, end);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        heapify(nums);
        int n = nums.size();
        for(int i = n - 2; i >= 0; --i){
            swap(nums[0], nums[i + 1]);
            siftDown(nums, 0, i);
        }
        return nums;
    }
};