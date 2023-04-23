class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1.front() < v2.front();
        });
        vector<vector<int>> res;
        res.push_back(intervals.front());
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] <= res.back()[1]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};