class Solution {
public:
    const vector<string> digits_chars = {
        {"abc"}, {"def"}, {"ghi"}, 
        {"jkl"}, {"mno"}, {"pqrs"},
        {"tuv"}, {"wxyz"}
    };
    void helper(string digits, int current_digit, string str, vector<string> &result) {
        if(current_digit < digits.size()){
            for(char ch : digits_chars[digits[current_digit] - '0' - 2])
                helper(digits, current_digit + 1, str + ch, result);
        }else{
            result.push_back(str);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(!digits.empty())
            helper(digits, 0, "", result);
        return result;
    }
};