class Solution {
    private:
    int solve( vector<vector<int>>&adj, vector<int>& informTime, int head ){
        int time=0;

        for(auto &n : adj[head]){
             time = max(time , solve(adj, informTime, n));
        }
        return informTime[head]+time;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // step 1. make an adjeacenc list for all the emptloyes like who knows who
        vector<vector<int>>adj(n);
        int head =-1;
        for(int i=0; i<n; i++){
            int e1 = i;
            int e2 = manager[i];
            if(e2 == -1){
              continue;
            }
            else{
                adj[e2].push_back(e1);
            }

        }
        int time = solve(adj,  informTime, headID);

        return time;

    }
};