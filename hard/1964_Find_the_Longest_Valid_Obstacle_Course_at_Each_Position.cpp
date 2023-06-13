class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> res(obstacles.size());
        vector<int> lis;
        for(int i = 0; i < obstacles.size(); ++i) {
            int index = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
            if(index == lis.size()) {
                lis.push_back(obstacles[i]);
            }else{
                lis[index] = obstacles[i];
            }
            res[i] = index + 1;
        }
        return res;
    }
};