class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0;
        int left = -1;
        int n = seats.size();
        for(int i = 0; i < n; ++i) {
            if(seats[i] == 0) 
                continue;
            if(left == -1)
                res = max(res, i);
            else
                res = max(res, (i - left)/2);
            left = i;
        }
        if(seats[n - 1] == 0)
            res = max(res, n - 1 - left);
        return res;
    }
};