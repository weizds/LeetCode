class Solution {
public:
    int minSwaps(string s) {
        // Just count unbalanced closing brackets
        int count = 0;
        int res = 0;
        for(auto ch : s) {
            if(ch == ']')
                ++count;
            else
                --count;
            res = max(res, count);
        }
        // Divided by 2 because one swap fixes 2 unbalanced closing brackets
        // ]]][ -> []][
        // 3 unbalanced closing brackets -> 1 unbalanced closing bracket
        return (res + 1) / 2;
    }
};