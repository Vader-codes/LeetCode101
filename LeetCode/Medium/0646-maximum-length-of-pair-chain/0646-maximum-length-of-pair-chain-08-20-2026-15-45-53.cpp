class Solution {
    int solve(vector<vector<int>>&pairs, int idx ,int prev,   vector<vector<int>>&dp){
            // base case
            if(idx >= pairs.size())return 0;

            // two options either take or not to take
            if(dp[idx][prev+1] != -1)return dp[idx][prev+1];
            int notTake = solve(pairs, idx+1, prev, dp);
            int take =0;

            // only take if it is icreasing
            if(prev == -1 || pairs[idx][0] > pairs[prev][1]){
                take = 1+solve(pairs, idx+1, idx, dp);
            }
            return dp[idx][prev+1] = max(take, notTake);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>>dp(n+1, vector<int>(n+2, -1));
        return solve(pairs, 0 , -1, dp);

    }
};