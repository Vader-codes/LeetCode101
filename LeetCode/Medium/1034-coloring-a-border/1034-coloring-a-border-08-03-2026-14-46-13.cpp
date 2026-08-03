class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row,
             int col, int color, vector<pair<int, int>>& borders) {
        int n = grid.size();
        int m = grid[0].size();

        bool isborder = false;
        // mark it as visited
        vis[row][col] = 1;

        // now we have to explore its 4 adjacent neighbours
        // l, r, up, down
        int r[] = {0, 0, -1, 1};
        int c[] = {-1, 1, 0, 0};

        for (int k = 0; k < 4; k++) {
            int nr = row + r[k];
            int nc = col + c[k];

            // now certain condition has to meet
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                isborder = true;
            }
            // diffferent color
            else if (grid[nr][nc] != color) {
                isborder = true;
            } else {
                // same component
                if (!vis[nr][nc])
                    dfs(grid, vis, nr, nc, color, borders);
            }
        }

        if (isborder)
            borders.push_back({row, col});
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<pair<int, int>> borders;

        int original = grid[row][col];

        dfs(grid, vis, row, col, original, borders);

        for (auto [row, col] : borders) {
            grid[row][col] = color;
        }
        return grid;
    }
};