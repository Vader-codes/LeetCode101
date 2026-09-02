class Solution {
public:
int dp[10001];
int solve(vector<int>&arr, int idx, int n){
    if(idx == n-1)return 0;
    
    int ans = INT_MAX;
    if(dp[idx] != -1)return dp[idx];

    /// try all the jumps form 1 to arr[idx];
    for(int i=1; i<=arr[idx]; i++){
        int next = idx + i;
        if(next < n){
            int subAns = solve(arr, next, n);
            if(subAns != INT_MAX){
                ans = min(ans, 1+subAns);
            }
        }
    }
    return  dp[idx]= ans;
}
    int jump(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, n);
    }
};