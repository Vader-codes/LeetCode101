class Solution {
    private:
     vector<vector<string>>ans;
     bool canPlace(int row, int col, vector<string>&board){
        int n = board.size();

       // we only have to check in 3 directions
       // check up int the col
       for(int i=row; i>=0; i--){
         if(board[i][col] == 'Q')return false;
       }
      // now check upward and to the left
       for(int i=row, j=col; i>=0 && j>=0; i-- ,j--){
            if(board[i][j] == 'Q')return false;
       }
       // now upward and to the right
       for(int i=row, j=col; i>=0 && j<n; i-- ,j++){
            if(board[i][j] == 'Q')return false;
       }
        return true;
     }
     void solve(int row,vector<string>&board){
        int n = board.size();
        if(row == n ){
            ans.push_back(board);
            return;
        }

        // we have to try all the row and cols
      
          // we have to place on a column of this row
          for(int col=0; col<n; col++){
            // if we can place the queen in this cell we could and explore
            if(canPlace(row, col, board)){
                board[row][col] = 'Q'; 

                solve(row+1, board);

                // backtrack
                board[row][col] = '.'; 
            }
          }
       
     }
public:
    vector<vector<string>> solveNQueens(int n) {
        // intitial configuration of the chess borad no queens has been placed
      vector<string> temp(n, string(n, '.'));
        solve(0,temp);

        return ans;
    }
};