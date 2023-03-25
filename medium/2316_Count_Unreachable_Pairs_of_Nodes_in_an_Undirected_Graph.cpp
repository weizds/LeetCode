class Solution {
public:
    int find(int v) {
        while(v != parent[v]){
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        return v;
    }
    void un(int v, int u) {
        v = find(v);
        u = find(u);
        if(v == u)
            return;
        parent[u] = v;
        rank[v] += rank[u];
        rank[u] = 0;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; ++i){
            parent[i] = i;
            rank[i] = 1;
        }
        for(auto e : edges) {
            un(e[0], e[1]);
        }
        long long res = 0;
        for(auto a : rank)
            if(a > 0)
                res += (long long)a * (n - a);
        return res / 2;
    }
private:
    vector<int> parent;
    vector<int> rank;
};