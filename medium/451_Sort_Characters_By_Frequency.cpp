class Solution {
public:
    string frequencySort(string s) {
        vector<int> count(75, 0);
        for(auto ch : s)
            ++count[ch - '0'];
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < count.size(); ++i)
            if(count[i] > 0)
                pq.push({count[i], '0' + i});
        string res;
        while(!pq.empty())
            res.append(pq.top().first, pq.top().second), pq.pop();
        return res;
    }
};