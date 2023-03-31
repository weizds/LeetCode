class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> actual;
        for(auto &e : emails) {
            int at_position = e.find('@');
            bool skip = false;
            bool domain = false;
            int j = 0;
            for(int i = 0; i < e.size(); ++i) {
                if(e[i] == '.' && !domain)
                    continue;
                if(e[i] == '+' && !domain)
                    skip = true;
                if(e[i] == '@'){
                    domain = true;
                    skip = false;
                }
                if(!skip) {
                    e[j] = e[i];
                    ++j;
                }
            }
            e.resize(j);
            actual.insert(e);
        }
        return actual.size();
    }
};