class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        unordered_map<int, int> memo; // Map: (row * cols + col) -> length
        
        int maxLen = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maxLen = max(maxLen, dfs(matrix, i, j, memo, cols));
            }
        }
        
        return maxLen;
    }
    
private:
    int dfs(vector<vector<int>>& matrix, int row, int col, unordered_map<int, int>& memo, int cols) {
        if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size()) {
            return 0;
        }
        
        int key = row * cols + col;
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        int current = matrix[row][col];
        int maxLen = 1;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (auto& dir : dirs) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            
            if (newRow >= 0 && newRow < matrix.size() && 
                newCol >= 0 && newCol < matrix[0].size() && 
                matrix[newRow][newCol] > current) {
                
                maxLen = max(maxLen, 1 + dfs(matrix, newRow, newCol, memo, cols));
            }
        }
        
        memo[key] = maxLen;
        return maxLen;
    }
};