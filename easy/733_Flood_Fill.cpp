class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int new_color) {
        if(r < 0 || r >= image.size() || c < 0 || c >= image.back().size())
            return;
        if(image[r][c] != color)
            return;
        image[r][c] = new_color;
        int dirs[]{1, 0, -1, 0, 1};
        for(int i = 0; i < 4; ++i)
            dfs(image, r + dirs[i], c + dirs[i + 1], color, new_color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};