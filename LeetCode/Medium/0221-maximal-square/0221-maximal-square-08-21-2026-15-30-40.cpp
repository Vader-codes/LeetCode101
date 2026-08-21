class Solution {
    int dp[301][301];
    int solve(vector<vector<char>>& matrix, int row ,int col, int &maxi){
        if(row >= matrix.size() || col >= matrix[0].size())return 0;

        if(dp[row][col] != -1)return dp[row][col];
        int diagnol = solve(matrix, row+1, col+1, maxi);
        int right = solve(matrix, row, col+1, maxi);
        int bottom = solve(matrix, row+1, col, maxi);
   
        if(matrix[row][col] == '1'){
            int ans = 1+min(diagnol, min(right, bottom));
            maxi = max(maxi, ans);
            return dp[row][col] = ans;
        }
         return dp[row][col]= 0;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        memset(dp, -1, sizeof(dp));
         solve(matrix, 0, 0, maxi);
         return maxi*maxi;
    }
};