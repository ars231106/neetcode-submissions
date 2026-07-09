class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxarea = 0;

        while(left < right){
            int h = min(heights[left], heights[right]);
            int w = right - left;
            maxarea = max(maxarea, h*w);

            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return maxarea;
    }
};
