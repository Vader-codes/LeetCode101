class Solution {
public:
int n;
int dp[5001][2];
 int solve(vector<int>&arr, int day, bool canBuy){
    //base case
    if(day >= n)return 0;

    int profit =0;
    if(dp[day][canBuy] != -1)return dp[day][canBuy];
    if(canBuy){
        profit = max(-arr[day] +solve(arr, day+1, false),solve(arr, day+1, true) );
    }
    else{
        profit = max(arr[day] + solve(arr, day+2, true), solve(arr, day+1, false));
    }
    return dp[day][canBuy] = profit;
 }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0,true);
    }
};