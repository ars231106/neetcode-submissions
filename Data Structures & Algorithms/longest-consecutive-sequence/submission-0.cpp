class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs;
        for(int i = 0; i<nums.size(); i++){
            hs.insert(nums[i]);
        }

        int longest = 0;

        for(int element : hs){
            if(hs.find(element - 1) == hs.end()){
                int curr_longest_seq = 1;
                int temp = element;
                
                while(hs.find(temp + 1) != hs.end()){
                    temp += 1;
                    curr_longest_seq += 1;
                }
                longest = max(longest, curr_longest_seq);
            }
        }

        return longest;
    }
};
