class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();  // rows
        int m = grid[0].size(); // cols

        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int, pair<int,int>>>q; //{ time, {row, col}}

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({0 ,{i,j}});
                    vis[i][j] = 1;

                }
            }
        }

        // lets make the dimensions of all the 4 directions from a cell
             // left, right, up , down
        int r[] = {0, 0, 1, -1};
        int c[] = {-1, 1 , 0,0};

        int time =0;

        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int t = q.front().first;

            time= max(time, t);

            q.pop();

            for(int i=0; i<4; i++){
                int nr = row+r[i];
                int nc = col+c[i];

                if(nr >=0 && nr < n && nc>=0 && nc <m && grid[nr][nc] == 1 &&
                  vis[nr][nc] ==0){
                    q.push({t+1, {nr, nc}});
                    vis[nr][nc] =1;
                  }
            }
        }

          for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) return -1;
            }
        }
        return time;
    }
};