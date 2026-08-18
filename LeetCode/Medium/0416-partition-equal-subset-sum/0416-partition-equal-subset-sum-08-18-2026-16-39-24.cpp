class Solution {
private:
    bool helper(vector<int>& nums, int idx, int target, int sum,    vector<vector<int>>&dp) {       
        if(sum > target)return false;
        if (idx >= nums.size()) {
          return (sum == target);
             
        }
        
        if(dp[idx][sum] != -1)return dp[idx][sum];
      bool pick = helper(nums, idx+1, target, sum+nums[idx], dp);
      bool notPick = helper(nums, idx+1, target, sum, dp);

      return dp[idx][sum] = pick||notPick;
    }

public:
    bool canPartition(vector<int>& nums) {

        int total = 0;
        for (int x : nums)
            total += x;
        if (total % 2 != 0)
            return false; // odd sum cannot be partitioned
        int target = total/2;
            vector<vector<int>>dp(nums.size(), vector<int>(target+1, -1));

        return helper(nums, 0, target, 0, dp);
    }
};