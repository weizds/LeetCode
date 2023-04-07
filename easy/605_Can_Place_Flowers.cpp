class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        for(int i = 0; i < size; ++i) {
            if(flowerbed[i] == 1)
                continue;
            int left = i > 0 ? flowerbed[i - 1] : 0;
            int right = i + 1 < size ? flowerbed[i + 1] : 0;
            if(left == 0 && right == 0) {
                flowerbed[i] = 1;
                ++count;
            }
        }
        return count >= n;
    }
};