class DSU{
    vector<int>parent;
    vector<int>rank;
    public:
    DSU(){
        // there gonna be lower case letters so 
        parent.resize(26);
        rank.resize(26);

        for(int i=0; i<26; i++){
            parent[i] = i;
            rank[i] =1;
        }
    }
    // dsu only have two funcions 
    int find(int x){
        if(parent[x] == x)return x;
        // path comprssion
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py)return;

        if(rank[px] > rank[py]){
            parent[py] = px;
        }
        else if(rank[py] > rank[px]){
            parent[px] = py;
        }
        else{
            // if there are equal attached to anyone but increase \
            the rank
            parent[px] = py;
            rank[py]++;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu;

        // first connect all the letter which has ==
        for(auto &e : equations){
            int u = e[0]-'a';
            int v = e[3]-'a';

            if(e[1] == '='){
                dsu.Union(u, v);
            }
        }

         for(auto &e : equations){
            int u = e[0]-'a';
            int v = e[3]-'a';

            if(e[1] == '!'){
              int pu = dsu.find(u);
              int pv = dsu.find(v);

              if(pu == pv)return false;
            }
        }
        
        return true;
    }
};