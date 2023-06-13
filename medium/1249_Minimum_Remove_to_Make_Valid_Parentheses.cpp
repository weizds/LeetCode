class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ')') {
                if(st.empty())
                    s[i] = '#';
                else
                    st.pop();
            }else if(s[i] == '(') {
                st.push(i);
            }
        }
        while(!st.empty())
            s[st.top()] = '#', st.pop();
        int skip = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '#')
                ++skip;
            else
                s[i - skip] = s[i];
        }
        s.resize(s.size() - skip);
        return s;
    }
};