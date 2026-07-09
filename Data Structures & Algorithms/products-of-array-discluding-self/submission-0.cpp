class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());

        prefix[0] = 1;
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        suffix[nums.size() - 1] = 1;
        for(int i = (int)nums.size() - 2; i > -1; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < nums.size(); i++) {
            answer[i] = prefix[i] * suffix[i];
        }

        return answer;
    }
};
