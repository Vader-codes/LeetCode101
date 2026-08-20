class Solution {
    int solve(vector<vector<int>>&grid, int row, int col, int n, int m,   vector<vector<int>>&dp){
        // base case

        if(row >=n || col >= m)return 0;
        if(grid[row][col] == 1)return 0;
        if(row == n-1 && col == m-1)return 1;

        if(dp[row][col] != -1)return dp[row][col];
        return dp[row][col] = solve(grid, row+1, col, n, m, dp )+solve(grid, row , col+1, n, m, dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(obstacleGrid, 0, 0, n,m, dp);
    }
};