class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        int land =0;
        vector<vector<int>>vis(n, vector<int>(n, 0));
        queue<pair<int, pair<int,int>>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({0, {i, j}});
                    vis[i][j] =1;
                    land++;
                }
            }
        }
        // check if all water or all land
        if(land == 0 || land == n*n)return -1;

        int r[] = {-1, 1, 0, 0};
        int c[] = {0,0, -1, 1};
        while(!q.empty()){
            auto[dist, direction ] = q.front();
            q.pop();
            int row = direction.first;
            int col = direction.second;

            ans = max(ans, dist);
            for(int i=0; i<4; i++){
                int nr = row+r[i];
                int nc = col+c[i];

                // check for valid nr and nc and unvisited
                if(nr >=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({dist+1, {nr, nc}});
                }
            }

        }

        return ans;

    }
};