class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, const string& word, int idx, int row, int col) {
        // Base case: matched entire word
        if (idx == word.length()) {
            return true;
        }
        
        // Boundary check and early termination
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return false;
        }
        
        // Character mismatch - prune immediately
        if (board[row][col] != word[idx]) {
            return false;
        }
        
        // Mark as visited to avoid reusing
        char original = board[row][col];
        board[row][col] = '#';
        
        // Explore 4 directions
        bool found = dfs(board, word, idx + 1, row - 1, col) ||
                     dfs(board, word, idx + 1, row + 1, col) ||
                     dfs(board, word, idx + 1, row, col - 1) ||
                     dfs(board, word, idx + 1, row, col + 1);
        
        // Backtrack: restore cell
        board[row][col] = original;
        
        return found;
    }
};