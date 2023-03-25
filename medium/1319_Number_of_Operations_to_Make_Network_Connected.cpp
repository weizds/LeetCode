class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
        int res = n - 1;
        for(auto con : connections) {
            res -= un(con[0], con[1]);
        }
        return res;
    }
    int find(int x) {
        while(x != parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    int un(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y)
            return 0;
        if(rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        if(rank[x] == rank[y])
            ++rank[x];
        return 1;
    }
private:
    vector<int> parent;
    vector<int> rank;
};