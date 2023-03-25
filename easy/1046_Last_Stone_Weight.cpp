class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        while(q.size() > 1){
            int stone1 = q.top();
            q.pop();
            int stone2 = q.top();
            q.pop();
            q.push(abs(stone1 - stone2));
        }
        if(q.empty())
            return 0;
        else
            return q.top();
    }
};