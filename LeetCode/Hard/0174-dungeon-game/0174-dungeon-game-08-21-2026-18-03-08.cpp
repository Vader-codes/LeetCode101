class Solution {
public:
int n, m;
int dp[201][201];
int solve(vector<vector<int>>&dungeon, int row, int col){
    if(row >=n || col >= m)return INT_MAX;

    if(row == n-1 && col == m-1){
        if(dungeon[row][col] >0)return 1;

        return abs(dungeon[row][col])+1;
    }
    if(dp[row][col] != INT_MAX)return dp[row][col];

    int right = solve(dungeon, row, col+1);
    int down = solve(dungeon, row+1, col);

    int result = min(right, down)-dungeon[row][col];


    return dp[row][col] = result >0? result :1;
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n= dungeon.size();
        m = dungeon[0].size();
        for(int i=0; i<201; i++){
            for(int j=0; j<201; j++){
                dp[i][j] = INT_MAX;
            }
        }
        return solve(dungeon, 0, 0);
    }
};