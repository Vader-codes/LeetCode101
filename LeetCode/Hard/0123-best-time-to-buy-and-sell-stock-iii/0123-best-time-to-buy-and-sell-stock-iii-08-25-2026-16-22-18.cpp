class Solution {
public:
int n;
int dp[100001][2][3];
int solve(vector<int>&arr, int day, bool canBuy, int cap){
    if(cap == 0 || day >= n)return 0;

    int profit =0;
    if(dp[day][canBuy][cap] != -1)return dp[day][canBuy][cap];

    if(canBuy){
        // either buy or not buy
        profit = max(-arr[day] + solve(arr, day+1, false , cap), solve(arr, day+1, true, cap));
    }
    else{
        // can sell or not to sell 
        profit = max(arr[day] + solve(arr, day+1, true, cap-1) , solve(arr, day+1, false, cap));
    }
    return dp[day][canBuy][cap] = profit;
}
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, true, 2);
    }
};