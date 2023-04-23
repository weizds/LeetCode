class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1) {
            int stone = pq.top();
            pq.pop();
            stone = abs(stone - pq.top());
            pq.pop();
            pq.push(stone);
        }
        return pq.top();
    }
};