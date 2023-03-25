class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> map{{')', '('}, {']', '['}, {'}', '{'}};
        for(auto ch : s){
            if(map.find(ch) != map.end()) {
                if(stack.empty())
                    return false;
                if(stack.top() == map[ch])
                    stack.pop();
                else
                    return false;
            }else{
                stack.push(ch);
            }
        }
        return stack.empty();
    }
};