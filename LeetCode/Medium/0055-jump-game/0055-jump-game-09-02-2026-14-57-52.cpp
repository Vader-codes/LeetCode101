class Solution {
public:
int dp[10001];
bool solve(vector<int>&arr, int idx, int n){
    if(idx == n-1)return true;

    if(dp[idx] != -1)return dp[idx];

    for(int i=1; i<=arr[idx]; i++){

        int newIdx = idx+i;
        if(newIdx < n && solve(arr, newIdx, n)){
            return dp[idx] = true;
        }
    }
    return dp[idx] = false;
}
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, n);
    }
};