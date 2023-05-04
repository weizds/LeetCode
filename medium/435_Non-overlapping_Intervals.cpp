class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a.back() < b.back();
        });
        int prev = 0;
        int res = -1;
        for(int i = 0; i < intervals.size(); ++i) {
            if(intervals[prev].back() > intervals[i].front())
                ++res;
            else
                prev = i;
        }
        return res;
    }
};