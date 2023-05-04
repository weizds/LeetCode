class Solution {
public:
    int find(int node) {
        while(parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }
    void join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y)
            return;
        if(rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        if(rank[x] == rank[y])
            ++rank[x];
    }
    bool static compare(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for(int i = 0; i < queries.size(); ++i)
            queries[i].push_back(i);
        sort(edgeList.begin(), edgeList.end(), compare);
        sort(queries.begin(), queries.end(), compare);
        int edge = 0;
        vector<bool> res(queries.size());
        for(auto& query : queries) {
            int p = query[0];
            int q = query[1];
            int limit = query[2];
            int index = query[3];
            while(edge < edgeList.size() && edgeList[edge][2] < limit) {
                int v = edgeList[edge][0];
                int u = edgeList[edge][1];
                join(v, u);
                ++edge;
            }
            res[index] = find(p) == find(q);
        }
        return res;
    }
private:
    vector<int> parent;
    vector<int> rank;
};