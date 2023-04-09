class Solution {
public:
    int calc_gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid.back().size();
        if(k == 0 || (n * m) == 1)
            return grid;
        k %= n * m;
        int gcd = calc_gcd(n * m, k);
        for(int i = 0; i < gcd; ++i) {
            int tmp = grid[i/m][i%m];
            for(int j = i + k; j != i; j = (j + k) % (n * m))
                swap(grid[j/m][j%m], tmp);
            swap(grid[i/m][i%m], tmp);
        }
        return grid;
    }
};