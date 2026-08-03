class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;
        
        // Edge cases
        if (abs(target) > sum) return 0;
        if ((sum + target) % 2 != 0) return 0;
        
        // Transform to subset sum problem
        // P - N = target, P + N = sum
        // So P = (sum + target) / 2
        int subsetSum = (sum + target) / 2;
        
        // Count subsets with sum = subsetSum
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1; // One way to get sum 0 (empty subset)
        
        for (int num : nums) {
            for (int i = subsetSum; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        
        return dp[subsetSum];
    }
};