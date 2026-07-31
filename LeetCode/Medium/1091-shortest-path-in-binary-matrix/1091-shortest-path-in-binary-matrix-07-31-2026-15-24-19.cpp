class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1)return -1;
        vector<vector<int>>vis(n, vector<int>(n, 0));
        // we can go into 8 directions which are
        // up down left right upleft upright downleft downright ,how they affect the row and col 
        int r[] ={-1, 1, 0, 0, -1, -1, 1, 1};
        int c[] = {0, 0, -1, 1, -1, 1, -1, 1};

        queue<pair<int, pair<int,int>>>q;
        q.push({1,{0, 0}});
        // mark as visited
        vis[0][0] =1;

        // now we can start the bfs from the {0, 0}
        while(!q.empty()){
            auto[step, direction] = q.front();
            q.pop();

            int row = direction.first;
            int col = direction.second;

            if(row == n-1 && col == n-1){
                // reached to the destination which is the last cell
                return step;
            }

            // need to explore its unvisited neighbours
            for(int i=0; i<8; i++){
                int nr = row+r[i];
                int nc = col+c[i];

                // we can only move to 0 and unvisited
                if(nr >=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 0 && vis[nr][nc] == 0){
                    // first mark as visited
                    vis[nr][nc] = 1;
                    q.push({step+1, {nr, nc}});
                }

            }
        }
        // we cannot react to the last cell

        return -1;

    }
};