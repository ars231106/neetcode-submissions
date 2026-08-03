class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;  // 0 jumps to reach index 0
        
        for (int i = 0; i < n - 1; i++) {
            if (dp[i] == INT_MAX) continue;  // Can't reach this index
            
            // From index i, we can jump to i+1, i+2, ..., i+nums[i]
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n) {
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
                }
            }
        }
        
        return dp[n - 1];
    }
};