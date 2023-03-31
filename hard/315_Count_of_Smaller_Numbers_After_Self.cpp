class Solution {
public:
    int parent(int i) {
        return i - (i & (-i));
    }
    int next(int i) {
        return i + (i & (-i));
    }
    int map_index(int i) {
        return i + max;
    }
    void update(int i, int val) {
        ++i;
        while(i < n) {
            bit[i] += val;
            i = next(i);
        }
    }
    int query(int i) {
        int sum = 0;
        ++i;
        while(i > 0) {
            sum += bit[i];
            i = parent(i);
        }
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums) {
        bit = vector<int>(n, 0);
        vector<int> res;
        for(auto num : nums)
            update(num + max, 1);
        for(auto num : nums) {
            res.push_back(query(num + max - 1));
            update(num + max, -1);
        }
        return res;
    }
private:
    vector<int> bit;
    int max{10000};
    int n{max*2 + 1};
};