class Solution {
    private:
    vector<int>solve(vector<int>&nums, int idx, int prevIdx,  vector<vector<vector<int>>>&dp){
        if(idx >= nums.size())return {};

        if(!dp[idx][prevIdx+1].empty())return dp[idx][prevIdx+1];
        // not take
        vector<int>notTake = solve(nums, idx+1, prevIdx, dp);

        vector<int>take;
        if(prevIdx == -1 || nums[idx] % nums[prevIdx] == 0){
            take = solve(nums, idx+1, idx, dp);
            take.push_back(nums[idx]);
        }
        return dp[idx][prevIdx+1] = take.size() > notTake.size() ? take : notTake;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<vector<int>>>dp(nums.size()+1, vector<vector<int>>(nums.size()+2));
        return solve(nums, 0, -1, dp);
    }
};