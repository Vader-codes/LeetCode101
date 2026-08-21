class Solution {
    int dp[201][201];
    private:
    int solve(vector<vector<int>>&triangle, int row,int col, int n){
        if(row == n-1)return triangle[row][col];

        if(dp[row][col] != INT_MAX)return dp[row][col];
        return dp[row][col] = triangle[row][col] + min(solve(triangle, row+1, col, n), solve(triangle, row+1, col+1,n));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = n;

        for(int i=0; i<201; i++){
            for(int j=0; j<201; j++){
                dp[i][j] = INT_MAX;
            }
        }
        return solve(triangle, 0,0, n);
    }
};