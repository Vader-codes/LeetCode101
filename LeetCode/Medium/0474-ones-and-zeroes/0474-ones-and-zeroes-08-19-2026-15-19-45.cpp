class Solution {
    int solve(vector<string>&strs, int idx, int m, int n,  vector<vector<vector<int>>>&dp){
        // it is a simple knapsack problem take or not take
        // base case reacht to end return 0;
        if(idx >= strs.size())return 0;
       if(dp[idx][m][n] != -1)return dp[idx][m][n];


        // we are skipping 
        int notTake = solve(strs, idx+1, m,n, dp);

        // lets decide to take 
       // before that lets count the no of zeros and ones in the given string at idx
       int zero =0, one=0;
       for(char c : strs[idx]){
        if(c == '0')zero++;
        else one++;
       }
       // now we can only take at most m zero and n one lets check if
       int take =0;
       if(zero<=m && one<=n){
        // we can take it now
        take = 1+solve(strs, idx+1, m-zero, n-one, dp);
       }
        return dp[idx][m][n] = max(notTake, take);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int k = strs.size();
        vector<vector<vector<int>>>dp(k+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        return solve(strs, 0, m, n, dp);
    }
};