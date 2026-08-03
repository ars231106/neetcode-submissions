class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;
        
        // If sum is odd, can't partition
        if (total % 2 != 0) return false;
        
        int target = total / 2;
        
        // dp[i] = true if sum i is achievable
        vector<bool> dp(target + 1, false);
        dp[0] = true; // sum 0 is always possible (empty subset)
        
        for (int num : nums) {
            // Traverse from right to left to avoid using same element twice
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        
        return dp[target];
    }
};