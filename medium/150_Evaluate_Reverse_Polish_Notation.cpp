class Solution {
public:
    bool is_operator(const string& str){
        if(str.size() == 1 && (str[0] == '+' || str[0] == '-' || 
                               str[0] == '*' || str[0] == '/'))
            return true;
        return false;
    }
    int calculate(char op, int first, int second){
        switch(op){
            case '+': return (second + first);
            case '-': return (second - first);
            case '*': return (second * first);
            case '/': return (second / first);
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(auto token : tokens){
            int first, second;
            if(is_operator(token)){
                first = stack.top();
                stack.pop();
                second = stack.top();
                stack.pop();
                stack.push(calculate(token[0], first, second));
            }else{
                stack.push(stoi(token));
            }
        }
        return stack.top();
    }
};