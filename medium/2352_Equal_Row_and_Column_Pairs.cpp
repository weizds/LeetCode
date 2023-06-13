class Solution {
public:
    string convertInt(int val) {
        if(val == 0)
            return "0#";
        string res;
        while((val & 0xFF) != 0) {
            res.push_back((char)(val & 0xFF));
            val = val >> 8;
        }
        res.push_back('#');
        return res;
    }
    string convertRow(const vector<vector<int>>& grid, int row) {
        string res;
        for(int i = 0; i < grid.size(); ++i) {
            res.append(convertInt(grid[row][i]));
        }
        return res;
    }
    string convertCol(const vector<vector<int>>& grid, int col) {
        string res;
        for(int i = 0; i < grid.size(); ++i)
            res.append(convertInt(grid[i][col]));
        return res;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> hash_map;
        for(int i = 0; i < n; ++i) {
            ++hash_map[convertRow(grid, i)];
        }
        int res = 0;
        for(int i = 0; i < n; ++i) {
            auto found = hash_map.find(convertCol(grid, i));
            if(found != hash_map.end())
                res += found->second;
        }
        return res;
    }
};