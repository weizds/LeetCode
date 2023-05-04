class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for(int i = 0; i < points.size(); ++i) {
            pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()) {
            int index = pq.top().second;
            pq.pop();
            res.push_back({points[index][0], points[index][1]});
        }
        return res;
    }
};