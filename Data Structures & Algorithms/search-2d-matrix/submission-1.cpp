class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int list1 = matrix.size();
        int list2 = matrix[0].size();

        int left = 0;
        int right = list1*list2 - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;;

            int i = mid / list2;
            int j = mid % list2;

            if(matrix[i][j] == target){
                return true;
            } 

            else if(matrix[i][j] < target){
                left = mid + 1;
            }

            else{
                right = mid - 1;
            }
        }
        return false;
    }
};