class Solution {
    int dp[1001];

private:
    int solve(vector<int>& cost, int idx, int n) {

        if(idx >= n)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int takeOne = cost[idx] + solve(cost, idx + 1, n);
        int takeTwo = cost[idx] + solve(cost, idx + 2, n);

        return dp[idx] = min(takeOne, takeTwo);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        memset(dp, -1, sizeof(dp));

        return min(solve(cost, 0, n),
                   solve(cost, 1, n));
    }
};