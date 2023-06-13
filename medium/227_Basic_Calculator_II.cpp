class Solution {
public:
    int calculate(string s) {
        if(s.empty())
            return 0;
        int len = s.size();
        stack<int> st;
        int current_num = 0;
        char op = '+';
        for(int i = 0; i < len; ++i) {
            if(isdigit(s[i]))
                current_num = current_num * 10 + (s[i] - '0');
            if(!isdigit(s[i]) && !iswspace(s[i]) || i == len - 1) {
                if(op == '-') {
                    st.push(-current_num);
                }else if(op == '+'){
                    st.push(current_num);
                }else if(op == '*'){
                    int val = st.top();
                    st.pop();
                    st.push(current_num * val);
                }else if(op == '/'){
                    int val = st.top();
                    st.pop();
                    st.push(val / current_num);
                }
                op = s[i];
                current_num = 0;
            }
        }
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};