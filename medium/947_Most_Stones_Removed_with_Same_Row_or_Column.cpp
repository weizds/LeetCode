class Solution {
public:
    int find(int x) {
        if(parent.find(x) == parent.end()) {
            parent[x] = x;
            ++islands;
        }
        while(x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if(x != y) {
            parent[y] = x;
            --islands;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        for(auto &stone : stones) {
            uni(stone.front(), stone.back() + 10001);
        }
        return stones.size() - islands;
    }
private:
    unordered_map<int, int> parent;
    int islands{0};
};