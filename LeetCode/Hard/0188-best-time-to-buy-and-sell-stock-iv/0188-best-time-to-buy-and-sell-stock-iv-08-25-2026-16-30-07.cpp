class Solution {
public:
 int n;
 int dp[1001][2][101];
 int solve(vector<int>arr, int day, bool canBuy, int cap ){
    // base case
    if( cap == 0 || day >= n)return 0;
    if(dp[day][canBuy][cap] != -1)return dp[day][canBuy][cap];
    int profit  =0;
    if(canBuy){
        // if can buy take max from buy or not buy
        profit = max(-arr[day] + solve(arr, day+1, false, cap), solve(arr,day+1, true, cap));
    }
    else{
        profit= max(arr[day] + solve(arr, day+1, true, cap-1), solve(arr, day+1, false, cap));
    }
    return dp[day][canBuy][cap] = profit;
 }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, true, k);
    }
};