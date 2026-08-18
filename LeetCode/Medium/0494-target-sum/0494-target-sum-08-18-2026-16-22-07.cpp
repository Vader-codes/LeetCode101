class Solution {
    int count =0;
    int total =0;
   

    int helper(vector<int>&arr, int idx, int target, int sum, vector<vector<int>>&dp){
        // baes case
       if(idx == arr.size()){
        if(target == sum)return 1;
        return 0;
       }
       if(dp[idx][sum+total] != -1)return dp[idx][sum+total];

        // for each idx we have two choices eiterh add + or -
      int plus =  helper(arr, idx+1, target, sum+arr[idx], dp);
      int minus =helper(arr, idx+1, target, sum-arr[idx], dp);
      
      return dp[idx][sum+total] = plus+minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        total =0;
        for(int x : nums) total+=x;
        vector<vector<int>>dp(21, vector<int>(2*total+1, -1));
        return helper(nums , 0, target, 0, dp);
       
    }
};