class Solution {
public:
    int nextGreaterElement(int num) {
        pair<int, int> for_swap{-1, -1};
        string str = to_string(num);
        int n = str.size();
        for(int i = n - 1; i > 0; --i) {
            if(str[i] > str[i - 1]) {
                for_swap.first = i - 1;
                break;
            }
        }
        if(for_swap.first < 0)
            return -1;
        for(int i = n - 1; i >= for_swap.first; --i) {
            if(str[i] > str[for_swap.first]) {
                for_swap.second = i;
                break;
            }
        }
        swap(str[for_swap.first], str[for_swap.second]);
        sort(str.begin() + for_swap.first + 1, str.end());
        auto res = stoll(str);
        if(res > INT_MAX)
            return -1;
        return res;
    }
};