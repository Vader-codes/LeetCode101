class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();  // rows
        int m = matrix[0].size(); // cols

        // lets start by making the boundary of our matrix
        // left right top down
        int left = 0;      // first col
        int right = m-1;  // last col
        int top = 0;     // first row
        int down = n-1; // last row

        int dir =0; 
        // direction will be 0, 1, 2, 3 where \
        0 => going left to right \
        1 => going top to down \
        2 => going from right to left \
        3 => going from down to top

        vector<int>ans;
        while( left <= right && top <= down){
            // now check for direction
            if(dir ==0){
                // left to right
                for(int i=left; i<=right; i++){
                    ans.push_back(matrix[top][i]);
                }
                dir++;
                top++;

            }
            else if(dir == 1){
                // top to down
                for(int i=top; i<=down; i++){
                    ans.push_back(matrix[i][right]);
                }
                dir++;
                right--;
            }
            else if(dir == 2){
                // right to left
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[down][i]);

                }
                dir++;
                down--;
            }
            else{
                // down to  top
                for(int i=down; i>= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                dir=0;
                left++;
            }
        }
        return ans;
    }
};