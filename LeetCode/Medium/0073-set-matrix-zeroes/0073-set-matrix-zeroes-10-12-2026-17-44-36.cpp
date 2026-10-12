class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

         // we need to break the problem in certain parts
         // part 1 check for row and col if there are any zeros

         bool first_row =false;
         bool first_col = false;
         for(int i=0; i<m; i++){
            if(matrix[0][i] ==0)
            first_row = true;
         }

         for(int j=0; j<n; j++){
            if(matrix[j][0] == 0)
            first_col = true;
         }

         // step 2. traverse the matrix if found 0 mark the frist row and col 0
         for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j]=0; // col
                    matrix[i][0] =0; // row
                }
            }
         }

         for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0] ==0 || matrix[0][j] ==0){
                    matrix[i][j]=0;
                }
            }
         }

         // now the first row and col are left if first_row and first_col are true\
         mark them as zeror
         if(first_row){
            for(int i=0; i<m; i++){
                matrix[0][i]=0;
            }
         }
         if(first_col){
            for(int i=0; i<n; i++){
                matrix[i][0] =0;
            }
         }
    }
};