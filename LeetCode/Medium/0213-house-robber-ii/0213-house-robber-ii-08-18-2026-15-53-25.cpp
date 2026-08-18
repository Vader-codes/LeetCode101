class Solution {
    private:
    int dp1[101];
    int dp2[101];
    int helper(vector<int>&nums, int idx, int n , int dp[]){
        // base case
        if(idx >=n)return 0;
        // check if the result already exists or not
        if(dp[idx] != -1)return dp[idx];
        // it is a pick or not to pick
       

        // rob the current house and move 
        int pick =  nums[idx] + helper(nums, idx+2, n, dp);

        // not to rob the house
        int notPick = helper(nums, idx+1, n, dp);
        return  dp[idx] = max(pick , notPick);
    }
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if( n == 1)return nums[0];
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        
        int c1 = helper(nums, 0, n-1, dp1);
        int c2 =  helper(nums, 1, n, dp2);

        return max(c1, c2);
    }
};