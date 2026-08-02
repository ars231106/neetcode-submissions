class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>>& grid, int n , int m){
         if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] == 1 || grid[i][j] != '1'){
            return;
         }

         visited[i][j] = 1;
         //recursively call dfs over top, bottom, left and right cells
         dfs(i-1, j, visited, grid, n, m); //top
         dfs(i+1, j,visited, grid, n , m); //bottom
         dfs(i, j-1, visited, grid, n, m); //left
         dfs(i, j+1, visited, grid, n, m); //right
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        vector<vector<int>> visited(m, vector<int>(n,0));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    islands++;
                    dfs(i, j, visited, grid, n, m);
                }
            }
        }

        return islands;
    }
};