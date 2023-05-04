class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size())
            swap(num1, num2);
        int j = num2.size() - 1;
        int carry = 0;
        for(int i = num1.size() - 1; i >= 0; --i, --j) {
            int val = num1[i] - '0' + carry;
            if(j >= 0)
                val += num2[j] - '0';
            carry = val / 10;
            num1[i] = (val % 10) + '0';
        }
        if(carry > 0)
            num1.insert(0, 1, carry + '0');
        return num1;
    }
};