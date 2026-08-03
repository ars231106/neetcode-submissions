class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp[i][j] = min edits to convert word1[0..i-1] to word2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Base cases
        for (int i = 0; i <= m; i++) dp[i][0] = i;  // Delete all
        for (int j = 0; j <= n; j++) dp[0][j] = j;  // Insert all
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // No operation needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Insert, Delete, Replace
                    dp[i][j] = 1 + min({
                        dp[i][j - 1],      // Insert
                        dp[i - 1][j],      // Delete
                        dp[i - 1][j - 1]   // Replace
                    });
                }
            }
        }
        
        return dp[m][n];
    }
};