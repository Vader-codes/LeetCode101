class Solution {
public:
 void topoSort(  vector<vector<int>>&adj,  vector<int>&indegree,    vector<int>&courses , int n){
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while( !q.empty()){
            int node = q.front();
            q.pop();
            courses.push_back(node);

            // now visit its neighbours;
            for(auto &ne : adj[node]){
                indegree[ne]--;
                if(indegree[ne] == 0)q.push(ne);
            }
        }
 }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n, 0);
        vector<int>courses;

        for(auto &p : prerequisites){
            int u = p[0];
            int v = p[1];

            // dependency is v -> u {a , b} b before a
            indegree[u]++;
            adj[v].push_back(u);

        }
        topoSort(adj, indegree, courses,n );
        return courses.size() == n ? courses : vector<int>{};
    }
};