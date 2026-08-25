class Solution {
public:
int n;
int dp[30001][2];
int solve(vector<int>&arr, int day, bool canBuy){
    // base case
    if(day == n)return 0;
    if(dp[day][canBuy] != -1)return dp[day][canBuy];
    int profit =0;
    // case 1 cany buy
    if(canBuy){
        //option 1 lets buy today or not buy today
        profit = max(-arr[day] + solve(arr, day+1, false), solve(arr, day+1, true));
        
    }
    else{
      // either sell or not sell
      profit = max(arr[day] + solve(arr, day+1, true), solve(arr, day+1, false));
    }
    return dp[day][canBuy]=profit;

      
}
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, true);
    }
};