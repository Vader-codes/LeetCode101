class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;
        int n = matrix.size();
        int col = matrix.size() - 1;
        for (int row = 0; row < n; row++) {
            for (int j = 0; j < n; j++) {

                // we have to swap the first row with last column
                temp[j][col] = matrix[row][j];
            }
            col--;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // we have to swap the first row with last column
                matrix[i][j] = temp[i][j];
            }
        }
    }
};