class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant_q;
        queue<int> dire_q;
        for(int i = 0; i < senate.size(); ++i) {
            if(senate[i] == 'R')
                radiant_q.push(i);
            else
                dire_q.push(i);
        }
        while(!radiant_q.empty() && !dire_q.empty()) {
            int radiant = radiant_q.front();
            radiant_q.pop();
            int dire = dire_q.front();
            dire_q.pop();
            if(radiant < dire)
                radiant_q.push(radiant + n);
            else
                dire_q.push(dire + n);
        }
        if(!radiant_q.empty())
            return "Radiant";
        return "Dire";
    }
};