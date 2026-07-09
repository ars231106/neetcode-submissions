class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /* brute force approach: 
        int left = 0;
        int right = numbers.size() - 1;

        vector<int> ans;

        for(int i = left; i<numbers.size(); i++){
            for(int j = right; j>=0; j--){
                if(i!=j && numbers[i] + numbers[j] == target){
                    ans.push_back(i + 1);
                    ans.push_back(j + 1);
                    return ans;
                }
            }
        }
        return ans; 
    */

    /* Optimal Approach (Two-Pointer): */
       
       int left = 0;
       int right = numbers.size() - 1;

       while(left < right){
           if(numbers[left] + numbers[right] == target){
                 return {left + 1, right + 1};
           }

           else if(numbers[left] + numbers[right] < target){
                 left++;
           }

           else{
                right--;
           }
       }

       return {};

    }
};
