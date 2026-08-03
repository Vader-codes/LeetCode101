class Solution {
private:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& vis,
             vector<int>& pathvis, vector<int>& safeNode) {
        // mark as visited and pahtvisited
        vis[node] = 1;
        pathvis[node] = 1;

        // explore its neighbours
        for (auto& ne : adj[node]) {
            if (!vis[ne]) { // when nde is not visited
                if (dfs(adj, ne, vis, pathvis, safeNode) == true) {
                    // means cycle found
                    return true;
                }
            }
            // if node is visited and pathvis also means a cycle
            else if(pathvis[ne] == 1){
                return true;
            }
        }

        safeNode[node] = 1;
        pathvis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // create an adjacency list
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (auto& ne : graph[i]) {
                adj[i].push_back(ne);
            }
        }
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> safeNode(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(adj, i, vis, pathvis, safeNode);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (safeNode[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};