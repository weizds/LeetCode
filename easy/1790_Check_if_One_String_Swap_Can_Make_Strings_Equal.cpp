class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<pair<char, char>> unequal;
        for(int i = 0; i < s1.size(); ++i) {
            if(s1[i] != s2[i]) {
                if(unequal.size() >= 2)
                    return false;
                unequal.push_back({s1[i], s2[i]});
            }
        }
        if(unequal.size() == 0)
            return true;
        if(unequal.size() == 2) {
            if(unequal[0].first == unequal[1].second &&
                unequal[1].first == unequal[0].second)
                return true;
        }
        return false;
    }
    // bool areAlmostEqual(string s1, string s2) {
    //     int flag = 0;
    //     int swap_index = 0;
    //     for(int i = 0; i < s1.size(); ++i) {
    //         if(s1[i] != s2[i] && flag == 0) {
    //             swap_index = i;
    //             flag = 1;
    //         }else if(s1[i] != s2[i] && flag == 1) {
    //             swap(s1[i], s1[swap_index]);
    //             if(s1 == s2)
    //                 return true;
    //             else
    //                 return false;
    //         }
    //     }
    //     return flag == 0;
    // }
};