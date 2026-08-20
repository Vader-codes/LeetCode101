class Solution {
public:
int dp[201][201];
int solve(vector<vector<int>>&grid, int row, int col , int n, int m ){
    // base case
    if(row >= n || col >= m)return INT_MAX;

    if(row == n-1 && col == m-1){
         return grid[row][col];
    }
    if(dp[row][col] != -1)return dp[row][col];

    return dp[row][col] = grid[row][col] + min(solve(grid, row+1, col, n,m), solve(grid, row, col+1, n, m));
}
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
       return solve(grid, 0, 0, n, m);
       
    }
};