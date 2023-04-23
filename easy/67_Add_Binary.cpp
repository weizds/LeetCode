class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.size() < b.size())
            swap(a, b);
        int carry = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(i < b.size())
                a[i] += b[i] - '0';
            a[i] += carry;
            carry = (a[i] - '0') / 2;
            a[i] = (a[i] - '0') % 2 ? '1' : '0';
        }
        if(carry > 0)
            a.push_back('1');
        reverse(a.begin(), a.end());
        return a;
    }
};