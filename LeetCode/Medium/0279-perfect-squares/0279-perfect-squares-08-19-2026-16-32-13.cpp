class Solution {
private:
int solve(int n, int num, int sum,  vector<vector<int>>&dp){
    // base case
    if(sum == n)return 0;
    if(sum > n || num*num > n)return INT_MAX/2;
    
    if(dp[num][sum] != -1)return dp[num][sum];
    // lets not take the sqaure of this number
    int notTake = solve(n, num+1, sum, dp);

    int take = INT_MAX/2;
    // when can we take if its square <= n and we can take it as much as we want
    if(num*num <= n){
        take = 1+solve(n, num, sum+(num*num), dp);
    }
    return dp[num][sum] = min(take, notTake);
}
public:
    int numSquares(int n) {
        int maxNum = sqrt(n);
        vector<vector<int>>dp(maxNum+1, vector<int>(n+1, -1));
        return solve(n, 1, 0, dp);
    }
};