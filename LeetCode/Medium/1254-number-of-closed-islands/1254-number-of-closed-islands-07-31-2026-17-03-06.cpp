class Solution {
    private:
    void dfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int row, int col){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

       int r[ ] = {-1, 1, 0, 0};
       int c[] ={0, 0, -1, 1};

       for(int i=0; i<4; i++){
         int nr = row+r[i];
         int nc = col+ c[i];

         if(nr >=0 && nr <n && nc>=0 && nc<m && grid[nr][nc] == 0 && !vis[nr][nc]){
            dfs(grid, vis, nr, nc);
         }
       }

        

    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n , vector<int>(m ,0 ));

        int islands =0;

        // explore left and right boundday if found an insland
        for(int i=0; i<n; i++){
            if(grid[i][0] == 0 && !vis[i][0])dfs(grid, vis, i, 0);

            if(grid[i][m-1] ==0 && !vis[i][m-1])dfs(grid, vis, i, m-1);
        }

        // top and bottom boundary
        for(int i=0; i<m; i++){
            if(grid[0][i] == 0 && !vis[0][i])dfs(grid, vis, 0, i);

            if(grid[n-1][i] == 0 && !vis[n-1][i])dfs(grid, vis, n-1, i);
        }
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                // we are skipping the first row col, and last row, col 
                if(grid[i][j] == 0 && !vis[i][j]){
                    islands++;
                    dfs(grid,vis, i,j);
                }
            }
        }




        return islands;

    }
};