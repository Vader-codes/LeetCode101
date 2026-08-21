class Solution {
public:
int dp[301][301];
    int n, m;
int solve(vector<vector<int>>& matrix, int row, int col){
    if(row >= n || col >= m)return 0;
    
    if(dp[row][col] != -1)return dp[row][col];
    if(matrix[row][col] == 0)return 0;

    int right = solve(matrix, row, col+1);
    int bottom = solve(matrix, row+1, col);
    int diagnol = solve(matrix, row+1, col+1);

    return dp[row][col] = 1+min({right, bottom, diagnol});
}
    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int result =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1){
                    result += solve(matrix, i, j);
                }
            }
        }
        return result;
    }
};