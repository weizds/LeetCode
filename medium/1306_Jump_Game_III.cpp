class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        vector<bool> visited(arr.size(), false);
        int n = arr.size();
        while(!q.empty()) {
            auto current = q.front();
            q.pop();
            if(arr[current] == 0)
                return true;
            if(visited[current])
                continue;
            visited[current] = true;
            if(current + arr[current] < n)
                q.push(current + arr[current]);
            if(current - arr[current] >= 0)
                q.push(current - arr[current]);
        }
        return false;
    }
};