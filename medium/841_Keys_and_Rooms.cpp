class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int room, vector<bool>& visited, int& count) {
        if(visited[room])
            return;
        visited[room] = true;
        ++count;
        for(auto key : rooms[room])
            if(!visited[key])
                dfs(rooms, key, visited, count);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        int count = 0;
        dfs(rooms, 0, visited, count);
        return count == n;
    }
};