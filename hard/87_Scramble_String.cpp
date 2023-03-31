class Solution {
public:
    bool isScrambleRec(const string &s1, const string &s2, unordered_map<string, bool> &mem) {
        string key = s1 + ' ' + s2;
        if(mem.find(key) != mem.end())
            return mem[key];
        if(s1.size() != s2.size())
            return mem[key] = false;
        if(s1 == s2)
            return mem[key] = true;
        int n = s1.size();
        if(n == 1)
            return mem[key] = false;
        for(int i = 1; i < n; ++i) {
            // swapped
            if(isScrambleRec(s1.substr(0, i), s2.substr(0, i), mem) &&
               isScrambleRec(s1.substr(i), s2.substr(i), mem))
                return mem[key] = true;
            // not sawpped
            if(isScrambleRec(s1.substr(0, i), s2.substr(n - i), mem) &&
               isScrambleRec(s1.substr(i), s2.substr(0, n - i), mem))
                return mem[key] = true;
        }
        return mem[key] = false;
    }
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> mem;
        return isScrambleRec(s1, s2, mem);
    }
};