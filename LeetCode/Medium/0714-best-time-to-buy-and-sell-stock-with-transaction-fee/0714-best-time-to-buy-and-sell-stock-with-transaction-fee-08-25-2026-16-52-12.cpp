class Solution {
public:
  int n;
  int dp[50001][2];
  int solve(vector<int>&arr, int day, bool canBuy, int fee){
    if(day >= n)return 0;

    int profit = 0;
    if(dp[day][canBuy] != -1)return dp[day][canBuy];
    if(canBuy){
        profit = max(-arr[day] + solve(arr, day+1, false, fee), solve(arr, day+1, true,fee));
    }
    else{
        profit = max(arr[day] - fee+solve(arr, day+1, true, fee), solve(arr, day+1, false, fee));
    }
    return dp[day][canBuy] = profit;
  }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();

        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, true, fee);
    }
};