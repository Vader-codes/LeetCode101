class Solution {
    
    private:
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        // check for row validity
        for(int i=0; i<9; i++){
           if( board[row][i] == c)return false;
        }
        // col validity check
        for(int i=0; i<9; i++){
            if(board[i][col] == c)return false;
        }
        // now for that cell validity
        int new_r = row/3*3;
        int new_c = col/3*3;

        for(int k=0; k<3; k++){
            for(int l=0; l<3; l++){
                if(board[new_r + k][new_c+l] == c)return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                // if we found the empty cell
                if(board[i][j] == '.'){
                    // we can try 1-9 numbers
                    for(char ch = '1'; ch<='9'; ch++){
                        if(isValid(board, i, j, ch)){
                            board[i][j] = ch;
                            if(solve(board))return true;
                            else board[i][j] = '.'; //
                        }
                    }
                    return false;
                }
            }
        }
            return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
    }
};