class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        for(int i = 0; i<heights.size(); i++){
            int left = i-1;
            int right = i+1;
            int width = 1;
            int maxheight = heights[i];

            while(left >= 0 && heights[left] >= heights[i]){
                maxheight = heights[i];
                width = width + 1;
                left--;
            }

            while(right < heights.size() && heights[right] >= heights[i]){
                maxheight = heights[i];
                width = width + 1;
                right++;
            }

            int area = maxheight * width;
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};