class Solution {
public:
    // abc3[de]2[f3[gh]]jkl
    string decodeString(string s) {
        stack<char> st;
        for(auto ch : s) {
            if(ch == ']') {
                string tmp;
                while(st.top() != '[')
                    tmp.push_back(st.top()), st.pop();
                st.pop(); // [
                reverse(tmp.begin(), tmp.end());
                string num;
                while(!st.empty() && isdigit(st.top()))
                    num.push_back(st.top()), st.pop();
                reverse(num.begin(), num.end());
                int count = stoi(num);
                while(count-- > 0) {
                    for(auto tmp_ch : tmp)
                        st.push(tmp_ch);
                }
            }else{
                st.push(ch);
            }
        }
        string res;
        int size = st.size();
        res.resize(size);
        for(int i = size - 1; i >= 0; --i) {
            res[i] = st.top();
            st.pop();
        }   
        return res;
    }
};