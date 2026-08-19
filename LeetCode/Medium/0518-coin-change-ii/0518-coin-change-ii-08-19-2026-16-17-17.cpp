class Solution {
    private:
int solve(vector<int>&coins,int idx, int amount,   vector<vector<int>>&dp){
    // base case
    if(amount == 0)return 1;
    if(idx >= coins.size() )return 0;

    // check if the answer already exists
    if(dp[idx][amount] != -1)return dp[idx][amount];
    //lets skip the current coin
    int notTake = solve(coins, idx+1, amount, dp);
    int take = 0;
    // well we can take the current coin only if coin <= ammount
    if(coins[idx] <= amount){
        take = solve(coins, idx , amount-coins[idx], dp);
    }
        return dp[idx][amount] = take+notTake;
}
public:
    int change(int amount, vector<int>& coins) {
             // it is sam e as take not take but with infinite supply 
        // means we can take something as much as we want
        if(amount ==0)return 1;
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        int ans = solve(coins,0, amount, dp);
        return ans == INT_MAX/2 ? 0 : ans;
    }
};