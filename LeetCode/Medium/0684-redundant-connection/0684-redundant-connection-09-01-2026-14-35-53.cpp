class DSU{
    vector<int>parent;
    vector<int>rank;
    public:
    // consturctor of dsu
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);

        // now initailize parent and rank
        for(int i=1; i<=n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    // dsu only two functions find parent and union
    int find(int x){
        if(parent[x] == x)return x;
        // path compression
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        // first find three parents
        int px = find(x); // parrent of x px
        int py = find(y); // parent of y py
        // both are in same component
        if(px == py)return;

        // we need to merge accoring to the rank 
        // lowere rank mergers itself to higher rank
        if(rank[px] > rank[py]){
            parent[py] = px;
        }
         else if(rank[py] > rank[px]){
            parent[px] = py;
         }
         else{
            parent[px] = py;
            // both are equal need to incrase the rank where we attached 
            rank[py]++;
         }


    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n  = edges.size();
        DSU dsu(n);

        int x =-1, y=-1;
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            // find the parent of u and v 
            int pu = dsu.find(u);
            int pv = dsu.find(v);
        // already connected means it is redundant
            if(pu == pv){
                x = u;
                y = v;
            }
            else{
                // need to make the union
                dsu.Union(u, v);
            }
        }


        return {x, y};
    }
};