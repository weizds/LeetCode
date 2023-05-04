class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        while(i < firstList.size() && j < secondList.size()) {
            int hi = min(firstList[i][1], secondList[j][1]);
            int low = max(firstList[i][0], secondList[j][0]);
            if(low <= hi)
                res.push_back({low, hi});
                if(firstList[i][1] < secondList[j][1])
                    ++i;
                else
                    ++j;
        }
        return res;
    }
};