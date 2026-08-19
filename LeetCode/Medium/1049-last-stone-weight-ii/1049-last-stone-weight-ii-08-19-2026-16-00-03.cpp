class Solution {
private:
int solve(vector<int>&stones, int idx, int target,   vector<vector<int>>&dp){
    // base case
    if(idx >= stones.size())return 0;
    if(dp[idx][target] != -1)return dp[idx][target];

    int notTake = solve(stones, idx+1, target ,dp);
    int take = 0;
    if(stones[idx] <= target){
        take = stones[idx]+solve(stones, idx+1, target-stones[idx], dp);
    }

   return  dp[idx][target] =max(take, notTake);
}
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int total =0;
        for(int x : stones)total+=x;


        int target = total/2;
        vector<vector<int>>dp(stones.size()+1, vector<int>(target+1, -1));

        // we want a group of stones that weights as close to target
        // now find the best posssible gruop of stones
        int group1 = solve(stones, 0, target,dp);

        int group2 = total-group1;

        return group2-group1;

    }
};