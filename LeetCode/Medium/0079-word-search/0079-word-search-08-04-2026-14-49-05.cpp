class Solution {
private:
    bool solve(vector<vector<char>>& board, int row, int col, string& word,
               vector<vector<int>>& vis, int idx) {

                if(idx == word.length())return true;
        // we have to search in 4 directions to find the next matching character
        int n = board.size();
        int m = board[0].size();
        // mark the current cell as visited
        vis[row][col] = 1;
                // up, d, l, r, upL, upR, dL, dR
        int r[] = {-1, 1, 0, 0 };
        int c[] = {0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int nr = row + r[i];
            int nc = col + c[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 &&
                board[nr][nc] == word[idx]) {
               if( solve(board, nr, nc, word,vis,  idx + 1))return true;
            }
        }
         vis[row][col] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<int>>vis(n, vector<int>(m, 0));
                if (board[i][j] == word[0]) {
                    if (solve(board, i, j, word, vis, 1))
                        return true;
                }
            }
        }
        return false;
    }
};