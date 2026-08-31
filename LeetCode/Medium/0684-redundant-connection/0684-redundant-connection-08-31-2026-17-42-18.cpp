class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int p, int c,
             int node) {
        // makr the node as visited
        vis[node] = true;

        // now traverese the neighnour but skip the p ->c or c->p;
        for (auto& ne : adj[node]) {
            // must be unvisited
            if (vis[ne] == false) {
                // p->c
                if (node == p && ne == c)
                    continue;
                else if (node == c && ne == p)
                    continue;
                else
                    dfs(adj, vis, p, c, ne);
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int x = -1;
        int y = -1;
        // no of nodes we have n
        // we have to make adjacency list skipping every edge only once
        // and try to move to the graph if we could visit all the n nodes
        // the edge was redundant add to the answer
        // let's build adjavecny first
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            // it is a two -way graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (auto& e : edges) {
            int parent = e[0];
            int child = e[1];

            // we have to skip this and see can we visit all the n nodes
            vector<bool> vis(n + 1, false);

            // call dfs and do a simple traversal
            int count = 0;
            for (int i = 1; i <= n; i++) {
                if (vis[i] == false) {
                    dfs(adj, vis, parent, child, i);
                    count++;
                }
            }
            // if the count is 1 that measn without the parent , child node
            // we were able to visit all n nodes in 1 traversal
            // that makes it the reduncant
            if (count == 1) {
                x = parent;
                y = child;
            }
        }
        return {x, y};
    }
};