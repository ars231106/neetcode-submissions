class Solution {
public:
     int findDuplicate(vector<int>& nums) {
    /*  Hashset Implementation

         unordered_set<int> st;
         for(int i = 0; i<nums.size(); i++){
              if(st.find(nums[i]) != st.end()){
                  return nums[i];
              }
              st.insert(nums[i]);
         } 
         return -1;  */

    //Floyd's Tortoise and Hare Algortihm (optimised)

        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);

        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
