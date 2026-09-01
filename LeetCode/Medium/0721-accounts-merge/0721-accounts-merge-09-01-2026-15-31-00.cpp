class DSU{
    vector<int>parent, rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        
        for(int i=0; i<n; i++){
            parent[i] =i;
        }
    }
    // dsu has only two functions find parent and do union
    int find(int x){
        if(parent[x] == x)return x;
        // path compression
        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y){
        int px = find(x);
        int py = find(y);

        if(px == py)return;

        if(rank[px] > rank[py]){
            parent[py] = px;
        }
        else if(rank[py] > rank[px]){
            parent[px] = py;
        }else{
               parent[px] = py;
               rank[py]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n  = accounts.size();
        DSU dsu(n);
        unordered_map<string, int>accMap;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(accMap.find(mail) == accMap.end()){
                    // cound not find it , belongs to i
                    accMap[mail] = i;
                }
                else{
                    // make a union cause it belongs to the same node
                    dsu.Union(i, accMap[mail]);

                }
            }
        }

        vector<string>mergedMails[n];
        for(auto &it : accMap){
            string mail = it.first;
            int node = it.second;

            int parent = dsu.find(node);
            mergedMails[parent].push_back(mail);
        }
          vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            if(mergedMails[i].size() == 0)continue;

            else{
               vector<string>temp;
               // need to sort the mails
               sort(mergedMails[i].begin(), mergedMails[i].end());
               // first push name
               temp.push_back(accounts[i][0]);
               // not all the mails 
               for(auto &it : mergedMails[i]){
                temp.push_back(it);
               }
               ans.push_back(temp);

            }
        }
        return ans;
    }
};