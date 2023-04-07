class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int res = 0;
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                ++l;
                --r;
            }else{
                --r;
            }
            ++res;
        }
        return res;
    }
};