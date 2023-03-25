class Solution {
public:
    void generate(string str, int opened, int closed){
        if(closed == n){
            res.push_back(str);
            return;
        }
        if(opened < n)
            generate(str + '(', opened + 1, closed);
        if(opened > closed)
            generate(str + ')', opened, closed + 1);
            
    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        generate("", 0, 0);
        return res;
    }
    vector<string> res;
    int n;
};