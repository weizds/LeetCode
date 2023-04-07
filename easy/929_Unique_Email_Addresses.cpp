class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> actual;
        for(auto &email : emails) {
            int j = 0;
            int at_position = email.find('@');
            for(int i = 0; i < at_position; ++i) {
                if(email[i] == '+')
                    break;
                if(email[i] == '.')
                    continue;
                email[j] = email[i];
                ++j;
            }
            for(int i = at_position; i < email.size(); ++i) {
                email[j] = email[i];
                ++j;
            }
            email.resize(j);
            actual.insert(email);
        }
        return actual.size();
    }
};