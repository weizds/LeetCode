class Solution {
public:
    bool dfs(const string& a, const string& b, unordered_set<string>& visited, double& val) {
        visited.insert(a);
        for(auto v : graph[a]) {
            if(visited.find(v) != visited.end())
                continue;
            val *= mp[a + "/" + v];
            if(v == b)
                return true;
            if(dfs(v, b, visited, val))
                return true;
            val /= mp[a + "/" + v];
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); ++i) {
            mp[equations[i].front() + "/" + equations[i].back()] = values[i];
            mp[equations[i].back() + "/" + equations[i].front()] = 1/values[i];
            graph[equations[i].front()].push_back(equations[i].back());
            graph[equations[i].back()].push_back(equations[i].front());
        }
        vector<double> res;
        for(const auto &query : queries) {
            if(graph.find(query.front()) == graph.end() || graph.find(query.back()) == graph.end()) {
                res.push_back(-1);
                continue;
            }
            if(query.front() == query.back()) {
                res.push_back(1);
                continue;
            }
            unordered_set<string> visited;
            double val = 1;
            if(dfs(query.front(), query.back(), visited, val)) {
                res.push_back(val);
                graph[query.front()].push_back(query.back());
                graph[query.back()].push_back(query.front());
                mp[query.front() + "/" + query.back()] = val;
                mp[query.back() + "/" + query.front()] = 1/val;
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }
private:
    unordered_map<string, double> mp;
    unordered_map<string, vector<string>> graph;
};