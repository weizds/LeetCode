class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto ch : num) {
            while(!st.empty() && st.top() > ch && k > 0)
                --k, st.pop();
            st.push(ch);
        }
        while(!st.empty() && k > 0)
            --k, st.pop();
        string res;
        while(!st.empty())
            res.push_back(st.top()), st.pop();
        while(res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        if(res.empty())
            res = "0";
        return res;
    }
};