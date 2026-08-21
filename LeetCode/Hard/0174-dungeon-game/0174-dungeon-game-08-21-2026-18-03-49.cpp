class Solution {
public:
    int n, m;
    int dp[201][201];

    int solve(vector<vector<int>>& dungeon, int row, int col) {

        // Out of bounds -> invalid path
        if(row >= n || col >= m)
            return INT_MAX;

        // Base case: princess cell
        // We need at least 1 HP after entering this cell.
        if(row == n-1 && col == m-1) {

            // Positive cell -> need only 1 HP
            if(dungeon[row][col] > 0)
                return 1;

            // Negative cell -> need enough HP to survive it
            return abs(dungeon[row][col]) + 1;
        }

        // If already calculated, return stored answer
        if(dp[row][col] != INT_MAX)
            return dp[row][col];

        // Find minimum HP required from the two possible directions
        int right = solve(dungeon, row, col+1);
        int down = solve(dungeon, row+1, col);

        // Choose the path requiring less HP
        int result = min(right, down) - dungeon[row][col];

        // Health can never become 0 or negative,
        // so minimum required health is always at least 1
        return dp[row][col] = result > 0 ? result : 1;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        n = dungeon.size();
        m = dungeon[0].size();

        // Initialize DP with INT_MAX = "not calculated"
        for(int i = 0; i < 201; i++) {
            for(int j = 0; j < 201; j++) {
                dp[i][j] = INT_MAX;
            }
        }

        // Minimum HP required when entering (0,0)
        return solve(dungeon, 0, 0);
    }
};