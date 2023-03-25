class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left != right){
            if(height[left] >= height[right]){
                if(height[right] * (right - left) > max_area)
                    max_area = height[right] * (right - left);
                right--;
            }else{
                if(height[left] * (right - left) > max_area)
                    max_area = height[left] * (right - left);
                left++;
            }
        }
        return max_area;
    }
};