class Solution {
private:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& vis,
             vector<int>& pathvis, vector<int>& safeNode) {
        // mark as visited and pahtvisited
        vis[node] = 1;
        pathvis[node] = 1;

        // explore its neighbours
        for (auto& ne : adj[node]) {
            // if the negibour is not visted go and check it out..
            if (!vis[ne]) {
                if (dfs(adj, ne, vis, pathvis, safeNode) == false) {
                    pathvis[ne] = 0;
                    return false;
                }

            }
            // neighbout is visited and also path vis means not a part of this
            // path
            else if (vis[ne] == 1 && pathvis[ne] == 1) {
                pathvis[ne] = 0;
                return false;
            }
            // what if the child is not safe
            else if (safeNode[ne] == 0) {
                pathvis[ne] = 0;
                return false;
            }
        }

        safeNode[node] = 1;
        pathvis[node] = 0;
        return true;
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