class Solution {
    private:
    int solve(vector<int>&days, vector<int>&costs, int idx,   vector<int>&dp){
        // base cae
        if(idx >= days.size())return 0;
        if(dp[idx] != -1)return dp[idx];

        // option 1 one day pass
        int cost1 = costs[0]+solve(days, costs, idx+1, dp);
        // option 2 7 day pass
        int i = idx;
        while(i < days.size() && days[i] < days[idx]+7)i++;

        int cost7 = costs[1]+solve(days, costs, i, dp);
        // for 30 day pass do the same thing
        i = idx;
        while(i < days.size() && days[i] < days[idx]+30 )i++;

        int cost30 = costs[2]+solve(days, costs, i, dp);

        return dp[idx] = min({cost1, cost7, cost30});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1, -1);
        return solve(days, costs, 0, dp);
    }
};