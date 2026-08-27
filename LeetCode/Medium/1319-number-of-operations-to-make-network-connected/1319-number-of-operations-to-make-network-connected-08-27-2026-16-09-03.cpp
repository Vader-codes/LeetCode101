class Solution {
public:
void dfs(  vector<vector<int>>&adj, int node, vector<bool>&vis){
    vis[node] = true;

    for(auto &ne : adj[node]){
        if(!vis[ne]){
            dfs(adj, ne, vis);
        }
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1)return -1;

        vector<vector<int>>adj(n);
        for(auto &c : connections){
            int u = c[0];
            int v = c[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n, false);
        int components=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj, i, vis);
                components++;
            }
        }
        return components-1;

    }
};