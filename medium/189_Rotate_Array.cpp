class Solution {
public:
    int calc_gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0 || n == 1)
            return;
        k %= n;
        int gcd = calc_gcd(n, k);
        for(int i = 0; i < gcd; ++i) {
            int tmp = nums[i];
            for(int j = i + k; j != i; j = (j + k) % n)
                swap(nums[j], tmp);
            swap(nums[i], tmp);
        }
    }
};
