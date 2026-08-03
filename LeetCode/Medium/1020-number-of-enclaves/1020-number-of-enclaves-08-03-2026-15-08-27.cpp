class Solution {
    private:
    void dfs(vector<vector<int>>&grid, int row, int col){
         int n = grid.size(); // rows
        int m = grid[0].size(); // cols

        grid[row][col] = -1;
        
        int r[] = {0, 0, -1, 1};
        int c[] = {-1, 1, 0, 0};

        for(int i=0; i<4; i++){
            int nr = row+r[i];
            int nc = col+c[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == 1){
                dfs(grid, nr, nc);
            }
        }

    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); // rows
        int m = grid[0].size(); // cols


        for(int i=0; i<n; i++){
           if(grid[i][0] == 1)dfs(grid, i,0); // first col

           if(grid[i][m-1] == 1)dfs(grid, i, m-1);


        }
        for(int i=0; i<m; i++){
            if(grid[0][i] == 1) dfs(grid, 0,i );

            if(grid[n-1][i] == 1 )dfs(grid, n-1,i );
        }
        int land =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 )land++;
            }
        }

        return land;
    }
};