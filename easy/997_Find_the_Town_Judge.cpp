class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n + 1);
        for(auto &edge : trust) {
            --count[edge.front()];
            ++count[edge.back()];
        }
        for(int i = 1; i <= n; ++i)
            if(count[i] == n - 1)
                return i;
        return -1;
    }
};