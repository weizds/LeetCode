class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        int i = 0;
        for(auto x : pushed) {
            pushed[i] = x;
            ++i;
            while(i > 0 && pushed[i - 1] == popped[j]) {
                --i;
                ++j;
            }
        }
        return i == 0;
    }
};