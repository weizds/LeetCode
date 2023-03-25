class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int> > st;
        int max_area = 0;
        int n = heights.size();
        for(int i = 0; i < n; ++i){
            int start = i;
            while(!st.empty() && st.top().first > heights[i]){
                max_area = max(max_area, st.top().first * (i - st.top().second));
                start = st.top().second;
                st.pop();
            }
            st.push({heights[i], start});
        }
        while(!st.empty()){
            int h = st.top().first;
            int i = st.top().second;
            if(h * (n - i) > max_area)
            max_area = h * (n - i);
            st.pop();
        }
        return max_area;
    }
};