class Solution {
public:
int topoSort( vector<vector<int>>&adj,  vector<int>&indegree , int n){
    int count =0;
    queue<int>q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            count++;
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        // check its neighbours
        for(auto &ne : adj[node]){
            indegree[ne]--;
            if(indegree[ne] ==0){
                q.push(ne);
                count++;
            }

        }
    }
    return count == n;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n, 0);
        for(auto &p : prerequisites){
            int u = p[0];
            int v = p[1];
            //  v --> u
            indegree[u]++;
            adj[v].push_back(u);
        }
        return topoSort(adj, indegree, n);
    }
};