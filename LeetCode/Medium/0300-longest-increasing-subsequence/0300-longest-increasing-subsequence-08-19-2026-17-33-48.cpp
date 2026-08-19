class Solution {
    private:
    int solve(vector<int>&nums, int idx, int prevIdx,  vector<vector<int>>&dp){
        // base case
        if(idx >= nums.size())return 0;
        if(dp[idx][prevIdx+1] != -1)return dp[idx][prevIdx+1];
        // two options take not take
        // not take
        int notTake = solve(nums, idx+1, prevIdx, dp);
        // lets take only if it is increasing
        int take = 0;
        if( prevIdx == -1 || nums[idx] > nums[prevIdx]){
            take = 1+solve(nums, idx+1, idx, dp);
        }

        return dp[idx][prevIdx+1] = max(take ,notTake);

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1,-1));
        return solve(nums, 0, -1 , dp);
    }
};