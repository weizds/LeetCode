class Solution {
public:
    string getHint(string secret, string guess) {
        int count[10]{0};
        int cows = 0;
        for(auto num : secret)
            ++count[num - '0'];
        for(auto num : guess) {
            --count[num - '0'];
            if(count[num - '0'] >= 0)
                ++cows;
        }
        int bulls = 0;
        for(int i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i])
                ++bulls;
        }
        ostringstream oss;
        oss << bulls << "A" << cows - bulls << "B";
        return oss.str();
    }
};