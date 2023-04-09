class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> q;
        q.push(0);
        int reachable = 0;
        while(!q.empty()) {
            auto current = q.front();
            q.pop();
            if(current == n - 1)
                return true;
            int start = max(current + minJump, reachable + 1);
            int end = min(current + maxJump, n - 1);
            for(int i = start; i <= end; ++i) {
                if(s[i] != '1')
                    q.push(i);
            }
            reachable = current + maxJump;
        }
        return false;
    }
};