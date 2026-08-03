class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<vector<int>>revAdj(n);
            vector<int>inDegree(n, 0);

            /// now let's create a reverse adjacency list
            for(int i=0; i<n; i++){
                // i is pointing to it

                for(auto &it : graph[i]){
                    inDegree[i]++;
                    revAdj[it].push_back(i);
                }
            }

            queue<int>q;
            for(int i=0; i<n; i++){
                if(inDegree[i] == 0)q.push(i);
            }
            vector<int>ans;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                ans.push_back(node);

                // explore its neighbours
                for(auto &ne : revAdj[node]){
                    inDegree[ne]--;
                    if(inDegree[ne] == 0)q.push(ne);
                }
            }
            sort(ans.begin(), ans.end());
            return ans;
    }
};