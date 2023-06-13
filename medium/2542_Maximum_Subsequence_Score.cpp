class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs;
        for(int i = 0; i < n; ++i)
            pairs.push_back({nums2[i], nums1[i]});
        sort(pairs.begin(), pairs.end(), greater<pair<int, int>>());
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i < k; ++i) {
            sum += pairs[i].second;
            heap.push(pairs[i].second);
        }
        long long res = sum * pairs[k - 1].first;
        for(int i = k; i < n; ++i) {
            sum += pairs[i].second - heap.top();
            heap.pop();
            heap.push(pairs[i].second);
            res = max(res, sum * pairs[i].first);
        }
        return res;
    }
};  