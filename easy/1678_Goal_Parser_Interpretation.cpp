class Solution {
public:
    string interpret(string command) {
        string res;
        for(int i = 0; i < command.size(); ++i) {
            if(command[i] == '(')
                continue;
            if(command[i] == ')')
                res.push_back('o');
            else if(command[i] == 'a')
                i+=2, res.append("al");
            else
                res.push_back('G');
        }
        return res;
    }
};