class Solution {
    private:
    void dfs(vector<vector<int>>&grid, int row, int col, vector<vector<int>>&vis){
         int n = grid.size(); // rows
        int m = grid[0].size(); // cols

        vis[row][col] = 1;
        
        int r[] = {0, 0, -1, 1};
        int c[] = {-1, 1, 0, 0};

        for(int i=0; i<4; i++){
            int nr = row+r[i];
            int nc = col+c[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == 1 && !vis[nr][nc]){
                dfs(grid, nr, nc, vis);
            }
        }

    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); // rows
        int m = grid[0].size(); // cols

        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
           if(grid[i][0] == 1 && !vis[i][0])dfs(grid, i,0, vis); // first col

           if(grid[i][m-1] == 1 && !vis[i][m-1])dfs(grid, i, m-1, vis);


        }
        for(int i=0; i<m; i++){
            if(grid[0][i] == 1 && !vis[0][i])dfs(grid, 0,i,vis );

            if(grid[n-1][i] == 1 && !vis[n-1][i])dfs(grid, n-1,i,vis );
        }
        int land =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j])land++;
            }
        }

        return land;
    }
};