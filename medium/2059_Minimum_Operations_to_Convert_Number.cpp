class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        q.push(start);
        vector<int> dist(1001, 0xFFFFFFF);
        dist[start] = 0;
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            for(auto num : nums) {
                if((current + num == goal) || (current - num == goal) || ((current ^ num) == goal))
                    return dist[current] + 1;
            if((current + num >= 0) && (current + num <= 1000) && (dist[current + num] > dist[current] + 1)){
                dist[current + num] = dist[current] + 1;
                q.push(current + num);
            }
            if((current - num >= 0) && (current - num <= 1000) && (dist[current - num] > dist[current] + 1)){
                dist[current - num] = dist[current] + 1;
                q.push(current - num);
            } 
                if(((current ^ num) >= 0) && ((current ^ num) <= 1000) && 
                (dist[current ^ num] > dist[current] + 1)){
                    dist[current ^ num] = dist[current] + 1;
                    q.push(current ^ num);
                }
            }
        }
        return -1;
    }
};