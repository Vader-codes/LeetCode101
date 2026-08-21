class Solution {
public:
  int dp[51][51][51][51];
 
    int n, m;
    int solve(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        // base case
        if (r1 >= n || r2 >= n || c1 >= m || c2 >= m)
            return INT_MIN;
        // Thorn
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        // destination
        if (r1 == n - 1 && c1 == m - 1 && r2 == n - 1 && c2 == m - 1)
            return grid[r1][c1];


        if(dp[r1][c1][r2][c2] != -2)return dp[r1][c1][r2][c2];
        int cherries = 0;
        if (r1 == r2 && c1 == c2)
            cherries += grid[r1][c1];
        else
            cherries += grid[r1][c1] + grid[r2][c2];
        // two person starting to collect the cherreis their positions can be

        int p1 = solve(grid, r1, c1 + 1, r2, c2 + 1); // both move to the right
        int p2 = solve(grid, r1 + 1, c1, r2 + 1, c2); // both moving to the down
        int p3 = solve(grid, r1, c1 + 1, r2 + 1,
                       c2); // one is moving right other down
        int p4 = solve(grid, r1 + 1, c1, r2,
                       c2 + 1); // one is moving down other right

        cherries += max({p1, p2, p3, p4});
        return dp[r1][c1][r2][c2] =cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
         
         for(int i=0; i<51; i++)
         for(int j=0; j<51; j++)
         for(int k=0; k<51; k++)
         for(int l=0; l<51; l++)
         dp[i][j][k][l] = -2;
         
        return max(0, solve(grid, 0, 0, 0, 0));
    }
};