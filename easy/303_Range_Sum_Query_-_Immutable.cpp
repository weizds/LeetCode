class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pref_sum = vector<int>(n);
        pref_sum[0] = nums[0];
        for(int i = 1; i < n; ++i)
            pref_sum[i] = pref_sum[i - 1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        if(left > 0)
            return pref_sum[right] - pref_sum[left - 1];
        else
            return pref_sum[right];
    }
private:
    vector<int> pref_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */